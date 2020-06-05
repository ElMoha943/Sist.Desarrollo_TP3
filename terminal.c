//LIBRERIAS
#include <xc.h>
#include <pic16f886.h>
#include <stdlib.h>
#include <string.h>
#include "terminal.h"

void RxChar(char c){
    if(c!=0x0D){ //DETECTA EL CARACTER ES UN ENTER
        RxBuffer[j]=c; //RELLENA LA CADERA
        j++;
    }
    else
    {
        strcpy(RxBuffer,RxArray);
        strcpy(RxClear,RxBuffer);
        j=0;
        recibido=1;
    }
}

signed int ParseCommand(void){
    char cadena[10];
    int i=0;
    //SEPARACION DE COMANDO Y ARGUMENTO
    while(RxArray[i]!=':')
    {
        cadena[i]=RxArray[i];
        i++;
    }
    //IDENTIFICACION DE COMANDO
    if(strcmp(cadena,"SETOUT")==0)
        return 1;
    else if (strcmp(cadena,"GETIN")==0)
        return 2;
    else if (strcmp(cadena,"SETREG")==0)
        return 3;
    else if (strcmp(cadena,"GETREG")==0)
        return 4;
    else
        return 0; //COMANDO DESCONOCIDO
}

signed int ParsedData(void){
    int caca=0;
    caca=atoi(RxArray); //EXTRAE EL ARGUMENTO DEL COMANDO
    return caca;
}

void ClearRxArray(void){
    strcpy(RxClear,RxArray); 
}