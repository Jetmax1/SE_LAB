#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "student.h"

int isValidID(char id[]){
    int i;
    for(i=0;id[i];i++){
        if(!isalnum(id[i]))
            return 0;
    }
    return 1;
}

int isUniqueID(struct Student s[],int n,char id[]){
    int i;
    for(i=0;i<n;i++){
        if(strcmp(s[i].id,id)==0)
            return 0;
    }
    return 1;
}

int isValidName(char name[]){
    int i;
    for(i=0;name[i];i++)
        if(!isalpha(name[i])) return 0;
    return 1;
}