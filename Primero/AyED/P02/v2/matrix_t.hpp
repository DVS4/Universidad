/* Universidad de La Laguna
 *  Escuela Superior de Ingeniería y Tecnología
 *  Grado en Ingeniería Informática
 *  Asignatura: Algoritmos y estructuras de datos
 *  Curso: 2º
 *  Práctica 2: Vectores y matrices de números racionales
 *  Autor: David Villarino Santana
 *  Correo: alu0101587615@ull.edu.es
 *  Fecha: 04/03/2025
 *  Archivo matrix_t.hpp: Cabecera de la clase matrix_t.
 */

#pragma once

// Librerías de C++:
#include <cassert>
#include <iostream>

#include "vector_t.hpp"


template <class T>
class matrix_t {
   public:
    matrix_t(const int = 0, const int = 0);
    ~matrix_t();

    void resize(const int, const int);

    // getters
    int get_m(void) const;
    int get_n(void) const;

    // getters-setters
    T& at(const int, const int);
    T& operator()(const int, const int);

    // getters constantes
    const T& at(const int, const int) const;
    const T& operator()(const int, const int) const;

    // operaciones y operadores
    void multiply(const matrix_t<T>&, const matrix_t<T>&);

    void write(std::ostream& = std::cout) const;
    void read(std::istream& = std::cin);

   private:
    int m_, n_;  // m_ filas y n_ columnas
    vector_t<T> v_;

    int pos(const int, const int) const;
};

template <class T>
matrix_t<T>::matrix_t(const int m, const int n) {
    m_ = m;
    n_ = n;
    v_.resize(m_ * n_);
}

template <class T>
matrix_t<T>::~matrix_t() {}

template <class T>
void matrix_t<T>::resize(const int m, const int n) {
    assert(m > 0 && n > 0);
    m_ = m;
    n_ = n;
    v_.resize(m_ * n_);
}

template <class T>
inline int matrix_t<T>::get_m() const {
    return m_;
}

template <class T>
inline int matrix_t<T>::get_n() const {
    return n_;
}

template <class T>
T& matrix_t<T>::at(const int i, const int j) {
    assert(i > 0 && i <= get_m());
    assert(j > 0 && j <= get_n());
    return v_[pos(i, j)];
}

template <class T>
T& matrix_t<T>::operator()(const int i, const int j) {
    return at(i, j);
}

template <class T>
const T& matrix_t<T>::at(const int i, const int j) const {
    assert(i > 0 && i <= get_m());
    assert(j > 0 && j <= get_n());
    return v_[pos(i, j)];
}

template <class T>
const T& matrix_t<T>::operator()(const int i, const int j) const {
    return at(i, j);
}

template <class T>
void matrix_t<T>::write(std::ostream& os) const {
    os << get_m() << "x" << get_n() << std::endl;
    for (int i = 1; i <= get_m(); ++i) {
        for (int j = 1; j <= get_n(); ++j) os << at(i, j) << "\t";
        os << std::endl;
    }
    os << std::endl;
}

template <class T>
void matrix_t<T>::read(std::istream& is) {
    is >> m_ >> n_;
    resize(m_, n_);
    for (int i = 1; i <= get_m(); ++i)
        for (int j = 1; j <= get_n(); ++j) is >> at(i, j);
}

template <class T>
inline int matrix_t<T>::pos(const int i, const int j) const {
    assert(i > 0 && i <= get_m());
    assert(j > 0 && j <= get_n());
    return (i - 1) * get_n() + (j - 1);
}

// FASE III: producto matricial
template <class T>
void matrix_t<T>::multiply(const matrix_t<T>& A, const matrix_t<T>& B) {
    // rellenar código
}
