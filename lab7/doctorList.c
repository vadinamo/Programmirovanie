#include "doctorList.h"
#include <string.h>

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

void doctorPrint(doctorList *list) {
    doctorNode *head;
    head = list->head;
    while (head != NULL) {
        doctorInformation(head->doctor);
        head = head->next;
    }
}
