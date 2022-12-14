#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;

template<class T>
class Nodo
{
private:
    Nodo<T> *parent;
    Nodo<T> *left;
    Nodo<T> *right;

    T data;
public:
    Nodo(T);
    ~Nodo();

    void setParent(Nodo<T> *);
    void setLeft(Nodo<T> *);
    void setRight(Nodo<T> *);
    void setInfo(T);

    Nodo<T> *getParent(){return parent;}
    Nodo<T> *getLeft(){return left;}
    Nodo<T> *getRight(){return right;}
    T getInfo(){return data;}
};

template <class T> Nodo <T>::Nodo(T v)
{
    parent = nullptr;
    left = nullptr;
    right = nullptr;

    data = v;
}

template <class T> Nodo<T>::~Nodo()
{
    delete data;
    delete parent;
    delete left;
    delete right;
}

template <class T> void Nodo<T>::setParent(Nodo<T> *p)
{
    parent = p;
}

template <class T> void Nodo<T>::setLeft(Nodo<T> *l)
{
    left = l;
}

template <class T> void Nodo <T>::setRight(Nodo<T> *r)
{   
    right = r;
}

template <class T> void Nodo <T>::setInfo(T i)
{
    data = i;
}

#endif