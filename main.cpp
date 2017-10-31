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

    void addAt(int,T);

    T pop();

    T itemAt(int);

    void remove(int);

    int size();

    void imprimir();


};


template <class T>
void Lista<T>::addAt(int indice, T item) {
      this->items.at(indice) = item ;
}



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
    Vertice<int>* pred;

public:
    Vertice(){};

    Vertice(T);

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
Vertice<T>::Vertice(T item){
    this->item =  item;
    this->setPred(nullptr);
    this->setCor("vazio");
}


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

    void insertEdge( Vertice<T> *,  Vertice<T> *);

    void ordenarLista() ;

    void insertionSort(Lista<Vertice<int>*>*);

    void print();

    void bfs(Vertice<T>*);

    Lista<T> &getListAdj();

    void setListAdj(Lista<T> &listAdj);

    int getOrdem();

    void setOrdem(int ordem);

    int getTamanho();

    void setTamanho(int tamanho);

    void imprimir();

    Lista<Vertice<T>*> *getCaminho(Vertice<T>*);

};

template <class T>
void Grafo<T>::insertionSort(Lista<Vertice<int>*> *lista ) {

    Vertice<int> *aux = new Vertice<int>() ;

    int j = 0;

      for (int i = 1; i < lista->size();i++ ){
                 aux = lista->itemAt(i);
                 j = i - 1;
                 while (j >= 0 && aux->getItem() < lista->itemAt(j)->getItem()) {
                         lista->addAt(j+1, lista->itemAt(j));
                         j--;
                     }
                 lista->addAt(j+1, aux);
             }

}


template <class T>
void Grafo<T>::ordenarLista()  {

        for (int i=0;i<64;i++) {
            insertionSort(&this->listAdj[i]);
        }
}

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
void Grafo<T>::insertEdge(Vertice<T> *origem, Vertice<T> *destino) {
    listAdj[origem->getItem()].addToEnd(destino);
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

template<class T>
Lista<Vertice<T>*>  *Grafo<T>::getCaminho(Vertice<T> *alvo){
    Lista<Vertice<T>*>* caminho = new Lista<Vertice<T>*>();
    Vertice<T> *caminhante = new Vertice<T>();
    *caminhante = *alvo;

    while (caminhante->getPred() != nullptr) {
            Vertice<T> *jogada = new Vertice<T>();
            *jogada = *caminhante;

            caminho->addToEnd(jogada);

            caminhante = caminhante->getPred();
    }
            caminho->addToEnd(caminhante);

    return caminho;
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
                    destino->setCor("cinza");
                    destino->setDist(origem->getDist()+1);
                    destino->setPred(origem);
                    fPrioridades.addToEnd(destino);
                }
            origem->setCor("preto");
            }
        }
}


class Tabuleiro {
private:
    Grafo<int> *grafo;
    Lista<Vertice<int>*> *verticesCavaleiros;
    Lista<Lista<Vertice<int>*>*> *caminhoCavalos;
    Vertice<int> *verticeRei;
    Lista<string> *posCavalos;
    string correspondencia[8][8] = {
            {"a8","b8","c8","d8","e8","f8","g8","h8"},
            {"a7","b7","c7","d7","e7","f7","g7","h7"},
            {"a6","b6","c6","d6","e6","f6","g6","h6"},
            {"a5","b5","c5","d5","e5","f5","g5","h5"},
            {"a4","b4","c4","d4","e4","f4","g4","h4"},
            {"a3","b3","c3","d3","e3","f3","g3","h3"},
            {"a2","b2","c2","d2","e2","f2","g2","h2"},
            {"a1","b1","c1","d1","e1","f1","g1","h1"},
    };
    int rei;
    Vertice<int> *matriz[8][8];


public:
    Tabuleiro();

    void setPosCavalos(Lista<string> *);

    int stringToNumber(char);


    char numberToNumber(int);

    Grafo<int> *getGrafo();

    void inserirCavalo(Vertice<int>*);

    void setPosRei(string);

    //void ataqueDosCavaleiros();
    vector<int> ataqueDosCavaleiros();


};

//void Tabuleiro::ataqueDosCavaleiros() {
vector<int> Tabuleiro::ataqueDosCavaleiros() {

	vector<int> v;
	
	v.clear();	

    for (int i = 0 ; i < this->verticesCavaleiros->size();i++ ) {
        this->grafo->bfs(this->verticesCavaleiros->itemAt(i));
        this->caminhoCavalos->addToEnd(this->grafo->getCaminho(this->verticeRei));
    }

    int  menor = 999;
    
    for (int i = 0; i < caminhoCavalos->size(); i++) {
         if (menor > caminhoCavalos->itemAt(i)->size()) {
             menor = caminhoCavalos->itemAt(i)->size();
         }
    }
    
    for (int j = 0; j < caminhoCavalos->size(); j++) {
    	if (menor == caminhoCavalos->itemAt(j)->size()) {
    		v.push_back(menor-2);
    	}
    }   
    
    return v;   
}

