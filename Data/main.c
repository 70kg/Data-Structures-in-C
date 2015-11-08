//
//  main.c
//  Data
//  Created by Mr_Wrong on 15/11/6.
//  Copyright (c) 2015年 70kg. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SeqList.h"
#include "LinkList.h"


int main(int argc, const char * argv[]) {
    int a[10] = {1,3,9,8,4,2,5,0,7.6};
    int b[4] = {2,2,3};
    int c[4] = {1,3,3,4};
    SeqList list;//这个怎么直接全部赋值

    fillList(&list, a, 10);
    
    printf("获取位置:%d\n",Locate(list, 2));//按内容查找
    
    printf("插入:%s\n",InsList(&list,2,10)==1?"OK":"ERROR");//插入
    
    int delement;
    printf("删除：%s,删除的元素：%d\n",DelList(&list,3,&delement)==1?"ok":"ERROR",delement);//删除
    
    
    SeqList list1,list2,list3;
    
    fillList(&list1,b,3);
    fillList(&list2,c,4);
    
    mergeList(&list1,&list2,&list3);//合并两个非递减有序线性表
    printf("合并后的list：%d\n",list3.elem[7]);
    
    printf("---------%s---------\n","链表");
    
    //----------链表-------
    
    LinkList L;
    InitList(&L);
    
    //CreateFromHead(L);
    CreateFormTail(&L);
    
    Node *p = Get(L, 2);
    printf("链表的第2个节点：%c\n",p->data);
    
    
    Node *pp = Located(L,'2');
    printf("key是2的节点：%c\n",pp->data);
    
    printf("链表的长度是：%d\n",ListLength(L));
    
    InseList(L,1,'5');
    printf("插入后的链表长度：%c\n",Get(L, 1)->data);
    return 0;
}
