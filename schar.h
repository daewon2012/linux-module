#ifndef LM_SCHAR_H
#define LM_SCHAR_H


/*
struct file_operations {
ssize_t (*read) (struct file *, char*, size_t, loff_t *);
ssize_t (*write) (struct file *, const char *, size_t, loff_t *);
unsigned int (*poll) (struct file *, struct poll_table_struct *);
int (*ioctl) (struct inode *, struct file *, unsigned int, unsigned long);
int (*open) (struct inode *, struct file *);
int (*release) (struct inode *, struct file *);
}
*/
/* extern declaration */
extern struct file_operations schar_fops;
#endif