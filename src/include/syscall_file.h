#ifndef __SYSCALL_FILE_H_
#define __SYSCALL_FILE_H_

int call_write(int fd, const void *buf, size_t count);
int call_setxattr(const char *path, const char *name,const void *value, size_t size, int flags);

#endif
