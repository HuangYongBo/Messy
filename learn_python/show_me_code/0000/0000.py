#!/usr/bin/python2.7
#coding:utf-8

myPath="./"
fontPath="./"
fontFile="KhmerOS.ttf"
inputFile="hyb.jpg"
outputFile="output.jpg"

import Image,ImageFont,ImageDraw

img = Image.open(myPath+inputFile)
draw=ImageDraw.Draw(img)
fontsize=min(img.size)/4
font=ImageFont.truetype(fontPath+"KhmerOS.ttf",fontsize)
draw.text((img.size[0]-fontsize,0),'8',font=font,fill=(255,0,0))
img.save(myPath+outputFile,"jpeg")
