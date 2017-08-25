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
			*same = *(str1+i);
			*same |= i<<8;	
	//		printf("%c\n",*(str2+i));
	//		printf("%x\n",*(same));
			same++;		
			count++; 
		}
		i++;
	}
	return count;
}

int main(int argc ,char *argv[])
{
	char day_str1[60] = {0};
	char day_str2[60] = {0};
	char hour_str1[60] = {0};
	char hour_str2[60] = {0};
	char *str[4] = {day_str1,day_str2,hour_str1,hour_str2};
	int i;
	for(i=0;i<4;i++)
	{
		scanf("%s",str[i]);	
	}

	short time1[60] = {0};
	short time2[60] = {0};

	find_same_word(str[0],str[1],time1,60);	
	find_same_word(str[2],str[3],time2,60);	
	
	char tmp;
	int k;
	for(i = 0;i<60;i++)
	{
		tmp = time1[i] & 0xFF;
  		if(tmp >= 'A' &&tmp <= 'G')
		break;	
	}
	k =tmp - 'A';
	printf("%s ",Day[k]);
	
	for(i = i+1;i<sizeof(time1)/sizeof(time1[0]);i++)
	{
		tmp = time1[i] & 0xFF;
		if((tmp >= 'A' &&tmp <= 'N')||(tmp >= '0' && tmp<='9'))
		break;
	}
	k = (tmp > '9')?(tmp - 'A' + 10):(tmp - '0');
	printf("%d:",k);

	for(i = 0;i<sizeof(time2)/sizeof(time2[0]);i++)
	{
		tmp = time2[i] & 0xFF;
	//	if((tmp >= 'A' &&tmp <= 'Z')||(tmp >= 'a' && tmp<='z'))
		if(tmp >= 'a' && tmp<='z')
		break;
	}
	k = time2[i] / 0xFF;
	if(k<9) 	printf("0");
	printf("%d\n",k);
	return 0;

}
