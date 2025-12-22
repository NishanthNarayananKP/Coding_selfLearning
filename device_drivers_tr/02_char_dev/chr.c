#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/kdev_t.h>
#include <linux/uaccess.h>

#define DEV_MEM_SIZE 512


char dev_buffer[DEV_MEM_SIZE] ;

/* dev variable for device number */
dev_t device_number;

/*  cdev variable */

struct cdev pcd_cdev ;
/*template could be found in linux src path : include/linu/fs.h -- check file operations*/
loff_t pcd_lseek (struct file *filp, loff_t off, int whence)
{
	return 0 ;
}
ssize_t pcd_read (struct file *filp, char __user *buff, size_t count, loff_t *f_pos)
{
	pr_info("read requested for %zu bytes\n",count);
	/* Adjust the count */
	if( (*f_pos + count ) > DEV_MEM_SIZE) {
		count = DEV_MEM_SIZE - *f_pos;
	}
	/*copy to usr */
	if( copy_to_user(buff , &dev_buffer[*f_pos] , count ) ){
		return EFAULT ;
	}

	/* Update current file position */
	*f_pos += count ;

	pr_info("successfully read %zu\n",count);
	return count ;
}
ssize_t pcd_write (struct file *filp, const char __user *buff, size_t count, loff_t *f_pos)
{
	pr_info("write count requested %zu\n",count);

	/* Adjust the count */
        if( (*f_pos + count ) > DEV_MEM_SIZE) {
                count = DEV_MEM_SIZE - *f_pos;
        }
        /*copy from usr */
        if( copy_from_user( &dev_buffer[*f_pos],buff , count ) ){
                return EFAULT ;
        }
	/* Update current file position */
        *f_pos += count ;

        pr_info("successfully written %zu\n",count);
	return count;
}
int pcd_open (struct inode *inode, struct file *filp)
{
	return 0 ;
}
int pcd_release (struct inode *inode, struct file *filp)
{
	return 0 ;
}

/*c99 approach order is not important */
struct file_operations pcd_fops=
{
	.open=pcd_open, 
	.write=pcd_write,
	.read=pcd_read,
	.llseek=pcd_lseek,
	.release=pcd_release,
	.owner=THIS_MODULE
};

struct class* class_pcd ;
struct device* device_pcd ;

static int __init pcd_driver_init(void)
{
	/*1. allocate regions for single noe */
	alloc_chrdev_region(&device_number , 0 , 1 ,"pcd_devices" );
	pr_info("%s Major and minor : %d:%d" ,__func__ , MAJOR(device_number) , MINOR(device_number) ) ;
	/*2. init cdev and then assign owner memset 0 happens durig init*/
	cdev_init(&pcd_cdev , &pcd_fops) ;
	/*3. register with VFS*/
		
	pcd_cdev.owner = THIS_MODULE ;
	cdev_add(&pcd_cdev , device_number,1);
	/*4.  create class in sys/class */
	class_pcd = class_create(THIS_MODULE,"pcd_class");
	/* device file cretaion - popluates sysfs */
	device_pcd = device_create(class_pcd , NULL ,device_number, NULL ,"pcd");
	pr_info("init success\n");

	return 0 ;
}

static void __exit pcd_driver_exit(void){
	device_destroy(class_pcd , device_number);
	class_destroy(class_pcd);
	cdev_del(&pcd_cdev);
	unregister_chrdev_region(device_number ,1);
	pr_info("%s exiting clean up\n" , __func__);
}


module_init(pcd_driver_init);
module_exit(pcd_driver_exit);

MODULE_DESCRIPTION("sample one node char dev");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nishanth");
