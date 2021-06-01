#ifndef UNTITLED1_FUNCTIONTEST_H
#define UNTITLED1_FUNCTIONTEST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Patient {
    char *name;
    char *address;
    int dateOfBirth;
    char *diagnosis;
    int admissionDate;
    int dischargeDate;
    int roomNumber;
}Patient;

typedef struct Doctor {
    char *name;
    char *post;
    char *speciality;
}Doctor;

typedef struct Department {
    char *name;
    char *location;
    Patient patient[20];
    Doctor doctor[20];

    int capacity;

}Department;


typedef struct patientNode
{
    Patient *patient;
    struct patientNode *next;
    struct patientNode *prev;
} patientNode;

typedef struct patientList
{
    patientNode *head;
    patientNode *tail;
} patientList;


typedef struct doctorNode
{
    Doctor *doctor;
    struct doctorNode *next;
    struct doctorNode *prev;
} doctorNode;

typedef struct doctorList
{
    struct doctorNode *head;
    struct doctorNode *tail;
} doctorList;


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


void patientAdd(patientList **list, Patient *patient);
Patient *patientCreate(char *name,
                       char *address,
                       int dateOfBirth,
                       char *diagnosis,
                       int admissionDate,
                       int dischargeDate,
                       int roomNumber);
void patientInformation(Patient *patient);


void doctorAdd(doctorList **list, Doctor *doctor);
Doctor *doctorCreate(char *name,
                     char *post,
                     char *speciality);
void doctorInformation(Doctor *doctor);


Department *departmentCreate(char *name,
                             char *location);
void departmentAdd(departmentList **list, Department *department);
void departmentInformation(Department *department);
void departmentPrint(departmentList *list);
void departmentAddInformation(Department *department, Patient *patient, Doctor *doctor);
void departmentCalculate(departmentList *list);
int findMin(int a, int b);
#endif
