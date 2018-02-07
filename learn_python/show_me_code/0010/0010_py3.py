#! /usr/bin/python3
#coding:utf-8

from PIL import Image,ImageFont,ImageDraw
import string,random
import pygame
import sys
from pygame.locals import *
#if in python2 :field = string.letters+string.digits

field = string.ascii_letters+string.digits

myPath="./"
fontPath="./"
inputFile="hyb.jpg"
outputFile="output.jpg"
fontFile="KhmerOS.ttf"

def get_activation_code(l,n):
	"""
	l(length):the length of code
	n(number):how many code would you want
	"""
	ret = []
	for i in range(n):
#		tmp =string.join(random.sample(field,l),'')
		ret.append(''.join(random.sample(field,l))
)
	return ret

def picture_change(fileFile,fontFile,code,outputFile):
	img = Image.open(fileFile)
	draw=ImageDraw.Draw(img)

	count =len(code)
	print(count)
	for i in range(count):
		fontsize=int(min(img.size)/(random.randrange(2,count)))
		print(fontsize)
		font=ImageFont.truetype(fontFile,fontsize)
		tmp_x = int(i*img.size[0]/count)
		x = random.randrange(tmp_x,tmp_x +10)
		y = random.randrange(0,img.size[1]-fontsize)
		color=[random.randrange(255),random.randrange(255),random.randrange(255)]
		print(color)
		draw.text((x,y),code[i],font=font,fill=tuple(color))

	img.save(outputFile,"jpeg")

def show(path):
	img = pygame.image.load(path)
	screen = pygame.display.set_mode(img.get_size())
	screen.blit(img,(0,0))
	pygame.display.update()
	

def get_control():
	for event in pygame.event.get():
		if event.type == QUIT:
			sys.exit()

if __name__ == "__main__":
	result =get_activation_code(6,1)
	print(str(result))
	picture_change(myPath+inputFile,fontPath+fontFile,result[0],myPath+outputFile)
	while True:
		pygame.time.delay(1)
		show(myPath+outputFile)
		get_control()
