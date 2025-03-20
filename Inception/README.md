# Inception
Setting up containerised infrastructure in Docker.
<br><br>


<details>
   <summary>

   #### Step 0: Set up a [`Virtual Machine`](https://baigal.medium.com/born2beroot-e6e26dfb50ac)(Debian).
Because we need sudo to use Docker.
   </summary>

1. 6144 MB RAM, 3 CPU, 40 GB hard disk.
2. Graphical Install<br>
   (otherwise is tricky to access the containers outside the VM)
3. hostname: login or whatever
4. domain name: login.42.fr
5. Write the changes to disks.
6. Don't scan more media.
7. No HTTP proxy.
   (optional SSH server)
8. Install GRUB → /dev/sda
9. Configure sudo
    (link above: 2.1. Installing sudo)
<details>
   <summary><i>
(optional) Activate mutual clipboard</i>
   </summary>

1. Go to the folder corresponding to your debian version.
2. Download the .iso and mount it on your VirtualBox.
   (裝置→光碟機→Choose/Create a Disk Image)
3. ```
   sudo mount /dev/cdrom /media/cdrom0
   cd /media/cdrom0
   sudo ./VBoxLinuxAdditions.run
   ```
4. Reboot
   ```
   sudo reboot
   ```
</details>

<br><br>
---
</details>
<details>
<summary>

#### Step 1: Install Docker V2
</summary>

1. ```
   sudo apt update
   sudo apt install -y ca-certificates curl gnupg lsb-release
   sudo mkdir -p /etc/apt/keyrings
   curl -fsSL https://download.docker.com/linux/debian/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
   echo "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/debian $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
   sudo apt update
   sudo apt install -y docker-ce docker-ce-cli containerd.io docker-compose-plugin (or sudo apt install -y docker.io docker-compose-plugin if you are using the distro version)
   sudo systemctl enable docker
   sudo systemctl start docker
   sudo usermod -aG docker username
   ```
2. Check1:
   ```
   docker --version
   docker compose version
   docker-compose --version
   ```
   The last one should be an error, because it checks if you installed a Docker V1.
3. Check2:
   ```
   docker run hello-world
   ```
   If `groups` and `groups username` are inconsistent, reboot.

<br><br>
---
</details>
<details>
<summary>

#### Step 2: Configure Docker
</summary>

1. Set up a `docker-compose.yml`.<br>
> Information for Docker to build the containers.
2. Set up a `Dockerfile` for each service.<br>
> Dockerfile is a script with instructions to build a Docker image, just like a Makefile to build a program.

<br><br>
---
</details>

#### Step 3: Register the SSH key
- [42 Tutorial](https://www.youtube.com/watch?v=qu8vjw5xwLA)

<details>
   <summary>
      
##### References
   </summary>

- [`Benjamin`](https://github.com/BenjaminHThomas/DockerInception/tree/main) (mariadb set-up is flawed
- [`Tsung-Hao`](https://github.com/Tsunghao-C/Inception/tree/main)
- https://mariadb.com/kb/en/creating-a-custom-container-image/
- https://docs.docker.com/compose/intro/compose-application-model/
 - https://hub.docker.com/r/fauria/vsftpd/
</details>
