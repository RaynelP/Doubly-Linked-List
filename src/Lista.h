#ifndef _LISTA_ALUMNOS_H_
#define _LISTA_ALUMNOS_H_

#include <string>
#include <ostream>

using namespace std;

typedef unsigned long Nat;



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
    struct Nodo{
        Nodo* adelante_;
        Nodo* atras_;
        int dato_;
    };
    bool esRama(Nodo* n, bool &queramaes);
    void DestructorRecursivo(Nodo* n);
    Nodo* ramaDelantera_;
    Nodo* ramatrasera_;
    int longitud_;
};

bool Lista::esRama(Nodo *n, bool &queramaes) {
    bool ramaTrasera = (n->atras_ == nullptr && n->adelante_ != nullptr);
    bool ramaDelantera = (n->atras_ != nullptr && n->adelante_ == nullptr);
    if (ramaDelantera){
        queramaes = true;
    }else{
        queramaes = false;
    }
    return ramaDelantera || ramaTrasera;
}
#include "Lista.hpp"

#endif
