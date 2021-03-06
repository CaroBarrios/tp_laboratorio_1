#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

#define QTY_EMPLOYEE 1000

/**
* \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
    int answer = -1;
	if(list != NULL && len > 0)
	{
		answer = 0;
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
	}
	return answer;
}

/**
 * \brief Find fist empty position in the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return Returns the index of the position empty and -1 in case of error
 *
 */
int getEmptyIndexEmployee(Employee* list,int len)
{
	int answer = -1;
	if(list != NULL && len > 0)
	{
		answer = 0;
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				answer = i;
				break;
			}
		}
	}
	return answer;
}

/**
* \brief Add in a existing list of employees the values received as parameters in the first empty position
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param index Position to be updated
* \param id Position where an employee will be registered
* \return Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, int index, int* id)
{
    int answer = -1;
	Employee bufferEmployee;

	if(list != NULL && len > 0 && index < len && index >= 0 && id != NULL)
	{
		if(	utn_getString(bufferEmployee.name,NAME_LEN,"\nEnter the Employee's name: ",
                                                       "\nERROR, the entered data is not a name. You can only enter names without numbers or special characters.\n",2) == 0 &&
			utn_getString(bufferEmployee.lastName,LASTNAME_LEN,"\nEnter the Employee's last name: ",
                                                               "\nERROR, the entered data is not a last name. You can only enter last names without numbers or special characters.\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferEmployee.salary,"\nEnter the Employee's salary: ",
                                                         "\nERROR, the data entered is not a salary. You can only enter wages without letters or special characters.\n",0, 1000000, 2) == 0 &&
            utn_getNumero(&bufferEmployee.sector,"\n*****Sectors*****"
                                                 "\n1 - Human Resources"
                                                 "\n2 - Marketing Department"
                                                 "\n3 - Systems Department"
                                                 "\n4 - Accounting Department"
                                                 "\n5 - Collection Department\n"
                                                 "\nEnter the number of the sector to which the employee belongs: ",
                                                 "\nERROR, the data entered is not a sector. You can only enter sectors from 1 to 5 without letters or special characters.\n",0,5,2) == 0)
		{
			answer = 0;
			bufferEmployee.id = *id;
			bufferEmployee.isEmpty = 0;
			list[index] = bufferEmployee;
			(*id)++;
		}
	}
	return answer;
}

/**
 * \brief Print the content of employee in a position
 * \param pElement Pointer to the product to be printed
 * \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int Employee_print(Employee* pElement)
{
	int answer = -1;

	if(pElement != NULL && pElement->isEmpty == 0)
	{
		answer = 0;

		printf ("%d     %s        %s         %.2f       %d\n\n", pElement->id, pElement->name, pElement->lastName, pElement->salary, pElement->sector);
	}
	return answer;
}

/**
* \brief Print the content of employees array
* \param list Employee* Pointer to array of employees
* \param length int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int printEmployees(Employee* list, int length)
{
    int answer = -1;

	if(list != NULL && length > 0)
	{
		answer = 0;
		printf ("\n******Employee******\n\n");
        printf ("ID    Name          Last Name        Salary     Sector\n\n");
		for(int i=0;i<length;i++)
		{
			if (list[i].isEmpty != 1)
            {
                Employee_print(&list[i]);
            }
		}
	}
	return answer;
}

/**
* \brief Find an ID in an array and return the position it is in
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id Position to be found
* \return Returns the index of the position whith the sought value, o if finds the sought value and -1 in case of error
*
*/
int findEmployeeById(Employee* list, int len, int id)
{
	int answer = -1;
	int i;
	if(list != NULL && len > 0 && id >= 0)
	{
		answer = 0;
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				printf("\nThe selected employee is as follows: \n\n");
				printf ("ID    Name          Last Name        Salary     Sector\n\n");
				answer = i;
				Employee_print(&list[answer]);
				break;
			}
		}
	}
	return answer;
}

