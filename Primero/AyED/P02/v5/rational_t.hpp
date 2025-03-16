/* Universidad de La Laguna
 *  Escuela Superior de Ingeniería y Tecnología
 *  Grado en Ingeniería Informática
 *  Asignatura: Algoritmos y estructuras de datos
 *  Curso: 2º
 *  Práctica 2: Vectores y matrices de números racionales
 *  Autor: David Villarino Santana
 *  Correo: alu0101587615@ull.edu.es
 *  Fecha: 04/03/2025
 *  Archivo rational_t.hpp: Cabecera de la clase rational_t.
 */
//
#pragma once

// Librerías de C++:
#include <cassert>
#include <cmath>
#include <iostream>

// Constantes:
#define EPSILON 1e-6

class rational_t {
	public:
		rational_t(const int = 0, const int = 1);		// rational_t a(denominador/divisor)
		~rational_t() {}

		// getters
		int get_num() const;
		int get_den() const;

		// setters
		void set_num(const int);
		void set_den(const int);

		double value(void) const;
		rational_t opposite(void) const;
		rational_t reciprocal(void) const;

		bool is_equal(const rational_t&, const double precision = EPSILON) const;
		bool is_greater(const rational_t&, const double precision = EPSILON) const;
		bool is_less(const rational_t&, const double precision = EPSILON) const;

		rational_t add(const rational_t&) const;
		rational_t substract(const rational_t&) const;
		rational_t multiply(const rational_t&) const;
		rational_t divide(const rational_t&) const;

		void write(std::ostream& os = std::cout) const;
		void read(std::istream& is = std::cin);

	private:
		int num_, den_;
};

// sobrecarga de los operadores de E/S
std::ostream& operator<<(std::ostream& os, const rational_t&);
std::istream& operator>>(std::istream& is, rational_t&);

// FASE I: operadores
rational_t operator+(const rational_t&, const rational_t&);
rational_t operator-(const rational_t&, const rational_t&);
rational_t operator*(const rational_t&, const rational_t&);
rational_t operator/(const rational_t&, const rational_t&);
