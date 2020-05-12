#include <asm/unistd.h>
#include <unistd.h>
#include "syscall_file.h"


#ifdef __x86_64__

/*fwrite:传参寄存器的使用
 *fd:        rdi
 *buff:      rsi
 *count:     rdx
 *_NR_write: rax
 * */
int call_write_x86_64(int fd, const void *buf, size_t count)
{
    long ret;
    long nu = __NR_write;

    if(fd <0 || NULL == buf || count <=0)
        return -1;

    asm volatile(
        "movq %1, %%rax\n"
        "syscall\n"
        "movq %%rax,%0\n"
       :"=m"(ret)
       :"r"(nu)
    );

    return (int)ret;
}
#endif


int call_write(int fd, const void *buf, size_t count)
{

#ifdef __x86_64__        
    return call_write_x86_64(fd,buf,count);
#endif

    return 0;
}




