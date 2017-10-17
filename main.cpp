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

    void addToEnd(T&);

    T pop();

    T itemAt(int);

    void remove(int);

    int size();

    void imprimir();


};

template<class T>
Lista<T>::Lista() {

}

template<class T>
T Lista<T>::pop() {

    T item;
    item = this->items.at(0);
    this->items.erase(this->items.begin());
    return item;

}



template<class T>
void Lista<T>::imprimir() {

    for(int i = 0;i < items.size();i++) {
        cout << items.at(i) << " " ;
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
void Lista<T>::addToEnd(T &item ) {
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
    Vertice<int>* pred;

public:
    Vertice(){};

    T getItem();
    void setItem(T);

    string getCor();
    void setCor(string);

    int getDist() const;
    void setDist(int dist);

    void setPred(Vertice<int>*);
    Vertice<T>* getPred();

};

template <class T>
Vertice<T>* Vertice<T>::getPred() {
    return this->pred;
}


template <class T>
void Vertice<T>::setPred(Vertice<int>* pred) {
    this->pred =  pred;
}

template<class T>
void Vertice<T>::setCor(string cor ) {
    this->cor = cor;
}

template<class T>
string Vertice<T>::getCor(){
    return this->cor;
}

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
    Lista<Vertice<int>*> *listAdj;
    int ordem;
    int tamanho;
    Vertice<int>* pred;
public:
    Grafo<T>(int);

    void inicialize(int);

    void insertEdge( Vertice<T>*,  Vertice<T>*);

    void print();

    void bfs(Vertice<T>*);

    Lista<T> &getListAdj();

    void setListAdj(Lista<T> &listAdj);

    int getOrdem();

    void setOrdem(int ordem);

    int getTamanho();

    void setTamanho(int tamanho);

    void imprimir();

};


template <class T>
Grafo<T>::Grafo(int ordem) {
    inicialize(ordem);
}

template <class T>
Lista<T> &Grafo<T>::getListAdj() {
    return &listAdj;
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
    this->listAdj =  new Lista<Vertice<T>*>[ordem+1];
}

template<class T>
void Grafo<T>::insertEdge(Vertice<T>* origem, Vertice<T>* destino) {
    listAdj[origem->getItem()].addToEnd(destino);
    listAdj[destino->getItem()].addToEnd(origem);
    tamanho++;
}

template<class T>
void Grafo<T>::imprimir() {
       for (int i = 0;i<ordem;i++ ) {
           cout << "No: " << i << "\n";
           for (int j=0;j<listAdj[i].size();j++) {

               cout << listAdj[i].itemAt(j)->getItem() << "-" << listAdj[i].itemAt(j)->getCor() << " ";
           }
           cout << "\n\n";
       }
}


template <class T>
void Grafo<T>::bfs(Vertice<T>* origem) {
        //Colocando os vertices para branco
        for (int i=0;i<ordem;i++){
            for (int j=0;j<listAdj[i].size();j++){
                listAdj[i].itemAt(j)->setCor("branco");
                listAdj[i].itemAt(j)->setDist(9999);
                listAdj[i].itemAt(j)->setPred(nullptr);
            }
        }
        origem->setCor("cinza");
        origem->setDist(0);
        origem->setPred(nullptr);

        Lista<Vertice<T>*> fPrioridades;
        fPrioridades.addToEnd(origem);

        while (fPrioridades.size() > 0) {
            Vertice<T>* origem = fPrioridades.pop();

            for (int i =0;i<listAdj[origem ->getItem()].size();i++){
                if ( listAdj[origem->getItem()].itemAt(i)->getCor() == "branco" ){
                    Vertice<T>* destino = listAdj[origem->getItem()].itemAt(i);
                    destino->getCor("cinza");
                    destino->setDist(origem->getDist()+1);

                }
            }



        }


}


int main() {

    Grafo<int> grafo(4);





    /*

    Lista<int> fila;

    int *ponteiro  = new int() ;
    int *ponteiro2 = new int() ;
    int *ponteiro3 = new int() ;
    *ponteiro = 1;
    *ponteiro2 = 2;
    *ponteiro3 = 3;


    fila.addToEnd(*ponteiro);
    fila.addToEnd(*ponteiro2);
    fila.addToEnd(*ponteiro3);
    fila.imprimir();
    cout<<fila.size();
    fila.pop();
    cout << endl;
    fila.imprimir();
    cout<<fila.size();

/* Ekementos de Teste
    Vertice<int> *vertice0 = new Vertice<int>();
    Vertice<int> *vertice1 = new Vertice<int>();
    Vertice<int> *vertice2 = new Vertice<int>();
    Vertice<int> *vertice3 = new Vertice<int>();

    vertice0->setItem(0);
    vertice0->setCor("branco");

    vertice1->setItem(1);
    vertice1->setCor("azul");

    vertice2->setItem(2);
    vertice2->setCor("amarelo");

    vertice3->setItem(3);
    vertice3->setCor("roxo");

    grafo.insertEdge(vertice0, vertice1);
    grafo.insertEdge(vertice0, vertice3);
    grafo.insertEdge(vertice1, vertice2);
    grafo.insertEdge(vertice3, vertice2);
    grafo.imprimir();
    cout << "teste cor============================================="<<"\n";
    vertice1->setCor("Verde");
    grafo.imprimir();
*/
    return 0;
}