//
//  LinkList.c
//  
//
//  Created by Mr_Wrong on 15/11/8.
//
//

#include "LinkList.h"

void InitList(LinkList *L){

    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

void CreateFromHead(LinkList L){

    Node *s;
    char c;
    int flag = 1;
    while (flag) {
        c= getchar();
        if (c!='$') {
            s= (Node *)malloc(sizeof(Node));
            s->data= c;
            s->next = L->next;
            L->next = s;
        }
        else
            flag = 0;
    }
}

void CreateFormTail(LinkList *L){
    char c;
    Node *r,*s;
    int flag = 1;
    r = *L;
    while (flag) {
        c = getchar();
        if (c!='$') {
            s = (Node *)malloc(sizeof(Node));
            s->data = c;
            r->next = s;
            r= s;
        }
        else{
            flag = 0;
            r->next = NULL;
        }
    }
}
Node * Get(LinkList L,int i){
    int j;
    Node *p;
    if (i<=0)return NULL;
    p = L;j = 0;
    while (p->next!=NULL&&j<i) {
        p = p->next;
        j++;
    }
    if (i == j) {
        return p;
    }else
        return NULL;
}
Node * Located(LinkList L,char ele){
    Node *p;
    p = L->next;
    while (p!=NULL) {
        if (p->data!=ele) {
            p = p->next;
        }else
            break;
    }
      return p;
}
int ListLength(LinkList L){
    int i = 0;
    Node *p;
    p = L->next;
    while (p!=NULL) {
        p = p->next;
        i++;
    }
    return i;
}
int InseList(LinkList L,int i,char ele){
    Node *pre,*s;
    pre = L;
    int j;
    if (i<=0) {
        return ERROR;
    }
    while (pre!=NULL&&j<i) {
        j++;
        pre = pre->next;
    }
    if (!pre) {
        printf("插入位置不合法");
        return ERROR;
    }
    
    s = (Node *)malloc(sizeof(Node));
    s->data = ele;
    s->next = pre->next;
    pre->next = s;
    
    return OK;
}

int DellList(LinkList L,int i,char * e){
    Node *pre,*r;
    pre = L;
    int k = 0;
    while (pre->next!=NULL&&k<i-1) {
        k++;
        pre = pre->next;
    }
    
    if (!pre->next) {//是空的
        printf("删除的位置不合法");
        return ERROR;
    }
    
    r = pre->next;
    pre->next = r->next;
    *e = r->data;
    free(r);
    return OK;
}
LinkList MergeLinkList(LinkList LA,LinkList LB){
    Node *pa,*pb,*r;
    LinkList LC;
    pa = LA->next;
    pb = LB->next;
    LC = LA;
    LC->next = NULL;
    r = LC;
    
    while (pa!=NULL&&pb!=NULL) {
        if (pa->data<=pb->data) {
            r->next = pa;
            r = pa;
            pa = pa->next;
        }
        else{
            r->next = pb;
            r = pb;
            pb = pb->next;
        }
        
    }
    if (pa) {
        r->next = pa;
    }else
        r->next = pb;
    
    free(LB);
    return LC;
    
}