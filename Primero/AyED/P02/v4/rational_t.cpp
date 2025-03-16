/* Universidad de La Laguna
*  Escuela Superior de Ingeniería y Tecnología
*  Grado en Ingeniería Informática
*  Asignatura: Algoritmos y estructuras de datos
*  Curso: 2º
*  Práctica 2: Vectores y matrices de números racionales
*  Autor: David Villarino Santana
*  Correo: alu0101587615@ull.edu.es
*  Fecha: 04/03/2025
*  Archivo rational_t.cpp: Definicion de clase rational_t.
*/

// Cabecera:
#include "rational_t.hpp"

rational_t::rational_t(const int n, const int d) {
    assert(d != 0);
    num_ = n, den_ = d;
}



inline int rational_t::get_num() const { return num_; }

inline int rational_t::get_den() const { return den_; }

void rational_t::set_num(const int n) { num_ = n; }

void rational_t::set_den(const int d) {
    assert(d != 0);
    den_ = d;
}

inline double rational_t::value() const { return double(get_num()) / get_den(); }

rational_t rational_t::opposite() const {
    return rational_t((-1) * get_num(), get_den());
}

rational_t rational_t::reciprocal() const { return rational_t(get_den(), get_num()); }

// comparaciones
bool rational_t::is_equal(const rational_t& r, const double precision) const {
    return fabs(value() - r.value()) < precision;
}

bool rational_t::is_greater(const rational_t& r, const double precision) const {
    return (value() - r.value()) > precision;
}

bool rational_t::is_less(const rational_t& r, const double precision) const {
    return r.is_greater(*this, precision);
}

// operaciones
rational_t rational_t::add(const rational_t& r) const {
    return rational_t(get_num() * r.get_den() + get_den() * r.get_num(), 
                      get_den() * r.get_den());
}

rational_t rational_t::substract(const rational_t& r) const {
    return add(r.opposite()); 
}

rational_t rational_t::multiply(const rational_t& r) const {
    return rational_t(get_num() * r.get_num(), get_den() * r.get_den());
}

rational_t rational_t::divide(const rational_t& r) const {
    return multiply(r.reciprocal());
}

// FASE I: operadores (Para)
rational_t operator+(const rational_t& a, const rational_t& b) {
    return a.add(b);
}

rational_t operator-(const rational_t& a, const rational_t& b) {
    return a.substract(b);
}

rational_t operator*(const rational_t& a, const rational_t& b) {
    return a.multiply(b);
}

rational_t operator/(const rational_t& a, const rational_t& b) {
    return a.divide(b);
}

// E/S
void rational_t::write(std::ostream& os) const {
    os << get_num() << "/" << get_den() << "=" << value() << std::endl;
}

void rational_t::read(std::istream& is) {
    is >> num_ >> den_;
    assert(den_ != 0);
}

std::ostream& operator<<(std::ostream& os, const rational_t& r) {
    r.write(os);
    return os;
}

std::istream& operator>>(std::istream& is, rational_t& r) {
    r.read(is);
    return is;
}