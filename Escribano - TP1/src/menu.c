#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int menuCalculadora(){
char continuar = 's';
	float numeroUno=0;
	float numeroDos=0;
    int opcion;
	    int flagNum1 = 0;
	    int flagNum2 = 0;
	    int flagOp=0;
	    do
	    {

	        printf("*************************************\n");
	        printf("**** Bienvenido a la calculadora ****\n");
	        printf("******* de : Martin Escribano *******\n");
	        printf("********* Menu de opciones **********\n");
	        printf("*************************************\n");
	        printf("1- Ingresar primer operando A:%.2f \n", numeroUno);
	        printf("2- Ingresar segundo operando B:%.2f \n",numeroDos);
	        printf("3- Realizar operaciones\n");
	        printf("*** Suma: A:%.2f + B:%.2f\n",numeroUno, numeroDos);
	        printf("*** Resta:  A:%.2f - B:%.2f\n",numeroUno, numeroDos);
	        printf("*** Multiplicacion:  A:%.2f * B:%.2f\n",numeroUno, numeroDos);
	        printf("*** Division: A:%.2f / B:%.2f\n",numeroUno, numeroDos);
	        printf("*** Factorial:  A:%lf ! B:%lf\n",numeroUno, numeroDos);
	        printf("4- Resultados\n");
	        printf("5- Salir\n\n");
	        printf("Indique opcion: ");
	        scanf("%d", &opcion);
	        switch(opcion)
	        {
	        case 1:

	            numeroUno = ingresarNumero();
	            flagNum1 = 1;
	            break;
	        case 2:

	            if(flagNum1){
	                numeroDos = ingresarNumero();
	                flagNum2 = 1;
	            }else
	            {
	                printf("Para ingresar el segundo numero, debe ingresar el primero antes\n");
	            }
	            break;
	        case 3:

	            if(flagNum1 && flagNum2){
	                 printf("Calculando resultados\nVuelva al menu e ingrese la opcion 4 para obtener los resultados\n");
	                 flagOp=1;
	            }else{
	            printf("Ingrese los dos numeros en primer lugar\n");
	            }

	            break;
	        case 4:

	            if(flagOp){
	            printf("El resultado de la suma es: %.2f\n", suma(&numeroUno, &numeroDos));
	            printf("El resultado de la resta es: %.2f\n", resta(&numeroUno, &numeroDos));
	            division(&numeroUno, &numeroDos);
	            printf("El resultado de la multiplicacion es: %.2f\n", multiplicacion(&numeroUno, &numeroDos));
	            factorialNumUno(&numeroUno);
	            factorialNumDos(&numeroDos);
	            }else{
	            printf("Utilice las opciones 1,2 y 3 antes de la 4\n");
	            }
	            break;
	        case 5:
	        	printf("Desea continuar en la aplicacion? s/n : \n");
	        	fflush(stdin);
	        	 scanf("%c", &continuar);
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
}
float ingresarNumero()
{
    float numero1;
    printf ("Ingrese un numero: ");
    scanf("%f", &numero1);
    return numero1;
}

float suma(float *numeroUno, float *numeroDos)
{
    int retorno = -1;

    if(retorno)
    {
        return *numeroUno + *numeroDos;
        retorno = 0;
    }
    return retorno;
}
float resta(float *numeroUno, float *numeroDos)
{
    int retorno = -1;

    if(retorno)
    {
        return *numeroUno - *numeroDos;
        retorno = 0;
    }
    return retorno;

}
float division(float *numeroUno, float *numeroDos)
{
    int retorno = -1;
    float resultado;
    if(*numeroDos != 0)
    {
        resultado = *numeroUno / *numeroDos;
        printf("El resultado de la division es: %.2f\n",resultado);
        retorno = 0;
    }
    else
    {
        printf("No es posible dividir por 0\n");
        printf("Vuelva a ingresar el divisor\n");
    }
    return retorno;

}
float multiplicacion(float *numeroUno, float *numeroDos)
{
    int retorno = -1;
    if(retorno)
    {
        return *numeroUno * *numeroDos;
        retorno = 0;
    }
    return retorno;
}

long long int factorialNumUno(float *numeroUno)
{
    float factNum1 = 1;
    float iNum1;
    int retorno = -1;
    if(numeroUno > 0)
    {
        for(iNum1 = 1; iNum1 <= *numeroUno; iNum1++)
        {
            factNum1 = factNum1 * iNum1;
        }
        retorno = 0;
        printf("El factorial del primer numero es: %lf \n",factNum1);
    }
    else
    {
        printf("No es posible obtener factorial de 0 y de numeros negativos\n");
    }
    return retorno;
}
long long int factorialNumDos(float *numeroDos)
{
    float factNum2 = 1;
    float iNum2;
    int retorno = -1;
    if(*numeroDos > 0 )
    {
        for(iNum2 = 1; iNum2<= *numeroDos; iNum2++)
        {
            factNum2 = factNum2 * iNum2;
        }
        retorno = 0;
        printf("El factorial del segundo numero: %lf \n",factNum2);
    }
    else
    {
        printf("No es posible obtener factorial de 0 y de numeros negativos\n");
    }
    return retorno;
}


