#define TAMN 25
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menues.h"
#include "utn.h"
#include "parser.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 0)
        {
            printf("Datos cargados con exito!\n\n");
            retorno = 0;
        }
        else
        {
            printf("No ha sido posible cargar los datos\n\n");
        }
    }
    else
    {
        system("cls");
        printf("Error NULL\n\n");
    }

    fclose(pFile);

    return retorno;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;

    pFile = fopen(path, "rb");

    if(pFile != NULL)
    {
        if(parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 0)
        {
            printf("Datos cargados con exito\n");
            retorno = 0;
        }
        else
        {
            printf("No ha sido posible cargar los datos\n\n");
        }
    }
    else
    {
        printf("Error NULL\n");
    }
    fclose(pFile);
    return retorno;
}
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmployee = employee_new();

    int nextId;
    char auxNombre[TAMN];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pArrayListEmployee != NULL && pEmployee != NULL)
    {
        printf("||Alta Empleados||\n\n");

        if(get_Cadena(auxNombre,TAMN, 3, "Ingrese nombre del nuevo empleado: ", "Error, reingrese nombre: \n") == 0 &&
                get_Entero(&auxHorasTrabajadas, 3, "Ingrese horas trabajadas: ", "Error, reingrese horas: \n", 0, 5000) == 0 &&
                get_Entero(&auxSueldo, 3, "Ingrese sueldo: ", "Error, reingrese sueldo: \n", 12000, 300000) == 0)
        {
            normalizeStr(auxNombre);

            nextId = employee_lastId(pArrayListEmployee) + 1;

            if(employee_setId(pEmployee, nextId) == 0 &&
                    employee_setNombre(pEmployee, auxNombre) == 0 &&
                    employee_setHorasTrabajadas(pEmployee, auxHorasTrabajadas) == 0 &&
                    employee_setSueldo(pEmployee, auxSueldo) == 0)
            {
                ll_add(pArrayListEmployee, pEmployee);
                retorno = 0;
            }
            else
            {
                free(pEmployee);
            }
        }
        else
        {
            free(pEmployee);
        }
    }

    return retorno;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmployee;
    int auxId;
    int lastId;
    int index;
    int quitMenu = 1;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);

            employee_getId(auxEmployee, &auxId);
            if(auxId >= lastId)
            {
                lastId = auxId;
            }
        }
        if(get_Entero(&auxId, 3, "\nIngrese ID del empleado a modificar: ", "Error, reingrese un ID valido: \n", 0, lastId) == 0)
        {
            index = employee_searchForId(pArrayListEmployee, auxId);

            if(index >= 0)
            {
                printf("||Modificar Empleados||\n\n");
                printf("Usted eligio el siguiente empleado para modificar:\n\n");
                printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                employee_printEmployee(pArrayListEmployee, index);

                printf("\nQue desea modificar?\n");

                do
                {
                    switch(menuModifications())
                    {
                    case 1:
                        if(employee_changeName(pArrayListEmployee, index) == 0)
                        {
                            printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                            employee_printEmployee(pArrayListEmployee, index);
                            printf("\nNombre modificado con exito! Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            printf("No se pudo realizar la modificacion del nombre, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 2:
                        if(employee_changeHours(pArrayListEmployee, index) == 0)
                        {
                            printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                            employee_printEmployee(pArrayListEmployee, index);
                            printf("\nHoras trabajadas modificadas con exito! Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            printf("No se pudo realizar la modificacion de las horas trabajadas, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 3:
                        if(employee_changeSalary(pArrayListEmployee, index) == 0)
                        {
                            printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                            employee_printEmployee(pArrayListEmployee, index);
                            printf("Sueldo modificado con exito. Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            system("cls");
                            printf("No se pudo realizar la modificacion del sueldo, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 4:
                        quitMenu = 0;
                        break;
                    default:
                        system("cls");
                        printf("No es una opcion valida\n\n");
                        break;
                    }
                }
                while(quitMenu == 1);

            }

        }

    }

    return retorno;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmployee;

    int auxId;
    int lastId;

    int index;
    char confirmDelete;

    if(pArrayListEmployee != NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);

            employee_getId(auxEmployee, &auxId);
            if(auxId >= lastId)
            {
                lastId = auxId;
            }
        }
        if(get_Entero(&auxId, 3, "\nIngrese ID del empleado a eliminar: ", "Error, reingrese un ID valido: \n", 0, lastId) == 0)
        {
            index = employee_searchForId(pArrayListEmployee, auxId);

            if(index >= 0)
            {
                printf("||Baja Empleados||\n\n");
                printf("Usted eligio el siguiente empleado para dar de baja:\n\n");
                auxEmployee = ll_get(pArrayListEmployee, index);
                printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                employee_printEmployee(pArrayListEmployee, index);

                printf("\nDesea eliminar al empleado? s/n: ");
                fflush(stdin);
                scanf("%c", &confirmDelete);

                if(confirmDelete == 's')
                {
                    ll_remove(pArrayListEmployee, index);
                    if(employee_delete(auxEmployee) == 0)
                    {
                        printf("Baja realizada con exito!\n\n");
                        retorno = 0;
                    }
                }
                else
                {
                    printf("No se ha realizado la baja\n");
                }
            }
        }
    }
    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            employee_printEmployee(pArrayListEmployee, i);
        }
        retorno = 0;
    }
    else
    {
        printf("No hay empleados cargados para mostrar\n");
    }

    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        if(employee_sort(pArrayListEmployee) == 0)
        {
            printf("\nEmpleados ordenados exitosamente.\n\n");
        }
    }
    else
    {
        printf("Error\n");
    }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    FILE* pFile;
    Employee* pEmployee;

    int auxId;
    char auxName[TAMN];
    int auxHours;
    int auxSalary;


    if(pArrayListEmployee != NULL && path != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {

            for(int i = 0; i < ll_len(pArrayListEmployee); i++)
            {
                pEmployee = ll_get(pArrayListEmployee, i);
                if(!employee_getId(pEmployee, &auxId) &&
                        !employee_getNombre(pEmployee, auxName) &&
                        !employee_getHorasTrabajadas(pEmployee, &auxHours) &&
                        !employee_getSueldo(pEmployee, &auxSalary))
                {
                    fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxName, auxHours, auxSalary);
                }
            }
            fclose(pFile);
            printf("Datos guardados como texto de forma exitosa\n\n");
            retorno = 0;
        }
    }

    return retorno;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
	FILE* pFile;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 1; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmployee, sizeof(Employee), 1, pFile);
		}
		fclose(pFile);
		system("cls");
		printf("Datos guardados como binario de forma exitosa!\n");
		retorno = 0;
	}

    return retorno;
}