void Tabuleiro::setPosRei(string casa) {
    int coluna = stringToNumber(casa[0]);
    int linha = numberToNumber(casa[1]);
    this->verticeRei = this->matriz[linha][coluna];
}

Grafo<int> *Tabuleiro::getGrafo() {
    return this->grafo;
}

void Tabuleiro::inserirCavalo(Vertice<int> *vertice) {
    this->grafo->bfs(vertice);
}


int Tabuleiro::stringToNumber(char letra) {
    switch (letra) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;

    }
    return '9';
}

char Tabuleiro::numberToNumber(int numero) {
    switch (numero) {
        case '1':
            return 7;
        case '2':
            return 6;
        case '3':
            return 5;
        case '4':
            return 4;
        case '5':
            return 3;
        case '6':
            return 2;
        case '7':
            return 1;
        case '8':
            return 0;
    }
    return '9';
}


void Tabuleiro::setPosCavalos(Lista<string> *posCavalos) {


    for (int i = 0 ; i < posCavalos->size();i++) {
        string casa = posCavalos->itemAt(i);
        //int coluna = e;
        //int linha = 1
        int coluna = stringToNumber(casa[0]);
        int linha = numberToNumber(casa[1]);
        this->verticesCavaleiros->addToEnd(matriz[linha][coluna]);
    }

}


Tabuleiro::Tabuleiro() {

    this->grafo = new  Grafo<int>(64);
    this->verticesCavaleiros = new Lista<Vertice<int>*>();
    this->verticeRei = new Vertice<int>();
    this->caminhoCavalos =  new Lista<Lista<Vertice<int>*>*>();

    int numeroCasa = 0;

    for (int i = 0;i<8;i++) {
        for (int j=0; j<8;j++) {
             matriz[i][j] = new Vertice<int>(numeroCasa);
             numeroCasa++;
        }
    }



    for (int i=0;i<8;i++) {
        for ( int j=0;j<8;j++) {

            //direita
            if ((i+1 < 8) &&  (j+2 < 8)) {
                grafo->insertEdge(matriz[i][j], matriz[i + 1][j + 2]);
            }
            if ( (i-1 >=0 ) && (j+2 < 8) ) {
                grafo->insertEdge(matriz[i][j], matriz[i - 1][j+2]);
            }
            //baixo
            if ( (i+2 < 8) && ( j+1 < 8  )   ) {
                grafo->insertEdge(matriz[i][j], matriz[i + 2][j + 1]);
            }
            if ( (i+2 < 8) && ( j-1 >= 0  ) ) {
                grafo->insertEdge(matriz[i][j], matriz[i + 2][j - 1]);
            }
            //esquerda
            if (( i+1 < 8 ) && (j - 2 >= 0 ) ){
                grafo->insertEdge(matriz[i][j], matriz[i + 1][j - 2]);
            }
            if (( i-1 >= 0 ) && (j - 2 >= 0 ) ){
                grafo->insertEdge(matriz[i][j], matriz[i - 1][j - 2]);
            }
            //cima
            if (( i-2 >= 0 ) && (j - 1 >= 0 ) ){
                grafo->insertEdge(matriz[i][j], matriz[i - 2][j - 1]);
            }
            if (( i-2 >= 0 ) && (j + 1 < 8 ) ){
                grafo->insertEdge(matriz[i][j], matriz[i - 2][j + 1]);
            }

        }

    }

       grafo->ordenarLista();
}

int main() {

	int n;
	string c;
	string r;
	vector<int> p;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
    	
    	Tabuleiro *tabuleiro = new Tabuleiro();
    	Lista<string> *posCavalos = new Lista<string>();
    
    	for (int j = 0; j < 4; j++ ) {
    		cin >> c;
    		posCavalos->addToEnd(c);
    	}
    	
    	tabuleiro->setPosCavalos(posCavalos);
    	
    	cin >> r;
    	tabuleiro->setPosRei(r);   	
    	p = tabuleiro->ataqueDosCavaleiros();
  
    	for (unsigned int k = 0; k < p.size(); k++) {
    		cout << p[k] << " ";
    	}
    	
    	p.clear();
  
    	cout << endl;
    }

    return 0;
}
