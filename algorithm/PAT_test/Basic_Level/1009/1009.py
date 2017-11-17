#!/usr/bin/python3
#coding:utf-8

import re,os

def sentence_reverse(str):
	pattern = r"""[A-Za-z]+|\$?\d+%?$"""
	r = re.findall(pattern,str)
	word_count = len(r)
	while word_count:
		word_count -= 1
		if word_count == 0:
			print(r[word_count])
		else :
			print(r[word_count],end =' ')
	return

str = input()
sentence_reverse(str)

