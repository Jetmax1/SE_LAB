#include "student.h"

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

    printf("\nOutput written to output.txt\n");
    return 0;
}
