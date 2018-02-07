#!/usr/bin/env python3
#coding:utf-8

import sys,random

class Home(object):
	def __init__(self,name,area,location):
		self.name = name
		self.area = area
		self.location = location
		self.furniture_count=0
		self.furniture=[]
		print("构造房子:%s"%(self.name))
		print("房子位于:%s占地面积:%d"%(self.location,self.area))
	def __del__(self):
		print("房子已被拆迁")
	def add_furniture(self,item):
		self.furniture.append(item)
		print("%s 添加家具 %s"%(self.name,item.furniture_type))
	def show_furniture(self):
		print("已有家具:%s"%(str(self.furniture)))
	def boom(self):
		for tmp in self.furniture:
			tmp.kill_myself()			
	
class Furniture(object):
	__count=0
	def __init__(self,new_type,new_area):
		self.furniture_type = new_type
		self.area = new_area
		print("构造家具%s"%(self.furniture_type))
	def __del__(self):
		print("%s已经被销毁"%(self.furniture_type))

	def kill_myself(self):		
		self.__del__()
	def __str__(self):
		pass



desk=Furniture("desk",2)
chair=Furniture("chair",2)
bed=Furniture("bed",4)
myhouse=Home("大富翁别墅",200,"北京市 朝阳区 长安街666号")
myhouse.add_furniture(desk)
myhouse.add_furniture(chair)
myhouse.add_furniture(bed)
del desk
del bed
del chair

myhouse.boom()

print(sys.getrefcount(myhouse.furniture))
