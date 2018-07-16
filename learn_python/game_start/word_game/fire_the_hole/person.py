#!/usr/bin/env python3
#coding:utf-8

class Package(object):
	"""描述背包的类"""
	def __init__(self):
		self.content = []
		self.left_size = 10
		

	def add_something(self,item):
		ret = 0
		if self.left_size > 0:
			self.content.append(item)
			self.left_size -= 1
			ret = 1
		return ret
		

	def remove_something(self,item):
		self.content.pop(item)

	def __str__(self):
		msg = ""
		if self.content:
			for tmp in self.content:
				msg += tmp.type
				msg +="\n"
		else:
			msg = "空空如也"
		return msg					

	def __del__(self):
		print("Package 被销毁")

class Person(object):
	"""描述人物的类"""
	__max_hp = 0
	def __init__(self,name):
		self.name=name
		self.hp = Person.__max_hp
	def injured(self,item):
		self.hp  -= item.power 
		if self.hp > 0:
			print("剩余血量:%d"%self.hp)
		else:
			print("%s被击杀"%self.name)
	def __del__(self):
		print("%s 被销毁"%self.name)
class Enemy(Person):
	"""描述游戏中怪物的类"""
	__max_hp = 50

	def __init__(self,name):
		self.name=name
		self.hp = Enemy.__max_hp
	def __str__(self):
		if self.hp > 0:
			return "%s剩余血量%d/%d"%(self.name,self.hp,Enemy.__max_hp)
		else:
			print("%s以死亡")

	
class Gamer(Person):
	"""描述玩家的类"""
	__max_hp = 100
	def __init__(self,name):
		self.name=name
		self.hp = Gamer.__max_hp
		self.package = Package()	
		self.arms = None#无武器

	def __str__(self):
		msg = "角色名称:%s\n血量:%d/%d\n包裹信息:%s"\
					%(self.name,self.hp,Gamer.__max_hp,self.package)
		return msg
	def get_something(self,item):
		ret = self.package.add_something(item)
		msg = "包裹已满,无法获得装备"
		if ret:
			msg = "\t恭喜获得装备%s"%(item.name)
		print(msg)

	def remove_something(self,item):
		self.package.remove_something(item)

	def using_something(self,item):
		if item.type == "gun":
			self.arms = item
			
	def attack(self,someone):
		if self.arms:
			self.arms.attack(someone)
		else:
			print("没有装备武器")
