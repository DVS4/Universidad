/* Universidad de La Laguna
 *  Escuela Superior de Ingeniería y Tecnología
 *  Grado en Ingeniería Informática
 *  Asignatura: Algoritmos y estructuras de datos
 *  Curso: 2º
 *  Práctica 2: Vectores y matrices de números racionales
 *  Autor: David Villarino Santana
 *  Correo: alu0101587615@ull.edu.es
 *  Fecha: 04/03/2025
 *  Archivo vector_t.hpp: Cabecera de la clase vector_t.
 */

#pragma once

// Librerías de C++:
#include <cassert>
#include <iostream>

template <class T>
class vector_t {
   public:
    vector_t(const int = 0);
    ~vector_t();

    void resize(const int);

    // getters
    T get_val(const int) const;
    int get_size(void) const;

    // setters
    void set_val(const int, const T);

    // getters-setters
    T& at(const int);
    T& operator[](const int);

    // getters constantes
    const T& at(const int) const;
    const T& operator[](const int) const;

    void write(std::ostream& = std::cout) const;
    void read(std::istream& = std::cin);

   private:
    T* v_;
    int sz_;

    void build(void);
    void destroy(void);
};

template <class T>
vector_t<T>::vector_t(const int n) {
    sz_ = n;
    build();
}

template <class T>
vector_t<T>::~vector_t() {
    destroy();
}

template <class T>
void vector_t<T>::build() {
    v_ = NULL;
    if (sz_ != 0) {
        v_ = new T[sz_];
        assert(v_ != NULL);
    }
}

template <class T>
void vector_t<T>::destroy() {
    if (v_ != NULL) {
        delete[] v_;
        v_ = NULL;
    }
    sz_ = 0;
}

template <class T>
void vector_t<T>::resize(const int n) {
    destroy();
    sz_ = n;
    build();
}

template <class T>
inline T vector_t<T>::get_val(const int i) const {
    assert(i >= 0 && i < get_size());
    return v_[i];
}

template <class T>
inline int vector_t<T>::get_size() const {
    return sz_;
}

template <class T>
void vector_t<T>::set_val(const int i, const T d) {
    assert(i >= 0 && i < get_size());
    v_[i] = d;
}

template <class T>
T& vector_t<T>::at(const int i) {
    assert(i >= 0 && i < get_size());
    return v_[i];
}

template <class T>
T& vector_t<T>::operator[](const int i) {
    return at(i);
}

template <class T>
const T& vector_t<T>::at(const int i) const {
    assert(i >= 0 && i < get_size());
    return v_[i];
}

template <class T>
const T& vector_t<T>::operator[](const int i) const {
    return at(i);
}

template <class T>
void vector_t<T>::write(std::ostream& os) const {
    os << get_size() << ":\t";
    for (int i = 0; i < get_size(); i++) os << at(i) << "\t";
    os << std::endl;
}

template <class T>
void vector_t<T>::read(std::istream& is) {
    is >> sz_;
    resize(sz_);
    for (int i = 0; i < sz_; ++i) is >> at(i);
}

// FASE II: producto escalar
template <class T>
T scal_prod(const vector_t<T>& v, const vector_t<T>& w) {
    // producto escalar de dos vectores: v * w = v1*w1 + v2*w2 + ... + vn*wn || v.size() == w.size()
    if (v.get_size() != w.get_size()) {
        std::cerr << "Error: los vectores no tienen la misma dimensión." << std::endl;
        return 0;
    } else {
        T result = 0;
        for (int i = 0; i < v.get_size(); i++) {
            result += v[i] * w[i];
        }
        return result;
    }
}

double scal_prod(const vector_t<rational_t>& v, const vector_t<rational_t>& w) {
    // producto escalar de dos vectores: v * w = v1*w1 + v2*w2 + ... + vn*wn || v.size() == w.size()
    if (v.get_size() != w.get_size()) {
        std::cerr << "Error: los vectores no tienen la misma dimensión." << std::endl;
        return 0;
    } else {
        double result = 0;
        for (int i = 0; i < v.get_size(); i++) {
            result += v[i].value() * w[i].value();
        }
        return result;
    }
}
