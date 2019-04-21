/*
* Funciones auxiliares del terminal.
*/

/***************************** LIBRERÍAS EXTERNAS *****************************/
#include <stdio.h>                                                              // Librería de E/S básica
#include <string.h>                                                             // Librería para trabajar con strings
#include <stdlib.h>                                                             // Librería de funciones más comunes
#include "auxiliar.h"                                                           // Cabeceras de funciones auxiliares

/**************************** FUNCIONES AUXILIARES ****************************/
void auxMostrarTextoDia(int dia) {
    /* Recibe el número de la semana correspondiente al día [0, 6] y devuelve un
    string indicando su correspondiente día de la semana. */
    switch(dia) {                                                               // Formato inglés: semana comienza en domingo
        case 0: printf("Domingo"); break;
        case 1: printf("Lunes"); break;
        case 2: printf("Martes"); break;
        case 3: printf("Miércoles"); break;
        case 4: printf("Jueves"); break;
        case 5: printf("Viernes"); break;
        case 6: printf("Sábado"); break;
    }
}

void auxMostrarNombre() {
    /* Muestra el nombre del desarrollador */
    printf("Desarrollador: Javier Cancela Mato");
}

void auxMostrarEmail() {
    /* Muestra el email de contacto del desarrollador */
    printf("javiciier@gmail.com");
}

/****************************** IMPLEMENTACIÓN ********************************/
void funcionFecha(char* comandos[]) {
    /* Imprime por pantalla la fecha actual */
    time_t tiempo;
    struct tm* datos;                                                           // Puntero a struct que almacena datos del tiempo (todos de tipo int)

    if (comandos[1] != NULL)                                                    // Si recibe algún argumento, muestra un error
        printf(INVALID_ARGUMENT);
    else {
        tiempo = time(NULL);                                                    // Inicializa la variable a 0
        datos = localtime(&tiempo);                                             // Obtiene los datos de la fecha actual y los guarda en la estructura.
        
        // Muestra el día de la semana y la fecha
        printf("Hoy es "); auxMostrarTextoDia(datos->tm_wday)); printf(", ");
        printf("%i/%i/%i.\t", datos->tm_mday, datos->tm_mon + 1, 1900 + datos->tm_year);
    }
}

void funcionHora(char* comandos[]) {
    /* Muestra la hora por pantalla y la actualiza */
    time_t tiempo;
    struct tm* info;

    if (comandos[1] != NULL) {                                                  // Recibe arguemntos -> Muestra error
        printf(INVALID_ARG);
    }
    else {
        tiempo = time(NULL);                                                    // Inicializa la variable a 0
        info = localtime(&tiempo);                                              // Obtiene los datos de la fecha actual y los guarda en la estructura.
        int segundo;
        do {
            segundo = info->tm_sec;                                             // Obtiene el segundo actual
            
        } while ();
    }
}

void funcionAutor(char* comandos[]) {
    /* Muestra el nombre y el email de contacto del desarrollador.
    [-e]: muestra el correo electrónico solamente.
    [-n]: solo muestra el nombre. */
    if ( comandos[1] == NULL ) {                                                // No recibe ningún argumento
        auxMostrarNombre();
        auxMostrarEmail();
    }
    else if ( (comandos[1] != NULL) && (comandos[2] == NULL) ) {                // Recibe un único argumento
        switch(comandos[1][0]) {                                                // Comprueba si la opción está escrita correctamente
            case '-':
                switch(comandos[1][1]) {                                        // Comprueba la opción recibida
                    case 'e': auxMostrarEmail(); break;
                    case 'n': auxMostrarNombre(); break;
                }; // fin switch
            break;
            default:
                printf("%s:: Opción debe comenzar con un guión (-).\n", MISSING_ARGUMENT);
        } // fin switch
    }
}
/* -------------------------------------------------------------------------- */
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
   Realiza la separación por espacios, nueva línea (ENTER) o TABULADOR.*/
    int palabras=1;

    if ( (comandos[0] = strtok(texto, " \n\t")) == NULL )                       // Si usuario no escribió nada, al trocear las peticiones obtenemos NULL
        return 0;
    while ( (comandos[palabras] = strtok(NULL, " \n\t")) != NULL )              // Mientras no obtenga NULL, sigue troceando y contando las palabras obtenidas
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
        else if( !strcmp(comandos[0], "fecha") ) {
            funcionFecha(comandos);
        }
        else if ( !strcmp(comandos[0], "autor")) {
            funcionAutor(comandos[]);
        }
        /* FICHEROS Y DIRECTORIOS */

        /* GESTIÓN DE MEMORIA */

        /* COMANDO NO VÁLIDO */
        else
            printf(INVALID_COMMAND);
    } // fin separarComandos
}
