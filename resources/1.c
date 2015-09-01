//
//  main.c
//  列出目录中的所有文件
//
//  Created by admin on 15/7/16.
//  Copyright (c) 2015年 Pandora. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, const char * argv[])
{
    DIR *dp;
    struct dirent *dirp;
    if (argc != 2) {
        fprintf(stderr, "Usage: ls directory_name");
        exit(1);
    }
    if ((dp = opendir(argv[1])) == NULL) {
        fprintf(stderr, "can't open %s", argv[1]);
    }
    while ((dirp = readdir(dp)) != NULL) {
        printf("%s \n", dirp->d_name);
    }
    closedir(dp);
    return 0;
}
