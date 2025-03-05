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
