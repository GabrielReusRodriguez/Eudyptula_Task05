#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>

#define AUTHOR "Gabriel Reus Rodríguez"
#define DESCRIPTION "Eudyptula Task05"
#define LICENSE "GPL"
#define VERSION "0.1"

/* https:/github.com/martinezjavier/ldd3/bob/master/usb/usb-skeleton.c */



/* Define the values to match your devices */
#define USB_VENDOR_ID 	0xfff0
#define USB_PRODUCT_ID 	0xfff0

static struct usb_device_id usb_table [] = {
	{
		USB_DEVICE(USB_VENDOR_ID,USB_PRODUCT_ID)
	},{ }
};

/* table of devices that work with this driver */

MODULE_DEVICE_TABLE(usb,usb_table);

/* USB Operations */

static ssize_t usb_write(struct file *file, const char __user *user_buffer, size_t count, loff_t *ppos)
{
	int retVal = 0;
	return retVal;
}

static ssize_t usb_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
	int retVal = 0;
	return retVal;
}


static int usb_open(struct inode *inode, struct file *file)
{
	int retVal = 0;
	return retVal;
}

static int usb_release(struct inode *inode, struct file *file)
{
	return 0;
}

static struct file_operations usb_fops = {
	.owner 		= THIS_MODULE,
	.read		= usb_read,
	.write		= usb_write,
	.open		= usb_open,
	.release	= usb_release
};

static void usb_disconnect(struct usb_interface *interface)
{


}

/* Pregunta hasta que descubre el dispositivo USB.*/
static int usb_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	int retVal = 0;

	return retVal;

}
/* USB Driver definition */

static struct usb_driver my_usb_driver = {
	.name		= "skeleton",
	.id_table	= usb_table,
	.probe		= usb_probe,
	.disconnect	= usb_disconnect

};




/* Module inits*/
static int __init usb_inicio(void)
{
	int retVal = 0;
	retVal = usb_register(&my_usb_driver);
	if(retVal)
		//pr_err(KERN_ERR "usb_register failed.Error number %d",retVal);
		printk(KERN_ERR "usb_register failed.Error number %d",retVal);
	else
		printk(KERN_INFO "Hello World my id is: 7049f76c2121.\n");
	return retVal;
}

static void __exit usb_fin(void)
{
	usb_deregister(&my_usb_driver);
	printk(KERN_INFO "USB Deregistered id is: 7049f76c2121.\n");
	
}

module_init(usb_inicio);
module_exit(usb_fin);

MODULE_LICENSE(LICENSE);
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_VERSION(VERSION);
