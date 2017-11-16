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
