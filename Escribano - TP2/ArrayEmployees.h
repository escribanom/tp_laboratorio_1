/*
 * ArrayEmployees.h
 *
 *  Created on: 4 oct. 2020
 *      Author: Adm-Periodismo
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define TEXT_SIZE 51

typedef struct{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;//0=full 1=empty
}Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len);

/** \brief search for space in the array of employees
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param position int pointer to array position
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int searchForSpace(Employee* list, int len, int* position);
/** \brief copies loaded data into new function
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param id int id
 * \param name char employee's name
 * \param lastName char employee's last name
 * \param salary float employee's salary
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int addEmployees(Employee* list, int len, int* nextId);
/** \brief finds employee vy id
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param valor int employee's id
 * \param position int* pointer to array position
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int findEmployeeById(Employee *list,int size, int valor,int* position);
/** \brief deletes employee from array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len);
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len);

/** \brief Prints only one employee
 *
 * \param list Employee
 * \param len int
 * \return void
 *
 */
void printEmployee(Employee list);


/** \brief prints employee list
 * \param list Employee* Pointer to array of employees
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int printEmployees(Employee* list, int len);

/** \brief inform wanted items related to employees salaries
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 *
 *
 */
void orderSalary(Employee* list, int len);
/** \brief modifies employee parameters
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int modifyEmployee(Employee* list, int len);
/** \brief sort employees upwards
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int orderUpwards(Employee* list, int len);
/** \brief sort employees downwards
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int orderDownwards(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */
