#!/usr/bin/env python


"""
This program gets songs from the directory and adds them
to the datanbase file. This is a test program, but may be i 
need to create 2 databases, one for english songs, and 
the other one for hindi songs. Or there can be only one
which is merged version of hindi and english songs.
"""

import MySQLdb
import os
import sys

conn = MySQLdb.connect(host="localhost",
			user = "root",
			passwd = "passwd",
			db = "bnb")

cursor = conn.cursor();
cursor.execute("use bnb")
cursor.execute("SELECT * from select_song_englishsongs")
slist = os.listdir("/home/kc/Music/")
i=0 
c=0
scount=len(slist)
while c<scount:
	item = slist[c]
	l = len(item)
	query = "insert into select_song_englishsongs set "+ "sname=\""+item+"\""+" ,times_played=0"
	print "executing query - " ,query
	i+=1
	cursor.execute(query)
	c+=1

cursor.close()
conn.close()
