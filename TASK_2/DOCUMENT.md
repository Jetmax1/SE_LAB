# Introduction 
This is a moduder vrsion of the first task. Where i have created a "HEADER FILE" and sevral modules for this to work.

## HEADER FILE (student.h)
Module Name ->student.h
Input->Included by all .c files
Pre-Condition->Header file to be included.
Output->Helps in sharing od the module data

## MODULE 1(validation.c)
Module Name->validation.c
Functions in the Module:
>isValidID()
>isValidName()
>isUniqueID()
Input:
>Student ID
>Student Name
>Existing student list
Outpu->Returns validity status

## MODULE 2(result.c)
Module Name->result.c
Functions in the Module:
>calculate()
>getGrade()
>getCGPA()
Input->Student marks
Output:
>Total marks
>Percentage
>Grade
>CGPA

## MODULE 3(filehandeling.c)
Module Name->filehandeling.c
Functions in the Module:
>readStudent()
>printAll()
Input->input.txt
Output->output.txt

## MODULE 3(main.c)
Module Name->main.c
Input-> input.txt
Pre-Condition->All modules must be compiled successfully
Output->result report

# HOW TO USE IT

Make a local copy either by downloading the file in zip formet
OR use the pull command 
```bash 
git pull https://github.com/Jetmax1/SE_LAB
```

move to the same directery amd run the command in the terminal 
```bash
gcc main.c validation.c result.c filehandeling.c -o student
```
&&
```bash
./student
```

# Test Plan
Each function is tested with valid and invalid inputs to ensure correct behavior.
