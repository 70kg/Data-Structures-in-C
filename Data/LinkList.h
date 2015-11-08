//
//  LinkList.h
//  
//
//  Created by Mr_Wrong on 15/11/8.
//链表
//

#ifndef ____LinkList__
#define ____LinkList__
#define OK 1;
#define ERROR 0;

#include <stdio.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkList;

void InitList(LinkList *);//初始化头结点
void CreateFromHead(LinkList);//头插法建立单链表
void CreateFormTail(LinkList *);//尾插法建立单链表
Node * Get(LinkList,int);//查找第i个节点
Node * Located(LinkList,char);//按内容查找位置
int ListLength(LinkList);//获取链表的长度
int InseList(LinkList,int,char);
#endif /* defined(____LinkList__) */
