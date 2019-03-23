/*
* Version 1.0
* © Javier Cancela Mato
* Fichero con el código fuente del terminal. Aquí se implementará el main().
*/

/***************************** LIBRERÍAS EXTERNAS *****************************/
/* Funciones auxiliares definidas en ficheros auxiliar.h */
#include <stdio.h>                                                              // Librería de E/S básica
#include <string.h>                                                             // Librería para trabajar con strings
#include <stdlib.h>                                                             // Librería de funciones más comunes
#import "auxiliar.h"                                                            // Cabeceras de funciones auxiliares

/********************************* CONSTANTES *********************************/
// Constantes de TEXTO
#define PROMPT "#): "
#define INVALID_ARG "Argumento no válido.\n"
#define INVALID_COMMAND "Comando no encontrado.\n"
#define INVALID_ARGUMENT "Faltan argumentos: "
#define SHELL_EXIT "Saliendo del terminal..."
// Constantes NUMÉRICAS
#define LONGITUD_COMANDO 1024                                                   // Longitud máxima del comando recibido

/***************************** VARIABLES GLOBALES *****************************/
char* lineaComandos;                                                            // Comando que el usuario escribe en el terminal


/******************************* IMPLEMENTACIÓN *******************************/
int main(int argc, char* argv[]) {
    int ejecutar = 1;                                                           // Variable que controla el bucle de ejecución
    char* comandos[];                                                           // Array que almacena cada palabra de la instrucción recibida
    int numComandos;                                                            // Indica el número de palabras que forman el comando

    while ( !ejecutar ) {
        imprimirPrompt();
        leerLineaComandos(lineaComandos);                                       // Obtiene el comando insertado por el usuario
        if ( strcmp(lineaComandos, "") ) {                                      // Si el usuario ha insertado texto en el terminal
            numComandos = procesarComandos(lineaComandos, comandos);            // Obtiene el número de comandos y los procesa (ejecuta el código asociado a cada comando)
            if ( !strcmp(comandos[0], "salir") )                                // Si usuario inserta comando salir, se cierra el terminal
                ejecutar = 0;
        }
    }

    // Liberación de recursos temporales (si hubiese)


    return 0;
}
