#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "student.h"

void getGrade(float p,char g[]){
    if(p>=90) strcpy(g,"O");
    else if(p>=85) strcpy(g,"A+");
    else if(p>=75) strcpy(g,"A");
    else if(p>=65) strcpy(g,"B+");
    else if(p>=60) strcpy(g,"B");
    else if(p>=55) strcpy(g,"C");
    else if(p>=50) strcpy(g,"D");
    else strcpy(g,"F");
}

float getCGPA(char g[]){
    if(strcmp(g,"O")==0) return 10;
    if(strcmp(g,"A+")==0) return 9;
    if(strcmp(g,"A")==0) return 8;
    if(strcmp(g,"B+")==0) return 7;
    if(strcmp(g,"B")==0) return 6;
    if(strcmp(g,"C")==0) return 5;
    if(strcmp(g,"D")==0) return 4;
    return 0;
}

void calculate(struct Student *s){
    int i,pass=1;
    s->t=0;

    for(i=0;i<5;i++){
        s->t+=s->m[i];
        if(s->m[i]<50) pass=0;
    }

    s->percent = s->t / 5.0;

    if(pass)
        getGrade(s->percent,s->grade);
    else
        strcpy(s->grade,"F");

    s->cg = getCGPA(s->grade);
}