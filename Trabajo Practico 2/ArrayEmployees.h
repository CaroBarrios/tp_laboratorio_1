#ifndef ArrayEmployee_H_INCLUDED
#define ArrayEmployee_H_INCLUDED

#define NAME_LEN 51
#define LASTNAME_LEN 51

typedef struct
{
    int id;
    char name [NAME_LEN];
    char lastName [LASTNAME_LEN];
    float salary;
    int sector;
    int isEmpty;

}Employee;

int initEmployees(Employee* list, int len);
int getEmptyIndexEmployee(Employee* list,int len);
int addEmployee(Employee* list, int len, int index, int* id);
int Employee_print(Employee* pElement);
int printEmployees(Employee* list, int length);
int findEmployeeById(Employee* list, int len, int id);
int modifyEmployee(Employee* list, int len, int index);
int removeEmployee(Employee* list,int len, int id);
int sortEmployees(Employee* list,int len, int order);
int reportTotalSalary(Employee* list, int len, float *pTotalSalary);
int countEmployeesAndAverageSalary(Employee* list, int len, float totalSalary, float* pAverageSalary);
int employeesExceedAverageSalary(Employee* list, int len, float auxAverage, int* qtyEmployeesExceedAverageSalary);
int menuOrderEmployees(Employee* list, int lentgh);

#endif // ArrayEmployee_H_INCLUDED
