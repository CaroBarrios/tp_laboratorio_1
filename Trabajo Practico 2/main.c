#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define QTY_EMPLOYEE 1000

int main()
{
    Employee arrayEmployee[QTY_EMPLOYEE];
	int option;
	int auxiliaryIndex;
	int idEmployee = 0;
	int triggerRegister = 0;
	int auxiliaryId;

    if(initEmployees(arrayEmployee,QTY_EMPLOYEE) == 0)
	{
		printf("Array initialized successfully\n\n");
	}
    do
	{
		if ((utn_getNumero (&option,"\n*****EMPLOYEE OPTION MENU*****\n\n"
                                    "1. ADD\n"
                                    "2. MODIFY\n"
                                    "3. REMOVE\n"
                                    "4. REPORT\n"
                                    "5. EXIT\n\n\n"
                                    "Enter an option: ",
                                    "It is not a valid option. Try again.\n\n", 1, 5, 4))==0)
		{
			switch (option)
			{
			case 1:
			    auxiliaryIndex = getEmptyIndexEmployee(arrayEmployee,QTY_EMPLOYEE);
				if(auxiliaryIndex >= 0)
				{
				    if(addEmployee(arrayEmployee,QTY_EMPLOYEE,auxiliaryIndex,&idEmployee) == 0)
					{
						printf("\nSuccessfully registered\n\n");
						triggerRegister = 1;
					}
				}
				else
				{
					printf("\nTHERE IS NO MORE PLACE\n\n");
				}
			    system ("pause");
				system ("cls");
				break;
			case 2:
			    if (triggerRegister)
                {
                    printEmployees(arrayEmployee, QTY_EMPLOYEE);
                    if(utn_getNumero(&auxiliaryId,"\n\nIndicate the employee ID that you want to modify: ",
                                                 "\nID invalid\n\n",0,idEmployee,0) == 0)
                    {
                        auxiliaryIndex = findEmployeeById(arrayEmployee,QTY_EMPLOYEE,auxiliaryId);
                        if( auxiliaryIndex >= 0 &&
                            modifyEmployee(arrayEmployee,QTY_EMPLOYEE,auxiliaryId) == 0)
                            {
                                printf("\nSuccessful modification\n\n");
                            }
                    }
                }
                else
                {
                    printf ("\nYou can`t enter in this option without registering an employee in the option 1\n\n");
                }
			    system ("pause");
				system ("cls");
				break;
			case 3:
			    if (triggerRegister)
                {
                    printEmployees(arrayEmployee, QTY_EMPLOYEE);
                    if(utn_getNumero(&auxiliaryId,"\n\nIndicate the employee ID that you want to remove: ",
                                                 "\nID invalid\n\n",0,idEmployee,0) == 0)
                    {
                        auxiliaryId = findEmployeeById(arrayEmployee,QTY_EMPLOYEE,auxiliaryId);
                        if( auxiliaryId >= 0 &&
                            removeEmployee(arrayEmployee,QTY_EMPLOYEE,auxiliaryId) == 0)
                            {
                                printf("\nSuccessful remove\n\n");
                            }
                    }
                }
                else
                {
                    printf ("\nYou can`t enter in this option without registering an employee in the option 1\n\n");
                }
				system ("pause");
				system ("cls");
				break;
			case 4:
			    if (triggerRegister)
                {
                    menuOrderEmployees(arrayEmployee,QTY_EMPLOYEE);
                }
                else
                {
                    printf ("\nYou can`t enter in this option without registering an employee in the option 1\n\n");
                }
			    system ("pause");
				system ("cls");
				break;
			}
		}
	}while (option!=5);

	return EXIT_SUCCESS;
}
