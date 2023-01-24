#include "Lista.h"

Lista::Lista() : _longitud(0), _ramaDelantera(nullptr), _ramatrasera(nullptr){}

Lista::Lista(const Lista& l) : Lista(){
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista(){
    Nodo* p = _ramaDelantera;
    destructorRecursivo(p);
}

Lista& Lista::operator=(const Lista& aCopiar) {
     Nodo** ptrRamaTrasera = &_ramatrasera;
     _ramaDelantera = copiadorRecursivo(aCopiar._ramaDelantera, ptrRamaTrasera);
     _longitud = aCopiar._longitud;
     return *this;
}

void Lista::agregarAdelante(const int& elem) {
    Nodo* newNodo = new Nodo(elem);
    if (_longitud == 0){
        _ramatrasera = newNodo;
    }else{
        newNodo->_atras = _ramaDelantera;
        _ramaDelantera->_adelante = newNodo;
    }
    _ramaDelantera = newNodo;
    _longitud++;
}

void Lista::agregarAtras(const int& elem) {
    Nodo *nodo = new Nodo(elem);
    if (_longitud == 0) {
        _ramaDelantera = nodo;
    } else {
        nodo->_adelante = _ramatrasera;
        _ramatrasera->_atras = nodo;
    }
    _ramatrasera = nodo;
    _longitud++;
}

void Lista::eliminar(Nat i){

    Nodo* ptrNodo = _ramaDelantera;
    for (int j = 0; j < i; ++j)
        ptrNodo = ptrNodo->_atras;

    Nodo* anterior = ptrNodo->_atras;
    Nodo* proximo = ptrNodo->_adelante;

    if(anterior != nullptr) {
        anterior->_adelante = proximo;
    }
    if(proximo != nullptr){
        proximo->_atras = anterior;
    }

    if(i == 0) _ramaDelantera =  anterior;
    if(i == _longitud - 1) _ramatrasera =  proximo;

    _longitud--;
    delete(ptrNodo);
}

int Lista::longitud() const{
    return _longitud;
}

const int& Lista::iesimo(Nat i) const{
    Nodo* ptrNodo = _ramaDelantera;
    for (int j = 0; j < i; ++j)
        ptrNodo = ptrNodo->_atras;
    return ptrNodo->_dato;
}

int& Lista::iesimo(Nat i){
    Nodo* ptrNodo = _ramaDelantera;
    for (int j = 0; j < i; ++j)
        ptrNodo = ptrNodo->_atras;

    return ptrNodo->_dato;
}

void Lista::mostrar(ostream& o) {
    Nodo* ptrNodo = _ramaDelantera;
    o << "[";
    for (int j = 0; j < _longitud; ++j){
        o << ptrNodo->_dato;
        if(j != _longitud - 1) o << ", ";
        ptrNodo = ptrNodo->_atras;
    }
    o << "]" << endl;
}