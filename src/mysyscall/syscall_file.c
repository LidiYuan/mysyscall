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
static int call_write_x86_64(int fd, const void *buf, size_t count)
{
    long ret;
    long nu = __NR_write;

    if(fd <0 || NULL == buf || count <=0)
        return -1;
    asm volatile(
        "movq %1, %%rax\n"
        "movq %4,%%rdi\n"
        "movq %2,%%rsi\n"
        "movq %3,%%rdx\n"
        "syscall\n"
        "movq %%rax,%0\n"
       :"=m"(ret)
       :"m"(nu),"m"(buf),"m"(count),"m"(fd)
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

/*
 *__NR_setxattr: rax
 *path         :rdi
 *name         :rsi
 *value        :rdx
 *size         :r10
 *flags        :r8
 * */
static int call_setxattr_x86_64(const char *path, const char *name,const void *value, size_t size, int flags)
{
    long ret=0;
    long nu = __NR_setxattr;

    asm volatile (
                    "mov %1,%%rax\n"
                    "mov %2,%%rdi\n"
                    "mov %3,%%rsi\n"
                    "mov %4,%%rdx\n"
                    "mov %6,%%r8\n"
                    "mov %5,%%r10\n"
                    "syscall\n"
                    "mov %%rax,%0\n"
                    :"=m"(ret)
                    :"m"(nu),"m"(path),"m"(name),"m"(value),"m"(size),"m"(flags)
                    );
    return ret;

}

int call_setxattr(const char *path, const char *name,const void *value, size_t size, int flags)
{
	if(NULL == path || NULL ==name || '\0' == path[0] || '\0' == name[0])
            return -1;
#ifdef __x86_64__        
    return call_setxattr_x86_64(path,name,value,size,flags);
#endif

    return 0;	
	
}



