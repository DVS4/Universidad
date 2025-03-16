all: compilar

compilar:
	echo "Compilando el proyecto..."
	chmod +x main_p2.cpp rational_t.cpp
	g++ -g -w rational_t.cpp main_p2.cpp -o main_p2
	chmod +x main_p2.exe main_p2

clean: remover

remover:
	echo "Eliminando el ejecutable..."
	rm -r main_p2
