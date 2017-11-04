#include <iostream>
#include <vector>
using namespace std;

template<class T>
class No {
public:
    T item;
    No<T>* prox;

    No () {
        prox = NULL;
    }

    No (T item) {
        this->item = item;
        prox = NULL;
    }
};

template<class T>
class LSE {
private:
    No<T> *prim, *ult;
public:
    LSE ();
    void insere(T);
    No<T>* pred(No<T>*);
    bool vazia();
    No<T>* busca(T);
    void remove(No<T>*, T&);
    void print();
    int tam();
    bool estaOrdenada(int tam);
    No<T> *getPrim();
};

template<class T>
No<T> *LSE<T>::getPrim() {
    return this->prim;
}

template<class T>
LSE<T>::LSE(){
    prim = new No<T>();
    prim->prox = NULL;
    ult = prim;
}

template<class T>
void LSE<T>::insere(T item) {
    ult->prox = new No<T>();
    ult = ult->prox;
    ult->prox = NULL;
    ult->item = item;
}

template<class T>
bool LSE<T>::vazia() {
    return prim == ult;
}

template<class T>
No<T>* LSE<T>::pred(No<T>* r) {
    No<T>* p = prim->prox;
    while (p->prox != r) {
        p = p->prox;
    }
    return p;
}

template<class T>
void LSE<T>::remove(No<T>* r, T &vertice){
    if (vazia() || r == NULL || r == prim) {
        cout << "impossível remover\n";
    }
    else {
        vertice = r->item;
        No<T>* p = pred(r);
        p->prox = r->prox;
        if (p->prox == NULL) ult = p;
        delete r;
    }
}

template<class T>
No<T>* LSE<T>::busca(T vertice) {
    No<T>* p = prim->prox;
    while (p != NULL && p->item.num != vertice.num) {
        p = p->prox;
    }
    return p;
}

template<class T>
void LSE<T>::print() {
    No<T> *p = prim->prox;
    while (p != NULL) {
        p->item.print();
        p = p->prox;
        cout << endl;
    }
}

template<class T>
int LSE<T>::tam() {
    int tam;
    No<T>* p = prim->prox;

    if(vazia()) {
        tam = 0;
    }
    else {
        while (p != NULL ) {
            tam++;
            p = p->prox;
        }
    }

    p = prim->prox;

    return tam;
}

template<class T>
bool LSE<T>::estaOrdenada(int tam) {
    int i = 1;
    bool ordenada = true;
    No<T> *p = prim->prox;

    if(vazia()) {
        return true;
    }
    else {
        while ( ordenada && i < tam - 1) {
            if (p->item->getItem() <= p->prox->item->getItem()) {
                p = p->prox;
            }
            else
                ordenada  = false;
            i++;
        }
    }

    p = prim->prox;

    return ordenada;
}


//////////////////////////////////////////


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

    int getDist() ;
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
int Vertice<T>::getDist()  {
    return this->dist;
}

template<class T>
void Vertice<T>::setDist(int dist) {
    this->dist = dist;
}

template<class T>
class Grafo {
private:
    LSE<Vertice<int>*> *listAdj;

    int ordem;
    int tamanho;
    Vertice<int>* pred;
public:
    Grafo<T>(int);

    void inicialize(int);

    void insertEdge( Vertice<T> *,  Vertice<T> *);

    void ordenarLista() ;

    void selectionSort(LSE<Vertice<T>*> *);

    void bfs(Vertice<T>*);


};


template<class T>
void Grafo<T>::selectionSort(LSE<Vertice<T>*> *lista  ) {

    No<Vertice<T>*> *prim  = lista->getPrim();

    No<Vertice<T>*>* min;
    No<Vertice<T>*>* j;
    No<Vertice<T>*>* i = prim->prox;

    Vertice<int>* temp;

    for(;i->prox!=NULL;i=i->prox) {
        min = i;
        for(j=i->prox;j!=NULL;j=j->prox) {
            if(j->item->getItem() < min->item->getItem()){
                min=j;
            }
        }
        temp = i->item;
        i->item = min->item;
        min->item = temp;
    }
}



