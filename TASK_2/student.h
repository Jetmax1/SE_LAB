#ifndef STUDENT_H
#define STUDENT_H

#include<stdio.h>

#define MAX 100

struct Student{
    char id[20];
    char name[30];
    int m[5];
    char subG[5][3];   
    int t;
    float percent;
    char grade[3];
    float cg;
};


int isValidID(char[]);
int isValidName(char[]);
int isUniqueID(struct Student[],int,char[]);

void calculate(struct Student*);
void getGrade(float,char[]);
float getCGPA(char[]);

void getSubGrade(int,char[]);
int readStudent(FILE*,struct Student*,struct Student[],int);
void printAll(FILE*,struct Student[],int);

#endif