/**
* \brief Display menu for the user can choose what data want to modify
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param id Position to be modify
* \return Return (-1) if Error [Invalid length or NULL pointer or if the values given by the user are incorrect] - (0) if Ok
*
*/
int menuModifyEmployee (Employee* list, int len, int index)
{
	int answer = -1;
	int optionMenu;
	Employee bufferEmployee;

    if(list != NULL && len > 0 && index < len && index >= 0)
	{
		do
		{
			if ((utn_getNumero (&optionMenu,"\nWhat do you want to modify?\n\n"
											"1. Name.\n"
											"2. Last Name.\n"
											"3. Salary\n"
											"4. Sector\n"
											"5. Return\n\n"
											"Enter an option: ",
											"It is not a valid option. Try again.\n\n", 1, 5, 3))==0)
			{

				switch(optionMenu)
				{
					case 1:
						if (utn_getString(bufferEmployee.name,NAME_LEN,"\nEnter the Employee's name: ",
																		"\nERROR, the entered data is not a name. You can only enter names without numbers or special characters.\n",2)==0)
						{
							bufferEmployee.id = list[index].id;
							bufferEmployee.isEmpty = 0;
							strncpy(list[index].name, bufferEmployee.name, NAME_LEN);
							printf("\nThe name was successfully modified\n\n");
						}
						answer = 0;
						system ("pause");
						system ("cls");
						break;
					case 2:
						if (utn_getString(bufferEmployee.lastName,LASTNAME_LEN,"\nEnter the Employee's last name: ",
															   "\nERROR, the entered data is not a last name. You can only enter last names without numbers or special characters.\n",2)== 0)
						{
							bufferEmployee.id = list[index].id;
							bufferEmployee.isEmpty = 0;
							strncpy(list[index].lastName, bufferEmployee.lastName, LASTNAME_LEN);
							printf("\nThe last name was successfully modified\n\n");
						}
						answer = 0;
						system ("pause");
						system ("cls");
						break;
					case 3:
						if (utn_getNumeroFlotante(&bufferEmployee.salary,"\nEnter the Employee's salary: ",
																		"\nERROR, the data entered is not a salary. You can only enter wages without letters or special characters.\n",0, 1000000, 2)== 0)
						{
							bufferEmployee.id = list[index].id;
							bufferEmployee.isEmpty = 0;
							list[index].salary = bufferEmployee.salary;
							printf("\nThe salary was successfully modified\n\n");
						}
						answer = 0;
						system ("pause");
						system ("cls");
						break;
					case 4:
						if (utn_getNumero(&bufferEmployee.sector,"\n*****Sectors*****"
                                                                "\n1 - Human Resources"
                                                                "\n2 - Marketing Department"
                                                                "\n3 - Systems Department"
                                                                "\n4 - Accounting Department"
                                                                "\n5 - Collection Department\n"
                                                                "\nEnter the number of the sector to which the employee belongs: ",
                                                                "\nERROR, the data entered is not a sector. You can only enter sectors from 1 to 5 without letters or special characters.\n",0,5,2)== 0)
						{
							bufferEmployee.id = list[index].id;
							bufferEmployee.isEmpty = 0;
							list[index].sector = bufferEmployee.sector;
							printf("\nThe sector was successfully modified\n\n");
						}
						answer = 0;
						system ("pause");
						system ("cls");
						break;
				}
			}
		}while (optionMenu!=5);
	}
		return answer;
}

/**
 * \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id Position to be remove
 * \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int removeEmployee(Employee* list,int len, int id)
{
	int answer = -1;
	if(list != NULL && len > 0 && id >= 0 && list[id].isEmpty == 0)
	{
		list[id].isEmpty = 1;
		answer = 0;
	}
	return answer;
}


/**
 * \brief Sort the array of employees by last name and sector
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list,int len, int order)
{
	int answer = -1;
	int flagSwap;
	Employee buffer;
	int auxiliarCmp;

	if(list != NULL && len > 0)
	{
		do
		{
			flagSwap = 0;
			switch(order)
			{
				case 0:
                    for(int i=0;i<len-1;i++)
                    {
                        if(list[i].isEmpty || list[i+1].isEmpty)
                        {
                            continue;
                        }
                        auxiliarCmp = strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN);
                        if(	 auxiliarCmp > 0 ||
                            (auxiliarCmp == 0 && list[i].sector > list[i+1].sector) )
                        {
                            buffer = list[i];
                            list[i] = list[i+1];
                            list[i+1]= buffer;
                            flagSwap = 1;
                        }
                    }
                    answer = 0;
                    break;
				case 1:
                    for(int i=0;i<len-1;i++)
                    {
                        if(list[i].isEmpty || list[i+1].isEmpty)
                        {
                            continue;
                        }
                        auxiliarCmp = strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN);
                        if(	 auxiliarCmp < 0 ||
                            (auxiliarCmp == 0 && list[i].sector < list[i+1].sector) )
                        {
                            buffer = list[i];
                            list[i] = list[i+1];
                            list[i+1]= buffer;
                            flagSwap = 2;
                        }
                    }
                    answer = 1;
                    break;
			}
			len--;
		}while(flagSwap);
	}
	return answer;
}

/**
* \brief Calculate the total amount of salary for all the employees
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param pTotalSalary Pointer of sum of all salaries
* \return Return (-1) if Error [Invalid length or NULL pointer or if can't calculate the total salary] - (0) if Ok
*
*/
int reportTotalSalary(Employee* list, int len, float *pTotalSalary)
{
	int answer = -1;
	float auxTotalSalary = 0;
		if(list != NULL && len > 0)
		{
			for(int i=0; i < len; i++)
				{
				    if(list[i].isEmpty == 0)
                    {
                        auxTotalSalary += list[i].salary;
                    }
				}
			*pTotalSalary = auxTotalSalary;
			answer = 0;
		}
	return answer;
}

