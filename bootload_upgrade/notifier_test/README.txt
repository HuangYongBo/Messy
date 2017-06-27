/*
功能说明:Linux notifier 机制测试
	（Linux内核中各个子系统相互依赖，当其中某个子系统状态发生改变时，就必须使用一定的机制告知使用其服务的其	  他子系统，以便其他子系统采取相应的措施。为满足这样的需求，内核实现了事件通知链机制（notificationchain）。）

测试方式如下:现有两个驱动（gt9xx.ko,hello.ko)，一个充当通知方(gt9xx.ko)，一个充当被通知方(hello.ko)。当触摸屏有检测到有触摸事件时，hello.ko会向串口打印hello的信息。
            gt9xx.ko是触摸屏驱动,当中创建包含创建与注册通知链的函数，并在gtp_touch_down中调用notifier_call_chain来触发处理函数。
	    hello.ko是一个简单的驱动，当中包含回调函数的声明与定义。

*/


/*

如何编译：
	1.将此目录至于/home/kernelpath/目录下，kernelpath为源码的kernel的路径
	2.执行命令：
		/home/kernelpath/ M=$(pwd) module                 
		module为要编译的驱动名字，如要编译hello.ko 则将module替换成hello.ko


*/


/*

注意事项；
	需要先装驱动gt9xx.ko再装载hello.ko，不然会提示错误信息。



*/
