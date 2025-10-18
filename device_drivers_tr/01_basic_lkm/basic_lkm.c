/*
 * basic_lkm.c - Simple Hello World Kernel Module
 *
 * Prints a message when loaded and unloaded from the kernel.
 *
 * Author: Nishanth
 * Date: 18-Oct-2025
 * License: GPL
 */



#include <linux/module.h> // Kernel space header

/*
 *Entry point function is static because its module specific , return an int value.
 * 
 */
static int __init hellow_world_init(void){
	// pr_info is a wrapper around printk . need to \n else will store in buffer and cause delay in demsg
	// Additional spaces will also cause messages to stay in buffer
	pr_info("Loading kernel module \n");
	printk("Hello world ............\n");
	return 0 ;
}

/*
 *Exit point . only needed for dynamic modules .not needed for static module
 */
static void __exit hello_world_exit(void){
	pr_info("Removing module : hello world \n");
}

/*
 * __init and __exit are fnction section attributes. defined as :
 * #define __init              __attribute__((section(".init.text")))
 * #define __exit              __attribute__((section(".exit.text")))
 */


// Assign init and exit functions `
module_init(hellow_world_init);
module_exit(hello_world_exit) ;

// MOUDLE IFORMATION
MODULE_DESCRIPTION("Simple LKM module for printing hello world");
MODULE_LICENSE("GPL"); // mandatory
MODULE_AUTHOR("NISHANTH NARAYANAN K P");
MODULE_INFO(DATE,"18/10/2025"); // Custom module info
MODULE_INFO(MACHINE,"x86");



/*
 * Build : static or Dynamic
 *
 * Dynamic : intree and out of tree
 * intree : internal to linux kernel src approved by kernel developers
 * out of tree : external to linux . eg; current module. taint flag will be set.
 *
 * kbuild : to build modules
 *
 */
