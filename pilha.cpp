#include <iostream>
using namespace std;
typedef int Dado;

class noh {
friend class pilha;
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

class pilha {
private:
    noh* topo;
    int tamanho;
public:
    pilha();
    ~pilha();
    void empilha(Dado valor);
    Dado desempilha();
    Dado espia();
    void imprime();
};
pilha::pilha(){
	topo = NULL;
	tamanho = 0;
}
pilha::~pilha(){
	int aux = 0;
	noh* temp = topo;
	noh* a;
	while(aux < tamanho){
		a = temp;
		temp = temp->proximo;
		delete a;
		aux++;
	}

}
void pilha::empilha(Dado dado){
	noh* novo = new noh(dado);
	novo->proximo = topo;
	topo = novo;
	tamanho++;
}
Dado pilha::desempilha(){
	noh* novo = topo;
	int removido =  topo->dado;
	topo = novo->proximo;
	delete novo;
	tamanho--;
	return removido;
}
void pilha:: imprime(){
	noh* aux = topo;
	int n = 0;
	while(n < tamanho){
		cout << aux->dado << ' ';
		aux = aux->proximo;
		n++;
	}
	cout << endl;
}
Dado pilha::espia(){
	return topo->dado;
}
int main (){
	pilha p1;
	p1.empilha(5);
	p1.empilha(9);
	p1.empilha(7);
	p1.empilha(22);
	p1.imprime();
	p1.desempilha();
	p1.imprime();
	cout << p1.espia()<< endl;
	return 0;
}
