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
