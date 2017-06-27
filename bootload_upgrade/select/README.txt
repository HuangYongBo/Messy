/********************          主要功能           ***********************/
实现kernel和recovery分区，并通过触屏选择实现加载相应内容。



/*********************          文件说明         ************************/
select.c 源文件
select.h 头文件

/*********************          使用说明         ************************/
如需使用该包，建议按照以下步骤将其添加到uboot工程中。
1.将这个目录完整的拷贝到~/ac8xx7_src/autochips/platform/uboot/uboot-83xx/common 目录下
2.在~/ac8xx7_src/autochips/platform/uboot/uboot-83xx/Makefile中的合适位置添加如下代码：

LIBS += common/select/libselect.a
TAG_SUBDIRS += common/select

两条命令作用分别为：添加指定静态库 和 添加工程包目录。



/*********************          函数说明         ************************/



