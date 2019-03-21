#!/usr/bin/python3
import sys
def move(src,dest,tmp,size):

    if(size == 1):
        dest.append(src.pop())
        return

    move(src,tmp,dest,size-1)
    dest.append(src.pop())
    move(tmp,dest,src,size-1)



x = [5,4,3,2,1]
y = []
z = []

size = 5
if(len(sys.argv) == 2):
    size = int(sys.argv[1])
move(x,y,z,size)

print(x,y,z)
    

