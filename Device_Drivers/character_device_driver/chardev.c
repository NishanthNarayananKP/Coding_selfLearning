/*
 * File: chardev.c
 * Author: Nishanth
 * Description: A simple character device driver with static and dynamic allocation.
 * Date: 2025-03-29
 * Time: 10:32 PM
 */

#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "mychardev"
#define BUFFER_SIZE 1024

static char device_buffer[BUFFER_SIZE]; // Buffer for storing data
static int major; // Major number for the device
static struct cdev my_cdev; // Character device structure
static struct class *my_class; // Class structure for device creation
static dev_t dev_num; // Device number (major + minor)

/* Uncomment this for static allocation of major number */
// #define STATIC_MAJOR 240
// static dev_t dev_num = MKDEV(STATIC_MAJOR, 0); // Manually set major number

/* Function to handle device open */
static int dev_open(struct inode *inodep, struct file *filep)
{
    printk(KERN_INFO "mychardev: Device opened\n");
    return 0;
}

/* Function to handle device close */
static int dev_release(struct inode *inodep, struct file *filep)
{
    printk(KERN_INFO "mychardev: Device closed\n");
    return 0;
}

/* Function to read data from the device */
static ssize_t dev_read(struct file *filep, char __user *user_buffer, size_t len, loff_t *offset)
{
    int bytes_read = len > BUFFER_SIZE - *offset ? BUFFER_SIZE - *offset : len;

    if (bytes_read == 0)
        return 0; // No more data to read

    if (copy_to_user(user_buffer, device_buffer + *offset, bytes_read))
        return -EFAULT; // Error copying to user space

    *offset += bytes_read;
    printk(KERN_INFO "mychardev: Read %d bytes\n", bytes_read);
    return bytes_read;
}

/* Function to write data to the device */
static ssize_t dev_write(struct file *filep, const char __user *user_buffer, size_t len, loff_t *offset)
{
    int bytes_to_write = len > BUFFER_SIZE - *offset ? BUFFER_SIZE - *offset : len;

    if (bytes_to_write == 0)
        return -ENOMEM; // No space left in buffer

    if (copy_from_user(device_buffer + *offset, user_buffer, bytes_to_write))
        return -EFAULT; // Error copying from user space

    *offset += bytes_to_write;
    printk(KERN_INFO "mychardev: Written %d bytes\n", bytes_to_write);
    return bytes_to_write;
}

/* File operations structure */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = dev_open,
    .release = dev_release,
    .read = dev_read,
    .write = dev_write,
};

/* Module Initialization Function */
static int __init mychardev_init(void)
{
    int result;

    /* Dynamic allocation of major number */
    result = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
    if (result < 0)
    {
        printk(KERN_ALERT "mychardev: Failed to allocate major number\n");
        return result;
    }
    major = MAJOR(dev_num);
    printk(KERN_INFO "mychardev: Registered with major number %d\n", major);

    /* Static allocation of major number (Uncomment if needed) */
    // result = register_chrdev_region(dev_num, 1, DEVICE_NAME);
    // if (result < 0)
    // {
    //     printk(KERN_ALERT "mychardev: Failed to register static major number\n");
    //     return result;
    // }

    /* Initialize and add character device */
    cdev_init(&my_cdev, &fops);
    result = cdev_add(&my_cdev, dev_num, 1);
    if (result < 0)
    {
        unregister_chrdev_region(dev_num, 1);
        printk(KERN_ALERT "mychardev: Failed to add cdev\n");
        return result;
    }

    /* Create class for device */
    my_class = class_create(THIS_MODULE, DEVICE_NAME);
    if (IS_ERR(my_class))
    {
        cdev_del(&my_cdev);
        unregister_chrdev_region(dev_num, 1);
        printk(KERN_ALERT "mychardev: Failed to create class\n");
        return PTR_ERR(my_class);
    }

    /* Create device file */
    if (device_create(my_class, NULL, dev_num, NULL, DEVICE_NAME) == NULL)
    {
        class_destroy(my_class);
        cdev_del(&my_cdev);
        unregister_chrdev_region(dev_num, 1);
        printk(KERN_ALERT "mychardev: Failed to create device\n");
        return -1;
    }

    printk(KERN_INFO "mychardev: Device created successfully\n");
    return 0;
}

/* Module Exit Function */
static void __exit mychardev_exit(void)
{
    device_destroy(my_class, dev_num); // Remove device file
    class_destroy(my_class); // Destroy device class
    cdev_del(&my_cdev); // Remove cdev from system
    unregister_chrdev_region(dev_num, 1); // Free the device number
    printk(KERN_INFO "mychardev: Device unregistered\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nishanth");
MODULE_DESCRIPTION("Character Device Driver with Static & Dynamic Allocation");

module_init(mychardev_init);
module_exit(mychardev_exit);

