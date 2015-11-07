//
//  First.c
//  
//
//  Created by Mr_Wrong on 15/11/7.
//
//

#include "First.h"

typedef struct{
    int max,min;
} Data;

int Min;//全局变量

int fun1(int a[],int n){//使用全局变量返回
    int i,max;
    max = Min = a[0];
    for (i = 1; i<n; i++) {
        if (a[i]>max) {
            max = a[i];
        }
        if (a[i]<Min) {
            Min = a[i];
        }
    }
    
    return max;
    
}

int * fun2(int a[],int n){//使用数组多返回值
    static int b[2];
    b[0] = b[1] = a[0];
    int i;
    for (i = 1; i<n; i++) {
        if (a[i]>b[0]) {
            b[0] = a[i];
        }
        if (a[i]<b[1]) {
            b[1] = a[i];
        }
    }
    return b;
    
}

Data * fun3(int a[],int n){//返回结构体 指针
    Data * p;
    int i;
    p = (Data *)malloc(sizeof(Data));
    p->max = p->min = a[0];
    for (i = 1; i<n; i++) {
        if (a[i]>p->max) {
            p->max = a[i];
        }
        if (a[i]<p->min) {
            p->min = a[i];
        }
    }
    return p;
}

Data fun4(int a[],int n){//返回结构体
    Data p;
    int i;
    p.min= p.max = a[0];
    for (i = 1; i<n; i++) {
        if (a[i]>p.max) {
            p.max = a[i];
        }
        if (a[i]<p.min) {
            p.min = a[i];
        }
    }
    return p;
}

void fun5(int a[],int n, int *p,int *q){//使用指针带回返回值
    int i;
    *p = *q = a[0];
    for (i = 1; i<n; i++) {
        if (*p<a[i]) {
            *p = a[i];
        }
        if (*q>a[i]) {
            *q = a[i];
        }
    }
}