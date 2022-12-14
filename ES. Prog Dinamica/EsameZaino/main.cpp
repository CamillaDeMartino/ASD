/*
    • Si consideri un esame con n problemi, ognuno dei quali
      vale v[i] punti e richiede t[i] minuti per essere risolto.

    • Trovare un algoritmo che dati v[1,...,n] e t[1,...,n] ed un punteggio minimo V, 
      trovi il sottoinsieme dei problemi che richiede il minor tempo possibile e permetta di superare l'esame
*/



#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#define W 5 
using namespace std;

class Casella
{
    private:
        int value;
        map<int, int> elem;         
    
    public:
        Casella():value{0}, elem{}{}

        int getValue(){return value;}
        void setValue(int value){
            this->value = value;
        }

        void setMapValue(int key, int value){
            elem[key] = value;      //mi dice se un elemento c'è o non c'è
        }

        int getMapValue(int key){
            return elem[key];
        }
};

int main(){

    Casella matrix[6][6];
    int i = 0, j = 0;

    vector<int> w = {0, 1, 1, 1, 2, 2};    //valore dell'esercizio
    vector<int> v = {0, 2, 2, 2, 3, 3};    //tempo per svolgerlo

    //inizializzazione della prima riga
    //se non ho alcun esercizio non raggiungerò mai il voto minimo
    for(j = 0; j< 6; j++)
    {
        matrix[0][j].setValue(UINT16_MAX);      //UINT16_MAX è il più infinito
        
        for(int k = 1; k < v.size(); k++)       //ogni cella della riga (sacco) dobbiamo dire se l'elemento c'è o non c'è nel sacco con la map
            matrix[0][j].setMapValue(k,0);      //l'elemento di indice 1 non c'è nel sacco ... 
                                                //fa riferimento ai singoli elementi (i) della tabella dei pesi e dei valori
                                                //quindi stiamo dicendo che lo zaino nella casella 0 non ha elementi dentro
    }

    //inizializzazione della prima colonna
    //per ottenere almeno 0 non risolvo alcun esercizio
    for(i = 0; i < 6; i++)
    {
        matrix[i][0].setValue(0);
        
        for(int k = 1; k < v.size(); k++)
            matrix[i][0].setMapValue(k,0);
    }   

    for(i = 1; i < v.size(); i++)
    {
        for(j = 1; j <= W; j++)
        {
            if(w[i] > j)                                                                   //se il peso dell'oggeto è più grande della capacità j
            {
                matrix[i][j].setValue(matrix[i-1][j].getValue());                          //prendi l'elemento sopra(in testa)
                for(int k = 1; k < v.size(); k++)
                {
                    matrix[i][j].setMapValue(k, matrix[i-1][j].getMapValue(k) );
                }
            }
            else if(matrix[i-1][j].getValue() < matrix[i-1][j - w[i]].getValue() + v[i])    //peso più piccolo o uguale alla capacità, cerco il minimo
            {                                                                               //poiché noi stiamo cercando il tempo minimo per ottenere il minimo voto
                matrix[i][j].setValue(matrix[i-1][j].getValue());                           //scarto l'elemento 

                for(int k = 1; k < v.size(); k++)
                {
                    matrix[i][j].setMapValue(k, matrix[i-1][j].getMapValue(k));
                }
            }
            else 
            {
                matrix[i][j].setValue(matrix[i-1][j - w[i]].getValue() + v[i]);
            
                for(int k = 1; k < v.size(); k++)
                {
                    matrix[i][j].setMapValue(k, matrix[i-1][j - w[i]].getMapValue(k));
                }
                matrix[i][j].setMapValue(i, 1);                                             //voglio prendere l'elemento
            }
        }
    }
    
    //stampa matrice
    for(i = 0; i < 6; i++)
    {
        for(j = 0; j < 6; j++)
            cout<<matrix[i][j].getValue()<<" ";
        cout<<endl;
    }

    cout<<endl;
    //stampa mappa zaino (come sta lavorando)
    for(int k = 1; k < v.size(); k++){
        cout<< k <<" ";
        cout<<matrix[4][5].getMapValue(k)<<endl;
    }

    return 0;
}