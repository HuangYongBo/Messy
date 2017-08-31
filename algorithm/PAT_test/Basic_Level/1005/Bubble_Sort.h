#ifndef  Bubble_Sort_H
#define  Bubble_Sort_H

#include <iostream>
void bubble_sort(int *array,int len)
{
	int i,j;
	int tmp;

	for(i = 0 ;i<len-1;i++)
	{
		for(j = 0 ; j < len -i -1;j++)
		{
			if(array[j] <= array[j+1])
			{
				tmp = array[j];
			//	std::cout<<"tmp:"<<tmp<<std::endl;
				array[j] = array[j+1];
				array[j+1] = tmp;
				
			}
		}

	}


}



#endif 
