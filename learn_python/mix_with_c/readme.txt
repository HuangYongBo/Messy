python中混合使用c或c++

确定c代码正确后,将代码做成python库
nm命令?
#! /usr/bin/env python?
wrapper包裹模块,将第三方代码适配成python库
A包裹函数,实现包裹主要分为4步:(mytestwrapper.c)
1包含python.h头文件 (/usr/include/python2.7/)
2为每个函数增加一个PyObject *Module_func()的包裹函数
3为模块添加一个PyMethod DefModuleMethods[]的数组
4添加模块的初始函数void initModule()

B编译安装到python环境:
1创建setup.py
	from distutils.core import setup,Extension
	MOD = "mytest"
	setup(name=MOD,ext_modules=[Extension(MOD,sources=['mytest.c','mytestwrapper.c'])])
2执行setup.py,生成so文件,安装
	python setup.py build
	python setup.py install
3导入包,import xxx

代码如下:
#include "Python.h"
#include <stdio.h>//c代码需要调用到的库
#include <string.h>

#include "mytest.h" //库文件的头文件

static PyObject *mytest_func1(PyObject *self,PyObject *args)//包裹函数名为包名_原函数名,但也不严格
{
	int num;
	if(!PyArg_ParseTuple(args,"i",&num))//将python的数据类型转换成c
		return NULL;

	return (PyObject *)Py_BuildValue*("i",func1(xxxx));//转成python数据
	
}

static PyObject *mytest_func2(PyObject *self,PyObject *args)
{

}

static PyMethodDef mytestMethods[]={
	{"func1",mytest_func1,METH_VARARGS},
	....
};
void initMytest(void)
{
	Py_InitModule("mytest",mytestMethods);
}





补充:
	Python和C/C++之间数据转换:
warning:
mix.h:5:1: warning: function declaration isn’t a prototype [-Wstrict-prototypes]
 void test();

solve:
	void test(void);

