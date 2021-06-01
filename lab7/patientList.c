#include "patientList.h"
#include <string.h>

Patient *patientCreate(char *name,
                char *address,
                int dateOfBirth,
                char *diagnosis,
                int admissionDate,
                int dischargeDate,
                int roomNumber) {
    Patient *patient = (Patient *)malloc(sizeof(Patient));

    char *n = (char *)malloc(128 * sizeof(char));
    char *a = (char *)malloc(128 * sizeof(char));
    char *d = (char *)malloc(128 * sizeof(char));

    strcpy(n, name);
    strcpy(a, address);
    strcpy(d, diagnosis);

    patient -> name = n;
    patient -> address = a;
    patient -> dateOfBirth = dateOfBirth;
    patient -> diagnosis = d;
    patient -> admissionDate = admissionDate;
    patient -> dischargeDate = dischargeDate;
    patient -> roomNumber = roomNumber;


    return patient;
}

void patientInformation(Patient *patient) {
    printf("Name: %s\n"
           "Address: %s\n"
           "Date of birth: %d\n"
           "Diagnosis: %s\n"
           "Admission date: %d\n"
           "Discharge date: %d\n"
           "Room number: %d\n\n",
           patient -> name,
           patient -> address,
           patient -> dateOfBirth,
           patient -> diagnosis,
           patient -> admissionDate,
           patient -> dischargeDate,
           patient -> roomNumber
    );
}


void patientAdd(patientList **list, Patient *patient)
{
    if (*list == NULL)
    {
        *list = (patientList *)malloc(sizeof(patientList));
        patientNode *temp = (patientNode *)malloc(sizeof(patientNode));
        temp->patient = patient;
        temp->next = temp->prev = NULL;
        (*list)->head = (*list)->tail = temp;
        return;
    }
    else
    {
        patientNode *temp = (patientNode *)malloc(sizeof(patientNode));
        temp->patient = patient;
        temp->next = NULL;

        temp->prev = (*list)->tail;
        (*list)->tail->next = temp;

        (*list)->tail = temp;
        return;
    }
}

void patientPrint(patientList *root)
{
    patientNode *head;
    head = root->head;
    while (head != NULL)
    {
        patientInformation(head->patient);
        head = head->next;
    }
}