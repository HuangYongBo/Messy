语法:

try:#可能出现异常的开始位置
	pass #可能出现异常的代码
except NameError:#变量名错误引发的异常
	print(NameError)#执行异常处理操作
except Exception as result:#除以上异常外的其他异常,as关键字将异常保存到result中
	print(result)
else:#如果没有出现异常,则执行的操作
	pass
finally:#无论是否发生异常都会执行的操作



抛出自定义异常:

class MyError(Exception):
	'''自定义的异常'''
	def __init__(self,len):
		#super().__init__()
		self.len = len

try:
	raise  MyError(3)
except MyError as result:
	print("Myerror:%d"%(result.len))
else:
	print("run without except")		


在异常处理中抛出异常
try:
	pass
except Exception:
	print("处理异常")#将异常写到log日志中,再让系统处理
	raise #将异常抛给系统
