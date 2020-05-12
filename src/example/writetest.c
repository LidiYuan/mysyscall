#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "syscall_file.h"


int main()
{
    printf("ret=%d\n",call_write(1,"hello\n",sizeof("hello\n")));
    return 0;
}
