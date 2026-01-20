#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include "student.h"


int readStudent(FILE *fp, struct Student *s, struct Student list[], int cnt){
    int i;

    if(fscanf(fp,"%s %s",s->id,s->name)==EOF)
        return 0;

    if(!isValidID(s->id) || !isUniqueID(list,cnt,s->id))
        return -1;

    if(!isValidName(s->name))
        return -1;

    for(i=0;i<5;i++){
        fscanf(fp,"%d",&s->m[i]);
        if(s->m[i]<0 || s->m[i]>100)
            return -1;
    }

    return 1;
}