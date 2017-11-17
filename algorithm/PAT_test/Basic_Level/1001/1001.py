#!/usr/bin/python3


def cut(data):
	count = 0
	while data != 1:
		count = count+1
		if(data%2):
			data = data*3+1
			data /= 2
		else:
			data /= 2

	return count

data = input()
time = cut(int(data))
print(time)
