#!/usr/bin/python3
#coding:utf-8

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



class Cat:
	#属性


	#方法
	def __init__(self,name):
		self.name = name
		print("猫出生了,名字叫做%s"%(self.name))
	def eat(self):
		print("猫在吃猫粮")
	def drink(self):
		print("猫在喝橙汁")
	def __del__(self):
		print("猫死了")


tom = Cat("Tom") #构造一个对象后返回一个引用
tom.eat()
tom.drink()
tom.age = 10
tom.sex = 'man'
tom.name = 'tom'
print("%s is %d years old"%(tom.name,tom.age))
