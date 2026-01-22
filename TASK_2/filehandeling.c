#include<string.h>
#include "student.h"

int readStudent(FILE *fp,struct Student *s,struct Student list[],int cnt){
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

void printAll(FILE *fp,struct Student s[],int n){
    int i,j;
    float sum=0,hi=s[0].percent,lo=s[0].percent;
    int gc[8]={0};

    printf("ID\tName\tMarks\t\t\tSub Grades\t\tT\t%%\tGrade\tCG\n");
    fprintf(fp,"ID\t\tName\tMarks\t\t\tSub Grades\t\tT\t%%\tGrade\tCG\n");


    for(i=0;i<n;i++){
        printf("%s\t%s\t",s[i].id,s[i].name);
        fprintf(fp,"%s\t%s\t",s[i].id,s[i].name);

        for(j=0;j<5;j++){
            printf("%d ",s[i].m[j]);
            fprintf(fp,"%d ",s[i].m[j]);
        }

        

        for(j=0;j<5;j++){
            printf("%s ",s[i].subG[j]);
            fprintf(fp,"%s ",s[i].subG[j]);
        }

        printf("\t%d\t%.2f\t%s\t%.1f\n",s[i].t,s[i].percent,s[i].grade,s[i].cg);

        fprintf(fp,"\t%d\t%.2f\t%s\t%.1f\n",s[i].t,s[i].percent,s[i].grade,s[i].cg);


        sum+=s[i].percent;
        if(s[i].percent>hi) hi=s[i].percent;
        if(s[i].percent<lo) lo=s[i].percent;

        if(strcmp(s[i].grade,"O")==0) gc[0]++;
        else if(strcmp(s[i].grade,"A+")==0) gc[1]++;
        else if(strcmp(s[i].grade,"A")==0) gc[2]++;
        else if(strcmp(s[i].grade,"B+")==0) gc[3]++;
        else if(strcmp(s[i].grade,"B")==0) gc[4]++;
        else if(strcmp(s[i].grade,"C")==0) gc[5]++;
        else if(strcmp(s[i].grade,"D")==0) gc[6]++;
        else gc[7]++;
    }

    printf("\nClass Avg: %.2f%%",sum/n);
    printf("\nHighest %%: %.2f",hi);
    printf("\nLowest %%: %.2f\n",lo);

    fprintf(fp,"\nClass Avg: %.2f%%",sum/n);
    fprintf(fp,"\nHighest %%: %.2f",hi);
    fprintf(fp,"\nLowest %%: %.2f\n",lo);

    printf("\nGrade Count:\n");
    fprintf(fp,"\nGrade Count:\n");

    printf("O:%d A+:%d A:%d B+:%d B:%d C:%d D:%d F:%d\n",
           gc[0],gc[1],gc[2],gc[3],gc[4],gc[5],gc[6],gc[7]);

    fprintf(fp,"O:%d A+:%d A:%d B+:%d B:%d C:%d D:%d F:%d\n",
            gc[0],gc[1],gc[2],gc[3],gc[4],gc[5],gc[6],gc[7]);
}
