#include <iostream>
using namespace std;
typedef int Dado;

class noh {
friend class fila;
private:
    Dado dado;
    noh* proximo;
public:
    noh(Dado d = 0);
};
noh::noh(int d){
	dado = d;
	proximo = NULL;
}
class fila {
private:
    noh* inicio;
    noh* fim;
    int tamanho;
public:
    fila();
   ~fila();
    void enfileira(Dado valor);
    Dado desenfileira();
    Dado espia();
    void imprime();
};
fila::~fila(){
	noh* novo = inicio;
	noh* temp;
	while(novo != NULL){
		temp = novo;
		novo = novo->proximo;
		delete temp;
	}
}
fila::fila(){
	inicio = NULL;
	fim = NULL;
	tamanho = 0;
}
void fila::enfileira(Dado valor){
	noh* novo = new noh(valor);
	if (tamanho == 0){
		inicio = novo;
		fim = novo;
	}
	else{
		fim->proximo = novo;
		fim = novo;
	}
	tamanho++;
}
void fila:: imprime(){
	noh* aux = inicio;
	while (aux!=NULL){
		cout << aux->dado << ' ';
		aux = aux->proximo;
	}
	cout << endl;
}
Dado fila::desenfileira(){
	if (tamanho == 0){
		cout << "nao contem nada na fila";
		return -1;
	}
	else{
        noh* novo = inicio;
        if (tamanho == 1){
            inicio = NULL;
            fim = NULL;
        }
        else{
            inicio = inicio->proximo;
        }
        Dado temp = novo->dado;
        delete novo;
        return temp;
	}
}
Dado fila::espia(){
	return inicio->dado;
}
int main (){
	fila f1;
	f1.enfileira(5);
	f1.enfileira(2);
	f1.enfileira(9);
	f1.enfileira(8);
	f1.imprime();
	f1.desenfileira();
	f1.imprime();
	cout << f1.espia() << endl;

	return 0;
}
