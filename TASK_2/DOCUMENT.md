# Introduction 
This is a moduder vrsion of the first task. Where i have created a "HEADER FILE" and sevral modules for this to work.

## HEADER FILE (student.h)
1. Module Name ->student.h
2. Input->Included by all .c files
3. Pre-Condition->Header file to be included.
4. Output->Helps in sharing od the module data

## MODULE 1(validation.c)
1. Module Name->validation.c
2. Functions in the Module:
    -isValidID()
    -isValidName()
    -sUniqueID()
3. Input:
    -tudent ID
    -tudent Name
    -xisting student list
4. Outpu->Returns validity status

## MODULE 2(result.c)
1. Module Name->result.c
2. Functions in the Module:
    -alculate()
    -etGrade()
    -etCGPA()
3. Input->Student marks
4. Output:
    -otal marks
    -ercentage
    -rade
    -GPA

## MODULE 3(filehandeling.c)
1. Module Name->filehandeling.c
2. Functions in the Module:
    -eadStudent()
    -rintAll()
3. Input->input.txt
4. Output->output.txt

## MODULE 3(main.c)
1. Module Name->main.c
2. Input-> input.txt
3. Pre-Condition->All modules must be compiled successfully
4. Output->result report

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

I have created a c cile Just to testg if the fuctions are working or not. 