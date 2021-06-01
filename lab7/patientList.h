#ifndef LAB7_LIST_H
#define LAB7_LIST_H
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

typedef struct patientNode
{
    Patient *patient;
    struct patientNode *next;
    struct patientNode *prev;
    int id;
} patientNode;

typedef struct patientList
{
    patientNode *head;
    patientNode *tail;
} patientList;

void patientAdd(patientList **list, Patient *patient);
void patientPrint(patientList *patient);

Patient *patientCreate(char *name,
                       char *address,
                       int dateOfBirth,
                       char *diagnosis,
                       int admissionDate,
                       int dischargeDate,
                       int roomNumber);

void patientInformation(Patient *patient);
void printMedicalCart(Patient *patient);
void medicalCart(patientList *list, int id);

int yearConvert(int date);
int monthConvert(int date);
int dayConvert(int date);
#endif
