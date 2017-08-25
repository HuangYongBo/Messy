#include <stdio.h>
char *Day[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
int find_same_word(char *str1,char *str2,short *same,int num)//num is number for same char
{	
	int count = 0;
	int i = 0;
	while(*(str1+i) != '\0' && *(str2+i) != '\0' && count != num)
	{
		if(*(str1+i) == *(str2+i))
		{
			*same = *str1;
			*same |= i<<8;	
			printf("%c\n",*(str2+i));
			same++;		
			count++; 
		}
		i++;
	}
	if(count == num)
		return 0;
	else
		return count;
}

void deal_with(short  *data)
{
	char day = *data && 0xFF;
	char hour = *(data+1) && 0xFF;
	char min = *(data+2)>>8;
		
	printf("%d,%d,%d",day,hour,min);
	hour = (hour >= '0' && hour <= '9')?(hour - '0'):(hour - 'A'+10);
	
	printf("%s ",Day[day - 'A']);
	printf("%d:",hour);
	printf("%d\n",min);

}
int main(int argc ,char *argv[])
{
	char day_str1[61] = {0};
	char day_str2[61] = {0};
	char hour_str1[61] = {0};
	char hour_str2[61] = {0};
	char *str[4] = {day_str1,day_str2,hour_str1,hour_str2};
	int i;
	for(i=0;i<4;i++)
	{
		scanf("%s",str[i]);	
	}

	short time[3] = {0};//0 day ;1 hour ;2 min

	find_same_word(str[0],str[1],time,2);	
	find_same_word(str[2],str[3],time+2,1);	

	deal_with(time);
	

	return 0;

}
