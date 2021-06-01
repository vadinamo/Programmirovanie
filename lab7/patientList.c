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

int yearConvert(int date) {
    return date / 365;
}

int monthConvert(int date) {
    return (date - yearConvert(date) * 365) / 31;
}

int dayConvert(int date) {
    return date - yearConvert(date) * 365 - monthConvert(date) * 31;
}

void patientInformation(Patient *patient) {

    printf("Name: %s\n"
           "Address: %s\n"
           "Date of birth: %d.%d.%d\n"
           "Diagnosis: %s\n"
           "Admission date: %d.%d.%d\n"
           "Discharge date: %d.%d.%d\n"
           "Room number: %d\n\n",
           patient -> name,
           patient -> address,
           dayConvert(patient -> dateOfBirth), monthConvert(patient -> dateOfBirth), yearConvert(patient -> dateOfBirth),
           patient -> diagnosis,
           dayConvert(patient -> admissionDate), monthConvert(patient -> admissionDate), yearConvert(patient -> admissionDate),
           dayConvert(patient -> dischargeDate), monthConvert(patient -> dischargeDate), yearConvert(patient -> dischargeDate),
           patient -> roomNumber
    );
}


void patientAdd(patientList **list, Patient *patient) {
    if (*list == NULL)
    {
        *list = (patientList *)malloc(sizeof(patientList));
        patientNode *temp = (patientNode *)malloc(sizeof(patientNode));
        temp->patient = patient;
        temp->next = temp->prev = NULL;
        temp -> id = 0;
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
        temp -> id = temp -> prev -> id + 1;

        (*list)->tail = temp;
        return;
    }
}

void patientPrint(patientList *list) {
    patientNode *head;
    head = list->head;
    while (head != NULL)
    {
        patientInformation(head->patient);
        printf("ID: %d\n\n", head -> id);
        head = head->next;
    }
}

void printMedicalCart(Patient *patient) {
    FILE *file;
    char name[] = "MedicalCart.txt";
    char str[128];

    if ((file = fopen(name, "w")) == NULL)
    {
        printf("File open error.\n");
        return;
    }

    fputs("Name: ", file);
    fputs(patient -> name, file);
    fputs("\n", file);

    fputs("Address: ", file);
    fputs(patient -> address, file);
    fputs("\n", file);

    fputs("Date of birth: ", file);
    sprintf(str, "%d.%d.%d\n", dayConvert(patient -> dateOfBirth), monthConvert(patient -> dateOfBirth), yearConvert(patient -> dateOfBirth));
    fputs(str, file);

    fputs("Diagnosis: ", file);
    fputs(patient -> diagnosis, file);
    fputs("\n", file);

    fputs("Admission date: ", file);
    sprintf(str, "%d.%d.%d\n", dayConvert(patient -> admissionDate), monthConvert(patient -> admissionDate), yearConvert(patient -> admissionDate));
    fputs(str, file);

    fputs("Discharge date: ", file);
    sprintf(str, "%d.%d.%d\n", dayConvert(patient -> dischargeDate), monthConvert(patient -> dischargeDate), yearConvert(patient -> dischargeDate));
    fputs(str, file);

    fputs("Room number: ", file);
    sprintf(str, "%d\n", patient -> roomNumber);
    fputs(str, file);

    fclose(file);

    printf("Medical cart was created successfully.\n");
}

void medicalCart(patientList *list, int id) {
    patientNode *temp;
    Patient *sought = NULL;

    temp = list->head;
    while (temp != NULL)
    {
        if(temp -> id == id) {
            sought = temp -> patient;
            break;
        }
        temp = temp->next;
    }

    if(sought != NULL)
        printMedicalCart(sought);

    else
        printf("Incorrect ID.\n");
}