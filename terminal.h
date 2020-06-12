/* 
 * File:   terminal.h
 * Author: valen
 *
 * Created on 5 de junio de 2020, 16:01
 */

#ifndef TERMINAL_H
#define	TERMINAL_H

//VARIABLES
char RxArray[10], RxBuffer[10], RxClear[10];
int j=0, recibido=0;

//FUNCIONES
void RxChar(char c);
signed int ParseCommand(void);
signed int ParsedData(void);
void ClearRxArray(void);
void EnviarTexto(char palabra[]);

#endif	/* TERMINAL_H */

