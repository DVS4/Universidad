/* Universidad de La Laguna
*  Escuela Superior de Ingeniería y Tecnología
*  Grado en Ingeniería Informática
*  Asignatura: Algoritmos y estructuras de datos
*  Curso: 2º
*  Práctica 1: Clase número racional
*  Autor: David Villarino Santana
*  Correo: alu0101587615@ull.edu.es
*  Fecha: 10/02/2025
*  Archivo rational_t.hpp: Definición de clase rational_t y sus métodos.
*/

#pragma once

#include <cassert>
#include <cmath>
#include <iostream>

// pauta de estilo [5]
#define EPSILON 1e-6


class rational_t {
public:
    // Constructor por defecto:
    rational_t(const int = 0, const int = 1);
    // Destructor:
    ~rational_t() {}

    // getters
    int get_num() const;
    int get_den() const;

    // setters
    void set_num(const int);
    void set_den(const int);

    double value(void) const;

    // FASE II
    // Métodos para operaciones lógicas:
    bool is_equal(const rational_t &, const double precision = EPSILON) const;
    bool is_greater(const rational_t &, const double precision = EPSILON) const;
    bool is_less(const rational_t &, const double precision = EPSILON) const;
    bool is_equal_zero(const double precision = EPSILON) const;

    // FASE III
    // Métodos para operaciones aritméticas:
    rational_t add(const rational_t&);
    rational_t substract(const rational_t&);
    rational_t multiply(const rational_t&);
    rational_t divide(const rational_t&);
    rational_t factorial();

    // Métodos para la entrada y salida de la clase
    void write(std::ostream & = std::cout) const;
    void read(std::istream & = std::cin);

private:
    // Variables privadas de la clase:
    int num_, den_;
};
