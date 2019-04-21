/*
* Funciones auxiliares del terminal.
*/
/***************************** LIBRERÍAS EXTERNAS *****************************/
/* Código implementado en fichero auxiliar.c */
#include <time.h>																// Librería para trabajar con información temporal

/**************************** FUNCIONES AUXILIARES ****************************/
void auxMostrarTextoDia(int dia);
void auxMostrarNombre();
void auxMostrarEmail();

/********************************* CABECERAS **********************************/
void funcionFecha(char* comandos[]);
void funcionHora(char* comandos[]);
void funcionAutor(char* comandos[]);
/* -------------------------------------------------------------------------- */
void imprimirPrompt();
void leerLineaComandos(char* comando);
int separarComandos(char* texto, char* comandos[]);
void procesarComandos(char* texto, char* comandos[]);
