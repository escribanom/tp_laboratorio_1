#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"


int get_Cadena(char *pAux, int limitChar, int retry, char* msg, char* msgError)
{
    int isOk = -1;
    char auxString[limitChar];

    if(pAux != NULL && msg != NULL && msgError != NULL && limitChar > 0 && retry >= 0)
    {
        do
        {
            printf("%s", msg);

            if(getCadena(auxString, limitChar) == 0 && isChar(auxString) == 0)
            {
                strncpy(pAux, auxString, limitChar);
                isOk = 0;
                break;
            }
            else
            {
                printf("%s", msgError);
            }
            retry--;

        }
        while(retry>=0);
    }

    return isOk;
}

int getCadena(char* pAux, int limitChar)
{
    char auxString[4000];
    int isOk = -1;

    if (pAux != NULL && limitChar > 0)
    {
        fflush(stdin);
        fgets(auxString,sizeof(auxString),stdin);

        if (auxString[strlen(auxString)-1]=='\n')
        {
            auxString[strlen(auxString)-1]='\0';
        }
        if(strlen(auxString)<= limitChar)
        {
            strncpy(pAux, auxString, limitChar);
            isOk=0;
        }
    }

    return isOk;
}

int isChar(char str[])
{

    int isOk = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            isOk = -1;
        }
    }

    return isOk;

}

int get_Entero(int* pEntero, int retry, char* msg, char*msgError, int min, int max)
{
    int isOk = -1;
    int auxInt;

    if(pEntero != NULL && msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s", msg);

            if(getInt(&auxInt) == 0 && auxInt >= min && auxInt <= max)
            {
                *pEntero = auxInt;
                isOk = 0;
                break;
            }
            else
            {
                printf("%s", msgError);
            }
        }
        while(retry >= 0);
    }
    return isOk;
}

int getInt(int* pAux)
{
    char auxString[400];
    int isOk = -1;

    if(getCadena(auxString, sizeof(auxString)) == 0 && isInt(auxString ) == 0)
    {
        *pAux = atoi(auxString);
        isOk = 0;
    }
    return isOk;
}

int isInt(char *pAux)
{
    int isOk = -1;
    int i = 0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) < '0' || *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }
    while (i < stringLong);

    if(i == stringLong)
    {
        isOk = 0;
    }

    return isOk;
}

int get_Flotante(float* pFloat, int retry, char* msg, char*msgError, float min, float max)
{
    int isOk = -1;
    float auxFloat;

    if(pFloat != NULL&& msg != NULL && msgError != NULL && min <= max && retry >= 0)
    {
        do
        {
            retry--;
            printf("%s",msg);
            if(getFloat(&auxFloat) == 0 && auxFloat >= min && auxFloat <= max)
            {
                *pFloat= auxFloat;
                isOk = 0;
                break;
            }
            else
            {
                printf("%s",msgError);
            }
        }
        while(retry >= 0);
    }
    return isOk;
}

int getFloat(float*pAux)
{
    char auxString[200];
    int isOk =-1;

    if(getCadena(auxString,200) == 0 && isFloat(auxString) == 0)
    {
        *pAux = atof(auxString);
        isOk = 0;
    }
    return isOk;
}

int isFloat(char* pAux)
{
    int isOk = -1;
    int i = 0;
    int dotCount=0;
    int stringLong = strlen(pAux);

    do
    {
        if(*(pAux + i) == '.')
        {
            dotCount++;
            if(dotCount == 2)
            {
                break;
            }
        }
        else if(*(pAux + i) < '0'|| *(pAux + i) > '9')
        {
            break;
        }

        i++;

    }while (i < stringLong);

    if(i == stringLong)
    {
        isOk = 0;
    }
    return isOk;
}

int normalizeStr(char* str)
{
    int isOk = -1;
    int i = 0;

    if(str != NULL)
    {
        strLwr(str);
        str[0] = toupper(str[0]);

        while(str[i] != '\0')
        {
            if(str[i] == ' ')
            {
                str[i + 1] = toupper(str[i + 1]);
                isOk = 0;
            }
            i++;
        }
    }
    return isOk;
}

int strLwr(char* str)
{
    int isOk = -1;
    int i = 0;

    if(str != NULL)
    {
        while(str[i] != '\0')
        {
            str[i] = tolower(str[i]);
            i++;
        }
        isOk = 0;
    }
    return isOk;
}

int validarNombre(char* cadena, int longitud)
{
    int retorno = 0;
    if(cadena != NULL && longitud > 0)
    {
        for(int i = 0; cadena[i] != '\0' && i < longitud; i++)
        {
            if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z'))
            {
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s 1",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}
int isValidName(char *cadena)
{
    int retorno = 1;
    int i;
    for(i=0; cadena[i] != '\0'; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a'))
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}
int getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,min,max,&reintentos,bufferStr)) //==0
            {
                if(isValidName(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,max);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",msgError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

