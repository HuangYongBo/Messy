#!/usr/bin/env python3
#coding:utf-8


lower_gun=["M249","AKM"]
LOWER_POWER = 10
class Clip(object):
	"""描述弹夹的类"""
	type="clip"
	def __init__(self,clip_type,bullet_count):
		self.clip_type = clip_type
		self.Max_num = 50
		self.bullet = Bullet(self.clip_type,bullet_count)
	def __str__(self):
		msg = "弹夹信息:%d/%d"%(self.bullet.count,self.Max_num)
		return msg
	def attack(self,someone):
		if self.bullet.count >0:
			self.bullet.attack(someone)	
		else:
			print("子弹用尽")
	def __del__(self):
		print("Clip 被销毁")			
	

class Bullet(object):
	"""描述子弹的类"""
	type = "bullet"
	def __init__(self,clip_type,count):
		self.power = power_for_clip_type(clip_type)
		self.type = clip_type
		self.count = count

	def attack(self,someone):
		someone.injured(self)
	def __del__(self):
		print("Bullet 被销毁")			
	

def power_for_clip_type(clip_type):
	if clip_type in lower_gun:
		return LOWER_POWER



class Gun(object):
	"""描述枪支的类"""
	type = "gun"
	def __init__(self):
		self.clip = None

	def loaded_bullet(self,clip):
		self.clip  = clip

	def __str__(self):
		pass

	def attack(self):
		"""开火"""
		pass
	def loaded_clip(self):
		"""换弹夹"""
		pass
	def __del__(self):
		print("Gun 被销毁")

class M249(Gun):
	
	def __init__(self):
		#super().__init__()
		self.name = "M249"
		self.clip = Clip("M249",10)
		
	def __str__(self):
		if self.clip:
			msg = "M249中%s"%(self.clip)
		else:
			msg= "M249未装备弹夹"
		return msg
	
	def attack(self,someone):
		if self.clip:
			self.clip.attack(someone)

