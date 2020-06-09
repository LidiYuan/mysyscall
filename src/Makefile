PWD=$(shell pwd)
CC= gcc
CFLAGS=-g -Wall -I$(INCPATH)

INCPATH=$(PWD)/include
EXPATH=$(PWD)/example
LIBPATH=$(PWD)/mysyscall

FILE=mybin
EXISTBIN=$(shell if [ -f $(FILE) ]; then echo "exist"; else echo "notexist"; fi;)

WRITETEST=testwrite
SETXATTR_TEST=setxattr_test
ALLPRO=$(WRITETEST) $(SETXATTR_TEST)

default: mkbin $(ALLPRO)


#example 1 write test
WRITETESTSRC=$(EXPATH)/writetest.c  $(LIBPATH)/syscall_file.c
$(WRITETEST): $(WRITETESTSRC) $(INCPATH)/syscall_file.h
	$(CC) $(CFLAGS) $(WRITETESTSRC) -o $(WRITETEST) 
	mv $(WRITETEST) ./mybin/

#example 2 setxattr  test
SETXATTR_TEST_SRC=$(EXPATH)/setxattr_test.c $(LIBPATH)/syscall_file.c
$(SETXATTR_TEST):$(SETXATTR_TEST_SRC) $(INCPATH)/syscall_file.h
	$(CC) $(CFLAGS) $(SETXATTR_TEST_SRC) -o $@
	mv $@ ./mybin

mkbin:
ifneq ("$(EXISTBIN)", "exist")
	mkdir mybin
endif


clean:
	rm -rf mybin/
	rm -rf *.o
	rm -rf $(WRITETEST)
