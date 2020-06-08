# Sist.Desarrollo_TP3
UART Avanzado

# Temas teóricos a desarrollar:
- Principio de funcionamiento de la UART. Protocolo RS232. Registros de control del
microcontrolador RCSTA, TXSTA, RCREG, TXREG. Interrupciones por UART
- Procesamiento de arreglos de caracteres. Búsqueda de un carácter específico. Función
atoi(...)
- Especificación del formato de comandos y datos

# Objetivos:
- Implementar una librería (Terminal.h y Terminal.c) que implemente las funciones
necesarias para enviar y recibir cadenas de caracteres por puerto serie.
- void RxChar(char c)
Se utiliza ante una interrupción por recepción en el puerto serie y carga el carácter
recibido en un buffer de entrada. Dicho buffer es un array (denominado RxBuffer)
definido dentro de la librería y se utiliza para acumular los caracteres recibidos del
terminal remoto. En caso de recibir un carácter ENTER (ascii 0x0D) debe hacer una
copia del buffer en otro array (RxArray), también propio de la librería e inicializar el
buffer para esperar nuevos caracteres.
- signed int ParseCommand(void)
Analiza la cadena de caracteres recibida en RxArray y devuelve un valor representativo
del comando reconocido según la siguiente tabla de comandos.
- signed int ParsedData(void)
Analiza la cadena de caracteres recibida en RxArray y devuelve el argumento numérico
del comando recibido como convertido a tipo numérico. Esta función hace uso de la
función atoi(...) de la librería estándar de C stdlib.h
- void ClearRxArray(void)
Limpia el array de comandos y datos RxArray. Posteriormente a ejecutar esta función,
un llamado a cualquiera de las funciones anteriores devolvería el valor -1 indicando
que no hay comandos o datos reconocidos.

# Comandos y rango de argumentos
El microcontrolador debe enviar al terminal remoto el prompt “SDD>” para indicar al usuario
que se encuentra listo para recibir comandos desde el terminal remoto. Los comandos de
terminal de escritura poseen la siguiente sintaxis

<b>COMANDO:ARGUMENTO</b>

En caso de que el comando sea reconocido por el microcontrolador, la respuesta debe ser

<b>OK</b>

Si el comando es reconocido pero el argumento esta fuera del rango especificado en la tabal
de comandos, el microcontrolador deberá devolver al terminal el mensaje

<b>OUT OF RANGE</b>

La sitntaxis para los comandos de lectura es simplemente el nombre del comando deseado y la
respuesta del microcontrolador al terminal deberá ser el valor solicitado, por ejemplo, si el
valor de setpoint actual es 500, el formato de comando de lectura y respuesta será:

SDD> GETSETPOINT (Comando intrudicido por el usuario)
500 (respuesta enviada por el microcontrolador)
SSD> (Prompt enviado por el microcontrolador a la espera de nuevo
comando)

#  Tabla de comandos y rango de argumentos

|  | CMD # | MIN | MAX |
| ------------- | ------------- | ------------- | ------------- |
| SETOUT | 1 | 0 | 7 |
| GETIN | 2 | 0 | 4 |
| SETREG | 3 | 0 | 10 |
| GETREG | 4 | 0 | 10 |
| CMD NO RECONOCIDO| 0 | - | - |
