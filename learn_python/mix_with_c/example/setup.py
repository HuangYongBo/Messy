#! usr/bin/python2.7
from distutils.core import setup,Extension

MOD = "mix"
setup(name=MOD,ext_modules=[Extension(MOD,sources=['mix.c','mixwrapper.c'])])
