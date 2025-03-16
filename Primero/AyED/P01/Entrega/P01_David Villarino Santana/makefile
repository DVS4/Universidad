all: compilar

compilar:
	echo "Compilando el proyecto..."
	chmod +x main_rational_t.cpp rational_t.cpp rational_t.hpp
	g++ -g -w rational_t.cpp main_rational_t.cpp -o main_rational_t
	chmod +x main_rational_t.exe main_rational_t

clean: remover

remover:
	echo "Eliminando el ejecutable..."
	rm -r main_rational_t
