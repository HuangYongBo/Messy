#!/usr/bin/env python3
#coding:utf-8


import pygame,sys,random,time
from pygame.locals import *

class Plant(object):
	"""描述飞机的类"""
	def __init__(self,pic,x=0,y=0):
		self.x = x
		self.y = y
		self.pic = pygame.image.load(pic)
		self.size = self.pic.get_size()
		self.width = self.size[0]
		self.height = self.size[1]
	def display(self,screen):
		screen.blit(self.pic,(self.x,self.y))
	def move(self,direction):
		if direction == "left":
			if self.x < 10:
				self.x = 0
			else:
				self.x -= 10
		elif direction == "right":
				self.x += 10
		elif direction == "down":
			self.y += 10
		elif direction == "up":
			self.y -= 10

class Hero(Plant):
	"""描述玩家飞机的类"""

class Enemy(Plant):
	"""描述游戏中敌机的类"""
	pass

def control_move(plant):
	for event in pygame.event.get():
		if event.type == QUIT:
			exit()
		elif event.type == KEYDOWN:
			if event.key == K_a or event.key == K_LEFT:
				plant.move("left")
			if event.key == K_d or event.key == K_RIGHT:
				plant.move("right")
			if event.key == K_w or event.key == K_UP:
				plant.move("up")
			if event.key == K_s or event.key == K_DOWN:
				plant.move("down")
	
def main():


	#创建窗口
	screen = pygame.display.set_mode((480,852))
	#获取图片
	background = pygame.image.load("./pic/background.png")
	#填充图片
	hero = Hero("./pic/hero1.png",200,400)

	while True:
		screen.blit(background,(0,0))
		control_move(hero)
		hero.display(screen)
		pygame.display.update()
#		time.sleep(0.1)

	

	


if __name__ == "__main__":
	main()
