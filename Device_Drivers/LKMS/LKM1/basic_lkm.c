#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("nishanth_narayanan");
MODULE_DESCRIPTION("Basic driver for printing");

static int __init hello_init(void) {
    printk(KERN_INFO "[INFO] Hello inserted new LKM into your kernel\n");
    printk(KERN_DEBUG "[DEBUG] Debug message during insertion\n");
    printk(KERN_WARNING "[WARNING] Just a warning example\n");
    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "[INFO] LKM created by nishanth is removed from your kernel\n");
    printk(KERN_ERR "[ERROR] Example error message during removal\n");
}

module_init(hello_init);
module_exit(hello_exit);

