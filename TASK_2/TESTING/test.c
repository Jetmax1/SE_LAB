#include<stdio.h>
#include<string.h>
#include "student.h"

int main(){
    int ch,i,n;
    char id[20],name[30],grade[3];
    float percent;
    struct Student s[10],st;

    do{
        printf("\n========= TEST MENU =========\n");
        printf("1. Test isValidID\n");
        printf("2. Test isValidName\n");
        printf("3. Test isUniqueID\n");
        printf("4. Test getGrade\n");
        printf("5. Test getCGPA\n");
        printf("6. Test calculate (Full Student Result)\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);

        switch(ch){

            case 1:
                printf("Enter ID: ");
                scanf("%s",id);
                if(isValidID(id))
                    printf("Valid ID\n");
                else
                    printf("Invalid ID\n");
                break;

            case 2:
                printf("Enter Name: ");
                scanf("%s",name);
                if(isValidName(name))
                    printf("Valid Name\n");
                else
                    printf("Invalid Name\n");
                break;

            case 3:
                printf("Enter number of existing students: ");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    printf("Enter ID %d: ",i+1);
                    scanf("%s",s[i].id);
                }
                printf("Enter ID to check: ");
                scanf("%s",id);

                if(isUniqueID(s,n,id))
                    printf("ID is Unique\n");
                else
                    printf("Duplicate ID\n");
                break;

            case 4:
                printf("Enter percentage: ");
                scanf("%f",&percent);
                getGrade(percent,grade);
                printf("Grade: %s\n",grade);
                break;

            case 5:
                printf("Enter grade (O/A+/A/B+/B/C/D/F): ");
                scanf("%s",grade);
                printf("CGPA: %.1f\n",getCGPA(grade));
                break;

            case 6:
                printf("Enter marks of 5 subjects:\n");
                for(i=0;i<5;i++){
                    printf("Subject %d: ",i+1);
                    scanf("%d",&st.m[i]);
                }

                calculate(&st);

                printf("\nTotal: %d",st.t);
                printf("\nPercentage: %.2f",st.percent);
                printf("\nOverall Grade: %s",st.grade);
                printf("\nCGPA: %.1f\n",st.cg);
                break;

            case 0:
                printf("Exiting test program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(ch!=0);

    return 0;
}
