/*
 * ArrayEmployee.c
 *
 *  Created on: 29 sep. 2020
 *      Author:
 */
#define TAM 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

int initEmployees(Employee* list, int len)
{
	int retorno =-1;
	//retorna 0 if ok
	int i=0;
	if(list!=NULL && TAM > 0)
	{
		for(i=0;i<TAM;i++){
			list[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}
int searchForSpace(Employee* list, int len, int* position)
{
	int retorno=-1;
	int i =0;
	if(list!=NULL && TAM >=0 && position!=NULL)
	{
		for(i=0;i<TAM;i++)
		{
			if(list[i].isEmpty==1)
			{
				retorno=0;
				*position=i;
			}
		}
	}
	return retorno;
}

int addEmployees(Employee* list, int len, int* nextId)
{
	int retorno=-1;
	// o ok -1 error
	int position;

	if(list!= NULL && TAM > 0 && nextId!= NULL)
	{
		if(searchForSpace(list,TAM,&position)==-1)
		{
			printf("No hay lugares disponibles\n");

		}
		else
		{

			(*nextId)++;
			list[position].id=*nextId;
			get_Cadena(list[position].name,51,1,"Ingrese nombre\n","Error, vuelva a ingresar nombre\n");
			get_Cadena(list[position].lastName,51,1,"Ingrese apellido\n","Error, vuelva a ingresar apellido\n");
			get_Flotante( &list[position].salary,1,"Ingrese salario\n","Error, vuelva a ingresar salario\n", 1,999999);
			get_Entero( &list[position].sector,1,"Ingrese numero de sector 1-Ventas, 2-Sistemas o 3-Marketing\n", "Error, vuelva a ingresar sector\n", 1,3);
			list[position].isEmpty=0;
			retorno=0;
		}
	}
	return retorno;
}


int findEmployeeById(Employee *list,int size, int valor, int* position)
{
	int retorno = -1;
		int i;
		if(list!= NULL && TAM >=0)
		    {
		        for(i=0;i<TAM;i++)
		        {
		            if(list[i].isEmpty==0)
		                continue;
		            else if(list[i].id==valor)
		            {
		                retorno=0;
		                *position=i;
		                break;
		            }
		        }
		    }
		    return retorno;
}
int removeEmployee(Employee* list, int len)
{
	int retorno =-1;
	    int position;
	    int auxId;
	    if(list!=NULL && TAM>0)
	    {
	       printEmployees(list,TAM);
	    	get_Entero(&auxId,1,"ID a dar de baja: \n","Error. Vuelva a ingresar ID\n",1,1000);

	    	 if(!findEmployeeById(list,TAM,auxId,&position))
	        {
	            printf("ID inexistente\n");
	        }
	        else
	        {
	            list[position].isEmpty=1;
	            list[position].id=0;
	            strcpy(list[position].name,"");
	            strcpy(list[position].lastName,"");
	            list[position].salary=0;
	            list[position].sector=0;
	            retorno=0;
	        }
	    }
	return retorno;
}
int sortEmployees(Employee* list, int len)
{
	int retorno = -1;
	char continuar='s';
	int op;
	if(list!=NULL && TAM>0)
		  {

	do{

		printf("De que manera desea informar alfabeticamente empleados?\n\n");
							printf("1-Ascendente\n\n");
							printf("2-Descendente\n\n");
							get_Entero(&op,1,"Indique opcion: ","Error: Indique opcion valida 1-2: ",1,2);
			switch(op){
				    	case 1://arriba
				    		orderUpwards(list, TAM);
				    		printEmployees(list,TAM);
				    		break;
				    	case 2://abajo
				    		orderDownwards(list,TAM);
				    		printEmployees(list,TAM);
				    		break;
				    	default:
				    		printf("No es una opcion valida\n");
				    	}
			printf("Desea volver al menu de informes? s/n : \n");
					        fflush(stdin);
					        scanf("%c", &continuar);

		retorno=0;

		}while(continuar=='s');
		  }
	return retorno;
}
void printEmployee(Employee list, int size)
{

	printf("%d   %-20s  %-20s   %.2f  %d   \n",list.id, list.name ,list.lastName, list.salary, list.sector);
}
int printEmployees(Employee list[], int size)
{
	int ret=-1;
	int i;
	printf("***************************Employee List***************************\n");
	printf("Id    Name    Last Name    Salary    Sector\n");
	if(list!=NULL && TAM >0){
		for(i=0;i<TAM;i++)
		{
			if(list[i].isEmpty==0)
				{
				printEmployee(list[i],TAM);
				ret=0;
				}
		}

	}
		return ret;
}

int modifyEmployee(Employee* list, int len)
{
	int retorno=-1;
	    int position=0;
	    int auxId;
	    int optionModify;
	    char continuar='s';

	    if(list!=NULL && TAM>0)
	    {
	    	printEmployees(list,TAM);
	    	get_Entero(&auxId,1,"ID a modificar: \n","Error. Vuelva a ingresar ID\n",1,1000);
	    	 	 	 	if(!findEmployeeById(list,TAM,auxId,&position))
	    		        {
	    		            printf("ID inexistente\n");
	    		        }
	    		        else
	    		        {

	            do
	            {
	            	 printEmployees(list,TAM);
	                get_Entero(&optionModify,1,"Modificar: 1-Nombre 2-Apellido 3-Salario 4-Sector 5(Salir)\n","Error.Ingrese opcion entre 1 y 5\n",1, 5);
	                switch(optionModify)
	                {
	                    case 1:
	                    	getName("Ingrese nuevo nombre: \n","Error. Ingrese nuevo nombre\n",1,TEXT_SIZE,1,list[position].name);
	                        break;
	                    case 2:
	                    	getName("Ingrese nuevo apellido: \n","Error. Ingrese nuevo apellido\n", 1, TEXT_SIZE, 1, list[position].lastName);
	                        break;
	                    case 3:
	                    	get_Flotante( &list[position].salary,1,"Ingrese nuevo salario: \n","Error. Ingrese nuevo salario\n", 1,999999);
	                        break;
	                    case 4:
	                    	get_Entero(&list[position].sector,1,"ingrese nuevo sector\n","Error, ingrese sector entre 1 y 3\n",1,3);
	                        break;
	                    case 5:

	                    	break;
	                    default:
	                        printf("Opcion no valida\n");
	                }
	            }while(continuar!='s');
	            retorno=0;
	        }

	    }
	    return retorno;
}
void orderSalary(Employee* list, int len)
{
	float avgSalary;
	int contador=0;
	float accumulatorSalaries=0;
	int cantOverAvg=0;
	if(list!=NULL && TAM >0){
		for(int i=0; i<TAM; i++)
			{
				if(list[i].isEmpty == 0)
				{
					accumulatorSalaries += list[i].salary;
					contador++;
				}
			}
			printf("Total de los salarios: %.2f\n\n", accumulatorSalaries);


			avgSalary = accumulatorSalaries / contador;

			printf("Promedio de los salarios: %.2f\n\n", avgSalary);




			for(int i=0; i<TAM; i++)
			{
				if(list[i].isEmpty == 0 && list[i].salary > avgSalary)
				{
					cantOverAvg++;
				}
			}
			printf("Los empleados sobre el salario promedio son:%d\n",cantOverAvg);
	}


}
int orderUpwards(Employee* list, int len)
{
	int ret=-1;
	Employee auxEmployee;
	if(list!=NULL && TAM>0){
	 for(int i=0; i<TAM-1; i++)
					    		    {
					    		        for(int j=i+1; j<TAM; j++)
					    		        {

					    		                if(list[i].sector < list[j].sector)
					    		                {
					    		                    auxEmployee = list[i];
					    		                    list[i] = list[j];
					    		                    list[j] = auxEmployee;
					    		                }
					    		                else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) > 0)
					    		                {
					    		                    auxEmployee = list[i];
					    		                    list[i] = list[j];
					    		                    list[j] = auxEmployee;
					    		                }
					    		            }
					    		    }
	ret=0;
	}
	return ret;
}
int orderDownwards(Employee* list, int len)
{
	int ret=-1;
		Employee auxEmployee;
		if(list!=NULL && TAM>0)
		{
		 for(int i=0; i<TAM-1; i++)
			{
			 for(int j=i+1; j<TAM; j++)
			 	{
			 	 if(list[i].sector > list[j].sector)
			 		 {
			 			auxEmployee = list[i];
			 			list[i] = list[j];
			 			list[j] = auxEmployee;
			 		 }
			 	else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) > 0)
			 		 {
			 			auxEmployee = list[i];
			 			list[i] = list[j];
			 			list[j] = auxEmployee;
			 		  }
			 		}
			 	}
		 ret=0;
			}
		return ret;
}
