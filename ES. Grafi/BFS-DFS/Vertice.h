//è il singlo valore del vertice ognuno con il suo predecessore, colore , valore e distanza
//sono i vertici della lista di adiacenza di un nodo

#ifndef VERTICE_H
#define VERTICE_H
#include <iostream>
#include <limits>
#include <string>

using namespace std;

enum class Color{
    WHITE, GRAY, BLACK
};


template<class T>
class Vertice
{
private:
    T value;
    Color colore;
    Vertice<T> *predecessore;
    int distanza;

    //ATTRIBUTI PER LA DFS
    int tempInizio;
    int tempFine;

public:
    Vertice(T);

    void setValue(T value){this->value = value;}
    void setColor(Color colore){this->colore = colore;}
    void setPredecessore(Vertice<T> *predecessore){this->predecessore = predecessore;}
    void setDistanza(int distanza){this->distanza = distanza;}

    T getValue(){return value;}
    Color getColor(){return colore;}
    Vertice<T> *getPredecessor(){return predecessore;}
    int getDistanza(){return distanza;}


    //DFS
    void setTempInizio(int tempInizio){this->tempInizio = tempInizio;}
    void setTempFine(int tempFine){this->tempFine = tempFine;}
    int getTempInizio(){return tempInizio;}
    int getTempFine(){return tempFine;}

    
    friend ostream& operator<<(ostream& out, const Vertice<T>& obj)
    {
        string c;
        switch (obj.colore)
        {
        case Color::WHITE:
            c = "WHITE";
            break;
        case Color::GRAY:
            c = "GRAY";
            break;
        case Color::BLACK:
            c = "BLACK";
            break;
        default:
            break;
        }

        out<<"Valore: "<<obj.value<<" Colore: "<<c;
        return out;
    }

    friend bool operator== (const Vertice<T> &a, const Vertice<T> &b)
    {
        return a.value == b.value;
    }
};

template<class T> Vertice<T>::Vertice(T value)
{
    this->value = value;
    colore = Color::WHITE;
    predecessore = nullptr;
    distanza = UINT16_MAX;

    //DFS
    tempInizio = 0;
    tempFine = 0;
}




#endif