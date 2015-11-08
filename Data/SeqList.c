//
//  SeqList.c
//
//
//  Created by Mr_Wrong on 15/11/7.
//
//

#include "SeqList.h"
#define OK 1;
#define ERROR 0;

//按内容查找
int Locate(SeqList L,int e){
    int i = 0;
    while ((i<=L.last)&&(L.elem[i]!=e))
        i++;
    if (i<=L.last)
        return (i+1);
    else
        return (-1);
}
//插入
int InsList(SeqList *L,int i,int e){
    int k;
    if(i<1||i>L->last+2){
        printf("插入位置不合法");
        return ERROR;
    }
    if(L->last>MAXSIZE-1){
        printf("表已经满了，无法插入");
        return ERROR;
    }
    
    for (k= L->last; k>i-1; k--) {
        L->elem[k+1] = L->elem[k];
    }
    
    L->elem[i-1] =e;
    L->last++;
    return OK;
    
}
//删除
int DelList(SeqList *L,int i,int *e){
    int k;
    if(i<1||i>L->last+2){
        printf("删除位置不合法");
        return ERROR;
    }
    *e = L->elem[i-1];
    for(k = i;k<L->last+1;k++){
        L->elem[k-1] = L->elem[k];
    }
    L->last--;
    return OK;
    
}

void mergeList(SeqList *LA,SeqList *LB,SeqList *LC){
    int i,j,k;
    i = k = j = 0;
    while (i<LA->last+1&&j<LB->last+1) {
        if (LA->elem[i]<=LB->elem[j]) {
            LC->elem[k] = LA->elem[i];
            i++;k++;
        }else{
            LC->elem[k]= LB->elem[j];
            k++;j++;
        }
    }
    while (i<LA->last+1) {
        LC->elem[k] = LA->elem[i];
        i++;k++;
    }
    while (j<LB->last+1) {
        LC->elem[k] = LB->elem[j];
        j++;k++;
    }
    
    LC->last = LA->last+LB->last+1;
}

void fillList(SeqList *L,int *a,int size){
    L->last = size;
    for(int i = 0;i<size;i++){
        L->elem[i] = a[i];
    }
}
