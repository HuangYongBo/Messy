#! /usr/bin/python2.7
#coding:utf-8

import Image,ImageFont,ImageDraw,string,random

field = string.letters+string.digits
#if in python3 :field = string.ascii_letters+string.digits

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
		tmp =string.join(random.sample(field,l),'')
		ret.append(tmp)
	return ret

def picture_change(fileFile,fontFile,code,outputFile):
	img = Image.open(fileFile)
	draw=ImageDraw.Draw(img)

	count =len(code)
	print(count)
	for i in range(count):
		fontsize=min(img.size)/(random.randrange(2,count))
		print(fontsize)
		font=ImageFont.truetype(fontFile,fontsize)
		#x = random.randrange(int(i*img.size[0]/count))
		#y = random.randrange(fontsize,img.size[1]-fontsize)
		x = i * int(img.size[0]/count)
		y = 10
		print("x = %d,y = %d",x,y)
		color=[random.randrange(255),random.randrange(255),random.randrange(255)]
		print(color)
		draw.text((x,y),code[i],font=font,fill=tuple(color))

	img.save(outputFile,"jpeg")


if __name__ == "__main__":
	result =get_activation_code(6,1)
	print(str(result))
	picture_change(myPath+inputFile,fontPath+fontFile,result[0],myPath+outputFile)
