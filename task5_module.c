#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/usb.h>

#define AUTHOR "Gabriel Reus Rodríguez"
#define DESCRIPTION "Eudyptula Task05"
#define LICENSE "GPL"
#define VERSION "0.1"

/* https:/github.com/martinezjavier/ldd3/bob/master/usb/usb-skeleton.c */

/*URL:
 * http://opensourceforu.com/2011/10/usb-drivers-in-linux-1/
 * Si pruebas con un  pendrive usb,
 * hay que "descargar de memoria"
 * el modulo de usbstorage:
 * sudo rmmod usb_storage
 */

/* Define the values to match your devices */
#define USB_VENDOR_ID 0x090C
#define USB_PRODUCT_ID 0x1000

static struct usb_device_id usb_table[] = {
	{
		USB_DEVICE(USB_VENDOR_ID, USB_PRODUCT_ID)
	}, { }
};

/* table of devices that work with this driver */

MODULE_DEVICE_TABLE(usb, usb_table);

static void usb_disconnect(struct usb_interface *interface)
{

//	printk(KERN_INFO "USB Disconnected id Eudyptula: 7049f76c2121.\n");
	pr_info("USB Disconnected id Eudyptula: 7049f76c2121.\n");


}

/* Pregunta hasta que descubre el dispositivo USB.*/
static int usb_probe(struct usb_interface *interface,
		     const struct usb_device_id *id)
{
	int retVal = 0;

	pr_info("USB ( %04X:%04X ) plugged with id Eudyptula: 7049f76c2121\n",
		id->idVendor, id->idProduct);
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
	if (retVal)
		//pr_err(KERN_ERR "usb_register failed.Error number %d",retVal);
		pr_info("usb_register failed.Error number %d", retVal);
	else
		pr_info("Hello World my id is: 7049f76c2121.\n");
	return retVal;
}

static void __exit usb_fin(void)
{
	pr_info("USB Deregistered id Eudyptula task 05 is: 7049f76c2121.\n");
	usb_deregister(&my_usb_driver);

}

module_init(usb_inicio);
module_exit(usb_fin);

MODULE_LICENSE(LICENSE);
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);
MODULE_VERSION(VERSION);
