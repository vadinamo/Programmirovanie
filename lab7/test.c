#include <assert.h>
#include "functionTest.h"

void test() {
    int i;
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
        departmentCalculate(departments);
    }

    departmentAddInformation(department, patient, doctor);

    free(patient);
    free(doctor);
    free(department);

    departmentCalculate(departments);
    departmentPrint(departments);

    assert(departments != NULL);
    assert(doctors != NULL);
    assert(patients != NULL);
    assert(findMin(2, 20) == 2);

    free(patients);
    free(doctors);
    free(departments);

    return;
}

int main() {
    test();
    printf("Test successfully completed.");

    return 0;
}