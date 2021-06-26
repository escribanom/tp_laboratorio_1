#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menues.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);
	char seguir = 's';
    char salir;
    int flagTxt = 1;
    int flagBin = 1;
    int flagSave = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    if(listaEmpleados == NULL)
    {
        printf("No se pudo conseguir espacio en memoria\n\n");
        exit(EXIT_FAILURE);
    }
    //Employee* auxEmpleado;

    do
    {
        switch(menuOpciones())
        {
        case 1:
            if(flagBin != 0 && flagTxt == 1)
            {
                if(controller_loadFromText("data.csv",listaEmpleados) == 0)
                {
                    flagTxt = 0;
                }
            }
            else
            {
                printf("El archivo ya fue cargado.\n");
            }
            break;

        case 2:
            if(flagTxt != 0 && flagBin == 1)
            {
                if(controller_loadFromBinary("data.bin", listaEmpleados) == 0)
                {
                    flagBin = 0;
                }
            }
            else
            {
                printf("El archivo ya fue cargado.\n");
            }
            break;

        case 3:
            if(flagTxt== 0 || flagBin == 0)
            {
                if(controller_addEmployee(listaEmpleados) == 0)
                {
                    printf("Se ha realizado el alta con exito!\n\n");
                    flagSave++;
                }
                else
                {
                    printf("Error, no se pudo realizar el alta\n\n");
                }
            }
            else
            {
                printf("Para realizar el alta, primero debe cargar los archivos\n\n");
            }
            system("pause");
            break;

        case 4:
            if(flagTxt == 0 || flagBin == 0)
            {
                controller_editEmployee(listaEmpleados);
                flagSave++;
            }
            else
            {
                printf("Para realizar modificaciones, primero debe haber empleados cargados\n\n");
            }
            break;

        case 5:
            if(flagTxt == 0 || flagBin == 0)
            {
                controller_removeEmployee(listaEmpleados);
                flagSave++;
            }
            else
            {
                printf("Para realizar bajas, primero debe haber empleados cargados\n\n");
            }
            break;

        case 6:
            if(flagTxt == 0 || flagBin == 0)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("No hay empleados que listar\n\n");
            }
            break;

        case 7:
            controller_sortEmployee(listaEmpleados);
            flagSave++;
            break;

        case 8:
            if(flagTxt == 0 || flagBin == 0)
            {
                controller_saveAsText("data.csv", listaEmpleados);
                flagSave = 0;
            }
            else
            {
                printf("No hay archivos cargados para guardar\n\n");
            }
            break;

        case 9:
            if(flagTxt == 0 || flagBin == 0)
            {
                controller_saveAsBinary("data.bin", listaEmpleados);
                flagSave = 0;
            }
            else
            {
                printf("No hay archivos cargados para guardar\n\n");
            }
            break;

        case 10:
            if(flagSave > 0)
            {
                do
                {
                    fflush(stdin);
                    printf("\nDesea salir del programa sin guardar los cambios? s/n: ");
                    scanf("%c", &salir);
                }
                while(salir != 's' && salir != 'n');
            }
            else if(flagSave == 0)
            {
                do
                {
                    fflush(stdin);
                    printf("\nDesea salir del programa? s/n: ");
                    scanf("%c", &salir);
                }
                while(salir != 's' && salir != 'n');
            }
            if(salir == 's')
            {
                ll_deleteLinkedList(listaEmpleados);
                seguir = 'n';
            }
            break;

        default:
            printf("No es una opcion valida\n\n");
            fflush(stdin);
            break;
        }
        fflush(stdin);

    }
    while(seguir == 's');

    return 0;

}
