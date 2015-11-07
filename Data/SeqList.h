//
//  SeqList.h
//  
//
//  Created by Mr_Wrong on 15/11/7.
//
//

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

#endif /* defined(____SeqList__) */

