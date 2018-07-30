
import sys
class  T(object):
    def __init__(self,num):
        number = num
t = T(12)
print(sys.getrefcount(t))
tt = t
print(sys.getrefcount(tt))
