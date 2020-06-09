#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <asm/unistd.h>
#include <errno.h>
#include "syscall_file.h"

#include <sys/xattr.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
    int ret = 0;
    char buff[256]={0};
    char *name="attr_test";
    char *key="user.test";
    char *value="test22";
    struct stat st;

    int size = strlen(value);

    system("touch attr_test");
    
    if(0 != stat("attr_test",&st))
    {
        printf("file attr_text not exist\n");
        return -1;
    }

    //测试自己的setxattr
    ret = call_setxattr(name,key,value,size,0);
    if(0 != ret )
    {
        printf("set error\n");
    }

    ret = getxattr(name,key,buff,256);
    if( ret > 0)
    {
        printf("get value=%s\n",buff);
    }
    else
    {
        printf("get value error\n");
    }


    return 0;
}
                

