
import os,requests

r=requests.get("http://www.cnblogs.com/codemind/p/8031710.html")
fp = open("./hello.html",'w')
fp.write(r.content)
fp.close()

