#!/usr/bin/python3
#test python project

def fun1(*a):
	a[0] = 2
	return a
def fun2(**a):
	print(a)
	for key in a:
		print(key+"="+str(a[key]))
	return 

