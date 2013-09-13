/*
#include <linux/module.h>

#if defined(CONFIG_SMP)
#define __SMP__
#endif


#if defined(CONFIG_MODVERSIONS)
#define MODVERSIONS
#include <linux/modversions.h>
#endif



#include <linux/kernel.h>

static __init int int_module(void)
{
  printfk(KERN_DEBUG "Hello, kernel!\n");
  return 0;
}

static __exit void cleanup_module(void)
{
  printfk(KERN_DEBUG, "Good-bye, kernel!\n");
}
*/

#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void)
{
	printk("<1>Hello World .\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_ALERT "Goodbye world 1.\n");
}
