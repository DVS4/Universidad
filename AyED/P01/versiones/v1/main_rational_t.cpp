/* Universidad de La Laguna
*  Escuela Superior de Ingeniería y Tecnología
*  Grado en Ingeniería Informática
*  Asignatura: Algoritmos y estructuras de datos
*  Curso: 2º
*  Práctica 1: Clase número racional
*  Autor: David Villarino Santana
*  Correo: alu0101587615@ull.edu.es
*  Fecha: 10/02/2025
*  Archivo main_rational_t.cpp: programa cliente.
*/

// librerías:
#include <cmath>
#include <iostream>

// ficheros de cabecera:
#include "rational_t.hpp"

int main() {
  // variables tipo rational_t:
  rational_t a(1, 2), b(3), c;

  std::cout << "a.value()= " << a.value() << std::endl;
  std::cout << "b.value()= " << b.value() << std::endl;
  std::cout << "c.value()= " << c.value() << std::endl;

  std::cout << "a: ";
  a.write();
  std::cout << "b: ";
  b.write();

  c.read();
  std::cout << "c: ";
  c.write();

  // FASE II:
  rational_t x(1, 3), y(2, 3);
  x.write();
  y.write();
  std::cout << "x == y? " << (x.is_equal(y) ? "true" : "false") << std::endl;
  std::cout << "x < y? " << (x.is_greater(y) ? "true" : "false") << std::endl;
  std::cout << "x > y? " << (x.is_less(y) ? "true" : "false") << std::endl;

  // FASE III
  // cout << "a + b: ";
  // a.add(b).write();

  // cout << "b - a: ";
  // b.substract(a).write();

  // cout << "a * b: ";
  // a.multiply(b).write();

  // cout << "a / b: ";
  // a.divide(b).write();

  return 0;
}