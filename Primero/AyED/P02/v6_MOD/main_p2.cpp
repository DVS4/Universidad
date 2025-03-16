/* Universidad de La Laguna
*  Escuela Superior de Ingeniería y Tecnología
*  Grado en Ingeniería Informática
*  Asignatura: Algoritmos y estructuras de datos
*  Curso: 2º
*  Práctica 2: Vectores y matrices de números racionales
*  Autor: David Villarino Santana
*  Correo: alu0101587615@ull.edu.es
*  Fecha: 04/03/2025
*  Archivo main_p2.cpp: programa cliente.
*/

// Librerías de C++:
#include <iostream>
#include <cmath>

// Cabeceras de las clases de la práctica:
#include "rational_t.hpp"
#include "vector_t.hpp"
#include "matrix_t.hpp"


int main() {
	rational_t a(1, 2), b(3);

	// FASE I (OK)
	std::cout << "a + b: ";
	(a+b).write();

	std::cout << "b - a: ";
	(b-a).write();

	std::cout << "a * b: ";
	(a*b).write();
	
	std::cout << "a / b: ";
	(a/b).write();
	
	std::cout << std::endl;
	
	// FASE II (OK)
	vector_t<double> v, w;
	v.read(), v.write();
	w.read(), w.write();
	
	std::cout << "Producto escalar de vector_t<double>: " << scal_prod(v, w) <<	std::endl << std::endl;
	
	vector_t<rational_t> x, y;
	x.read(), x.write();
	y.read(), y.write();
	
	std::cout << "Producto escalar de vector_t<rational_t>: " << scal_prod(x, y) << std::endl << std::endl;

	// FASE III
	matrix_t<double> A, B, C;
	A.read(), A.write();
	B.read(), B.write();
	
	C.multiply(A, B);
	std::cout << "Multiplicación de matrices A y B: " << std::endl;
	C.write();

	// MODIFICACION
	matrix_t<double> D;
	D.read(), D.write();
	
	std::cout << std::endl << "La suma de la diagonal secundaria es: " << D.SumaDiagonalSecundaria() << std::endl;

	// Testeo 1
	matrix_t<double> E;
	E.read(), E.write();

	std::cout << std::endl << "La suma de la diagonal secundaria es: " << E.SumaDiagonalSecundaria() << std::endl;


	// Testeo 2 (Debe dar error con el assert, ya que la matriz no es cuadrada)
	/*matrix_t<double> F;
	F.read(), F.write();

	std::cout << std::endl << "La suma de la diagonal secundaria es: " << F.SumaDiagonalSecundaria() << std::endl;
*/
	return 0;
}