PWD=$(shell pwd)
CC= gcc
CFLAGS=-g -Wall -I$(INCPATH)

INCPATH=$(PWD)/include
EXPATH=$(PWD)/example
LIBPATH=$(PWD)/mysyscall

FILE=mybin
EXISTBIN=$(shell if [ -f $(FILE) ]; then echo "exist"; else echo "notexist"; fi;)

WRITETEST=testwrite
ALLPRO=$(WRITETEST) 

default: mkbin $(ALLPRO)


#example 1 write test
WRITETESTSRC=$(EXPATH)/writetest.c  $(LIBPATH)/syscall_file.c
$(WRITETEST): $(WRITETESTSRC) $(INCPATH)/syscall_file.h
	$(CC) $(CFLAGS) $(WRITETESTSRC) -o $(WRITETEST) 
	mv $(WRITETEST) ./mybin/

mkbin:
ifneq ("$(EXISTBIN)", "exist")
	mkdir mybin
endif


clean:
	rm -rf mybin/
	rm -rf *.o
	rm -rf $(WRITETEST)
