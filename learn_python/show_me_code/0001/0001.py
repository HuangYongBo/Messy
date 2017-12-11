#!/usr/bin/python2.7
#coding:utf-8

import random,string

field = string.letters+string.digits
#if in python3 :field = string.ascii_letters+string.digits

def get_activation_code(l,n):
	"""
	l(length):the length of code
	n(number):how many code would you want
	"""
	ret = []
	for i in range(n):
		tmp ="".join(random.sample(field,l))
		ret.append(tmp)
	return ret
if __name__ == "__main__":
	result =get_activation_code(10,200)
	print(result)
