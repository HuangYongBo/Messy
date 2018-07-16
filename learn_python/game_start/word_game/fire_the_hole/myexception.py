#!/usr/bin/env python3
#conding:utf-8


class InputNone(Exception):
	def __init__(self):
		super().__init__()
def test():
	try:
		raise InputNone()
	except InputNone:
		print("xxx")

if __name__ == "__main__":
	test()
