/*************************************************************************
	> File Name:    2.创建线程.c
	> Author:       杨玉春
	> Mail:         www762268@foxmail.com
	> Created Time: 2016年08月04日 星期四 09时43分11秒
*************************************************************************/
/*
    3、将实验1.2改造一下,由主线程通过参数传递给子
    线程需要打印“-”的个数,学会使用参数传递。

*/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *fun(void *para)
{
    int i = *(int *)para;
    printf("para = %d\n", i);
    while(i--)
    {
        printf("-");
        fflush(stdout);
        usleep(1000);
    }
}
int main(int argc, char* argv[])
{
    int i = 1000;
    int n = 100;
    pthread_t thid;
    pthread_create(&thid, NULL, fun, &n);
    while(i--)
    {
        printf("*");
        fflush(stdout);
        usleep(1000);
    }
    return 0;
}
