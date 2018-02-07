#一个简单的搜索对应dict!
		s = {'iven':100,'kven':97,'linus':89,'lary':79,'harri':90}
		for d in s:
			print(d)
		print('输入你的需要查找的姓名:')
		name = input()

		ssd =s.get(name,False)
		if ssd == False:
			print('搜索结果:您输入的名字不存在!\n')
		else:
			x = int(s[name])
			print(name,'同学你好,你的分数是:',x,)

setdefault:如果不存在该值,则将其设置为默认值:
		spam = {'name':"hyb"}
		spam.setdefault('color',"black")

get:获得某个值,如果不存在则默认返回None,或则返回设置的值:
		spam = {'name':"hyb"}
		spam = get('ff')#此处返回None
		spam = get('ff',False)#此处返回False


计算一个字符串中每个字符出现的次数:
		message = "It was a bright cold day in April,and the clocks were striking thirteen"
		count = {}
		for c in message:
			nu = count.setdefault(c,0)
			count[c] = nu+1
		print(count)#打印更好看,可以import pprint,pprint.pprint(count)
