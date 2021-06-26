/*
 * main.c
 *
 *  Created on: 29 sep. 2020
 *      Author:
 */

#define TAM 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);
	Employee list[TAM];
	initEmployees(list,TAM);
	char continuar = 's';
	char continuarInf = 's';
		int opcion;
		int flagNum1 = 0;
		int posAux;
		int nextId=0;
		int opInf;
		    do
		    {

		        printf("*****************************************\n");
		        printf("**** Bienvenido al menu de empleados ****\n");
		        printf("*********** Menu de opciones ************\n");
		        printf("*****************************************\n");
		        printf("1- Altas\n");
		        printf("2- Modificar \n");
		        printf("3- Baja\n");
		        printf("4- Informes\n");
		        printf("5- Salir\n\n");
		        get_Entero(&opcion,1,"Indique opcion: ","Error: Indique opcion valida 1-5: ",1,5);
		        switch(opcion)
		        {
		        case 1:
		        	//id calcu auto el resto usuario
		        	if(searchForSpace(list, TAM, &posAux)==1)
		        	{
		        		printf("No hay lugar disponible");
		        	}
		        	else
		        	{

		        	addEmployees(list, TAM,&nextId);
		        	   flagNum1 = 1;
		        	}

		            break;
		        case 2:
		        	if((flagNum1 ==1)&& (searchForSpace(list, TAM, &posAux)==0))
		        	{
		        		modifyEmployee(list,TAM);
		        	}
		        	else
		        	{
		        		printf("Para modificar un empleado primero debe INGRESARLO\n");
		        	}
		            break;
		        case 3:
		        	if((flagNum1 ==1) && (searchForSpace(list, TAM, &posAux)==0))
		        	{

		        		removeEmployee(list,TAM);
		        	}
		            else
		        	{
		            printf("Para eliminar un empleado primero debe INGRESARLO");
		        	}

		            break;
		        case 4:
		        	if(flagNum1)
		        	{
		        		do{
		        		get_Entero(&opInf,1,"Ingrese opcion deseada: \n1-Ordenar empleados \n2-Informes salario\n","Error:Ingrese opcion valida:\n1-Ordenar empleados \n2-Informes salario\n",1,2);
		        		switch(opInf){
		        		case 1:
		        			sortEmployees(list,TAM);
		        			break;
		        		case 2:
		        			orderSalary(list, TAM);
		        			break;
		        		default:
		        			printf("No es una opcion valida\n");
		        		}
		        		printf("Desea volver al menu de informes? s/n : \n");
		        				        fflush(stdin);
		        				        scanf("%c", &continuarInf);
		        		}while(continuarInf=='s');
		        	}
		        	else
		        	{
		        	    printf("Para listar un empleado primero debe INGRESARLO");
		        	}
		        	//1-alfabecticaemete x apellido y sector
		        	//2-total y promedio de salarios y cuantos sobre salario promedio
		        	//needs case 1
		            break;
		        case 5:

		            printf("Ingrese n para salir\n");
		            break;
		        default:
		            printf("No es una opcion valida\n");
		        }
		        printf("Desea volver al menu? s/n : \n");
		        fflush(stdin);
		        scanf("%c", &continuar);
		       	    }
		    while(continuar =='s');
		    return opcion;


	return EXIT_SUCCESS;
}
