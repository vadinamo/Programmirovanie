#ifndef UNTITLED1_DOCTORLIST_H
#define UNTITLED1_DOCTORLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Doctor {
    char *name;
    char *post;
    char *speciality;
}Doctor;

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

void doctorAdd(doctorList **list, Doctor *doctor);
void doctorPrint(doctorList *list);


Doctor *doctorCreate(char *name,
                     char *post,
                     char *speciality);


void doctorInformation(Doctor *doctor);


#endif
