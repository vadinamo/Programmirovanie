#include <stdio.h>
#include "patientList.h"
#include "doctorList.h"
#include "departmentList.h"

#ifndef TESTING

int main() {
    int i, pick = -1;

    departmentList *departments;
    Department *department;
    Patient *patient;
    Doctor *doctor;
    patientList *patients;
    doctorList *doctors;

    char c;
    char *pChar = malloc(sizeof(char));

    departments = NULL;
    doctors = NULL;
    patients = NULL;

    department = departmentCreate("Minsk central regional hospital", "Minski district, forest village 223041");

    for(i = 0; i < 20; i++) {
        c = i + '0' + '1';
        *pChar = c;

        patient = patientCreate(pChar, pChar, i + 729400, pChar, i + 737703, i + 738007, i);
        doctor = doctorCreate(pChar, pChar, pChar);
        departmentAddInformation(department, patient, doctor);
        doctorAdd(&doctors, doctor);
        patientAdd(&patients, patient);
        departmentAdd(&departments, department);
    }


    while (pick != 0) {
        printf("1.Show patients.\n2.Display a medical history.\n3.Show departments.\n"
               "4.Show doctors.\n5.Load calculation.\n0.Exit.\n");

        scanf("%d", &pick);
        switch (pick) {
            case 1:
                patientPrint(patients);
                break;

            case 2:
                printf("Enter patient number.\n");
                scanf("%d", &i);
                medicalCart(patients, i);
                break;

            case 3:
                departmentPrint(departments);
                break;

            case 4:
                doctorPrint(doctors);
                break;

            case 5:
                departmentCalculate(departments);
                break;

            case 0:
                return 0;

            default:
                printf("Incorrect input!");
                break;
        }
    }
}

#endif
