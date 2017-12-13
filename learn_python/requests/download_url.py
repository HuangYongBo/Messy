#! /usr/bin/python2.7
#coding:utf-8

import os,sys,requests

def save_url(url_path,save_file):
	r=requests.get(url_path)
	if r == []:
		print("error url")

	fp = open(save_file,'w')
	fp.write(r.content)
	fp.close()

if __name__ == '__main__':
	argc=len(sys.argv)
	argv=sys.argv
	if argc != 3:
		print("Usage: get [url_path] [save_file]")
		sys.exit(-1)	
	save_url(argv[1],argv[2])

