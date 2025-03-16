/* Universidad de La Laguna
*  Escuela Superior de Ingeniería y Tecnología
*  Grado en Ingeniería Informática
*  Asignatura: Algoritmos y estructuras de datos
*  Curso: 2º
*  Práctica 1: Clase número racional
*  Autor: David Villarino Santana
*  Correo: alu0101587615@ull.edu.es
*  Fecha: 10/02/2025
*  Archivo rational_t.cpp: Implementación de "rational_t.hpp".
*/

#include "rational_t.hpp"

// Constructor por parametros:
rational_t::rational_t(const int n, const int d) {
    assert(d != 0);
    num_ = n, den_ = d;
}


// getters:
int rational_t::get_num() const { return num_; }

int rational_t::get_den() const { return den_; }

// setters:
void rational_t::set_num(const int n) { num_ = n; }

void rational_t::set_den(const int d) {
    assert(d != 0);
    den_ = d;
}

// método que retorna el resultado double desde un tipo rational_t de la clase:
double rational_t::value() const { return double(get_num()) / get_den(); }


// métodos lógicos de la clase rational_t:

    // comparaciones:
    bool rational_t::is_equal(const rational_t& r, const double precision) const {
        return (std::fabs(value() - r.value()) < precision);
    }

    bool rational_t::is_greater(const rational_t& r, const double precision) const {
        return ((value() - r.value()) > precision);
    }

    bool rational_t::is_less(const rational_t& r, const double precision) const {
        return (((value() - r.value()) < -precision) && (((r.value() - value()) > precision)));
    }

    // operaciones:
    rational_t rational_t::add(const rational_t& r) {
        return rational_t(value() + r.value());
    }

    rational_t rational_t::substract(const rational_t& r) {
        return (value() - r.value());
    }

    rational_t rational_t::multiply(const rational_t& r) {
        return (value() * r.value());
    }

    rational_t rational_t::divide(const rational_t& r) {
        double numerador = (get_num() * r.get_den());  // <resultado del numerador>
        double divisor =   (r.get_num() * get_den());  // <resultado del denominador>

        rational_t resultado = rational_t(numerador,divisor); // Llamo a la clase y construyo un objeto rational_t con el numerador y el divisor
        return resultado;
    }

// E/S
void rational_t::write(std::ostream &os) const {
  os << get_num() << "/" << get_den() << "=" << value() << std::endl;
}


void rational_t::read(std::istream &is) {
  std::cout << "Numerador? ";
  is >> num_;
  std::cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
