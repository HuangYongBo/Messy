可以直接添加属性
test.age = 7
del test.age //删除


getattr(obj,name[,default]);//访问对象属性
hasattr(obj,name):检测存在属性
setattr(obj,name,value):设置一个属性不存在则创建一个性的
delattr(obj,name)删除属性

Python内置类属性:
__dict__:类的属性（包含一个字典，由类的数据属性组成）
__doc__:类的文档字符串
__name__:类名
__module__:类定义所在的模块(类的全名是'__main__.className'，如果类位于一个导入模块mymod中
		那么className.__module__等于mymod)
__bases__:类的所有父类构成元素（包含了一个由所有父类组成的元组）



私有变量/方法以两个下划线开头，如：
class test:
		__sex = "man"
		__init__(self)
			print("creat")

无法直接.引用（同Ｃ++），但是用dir(test)可以看到
In[2]:	dir(test)
Out[2]: ['__doc__', '__init__', '__module__', '_test__sex', 'hello', 'num']
可以用_test__sex引用




类属性:不添加self
类方法:@classmethod
def add_num(cls):
静态方法:@staticmethod
def static_func():


继承:
class Father:
	pass
class Son(Father):
	pass

继承后重写父类方法:函数名相同
class Father:
	def introduce(self):
		print("I'm father")

class Son(Father):
	def introduce(self):
		print("I'm son")
使用被重写的父类方法
class Father:
	def introduce(self):
		print("I'm father")

class Son(Father):
	def introduce(self):
		print("I'm son")
		super().introduce()#第一种方式
		Father.introduce(self)#第二种方式


print(类名.__mro__)#调用方法的查找顺序,C3算法
globals()全局变量
locals()当前能访问的局部变量



如何发布一个python包?
1有一个工程
mymodule
├── setup.py
├── suba
│   ├── aa.py
│   ├── bb.py
│   └── __init__.py
└── subb
    ├── cc.py
    ├── dd.py
    └── __init__.py

2setup.py 添加一下内容
from distutils.core import setup

setup(name="test",version="1.0",description="my test module",author="huangyongbo",py_modules=['suba.aa','suba.bb','subb.cc','subb.dd'])


3构建 python setup.py build
.
├── build
│   └── lib.linux-x86_64-2.7
│       ├── suba
│       │   ├── aa.py
│       │   ├── bb.py

│       │   └── __init__.py
│       └── subb
│           ├── cc.py
│           ├── dd.py
│           └── __init__.py
├── setup.py
├── suba
│   ├── aa.py
│   ├── bb.py
│   └── __init__.py
└── subb
    ├── cc.py
    ├── dd.py
    └── __init__.py

4生成发布压缩包python setup.py sdist
.
├── build
│   └── lib.linux-x86_64-2.7
│       ├── suba
│       │   ├── aa.py
│       │   ├── bb.py
│       │   └── __init__.py
│       └── subb
│           ├── cc.py
│           ├── dd.py
│           └── __init__.py
├── dist
│   └── test-1.0.tar.gz
├── MANIFEST
├── setup.py
├── suba
│   ├── aa.py
│   ├── bb.py
│   └── __init__.py
└── subb
    ├── cc.py
    ├── dd.py
    └── __init__.py

会出现一个dist目录，目录中有一个压缩包

解压tar zxvf test-1.0.tar.gz
后进入test目录，执行python setup.py  install
