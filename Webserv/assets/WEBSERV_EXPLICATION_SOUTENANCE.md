# 🎯 Guide de Soutenance Webserv - Comprendre et Expliquer le Code

## 📋 Table des matières

1. [Les questions qu'on va vous poser](#questions-frequentes)
2. [Comment expliquer le flux principal](#flux-principal)
3. [Les parties critiques à maîtriser](#parties-critiques)
4. [Scripts de test pour la démo](#scripts-test)
5. [Réponses types pour la soutenance](#reponses-types)

---

## ❓ Les questions qu'on va vous poser {#questions-frequentes}

### 1. "Comment fonctionne votre serveur ?"

**Votre réponse :**
```
"Notre serveur utilise epoll pour gérer plusieurs clients simultanément de manière non-bloquante.
1. D'abord, on parse la configuration JSON pour créer nos serveurs
2. Chaque serveur écoute sur un port avec un socket
3. La boucle epoll surveille tous les sockets
4. Quand un client se connecte ou envoie des données, epoll nous prévient
5. On parse la requête HTTP, on génère la réponse appropriée"
```

### 2. "Montrez-moi où vous parsez les requêtes HTTP"

**Montrer :** `src/http/Request.cpp`

**Votre explication :**
```cpp
// Ligne 16 - parseHead() : Parse la première ligne
"GET /index.html HTTP/1.1"
 ↑       ↑         ↑
method  url     version

// On découpe la ligne avec les espaces
// On extrait method, URL et version
// Si l'URL contient '?', on sépare les query strings
```

### 3. "Comment gérez-vous plusieurs clients ?"

**Montrer :** `src/multiplexer/EventHandler.cpp:66`

**Votre explication :**
```
"On utilise epoll qui surveille tous nos sockets :
- EP_SERVER : nouveau client qui veut se connecter
- EP_CLIENT : client existant qui envoie des données
- EP_CGI : script CGI qui retourne des résultats
Chaque client a sa propre structure ClientConnection
qui stocke son buffer et son état"
```

---

## 🔄 Comment expliquer le flux principal {#flux-principal}

### Schéma simple à dessiner au tableau :

```
Client (Chrome)          Votre Serveur           Fichier/CGI
    |                         |                       |
    |-------- Connect ------->|                       |
    |                         |                       |
    |<------ Accept ----------|                       |
    |                         |                       |
    |-- GET /index.html ----->|                       |
    |                         |                       |
    |                         |---- Read file ------->|
    |                         |                       |
    |                         |<--- Content ---------|
    |                         |                       |
    |<--- HTTP/1.1 200 OK ----|                       |
    |<--- <html>...</html> ---|                       |
```

### Le parcours d'une requête (à savoir par cœur) :

1. **Connexion** (`EventHandler.cpp:124`)
   ```cpp
   // Un client se connecte
   int client_fd = accept(server_fd, ...);
   // On l'ajoute à epoll pour surveiller ses messages
   ```

2. **Réception** (`EventHandler.cpp:194`)
   ```cpp
   // Le client envoie "GET /index.html HTTP/1.1\r\n..."
   recv(client_fd, buffer, BUFFER_SIZE, 0);
   ```
3. **Parsing** (`Request.cpp:16`)
   ```cpp
   // On analyse la requête
   request.parse(buffer);
   // → method = "GET"
   // → url = "/index.html"
   ```

4. **Traitement** (`Response.cpp:79`)
   ```cpp
   // On génère la réponse selon la méthode
   if (method == "GET")
       handleGet();  // Lit le fichier
   ```

5. **Envoi** (`EventHandler.cpp:334`)
   ```cpp
   // On envoie la réponse
   send(client_fd, response.c_str(), response.size(), 0);
   ```
---
## 🔥 Les parties critiques à maîtriser {#parties-critiques}
### 1. **Pourquoi epoll et pas select ?**
```cpp
// select : limité à 1024 file descriptors
// epoll : peut gérer des milliers de connexions
// Votre code utilise epoll :
epoll_wait(_epfd, _events, MAX_EVENTS, -1);
// Plus efficace pour beaucoup de clients
```

### 2. **Le parsing HTTP ligne par ligne**

```cpp
// Request.cpp - À bien comprendre
void Request::parseHead(const std::string& head) {
    // "GET /page.html?name=test HTTP/1.1"

    // 1. Trouve le premier espace
    size_t pos1 = head.find(' ');
    _method = head.substr(0, pos1);  // "GET"

    // 2. Trouve le deuxième espace  
    size_t pos2 = head.find(' ', pos1 + 1);
    string full_url = head.substr(pos1 + 1, pos2 - pos1 - 1);

    // 3. Sépare URL et query string
    size_t q = full_url.find('?');
    if (q != string::npos) {
        _url = full_url.substr(0, q);           // "/page.html"
        _query_string = full_url.substr(q + 1);  // "name=test"
    }
}
```
### 3. **La gestion des erreurs HTTP**
```cpp
// Les codes à connaître :
200 OK              // Succès
201 Created         // POST réussi
204 No Content      // DELETE réussi
400 Bad Request     // Requête mal formée
404 Not Found       // Fichier introuvable
405 Method Not Allowed  // GET sur une route POST only
413 Payload Too Large   // Body trop gros
500 Internal Server Error
```

### 4. **Le chunked encoding**

```
// Si on vous demande :
"Le chunked permet d'envoyer des données sans connaître 
la taille totale à l'avance. On envoie par morceaux :
5\r\n        (taille en hexa)
Hello\r\n    (données)
0\r\n        (fin)
\r\n"
```

### 5. **CGI - Comment ça marche**

```cpp
// CGIManager.cpp simplifié
"On fork() un processus enfant qui execute le script Python/PHP
On redirige son stdout vers un pipe
On lit ce pipe pour récupérer la sortie HTML"

// Variables d'environnement importantes :
REQUEST_METHOD=GET
QUERY_STRING=name=value
CONTENT_LENGTH=123
```

---

## 🧪 Scripts de test pour la démo {#scripts-test}

### 1. **Test basique GET**
```bash
# Terminal 1
./webserv

# Terminal 2
curl http://localhost:8080/
# Montre la page d'accueil
```

### 2. **Test upload POST**
```bash
# Créer un fichier test
echo "Hello World" > test.txt

# Upload
curl -X POST -H "Content-Type: text/plain" \
     --data-binary @test.txt \
     http://localhost:8080/upload

# Vérifier
ls -la upload/
```

### 3. **Test DELETE**
```bash
# Supprimer un fichier uploadé
curl -X DELETE http://localhost:8080/upload/[filename]
```

### 4. **Test CGI Python**
```bash
# Créer un script simple
echo 'print("Content-Type: text/html\n")
print("<h1>Hello from Python</h1>")' > website/test.py

# Tester
curl http://localhost:8080/test.py
```

### 5. **Test erreur 404**
```bash
curl http://localhost:8080/fichier_inexistant
# Doit afficher votre page 404 custom
```

---

## 💬 Réponses types pour la soutenance {#reponses-types}

### "Pourquoi cette architecture ?"

```
"On a séparé les responsabilités :
- EventHandler : gère la boucle d'événements
- Request/Response : gère le protocole HTTP
- Config : gère la configuration
- CGIManager : gère les scripts externes
Ça rend le code modulaire et maintenable."
```

### "Comment gérez-vous la sécurité ?"

```
"Plusieurs points :
1. On vérifie que les chemins ne contiennent pas '..'
2. On limite la taille des requêtes (max_body_size)
3. On valide les méthodes HTTP autorisées
4. On ne crash jamais, on retourne des erreurs HTTP"
```

### "Expliquez le non-blocking"

```
"Au lieu d'attendre qu'un client finisse :
- On met tous les sockets en mode non-bloquant
- epoll nous dit qui a des données
- On lit ce qui est disponible sans bloquer
- On passe au client suivant
Résultat : on peut servir 1000 clients avec 1 thread"
```

### "Comment testez-vous votre serveur ?"

```
"On a plusieurs approches :
1. Tests manuels avec curl et telnet
2. Tests automatisés avec Hurl
3. Tests de charge avec Apache Bench
4. Tests avec de vrais navigateurs"
```

### "Montrez-moi un parcours complet"

**Ouvrir 3 terminaux :**

```bash
# Terminal 1 - Le serveur
./webserv
# Montrer les logs

# Terminal 2 - tcpdump (optionnel mais impressionnant)
sudo tcpdump -i lo -n port 8080

# Terminal 3 - Le client
curl -v http://localhost:8080/
```

**Expliquer en montrant les logs :**
```
"Regardez :
1. Nouvelle connexion détectée [EP_SERVER]
2. Requête reçue [EP_CLIENT] 
3. Parse de 'GET / HTTP/1.1'
4. Lecture du fichier index.html
5. Envoi de la réponse 200 OK
6. Connexion fermée"
```

---

## 📝 Check-list avant la soutenance

### À préparer :
- [ ] Serveur qui tourne sans erreurs
- [ ] Fichiers de test (HTML, images, etc.)
- [ ] Script CGI simple qui fonctionne
- [ ] Configuration avec plusieurs serveurs/ports
- [ ] Page 404 personnalisée

### À réviser :
- [ ] Le flux complet d'une requête
- [ ] Les codes HTTP importants
- [ ] La différence entre blocking/non-blocking
- [ ] Comment fonctionne epoll
- [ ] Le format des requêtes/réponses HTTP

### Questions à vous poser :
1. Où est le main() ? Que fait-il ?
2. Comment on accepte une connexion ?
3. Où on parse la requête ?
4. Comment on lit un fichier ?
5. Comment on gère les erreurs ?

---

## 🎯 Conseils finaux

1. **Restez simple** dans vos explications
2. **Montrez le code** en expliquant
3. **Utilisez le tableau** pour les schémas
4. **Ayez des exemples** prêts (GET, POST, 404)
5. **Reconnaissez** si vous ne savez pas, mais proposez où chercher

**Phrase magique :**
"Je vais vous montrer dans le code..." 
*[ouvrir le fichier et montrer]*

**Si vous êtes perdu :**
"Laissez-moi retrouver ça dans le code... Ah voilà, c'est ici dans EventHandler.cpp ligne 194 qu'on reçoit les requêtes"

Bonne chance pour demain ! 🚀