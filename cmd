gcc -o pc vlc.c $(pkg-config --cflags libvlc) $(pkg-config --libs libvlc) $(mysql_config --libs) $(mysql_config --cflags)
