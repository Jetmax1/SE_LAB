#include<stdio.h>
#include<string.h>
#include<ctype.h>

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

void inputStudent(struct Student *s,struct Student list[],int cnt){
    int i;

    do{
        printf("Enter ID: ");
        scanf("%s",s->id);
    }while(!isValidID(s->id) || !isUniqueID(list,cnt,s->id));

    do{
        printf("Enter Name: ");
        scanf("%s",s->name);
    }while(!isValidName(s->name));

    for(i=0;i<5;i++){
        do{
            printf("Marks %d: ",i+1);
            scanf("%d",&s->m[i]);
        }while(s->m[i]<0 || s->m[i]>100);
    }
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

void displayReport(struct Student s[],int n){
    int i,j;
    printf("\nID\tName\tMarks\t\t\tT\t%%\tGrade\tCG\n");
    for(i=0;i<n;i++){
        printf("%s\t%s\t",s[i].id,s[i].name);
        for(j=0;j<5;j++)
            printf("%d ",s[i].m[j]);

        printf("\t%d\t%.2f\t%s\t%.1f\n",
               s[i].t,s[i].percent,s[i].grade,s[i].cg);
    }
}

void stats(struct Student s[],int n){
    int i;
    float sum=0,hi=s[0].percent,lo=s[0].percent;
    int gc[8]={0};

    for(i=0;i<n;i++){
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
    printf("\nLowest %%: %.2f",lo);

    printf("\n\nGrade Count:\n");
    printf("O:%d A+:%d A:%d B+:%d B:%d C:%d D:%d F:%d\n",
           gc[0],gc[1],gc[2],gc[3],gc[4],gc[5],gc[6],gc[7]);
}
void printAll(FILE *fp,struct Student s[],int n){
    int i,j;
    float sum=0,hi=s[0].percent,lo=s[0].percent;
    int gc[8]={0};

    printf("\nID\tName\tMarks\t\tT\t%%\tGrade\tCG\n");
    fprintf(fp,"ID\tName\tMarks\t\tT\t%%\tGrade\tCG\n");

    for(i=0;i<n;i++){
        printf("%s\t%s\t",s[i].id,s[i].name);
        fprintf(fp,"%s\t%s\t",s[i].id,s[i].name);

        for(j=0;j<5;j++){
            printf("%d ",s[i].m[j]);
            fprintf(fp,"%d ",s[i].m[j]);
        }

        printf("\t%d\t%.2f\t%s\t%.1f\n",
               s[i].t,s[i].percent,s[i].grade,s[i].cg);

        fprintf(fp,"\t%d\t%.2f\t%s\t%.1f\n",
                s[i].t,s[i].percent,s[i].grade,s[i].cg);

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

int main(){
    struct Student s[MAX];
    int n,i,ok;
    FILE *fin,*fout;

    fin=fopen("input.txt","r");
    if(fin==NULL){
        printf("Input file not found\n");
        return 0;
    }

    fscanf(fin,"%d",&n);

    for(i=0;i<n;i++){
        ok = readStudent(fin,&s[i],s,i);
        if(ok!=1){
            printf("Invalid record near student %d\n",i+1);
            i--;
            continue;
        }
        calculate(&s[i]);
    }
    fclose(fin);

    fout=fopen("output.txt","w");
    printAll(fout,s,n);
    fclose(fout);

    printf("\nOutput also saved in output.txt\n");
    return 0;
}

