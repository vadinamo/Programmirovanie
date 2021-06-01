#ifndef UNTITLED1_DEPARTMENTLIST_H
#define UNTITLED1_DEPARTMENTLIST_H
#include <stdio.h>
#include <stdlib.h>
#include "doctorList.h"
#include "patientList.h"

typedef struct Department {
    char *name;
    char *location;
    Patient patient[20];
    Doctor doctor[20];

    int capacity;

}Department;

typedef struct departmentNode
{
    Department *department;
    struct departmentNode *next;
    struct departmentNode *prev;
} departmentNode;

typedef struct departmentList
{
    struct departmentNode *head;
    struct departmentNode *tail;
} departmentList;

Department *departmentCreate(char *name,
                             char *location);

void departmentAdd(departmentList **list, Department *department);
void departmentInformation(Department *department);
void departmentPrint(departmentList *list);
void departmentAddInformation(Department *department, Patient *patient, Doctor *doctor);
void departmentCalculate(departmentList *list);
int findMin(int a, int b);
#endif
