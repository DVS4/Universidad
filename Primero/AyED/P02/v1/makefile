# Variables
MAIN = main_p2.cpp
DEPENDENCIAS = rational_t.cpp
EJECUTABLE = programa
FLAGS = -g -w

all: compilar

compilar:
	echo "Compilando el proyecto"
	g++ $(FLAGS) $(MAIN) $(DEPENDENCIAS) -o $(EJECUTABLE)

clean: remover

remover:
	echo "Eliminando el ejecutable..."
	rm -f $(EJECUTABLE)