PWD=$(shell pwd)
CC= gcc
CFLAGS=-g -Wall -I$(INCPATH)

INCPATH=$(PWD)/include
EXPATH=$(PWD)/example
LIBPATH=$(PWD)/mysyscall


#example 1 write test
WRITETESTSRC=$(EXPATH)/writetest.c  $(LIBPATH)/syscall_file.c
WRITETEST=testwrite
$(WRITETEST): $(WRITETESTSRC) $(INCPATH)/syscall_file.h
	$(CC) $(CFLAGS) $(WRITETESTSRC) -o $(WRITETEST) 




clean:
	rm -rf *.o
	rm -rf $(WRITETEST)
