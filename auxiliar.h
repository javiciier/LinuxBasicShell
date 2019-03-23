/*
* Funciones auxiliares del terminal.
*/
/***************************** LIBRERÍAS EXTERNAS *****************************/
/* Código implementado en fichero auxiliar.c */

/**************************** FUNCIONES AUXILIARES ****************************/


/********************************* CABECERAS **********************************/
void imprimirPrompt();
void leerLineaComandos(char* comando);
int separarComandos(char* texto, char* comandos[]);
void procesarComandos(char* texto, char* comandos[]);
