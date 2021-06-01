#include "functionTest.h"
#include <string.h>


Department *departmentCreate(char *name, char *location) {
    Department *department = (Department *)malloc(sizeof(Department));

    char *n = (char *)malloc(128 * sizeof(char));
    char *a = (char *)malloc(128 * sizeof(char));

    strcpy(n, name);
    strcpy(a, location);

    department -> name = n;
    department -> location = a;
    department -> capacity = 0;

    return department;
}

void departmentInformation(Department *department) {
    int i;
    printf("Name: %s\n"
           "Location: %s\n\n",
           department -> name,
           department -> location
    );

    for(i = 0; i < department -> capacity; i++) {
        doctorInformation(&department -> doctor[i]);
        patientInformation(&department -> patient[i]);
    }
}


void departmentAdd(departmentList **list, Department *department)
{
    if (*list == NULL)
    {
        *list = (departmentList *)malloc(sizeof(departmentList));
        departmentNode *temp = (departmentNode *)malloc(sizeof(departmentNode));
        temp->department = department;
        temp->next = temp->prev = NULL;
        (*list)->head = (*list)->tail = temp;
        return;
    }
    else
    {
        departmentNode *temp = (departmentNode *)malloc(sizeof(departmentNode));
        temp->department = department;
        temp->next = NULL;

        temp->prev = (*list)->tail;
        (*list)->tail->next = temp;

        (*list)->tail = temp;
        return;
    }
}

void departmentPrint(departmentList *list) {
    departmentNode *head;
    head = list->head;
    while (head != NULL) {
        departmentInformation(head->department);
        head = head->next;
    }
}

void departmentAddInformation(Department *department, Patient *patient, Doctor *doctor) {
    if(department -> capacity == 20) {
        printf("Department is full!");
        return;
    }

    department -> doctor[department -> capacity] = *doctor;
    department -> patient[department -> capacity] = *patient;
    department -> capacity++;
}

int findMin(int a, int b) {
    if(a > b) return b;
    else return a;
}

void departmentCalculate(departmentList *list) {
    departmentNode *head;
    int i, min;
    head = list->head;
    min = head -> department -> patient -> dischargeDate;

    while (head != NULL) {
        if(head -> department -> capacity < 20) {
            printf("There is free space.\n");
            return;
        }

        for(i = 0; i < 20; i++) {
            min = findMin(head -> department -> patient[i].dischargeDate, min);
        }
        head = head->next;
    }

    printf("The place will be vacated on %d.%d.%d\n", dayConvert(min), monthConvert(min), yearConvert(min));
}


Doctor *doctorCreate(char *name,
                     char *post,
                     char *speciality) {
    Doctor *doctor = (Doctor *)malloc(sizeof(Doctor));

    char *n = (char *)malloc(128 * sizeof(char));
    char *a = (char *)malloc(128 * sizeof(char));
    char *d = (char *)malloc(128 * sizeof(char));

    strcpy(n, name);
    strcpy(a, post);
    strcpy(d, speciality);

    doctor -> name = n;
    doctor -> post = a;
    doctor -> speciality = speciality;


    return doctor;
}

void doctorInformation(Doctor *doctor) {
    printf("Name: %s\n"
           "Post: %s\n"
           "Speciality: %s\n\n",
           doctor -> name,
           doctor -> post,
           doctor -> speciality
    );
}

void doctorAdd(doctorList **list, Doctor *doctor)
{
    if (*list == NULL)
    {
        *list = (doctorList *)malloc(sizeof(doctorList));
        doctorNode *temp = (doctorNode *)malloc(sizeof(doctorNode));
        temp->doctor = doctor;
        temp->next = temp->prev = NULL;
        (*list)->head = (*list)->tail = temp;
        return;
    }
    else
    {
        doctorNode *temp = (doctorNode *)malloc(sizeof(doctorNode));
        temp->doctor = doctor;
        temp->next = NULL;

        temp->prev = (*list)->tail;
        (*list)->tail->next = temp;

        (*list)->tail = temp;
        return;
    }
}

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