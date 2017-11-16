#!/usr/bin/python3
#coding:utf-8
import re,os
from collections import Counter

FILE_PATH='./countword.txt'

def getCounter(articlefilesource):
	"""输入一个英文的纯文本文件,统计其中出现单词出现的次数 """
	pattern = r"""[A-Za-z]+|\$?\d+%?$"""
	with open(articlefilesource) as f:
		r=re.findall(pattern,f.read())
		return Counter(r)

#过滤单词
stop_word=['the','in','of','and','to','has','that','s','is','are','with','as','an']

def run(FILE_PATH):
#	os.chdir(FILE_PATH)
	total_counter = Counter()
	for i in os.listdir(os.getcwd()):
		if os.path.splitext(i)[1] =='.txt':
			total_counter += getCounter(i)

	for i in stop_word:
		total_counter[i]=0
	print(total_counter.most_common()[0][0])

if __name__ == '__main__':
	run(FILE_PATH)
