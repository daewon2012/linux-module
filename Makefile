KERNELDIR = /lib/modules/$(shell uname -r)/build

obj-m := hello.o \
	schar.o
CFLAG := -Wall
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

default:
	$(MAKE) $(CFLAG) -C $(KDIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.ko
	rm -rf *.mod.*
	rm -rf .*.cmd
	rm -rf *.o
	rm -rf .tmp_versions