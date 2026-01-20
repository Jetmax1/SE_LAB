#ifndef STUDENT_H
#define STUDENT_H
#include<stdio.h>
#define MAX 100

struct Student{
    char id[20];
    char name[30];
    int m[5];
    int t;
    float percent;
    char grade[3];
    float cg;
};

int isValidID(char[]);
int isUniqueID(struct Student[],int ,char[]);
int isValidName(char []);
#endif