#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Lista {
private:
    vector<T> items;

public:

    Lista<T>();

    Lista<T>(int);

    ~Lista<T>();

    vector<T> getItems();

    void setItems(vector<T> items);

    void addToEnd(T);

    T itemAt(int);

    void remove(int);

    int size();

    void imprimir();


};

template<class T>
Lista<T>::Lista() {

}


template<class T>
void Lista<T>::imprimir() {
    //Deve ser utilizado se a lista for de inteiras
    for(int i = 0;i < items.size();i++) {
        cout << items->at(i) << " " ;
    }
    cout << "\n";
}


template<class T>
Lista<T>::Lista(int tamanho) {
    items = vector<T>(tamanho);
}

template <class T>
Lista<T>::~Lista() {
    items.clear();
    items.shrink_to_fit();
}

template <class T>
vector<T> Lista<T>::getItems()  {
    return items;
}
template <class T>
void Lista<T>::setItems(vector<T> items) {
    Lista::items = items;
}

template <class T>
void Lista<T>::addToEnd(T item ) {
    items.push_back(item);
}

template  <class T >
T Lista<T>::itemAt(int posicao) {
    return items.at(posicao);
}

template <class T>
int Lista<T>::size() {
    return this->items.size();
}


//Implementaçao do Vertice

template<class T>
class Vertice {
private:
    T item;
    string cor;
    int dist;
public:
    Vertice(){};

    T getItem();
    void setItem(T);

    string getCor();
    void setCor(string);

    int getDist() const;
    void setDist(int dist);
};

template<class T>
T Vertice<T>::getItem() {
    return this->item;
}

template<class T>
void Vertice<T>::setItem(T item) {
    this->item = item;
}


template<class T>
int Vertice<T>::getDist() const {
    return dist;
}

template<class T>
void Vertice<T>::setDist(int dist) {
    this->dist = dist;
}




template<class T>
class Grafo {
private:
    Lista<T> *listAdj;
    int ordem;
    int tamanho;
public:
    Grafo(int);

    void inicialize(int);

    void insertEdge(Vertice<T>, Vertice<T>);

    void print();

    void bfs(Vertice<T>);

    Lista<T> &getListAdj();

    void setListAdj(Lista<T> &listAdj);

    int getOrdem();

    void setOrdem(int ordem);

    int getTamanho();

    void setTamanho(int tamanho);

    void imprimir();
};

template<class T>
Grafo<T>::Grafo(int ordem) {
    this->inicialize(ordem);
}

template <class T>
Lista<T> &Grafo<T>::getListAdj() {
    return listAdj;
}

template <class T>
void Grafo<T>::setListAdj(Lista<T> &listAdj) {
    this->listAdj = listAdj;
}


template <class T>
int Grafo<T>::getOrdem() {
    return ordem;
}

template <class T>
void Grafo<T>::setOrdem(int ordem) {
    this->ordem = ordem;
}

template <class T>
int Grafo<T>::getTamanho()  {
    return tamanho;
}

template <class T>
void Grafo<T>::setTamanho(int tamanho) {
    this->tamanho = tamanho;
}

template<class T>
void Grafo<T>::inicialize(int ordem) {
    this->ordem = ordem;
    this->listAdj =  new Lista<T>[ordem+1];
}

template<class T>
void Grafo<T>::insertEdge(Vertice<T> origem, Vertice<T> destino) {
    listAdj[origem.getItem()].addToEnd(destino.getItem());
    listAdj[destino.getItem()].addToEnd(origem.getItem());
    tamanho++;
}

template<class T>
void Grafo<T>::imprimir() {
    for (int i=0;i<=this->ordem;i++) {
        cout << "v[" << i << "] = ";
    }
}


template <class T>
void Grafo<T>::bfs(Vertice<T>) {

}



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}