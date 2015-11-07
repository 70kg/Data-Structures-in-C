//
//  main.c
//  Data
//  Created by Mr_Wrong on 15/11/6.
//  Copyright (c) 2015年 70kg. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"
#include "string.h"


int main(int argc, const char * argv[]) {
    int a[10] = {1,3,9,8,4,2,5,0,7.6};

    SeqList list;//这个怎么直接全部赋值
    
    list.last = 10;
    for(int i = 0;i<sizeof(a);i++){
        list.elem[i] = a[i];
    }
    
    printf("获取位置%d\n",Locate(list, 2));//按内容查找
    
    printf("插入:%s\n",InsList(&list,2,10)==1?"OK":"ERROR");//插入
    
    int delement;
    printf("删除：%s,删除的元素：%d\n",DelList(&list,3,&delement)==1?"ok":"ERROR",delement);//删除
    
    return 0;
}
