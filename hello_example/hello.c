#include <linux/module.h>  
#include <linux/kernel.h>  
#include <linux/init.h>
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Hello world!");

static int __init hello_init(void)
{
    printk(KERN_INFO "Hello world\n");
	/*
	if (in_task()) {
    	printk(KERN_INFO "In task\n");
	}
	*/
    return 0;
}

static void __exit hello_exit(void)
{
    printk(KERN_INFO "bye bye world\n");
}

module_init(hello_init);
module_exit(hello_exit);