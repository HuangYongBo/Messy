#!/usr/bin/python3

num_pingyin = ["ling","yi","er","san","si","wu","liu","qi","ba","jiu"]

def add_string_data(data_str):
	str_sum = 0
	strlen = len(data_str)
	while strlen:
		strlen=strlen-1
		str_sum = int(data_str[strlen])+str_sum
	return str_sum

def show_data_to_pingyin(data,time):
	if(int(data/10)):
		show_data_to_pingyin(data/10,time+1)

	print(num_pingyin[int(data%10)],end='')
	if(int(time) != 1):
		print(" ",end="")
	else:
		print()

str=input()
calc_end = add_string_data(str)
show_data_to_pingyin(calc_end,1)

