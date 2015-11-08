//
//  SeqList.h
//  
//
//  Created by Mr_Wrong on 15/11/7.
//
//线性表

#ifndef ____SeqList__
#define ____SeqList__

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct{
    int elem[MAXSIZE];
    int last;
}SeqList;


extern int Locate(SeqList,int);
extern int InsList(SeqList *,int,int);
extern int DelList(SeqList *,int,int *);
extern void mergeList(SeqList *,SeqList *,SeqList *);

extern void fillList(SeqList *,int *,int size);
#endif /* defined(____SeqList__) */

