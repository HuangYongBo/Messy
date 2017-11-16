生成随机数,可用于生成随机码



string.letters:英文字符

In [6]: string.letters
Out[6]: 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'

string.digits:数字
In [7]: string.digits
Out[7]: '0123456789'

string.letters+string.digits = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789'


#!/usr/bin/python3
#coding:utf-8

import string,random

field=string.letters+string.digits

def getRandom():
	return "".join(random.sample(field,4))

def concatenate(group):
	return "-".join([getRandom() for i in range(group)])

def gennerate(n):
	return [concatenate(4) for i in range(n)]

if __name__ == '__main__':
	print(gennerate(10))

