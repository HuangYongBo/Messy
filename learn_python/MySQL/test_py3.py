#!/usr/bin/env python3
import pymysql

conn = pymysql.connect(user='root',passwd='mysql20171208',db='test')
curtos = conn.cursor()
ret = curtos.execute("select * from user;")
curtos.fetchone()
ret = curtos.execute("select * from user;")
curtos.fetchmany(4)
ret = curtos.execute("select * from user;")
curtos.fetchall()
tp = 'djiftoo'
np='643277374'
curtos.execute("insert into user(password,username) value(%s,%s);",(tp,np))
ret = curtos.execute("select * from user;")
print(curtos.fetchall())
conn.commit()
conn.close()

