#include <linux/module.h>

#if defined(CONFIG_SMP)
#define __SMP__
#endif

/*
#if defined(CONFIG_MODVERSIONS)
#define MODVERSIONS
#include <linux/modversions.h>
#endif
*/

/* system header */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>


/* project header */
#include "schar.h"

/* define */
#define DEBUG

#ifdef DEBUG
#define MSG(string, args...) printk(KERN_DEBUG "schar:__FILE__-__LINE__:" string, ##args)
#else
#define MSG(string, args...)
#endif

/* Constants */
#define SCHAR_MAJOR 250

char *schar_name;

static int hello_init(void)
{
  int res = 0;
  printk(KERN_ALERT "Hello World.\n");

  if (schar_name == NULL)
    schar_name = "schar";
  
  //res = register_chrdev((unsigned int)SCHAR_MAJOR, (const char*)schar_name, &schar_fops);

  res = register_chrdev(SCHAR_MAJOR,
			schar_name,
			&schar_fops);
  if (res) {
    MSG("can't register device with kernel\n");
  }
  return res;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye world.\n");
}

module_init( hello_init );
module_exit( hello_exit );

MODULE_LICENSE( "GPL" );