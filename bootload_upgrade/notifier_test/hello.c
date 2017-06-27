#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>		
#include <linux/notifier.h>

extern int test_register_client(struct notifier_block *nb); 
static int test_notifier_callback(struct notifier_block *self,unsigned long event, void *data)
{
	//int *blank;
		
			printk("callback\r\n");
	switch(event)
	{
		case 0:
			printk("hello\r\n");
			break;
		case 1:
			printk("good bye \r\n");
		default:
			break;
	}
	


}

static struct notifier_block test_notifier ={
					.notifier_call = test_notifier_callback,
					};
static	 int hello_init(void)
{
	printk(KERN_ALERT"HELLO WORLD\r\n");

	
	test_register_client(&test_notifier);

	return 0;
}
static	 int hello_exit(void)
{

	printk(KERN_ALERT"GOODBYE WORLD\r\n");
	
	return 0;
}
module_init(hello_init);
module_exit(hello_exit);
