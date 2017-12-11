#!/usr/bin/python2.7
#coding:utf-8

myPath="./"
fontPath="./"
fontFile="KhmerOS.ttf"
inputFile="hyb.jpg"
outputFile="output.jpg"

import Image,ImageFont,ImageDraw

def picture_change(fileFile,fontFile,num,outputFile):
	img = Image.open(fileFile)
	draw=ImageDraw.Draw(img)
	fontsize=min(img.size)/4
	font=ImageFont.truetype(fontFile,fontsize)
	draw.text((img.size[0]-fontsize,0),num,font=font,fill=(255,0,0))
	img.save(outputFile,"jpeg")

if __name__ == '__main__':
	picture_change(myPath+inputFile,fontPath+fontFile,'8',outputFile)
