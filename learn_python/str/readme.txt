
概念
双引号
转义字符:\t \n \\ \' \"" ....
原始字符:(r"That is Carol\'s cat") \会被打印出来

三重引号的多行字符串: 
		print(""" xxxx
				xxx""")

多行注释: """"xxxxx"""


字符串的下标和切片:
字符串的in 和not in:


字符串的方法:upper(),lower(),isupper(),islower()
isX字符串的方法:
	isalpha(),返回True,如果字符串只包涵字母,并且非空
	isalnum(),返回True,如果字符串只包涵字母和数字,并且非空
	isdecimal(),返回True,如果字符串只包涵数字,并且非空
	isspace(),返回True,如果字符串只包涵空格/制表符/换行,并且非空
	istitle(),返回True,如果字符串只包涵以大写字母开头,后面都是小写字母的单词,并且非空

字符串startswith()和endswith():
	如果字符串的开始/结尾为传参,则返回true,如"Hello".startswith('Hello')返回True




 a = "abcd"

 a[::-1] --> "dcba"
