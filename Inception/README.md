# Inception
Setting up containerised infrastructure in Docker.
<br><br><br>

---
#### Step 0: Set up a [`Virtual Machine`](https://baigal.medium.com/born2beroot-e6e26dfb50ac)(Debian). <br>
Because we need sudo to use Docker.
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
    (link above: 2.1. Installing sudo)<br>
10. (optional) [Activate mutual clipboard]()
<br><br>
---
#### Step 1: Install Docker
1. ```
   sudo apt install -y docker.io docker-compose
   sudo systemctl enable docker
   sudo usermod -aG docker username
   ```
3. Check:
   ```
   docker --version
   docker-compose --version
   ```
<br><br>
Reference:
- [`Benjamin`](https://github.com/BenjaminHThomas/DockerInception/tree/main)
- https://mariadb.com/kb/en/creating-a-custom-container-image/
- https://docs.docker.com/compose/intro/compose-application-model/
- https://hub.docker.com/r/fauria/vsftpd/
