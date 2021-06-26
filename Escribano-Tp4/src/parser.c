#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1; //retorno error

    Employee* pEmployee;

    int nextId = 0;
    int cant = 4; //guarda la cantidad que devuelve fscanf
    char id[128];
    char nombre[128];
    char horasTrabajadas[128];
    char sueldo[128];

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

        do
        {
            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo) == cant)
            {
                pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

                if(pEmployee != NULL)
                {
                    ll_add(pArrayListEmployee, pEmployee);
                    retorno = 0;
                }
            }
            else
            {
                break;
            }

        }
        while(feof(pFile) == 0);
        retorno = nextId;
    }

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmployee;

    if(pFile != NULL)
    {
        do
        {
            pEmployee = employee_new();
            if(fread(pEmployee, sizeof(Employee), 1, pFile) == 1)
            {
                ll_add(pArrayListEmployee, pEmployee);
                retorno = 0;
            }
        }
        while(!feof(pFile));
    }

    return retorno;
}
