/*
 * parser.h
 *
 *  Created on: 12 jun. 2021
 *      Author: carolina
 */

//#ifndef PARSER_H_
//#define PARSER_H_

#include "LinkedList.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

//#endif /* PARSER_H_ */
