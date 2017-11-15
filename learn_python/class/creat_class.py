#!/usr/bin/python3

class test:
	'''
	this is a test demo class 
	'''
	num = 1
	__sex = "man"
	def __init__(self,name):
		self.name = name
		print(self.name)
	def hello(self):
		self.num ='100' 
		print(self.name + self.num)
