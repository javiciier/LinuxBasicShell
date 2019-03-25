# Version 1.0 -- Javier Cancela Mato
######################################################################
# nombreVariable = valorVariable
shell = terminal		# variable que se refiere al terminal

# Compilar el programa (añadir nuevas librerías en la primera línea)
# Opción -g permite debuggear programa
compilar : terminal.c auxiliar.c
	gcc -g -Wall shell.c auxiliar.o  -o $(shell)

# Eliminar el ejecutable y ficheros creados por el compilador
limpiar :
	rm *.o shell a.out

# Ejecutar el terminal
ejecutar :
	./$(shell)

# Debuggear el programa (GDB)
debuggear: 
	gdb $(shell)

######################################################################
# CREACIÓN DEL CÓDIGO OBJETO PARA EL COMPILADOR(extensión .o)
auxiliar.o : auxiliar.h auxiliar.c
	gcc -c auxiliar.c

directorios.o : directorios.h directorios.c
	gcc -Wall directorios.c

memoria.o : memoria.h memoria.c
	gcc -Wall memoria.c
