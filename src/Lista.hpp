#include "Lista.h"
Lista::Lista() : longitud_(0), ramaDelantera_(nullptr), ramatrasera_(nullptr){}

Lista::Lista(const Lista& l) : Lista(){
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista(){
    Nodo* p = ramaDelantera_;
    DestructorRecursivo(p);
}
void Lista::DestructorRecursivo(Nodo *n) {
    if(n != nullptr){
        DestructorRecursivo(n->atras_);
        delete n;
    }
    ramaDelantera_ = nullptr;
    ramatrasera_ = nullptr;
}

Lista& Lista::operator=(const Lista& aCopiar) {
    DestructorRecursivo(ramaDelantera_);
	Nodo* p = aCopiar.ramaDelantera_;
    if(aCopiar.longitud() == 0){
        ramaDelantera_ = nullptr;
        ramatrasera_ = nullptr;
        longitud_ = 0;
        return *this;
    }else{
        Nodo* delantero;
        while (p != nullptr){
            if (p == aCopiar.ramaDelantera_){
                Nodo* q = new Nodo();
                q->dato_ = p->dato_;
                ramaDelantera_ = q;
                ramatrasera_ = q;
                delantero = ramaDelantera_;
            }else{
                Nodo* q = new Nodo();
                q->dato_ = p->dato_;
                q->adelante_ = delantero;
                delantero->atras_ = q;
                ramatrasera_ = q;
                delantero = q;
            }
            p = p->atras_;
        }
        longitud_ = aCopiar.longitud();
        return *this;
    }
}

void Lista::agregarAdelante(const int& elem) {
    if (longitud_ == 0){
        Nodo* nodo = new Nodo();
        nodo->dato_ = elem;
        ramatrasera_ = nodo;
        ramaDelantera_ = nodo;
        longitud_++;
    }else{
        Nodo* nodo = new Nodo();
        nodo->dato_ = elem;
        nodo->atras_ = ramaDelantera_;
        ramaDelantera_->adelante_ = nodo;
        ramaDelantera_ = nodo;
        longitud_++;
    }
}

void Lista::agregarAtras(const int& elem) {
    if (longitud_ == 0){
        Nodo* nodo = new Nodo();
        nodo->dato_ = elem;
        ramatrasera_ = nodo;
        ramaDelantera_ = nodo;
        longitud_++;
    }else{
        Nodo* nodo = new Nodo();
        nodo->dato_ = elem;
        nodo->adelante_ = ramatrasera_;
        ramatrasera_->atras_ = nodo;
        ramatrasera_ = nodo;
        longitud_++;
    }
}

void Lista::eliminar(Nat i){
    Nodo* p = ramaDelantera_; //Buscar el nodo a eliminar
    int j = 0;
    while (j != i){
        p = p->atras_;
        j++;
    }
    if (longitud_ == 1){      //si es el unico nodo
        delete p;
        ramaDelantera_ = nullptr;
        ramatrasera_ = nullptr;
        longitud_--;
    }else{
        bool ramaDelantera;
        if(esRama(p, ramaDelantera)){    //si es una de las ramas
            if (ramaDelantera){
                ramaDelantera_ = p->atras_;
                ramaDelantera_->adelante_ = nullptr;
                delete p;
                longitud_--;
            }else{
                ramatrasera_ = p->adelante_;
                ramatrasera_->atras_ = nullptr;
                delete p;
                longitud_--;
            }
        }else {
            (p->adelante_)->atras_ = p->atras_;
            (p->atras_)->adelante_ = p->adelante_;
            delete p;
            longitud_--;
        }
    }
}

int Lista::longitud() const{
    return longitud_;
}

const int& Lista::iesimo(Nat i) const{
    Nodo* p = ramaDelantera_;
    int j = 0;
    while (j != i){
        p = p->atras_;
        j++;
    }
    return p->dato_;
}

int& Lista::iesimo(Nat i){
    Nodo* p = ramaDelantera_;
    int j = 0;
    while (j != i){
        p = p->atras_;
        j++;
    }
    return p->dato_;
}

void Lista::mostrar(ostream& o) {
}
