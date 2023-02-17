obj-m += driver.o
#CFLAGS_MODULE := -E
all:
	#对某个文件只做到预处理，也就是把所有的头文件和宏定义都展开了
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) driver.i
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
