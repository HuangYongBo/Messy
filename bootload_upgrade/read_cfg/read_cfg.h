#ifndef _CREAT_CFG_H_
#define _CREAT_CFG_H_

struct cfg_info{
	char name[16];
	unsigned addr_off;	
	unsigned int size;
};
#define MAX_INFO_NUM 10
#define CUR_INFO_NUM 2
#define CFG_DATA_SIZE 512 
#define TOUCH_CFG_DATA 0
#define KEY_CFG_dATA 1 


char *TYPE[] = {"touch_cfg","key_cfg"};
#endif
