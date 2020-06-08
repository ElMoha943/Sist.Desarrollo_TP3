//CONFIGURATION BITS
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = OFF
#pragma config CP = OFF
#pragma config CPD = OFF
#pragma config BOREN = OFF
#pragma config IESO = ON
#pragma config FCMEN = ON
#pragma config LVP = OFF
#pragma config BOR4V = BOR40V
#pragma config WRT = OFF 

//LIBRERIAS
#include <xc.h>
#include <pic16f886.h>
#include "terminal.h"

//DEFINES

//COMIENZO DEL PROGRAMA
void main(void) {
    //DECLARACION DE VARIABLES
    
    //CONFIGURACION DE PUERTOS
    ANSEL=0;
    ANSELH=0;
    TRISB=0;
    
    //CONFIGURACION DE UWART
    TRISCbits.TRISC6=0;
    BRG16=0;
    BRGH=1;
    SPBRG=25;
    TXSTAbits.TXEN=1;
    RCSTAbits.CREN=1;
    RCSTAbits.SPEN=1;
    
    EnviarTexto("SSD>");
    while(1)
    {
        //SI RECIBE INFORMACION
        if(RCIF)
        {
            RxChar(RCREG);
        }
        if (recibido==1){
            switch(ParseCommand())
            {
                case 1://SETOUT
                    if(ParsedData()<7&&ParsedData()>0) //VALIDA NUMERO DE PARAMETROS.
                        EnviarTexto("OK");
                    else
                        EnviarTexto("OUT OF RANGE");
                    break;
                case 2://GETIN
                    if(ParsedData()<4&&ParsedData()>0)
                        EnviarTexto("OK");
                    else
                        EnviarTexto("OUT OF RANGE");
                    break;
                case 3://SETREG
                    if(ParsedData()<10&&ParsedData()>0)
                        EnviarTexto("OK");
                    else
                        EnviarTexto("OUT OF RANGE");
                    break;
                case 4://GETREG
                    if(ParsedData()<10&&ParsedData()>0)
                        EnviarTexto("OK");
                    else
                        EnviarTexto("OUT OF RANGE");
                    break;
                default:
                    EnviarTexto("CMD NOT FOUND");
                    break;
            }
            ClearRxArray();
            recibido=0;
            EnviarTexto("SSD>");
        }
    }
}