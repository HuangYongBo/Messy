读取键盘输入
两个内置函数从标准输入一行文本，raw_input() input()
raw_input()括号中可以添加提示语

type(变量)查看变量类型


In [4]: fp = open("test.txt","w+")

In [5]: dir(fp)
Out[5]: 
['__class__',
 '__delattr__',
 '__doc__',
 '__enter__',
 '__exit__',
 '__format__',
 '__getattribute__',
 '__hash__',
 '__init__',
 '__iter__',
 '__new__',
 '__reduce__',
 '__reduce_ex__',
 '__repr__',
 '__setattr__',
 '__sizeof__',
 '__str__',
 '__subclasshook__',
 'close',
 'closed',
 'encoding',
 'errors',
 'fileno',
 'flush',
 'isatty',
 'mode',
 'name',
 'newlines',
 'next',
 'read',
 'readinto',
 'readline',
 'readlines',
 'seek',
 'softspace',
 'tell',
 'truncate',
 'write',
 'writelines',
 'xreadlines']

用hlep(fp)看详细描述
因为ipython解析器是用Ｃ语言写的，所以python中用到的open/read/close/write/seek/flush/gets/readline/都是用Ｃ实现的。也就是说，读写文件操作需要像Ｃ一样操作


可以用os库对文件进行重名/删除操作
