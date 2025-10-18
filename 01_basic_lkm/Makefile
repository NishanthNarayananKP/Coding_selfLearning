#
#Build : static or Dynamic

#Dynamic : intree and out of tree
#
#intree : internal to linux kernel src approved by kernel developers
#
#out of tree : external to linux . eg; current module. taint flag will be set.
#
#kbuild : to build modules
#
# -C to trigger top level make file of Linux kernel tree , which will be directed via M option to our local makefile 
#make -C  <path to linux kernel tree> M=<path to module> target
#
#
# Target : modules , modules_install ,clean , help
#

#Define a kbuild vairable 
#obj-<x> which can be:  m,n,y
#obj-<x> := <module>.o

#unamec -r and check kernel version to take modules path
# Eg : make -C /lib/modules/5.15.0-139-generic/build/ M=$PWD modules
#
#

obj-m := basic_lkm.o
KDIR := /lib/modules/$(shell uname -r)/build/
PWD := $(shell pwd)

all :
	make -C $(KDIR) M=$(PWD) modules

clean :
	make -C $(KDIR) M=$(PWD) clean

help : 
	make -C $(KDIR) M=$(PWD) help
