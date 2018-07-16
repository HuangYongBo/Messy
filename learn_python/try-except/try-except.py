#!/usr/bin/env python3
#coding:utf-8

if __name__ == "__main__":
	try:
		print("%d"%(num))
	except NameError:
		print("NameError")
	except Exception:
		print("other Error")
	finally:
		print("over")
