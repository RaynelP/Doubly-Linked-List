#ifndef _LISTA_ALUMNOS_H_
#define _LISTA_ALUMNOS_H_

#include <string>
#include <ostream>

using namespace std;

typedef unsigned long Nat;

struct Nodo{
    Nodo(int dato) : _dato(dato), _adelante(nullptr), _atras(nullptr) {}
    Nodo& operator=(const Nodo& aCopiar) {
    }
    Nodo* _adelante;
    Nodo* _atras;
    int _dato;
};

class Lista {
public:

    /**
     * Constructor por defecto de la clase Lista.
     */
    Lista();

    /**
     * Constructor por copia de la clase Lista.
     */
    Lista(const Lista& l);

    /**
     * Destructor de la clase Lista.
     */
    ~Lista();

    /**
     * Operador asignacion
     * @param aCopiar
     * @return
     */
    Lista& operator=(const Lista& aCopiar);

    /**
     * Agrega un elemento al principio de la Lista.
     * @param elem elemento a agregar
     */
    void agregarAdelante(const int& elem);

    /**
     * Agrega un elemento al final de la Lista.
     * @param elem elemento a agregar
     */
    void agregarAtras(const int& elem);

    /**
     * Elimina el i-ésimo elemento de la Lista.
     * @param i posición del elemento a eliminar
     */
    void eliminar(Nat i);

    /**
     * Devuelve la cantidad de elementos que contiene la Lista.
     * @return
     */
    int longitud() const;

    /**
     * Devuelve el elemento en la i-ésima posición de la Lista.
     * @param i posición del elemento a devolver.
     * @return referencia no modificable
     */
    const int& iesimo(Nat i) const;
    /**
     * Devuelve el elemento en la i-ésima posición de la Lista.
     * @param i posición del elemento a devolver.
     * @return referencia modificable
     */
    int& iesimo(Nat i);

    /**
     * Muestra la lista en un ostream
     * formato de salida: [a_0, a_1, a_2, ...]
     * @param o
     */
    void mostrar(ostream& o);

    /**
     * Utiliza el método mostrar(os) para sobrecargar el operador <<
     */
    friend ostream& operator<<(ostream& os, Lista& l) {
        l.mostrar(os);
        return os;
    }

    // -------------------------------------estructura interna-------------------------------------------//
private:

    void destructorRecursivo(Nodo* n);
    Nodo* copiadorRecursivo(Nodo* nodoAcopiar, Nodo** ramaTrasera);
    Nodo* _ramaDelantera;
    Nodo* _ramatrasera;
    int _longitud;
};

void Lista::destructorRecursivo(Nodo *n) {
    if(n != nullptr){
        destructorRecursivo(n->_atras);
        delete n;
    }
    _ramaDelantera = nullptr;
    _ramatrasera = nullptr;
}

Nodo* Lista::copiadorRecursivo(Nodo *nodoACopiar, Nodo** ptrRamaTrasera) {

    if(nodoACopiar == nullptr){
        return nullptr;
    }else{
        Nodo* nodoNuevo = new Nodo(nodoACopiar->_dato);
        Nodo* nodoAnterior = copiadorRecursivo(nodoACopiar->_atras, ptrRamaTrasera);
        if(nodoAnterior != nullptr){
            nodoAnterior->_adelante = nodoNuevo;
            nodoNuevo->_atras = nodoAnterior;
        } else {
            *ptrRamaTrasera = nodoNuevo;
        }
        return nodoNuevo;
    }

}

#include "Lista.hpp"

#endif
