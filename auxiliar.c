/*
* Funciones auxiliares del terminal.
*/

/***************************** LIBRERÍAS EXTERNAS *****************************/
#include <stdio.h>                                                              // Librería de E/S básica
#include <string.h>                                                             // Librería para trabajar con strings
#include <stdlib.h>                                                             // Librería de funciones más comunes
#include "auxiliar.h"                                                           // Cabeceras de funciones auxiliares

/**************************** FUNCIONES AUXILIARES ****************************/


/****************************** IMPLEMENTACIÓN ********************************/
void imprimirPrompt() {
/* Muestra el símbolo del terminal después del cual puede escribir el usuario. */
    printf(PROMPT);
}


void leerLineaComandos(char* comando) {
/* Almacena los comandos que el usuario escribe en el terminal. */
    gets(texto);
}


int separarComandos(char* texto, char* comandos[]) {
/* Recibe el comando que el usuario ha escrito y obtiene los comandos atómicos.
* Realiza la separación por espacios, nueva línea (ENTER) o TABULADOR. */
    int palabras=1;

    if ( (comandos[0] = strtok(texto, " \n\t")) == NULL )                       // Si usuario no escribió nada, al trocear las peticiones obtenemos NULL
        return 0;
    while ( (comandos[palabras] = strtok(NULL, " \n\t")) != NULL )                 // Mientras no obtenga NULL, sigue troceando y contando las palabras obtenidas
        palabras++;

    return palabras;
}

void procesarComandos(char* texto, char* comandos[]) {
/*  */
    int numArgumentos;
    if ( numArgumentos = separarComandos(texto, comandos) ) {                   // Comprueba si se ha escrito algún comando (numArgs != 0)
        /* COMANDOS BÁSICOS DEL TERMINAL */
        if ( !strcmp(comandos[0], "salir") ) {                                  // Cierre del terminal
            printf(SHELL_EXIT);
            exit(0);
        }
        /* FICHEROS Y DIRECTORIOS */

        /* GESTIÓN DE MEMORIA */

        /* COMANDO NO VÁLIDO */
        else
            printf(INVALID_COMMAND);
    } // fin separarComandos
}
