
#! /usr/bin/env python3
#codeing:utf-8


import random

list_tmp = []
def list_test(p):
	global list_tmp
	list_tmp.append(p)
	list_tmp.sort()
	print(list_tmp)

	list_tmp.reverse()
	print(list_tmp)
def test():
	#print("hello");
	count = 0
	for i in range(1,5):
		for j in range(1,5):
			for k in range(1,5):
				if (i != j) & (j != k) & (i != k):
					print(i*100+j*10+k)
					count+= 1

	print("all count = ",count)

if __name__ == '__main__':
    #test()
	print("hello")
if 1:
	list_test("fff")
	list_test("f")
	list_test("ff")
	list_tmp.extend(list_tmp)
	print(list_tmp)
	print(list_tmp.count('ff'))
