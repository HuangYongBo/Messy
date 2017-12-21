#! /usr/bin/env python3.4
#coding:utf-8

import string,random,pymysql

field = string.ascii_letters+string.digits

def get_activation_code(l,n):
	ret =[]
	for i in range(n):
		tmp=''.join(random.sample(field,l))
		ret.append(tmp)
	print("get_activation_code " )
	print( ret)
	return ret

def test():
	result = get_activation_code(6,200)
	conn = pymysql.connect(user = 'root',passwd= 'mysql20171208',db = 'test')
	cursor = conn.cursor()	
	for i in range(len(result)):
		cursor.execute("insert into random(num,code) value(%s,%s);",(i+200,result[i]))
	conn.commit()
	conn.close()
			

if __name__ =='__main__':
	test()
	print("save ok")