/**
* \brief Counts the employees registered to be able to obtain an average of the salary
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param totalSalary sum of all salaries
* \param pAverageSalary Pointer of average of all salaries
* \return Return (-1) if Error [Invalid length or NULL pointer or if can't calculate the total salary] - (0) if Ok
*
*/
int countEmployeesAndAverageSalary(Employee* list, int len, float totalSalary, float* pAverageSalary)
{
	int answer = -1;
	int quantyEmployees = 0;
	int auxAverage;

		if(list != NULL && len > 0)
		{
			for(int i=0; i < len; i++)
			{
				if(list[i].isEmpty == 0)
				{
					quantyEmployees++;
				}
			}
			auxAverage = totalSalary/quantyEmployees;
			*pAverageSalary = auxAverage;
			answer = 0;
		}
	return answer;
}

/**
* \brief Reports how many employees exceed the average salary
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \param auxAverage Average auxiliary
* \param qtyEmployeesExceedAverageSalary Pointer of the number of employees exceeding the average salary
* \return Return (-1) if Error [Invalid length or NULL pointer or if can't calculate the total salary] - (0) if Ok
*
*/
int employeesExceedAverageSalary(Employee* list, int len, float auxAverage, int* qtyEmployeesExceedAverageSalary)
{
	int answer = -1;
    int auxEmployeesExceedAverageSalary = 0;
		if(list != NULL && len > 0)
		{
			for(int i=0; i < len; i++)
				{
				    if(list[i].isEmpty == 0 && list[i].salary > auxAverage)
                    {
                        auxEmployeesExceedAverageSalary++;
                    }
				}
			*qtyEmployeesExceedAverageSalary = auxEmployeesExceedAverageSalary;
			answer = 0;
		}
	return answer;
}

/**
* \brief Display menu for the user can choose what data want to show
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return Return (-1) if Error [Invalid length or NULL pointer or if the values given by the user are incorrect] - (0) if Ok
*
*/
int menuOrderEmployees(Employee* list, int lentgh)
{
	int answer = -1;
	int optionMenu;
	int optionOrder;
	float totalSalary;
	float averageSalary;
	int qtyEmployeesExceedAverageSalary;

	if(list != NULL && lentgh > 0)
	{
		do
		{
			if ((utn_getNumero (&optionMenu,"\nWhat do you want to report?\n\n"
											"1. List of employees alphabetically by Last Name and Sector.\n"
											"2. Total and average wages, and how many employees exceed the average wage.\n"
											"3. Return\n\n"
											"Enter an option: ",
											"It is not a valid option. Try again.\n\n", 1, 3, 2))==0)
			{
				switch(optionMenu)
				{
					case 1:
						if ((utn_getNumero (&optionOrder,"\nEnter 0 for ascending or 1 for descending: ",
                                                         "\nIt is not a valid option. Try again.\n\n", 0, 1, 2))==0)
						{
							sortEmployees(list,QTY_EMPLOYEE,optionOrder);
							printEmployees(list, QTY_EMPLOYEE);
						}
						answer = 0;
						system ("pause");
                        system ("cls");
						break;
					case 2:
						reportTotalSalary(list,QTY_EMPLOYEE,&totalSalary);
						printf("\nThe total salary is: %.2f\n\n",totalSalary);
						countEmployeesAndAverageSalary(list,QTY_EMPLOYEE,totalSalary,&averageSalary);
						printf("The average salary is: %.2f\n\n",averageSalary);
						employeesExceedAverageSalary(list,QTY_EMPLOYEE,averageSalary,&qtyEmployeesExceedAverageSalary);
						printf("The number of employees above the average salary is: %.d\n\n",qtyEmployeesExceedAverageSalary);
						answer = 0;
						system ("pause");
                        system ("cls");
						break;
				}
			}
		}while (optionMenu!=3);

	}
	return answer;
}
