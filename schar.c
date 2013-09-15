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

/* local function */
ssize_t schar_read(struct file *file, char *buf, size_t count, loff_t *offset);
ssize_t schar_write(struct file *file, const char *buf, size_t count, loff_t *offset);
unsigned int schar_poll(struct file *file, struct poll_table_struct *wait);
int schar_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg);
int schar_mmap(struct file *file, struct vm_area_struct *vma);
int schar_open(struct inode *inode, struct file *file);
int schar_release(struct inode *inode, struct file *file);

struct file_operations schar_fops = {
  read: schar_read,
  write: schar_write,
  open: schar_open,
  release: schar_release,
};

static int schar_init(void)
{
  int res = 0;
  printk(KERN_ALERT "Hello World.\n");
  
  if (schar_name == NULL)
    schar_name = "schar";
  
  res = register_chrdev(SCHAR_MAJOR, "lm", &schar_fops);
  if (res) {
    MSG("can't register device with kernel\n");
  }
  return res;
  
  return 0;
}

static void schar_exit(void)
{
  printk(KERN_ALERT "Goodbye world.\n");
}

ssize_t schar_read(struct file *file, char *buf, size_t count, loff_t *offset)
{
  printk(KERN_ALERT "schar_read().\n");
  return 0;
}

ssize_t schar_write(struct file *file, const char *buf, size_t count, loff_t *offset)
{
  return 0;
}

unsigned int schar_poll(struct file *file, struct poll_table_struct *wait)
{
  return 0;
}

int schar_ioctl(struct inode *inode, struct file *file, unsigned int cmd, unsigned long arg)
{
  return 0;
}

int schar_mmap(struct file *file, struct vm_area_struct *vma)
{
    return 0;
}

int schar_open(struct inode *inode, struct file *file)
{
    return 0;
}

int schar_release(struct inode *inode, struct file *file)
{
    return 0;
}

module_init( schar_init );
module_exit( schar_exit );

MODULE_LICENSE( "GPL" );