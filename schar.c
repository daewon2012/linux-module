/* global header */
#include <linux/fs.h>
/* local header */
#include "schar.h"



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

ssize_t schar_read(struct file *file, char *buf, size_t count, loff_t *offset)
{
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
