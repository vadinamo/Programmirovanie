#include "departmentList.h"
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

    printf("The place will be vacated on %d\n", min);
}
