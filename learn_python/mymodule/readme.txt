如何发布一个python包?
1.1有一个工程
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
