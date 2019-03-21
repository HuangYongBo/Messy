#!/usr/bin/python3

# print 3*4 matrix:
#  1  2  3
# 10 11  4
#  9 12  5
#  8  7  6

# A A B 
# D   B
# D   B
# D C C

'''
def snakeMatrix(x_size,y_size,array):
    x = x_size -1
    y = y_size -1
    p = 0
    q = y
    number = 1
    while(p < q):
        #print  A
        for i in range(x,x_size):
            array[x][i] = number
            number++
        #print B
        for i in range(y,y_size):
            array[x_size -1][i] = number
            number++
        #print C
        for i in range(y_size-1,0):
            array[x_size -1][] = number
            number++
        #print B
        for i in range(y,y_size):
            array[x_size -1][y] = number
            number++
'''


def snakeMatrix(n,array):
    x = 0
    y = n-1
    t = 1

    while(x < y):



