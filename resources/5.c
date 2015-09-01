//
//  main.m
//  UepProject
//
//  Created by admin on 15/9/1.
//  Copyright (c) 2015年 yutiya. All rights reserved.
//

#include "apue.h"
#include <sys/wait.h>

int main(int argc, const char * argv[]) {
    char buf[MAXLINE];
    pid_t pid;
    int status;
    
    printf("%%  ");
    while(fgets(buf, MAXLINE, stdin) != NULL)
    {
        if (buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0;
        }
        if ((pid = fork()) < 0)
        {
            err_sys("fork error");
        }
        else if(pid == 0)
        {
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }
        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
            err_sys("waitpid error");
        }
        printf("%%  ");
    }
    return 0;
}
