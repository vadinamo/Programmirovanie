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

    departments = NULL;
    doctors = NULL;
    patients = NULL;

    department = departmentCreate("Minsk central regional hospital", "Minski district, forest village 223041");

    for(i = 0; i < 20; i++) {
        patient = patientCreate("1", "1", i, "1", i, i, i);
        doctor = doctorCreate("1", "1", "1");
        departmentAddInformation(department, patient, doctor);
        doctorAdd(&doctors, doctor);
        patientAdd(&patients, patient);
        departmentAdd(&departments, department);
    }


    while (pick != 0) {
        printf("1.Show patients.\n2.Show departments.\n"
               "3.Show doctors.\n4.Load calculation.\n0.Exit.\n");

        scanf("%d", &pick);
        switch (pick) {
            case 1:
                patientPrint(patients);
                break;

            case 2:
                departmentPrint(departments);
                break;

            case 3:
                doctorPrint(doctors);
                break;

            case 4:
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
