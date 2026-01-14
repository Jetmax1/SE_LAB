#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

struct Student {
    char id[20];
    char name[30];
    int marks[5];
    int total;
    float percent;
    char grade[3];
    float cgpa;
};

/* ---------- VALIDATION FUNCTIONS ---------- */

int isValidID(char id[]) {
    for (int i = 0; id[i]; i++)
        if (!isalnum(id[i])) return 0;
    return 1;
}

int isUniqueID(struct Student s[], int n, char id[]) {
    for (int i = 0; i < n; i++)
        if (strcmp(s[i].id, id) == 0) return 0;
    return 1;
}

int isValidName(char name[]) {
    for (int i = 0; name[i]; i++)
        if (!isalpha(name[i])) return 0;
    return 1;
}

/* ---------- GRADE & CGPA ---------- */



int main() {
    struct Student s[MAX];
    int n;

    FILE *fp = fopen("students.dat", "wb");

    printf("Enter number of students: ");
    scanf("%d", &n);

    

    return 0;
}
