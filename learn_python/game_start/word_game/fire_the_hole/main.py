#!/usr/bin/env python3
#conding:utf-8

from person import *
from gun import *
from myexception import *
import sys

def main():
	print("\t欢迎来到召唤师峡谷\t")
	print("\t当前没有角色,请先创建一名角色\t")
	print("请输入角色名:",end = "")
	try:
		name = input()
		if name == "":
			raise InputNone()
		#创建角色,初始无装备
		new_gamer = Gamer(name)
		print("成功创建角色,信息如下:")
		print(new_gamer)
		
	except InputNone:
		print("创建对象失败,程序结束")
		sys.exit()
	finally:
		for i in range(5):
			print()
	#创建一个武器对象
	gun_M249 = M249()
#	print(gun_M249)
	
	#创建一个弹夹对象
	clip_M249 = Clip("M249",30)
#	print(clip_M249)
	
	#创建一个子弹对象
	bullet_M249 = Bullet("M249",30)
	#人物获取武器
	new_gamer.get_something(gun_M249)
	print(new_gamer)

	#创建一个敌人
	enemy1 = Enemy("enemy1")
	print(enemy1)
	
	for tmp in new_gamer.package.content:
		if tmp.type == "gun":
			break
	new_gamer.using_something(tmp)
	
	for i in range(10):
		new_gamer.attack(enemy1)

	print("#####")

if __name__ == "__main__":
	main()