template <class T>
void Grafo<T>::ordenarLista()  {

        for (int i=0;i<64;i++) {
            selectionSort(&this->listAdj[i]);
        }


    for (int i=0; i<64;i++) {
        No<Vertice<T> *> *p = listAdj[i].getPrim();
        p = p->prox;


        cout << "Lista Adjacente  "<< i << " : ";
        while (p != nullptr) {
            cout << p->item->getItem() << " ";
            p = p->prox;
        }
        cout << "\n";

    }


}

template <class T>
Grafo<T>::Grafo(int ordem) {
    inicialize(ordem);
}

template<class T>
void Grafo<T>::inicialize(int ordem) {
    this->ordem = ordem;
    this->listAdj =  new LSE<Vertice<T>*>[ordem+1];
}

template<class T>
void Grafo<T>::insertEdge(Vertice<T> *origem, Vertice<T> *destino) {


    listAdj[origem->getItem()].insere(destino);
    tamanho++;
}

template <class T>
void Grafo<T>::bfs(Vertice<T>* origem) {
        //Colocando os vertices para branco
        for (int i=0;i<ordem;i++){
            No<Vertice<int>*> *p = listAdj[i].getPrim() ;
            p = p->prox;
            for(; p != nullptr ; p = p->prox){
                p->item->setCor("branco");
                p->item->setDist(9999);
                p->item->setPred(nullptr);
            }
        }
        origem->setCor("cinza");
        origem->setDist(0);
        origem->setPred(nullptr);

        Lista<Vertice<T>*> fPrioridades;
        fPrioridades.addToEnd(origem);

        while (fPrioridades.size() > 0) {
            Vertice<T>* origem = fPrioridades.pop();

            No<Vertice<int>*> *p = listAdj[origem ->getItem()].getPrim() ;

            p = p->prox;
            for(; p != nullptr ; p = p->prox){

                if ( p->item->getCor() == "branco" ){
                    Vertice<T> *destino = p->item;
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
    vector<Vertice<int>*> verticesCavaleiros;
    vector<int> caminhoCavalos;
    Vertice<int> *verticeRei;
    Vertice<int> *matriz[8][8];

public:
    Tabuleiro();

    void setPosCavalos(vector<string>);

    int stringToNumber(char);

    char numberToNumber(int);

    void setPosRei(string);

    vector<int> ataqueDosCavaleiros();


};

vector<int> Tabuleiro::ataqueDosCavaleiros() {

	vector<int> v;
	
	v.clear();	

    for (int i = 0 ; i < this->verticesCavaleiros.size();i++ ) {
        this->grafo->bfs(this->verticesCavaleiros.at(i));
        this->caminhoCavalos.push_back(this->verticeRei->getDist());
    }

    int  menor = 999;
    
    for (int i = 0; i < caminhoCavalos.size(); i++) {
         if (menor > caminhoCavalos.at(i)) {
             menor = caminhoCavalos.at(i);
         }
    }
    
    for (int j = 0; j < caminhoCavalos.size(); j++) {
    	if (menor == caminhoCavalos.at(j)) {
    		v.push_back(menor-1);
    	}
    }   
    
    return v;   
}

void Tabuleiro::setPosRei(string casa) {
    int coluna = stringToNumber(casa[0]);
    int linha = numberToNumber(casa[1]);
    this->verticeRei = this->matriz[linha][coluna];
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


void Tabuleiro::setPosCavalos(vector<string> posCavalos) {


    for (int i = 0 ; i < posCavalos.size();i++) {
        string casa = posCavalos.at(i);
        int coluna = stringToNumber(casa[0]);
        int linha = numberToNumber(casa[1]);
        this->verticesCavaleiros.push_back(matriz[linha][coluna]);

    }

}


Tabuleiro::Tabuleiro() {

    this->grafo = new  Grafo<int>(64);
    this->verticeRei = new Vertice<int>();
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

void processamento () {

	int n;
	string c;
	string r;
	vector<int> p;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
    	
    	Tabuleiro *tabuleiro = new Tabuleiro();
    	vector<string> posCavalos;
    
    	for (int j = 0; j < 4; j++ ) {
    		cin >> c;
    		posCavalos.push_back(c);
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

}

int main() {

	processamento();

    return 0;
}
