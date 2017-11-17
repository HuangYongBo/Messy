#!/usr/bin/python3

def answer_is_right(str):
	tmp = len(str)
	p_count = 0
	t_count = 0
	p_flag = 0
	a_flag = 0
	t_flag = 0
	for i in range(tmp):
		if str[i] == 'P':
			p_flag = 1
			p_count += 1
			p_index = i
			if p_count  != 1:
				print("NO")
				return 
		elif str[i] == 'T':
			t_flag = 1
			t_count += 1
			t_index = i
			if t_count  != 1:
				print("NO")
				return 
		elif str[i] == 'A':
			a_flag = 1
		else:
			print("NO")
			return

	if (a_flag & t_flag & p_flag) != 1:
		print("NO")
		return
	if(tmp - t_index -1 - p_index) != (t_index -p_index -2 )*p_index :
		print("NO")
		return
	
	print("YES")	



def solve_1003():
	str_list = []
	n = input()
	for i in range(int(n)):
		tmp_str = input()
		str_list.append(tmp_str)
	for i in range(len(str_list)):
		answer_is_right(str_list[i])

#if __name__ == '__main__':
solve_1003()
