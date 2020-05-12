X86传参顺序
    在64位机器上参数的传递前6个 从左向右分别保存在rdi,rsi,rdx,rcx,r8和r9中, 但是从第七个开始就要从右向左的入栈


【一】文件介绍
->src 存放源代码
--->example 存放例子
------>writetest.c  对write系统调用测试	
--->include 存放例子中使用的头文件
------>syscall_file.h 文件操作相关的系统调用封装头文件	
--->mysyscall 存放系统调用的封装			
------>syscall_file.c  文件操作相关的系统调用封装

【二】函数介绍
syscall_file.c/
--->int call_write(int fd, const void *buf, size_t count)
用于write系统调用的封装
