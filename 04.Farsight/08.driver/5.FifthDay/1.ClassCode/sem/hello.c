#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/semaphore.h>

static int major = 250;
static int minor = 0;
static dev_t devno;
static  struct cdev cdev;
static struct class *cls;
static struct device *tst_device;

struct semaphore sem;

static int hello_open(struct inode *inode, struct file *file)
{
	printk("hello_open\n");

	if(down_interruptible(&sem))
		return -ERESTARTSYS; 

	//down(&sem);
	return 0;	
}
static int hello_release(struct inode *inode, struct file *file)
{
	printk("hello_release\n");
	up(&sem);
	return 0;
}

struct file_operations hello_ops ={
	.owner		= THIS_MODULE,
	.open		= hello_open,        		//open();
	.release	       = hello_release,    	//close();
};

static int hello_init(void)
{
	int ret,rc;
	
	printk("hello_init()\n");
	ret = register_chrdev(major, "hello", &hello_ops);
	if(ret<0)
	{	
		printk("fail \n");
		return ret;		
	}
	cls = class_create(THIS_MODULE, "mycls");
	devno = MKDEV(major,minor);
	tst_device = device_create(cls, NULL, devno, NULL, "hello");

	sema_init(&sem,1);
	return 0;
}
static void hello_exit(void)
{
	printk("hello_exit()\n");
	device_destroy(cls, devno);
	class_destroy(cls);
	
	unregister_chrdev(major, "hello");
	return;
}
MODULE_LICENSE("GPL");
module_init(hello_init);
module_exit(hello_exit);
