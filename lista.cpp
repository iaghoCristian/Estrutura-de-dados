#include <iostream>
using namespace std;
typedef int Dado;
class noh{
friend class lista;
private:
	Dado dado;
	noh* proximo;
	noh* anterior;
public:
	noh(Dado d = 0);
	
};
class lista{
private:
	noh *primeiro;
	noh *ultimo;
	int tamanho;
public:
	lista();
	~lista();
	void insere(Dado dado);
	void insereNoFim(Dado dado);
	void insereNoInicio(Dado dado);
	void insereNaPosicao(int posicao,Dado dado);
	void insereOrdenado(Dado dado);
	void remove(int posicao);
	void insere2lista(lista l2);
	void remove2lista(lista l2);
	void intercala(lista l1, lista l2);
	void imprimeReverso();
	void imprime();
	bool vazia();
	int procura(Dado valor);
	void trocaPosicao(int pos1, int pos2);
	
};
noh::noh(Dado d){
	dado = d;
	proximo = NULL;
	anterior = NULL;
}
lista::lista(){
	tamanho = 0;
	primeiro = NULL;
	ultimo = NULL;
}
lista::~lista(){
	noh* aux = primeiro;
	noh* temp;
	while (aux!=NULL){
		temp = aux;
		aux = aux->proximo;
		delete temp;
	}
	primeiro = NULL;
	ultimo = NULL;
}
void lista::insere(Dado dado){
	insereNoFim(dado);
}
void lista::insereNoFim(Dado dado){
	noh* novo = new noh (dado);
	if (tamanho == 0){
		primeiro = novo;
		ultimo = novo;
	}
	else{
		novo->anterior = ultimo;
		ultimo->proximo = novo;
		ultimo = novo;
	}
	tamanho++;
}
void lista::insereNoInicio(Dado dado){
	noh* novo = new noh(dado);
	if (tamanho == 0){
		primeiro = novo;
		ultimo = novo;
	}
	else{
		primeiro->anterior = novo;
		novo->proximo = primeiro;
		primeiro = novo;
	}
	tamanho++;
}
void lista::insereNaPosicao(int posicao,Dado dado){
	noh* novo = new noh(dado);
	if ((posicao <=tamanho) and(posicao >=0)){
		if (tamanho == 0){
			primeiro = novo;
			ultimo = novo;
		}
		else if (posicao == tamanho){
				novo->anterior = ultimo;
				ultimo->proximo = novo;
				ultimo = novo;
			}
		else{
			noh* aux = primeiro;
			int posAux= 0;
			while (posAux < (posicao-1)){
				aux = aux->proximo;
				posAux++;
			}
			noh* temp = aux->proximo;
			novo->anterior = aux;
			novo->proximo = aux->proximo;
			temp->anterior = novo;
			aux->proximo = novo;
		}
		tamanho++;
	}
}
bool lista::vazia(){
	return (primeiro == NULL);
}
void lista::imprime(){
	noh* aux = primeiro;
	while(aux != NULL){
		cout << aux->dado << ' ';
		aux = aux->proximo;
	}
	cout << endl;
}
int	lista::procura(Dado valor){
	noh* aux = primeiro;
	int posaux = 0;
	while ((aux!=NULL) and (aux->dado !=valor)){
		posaux++;
		aux = aux->proximo;
	}
	if (aux == NULL){
		posaux = -1;
	}
	return posaux;
}
void lista::remove(int posicao){
	if ((posicao<=tamanho) and (posicao>=0)){
		if (posicao == 0){
			noh* aux = primeiro;
			primeiro = primeiro->proximo;
			delete aux;
		}
		else{
			noh* aux = primeiro->proximo;
			noh* ant = primeiro;
			int posAux = 1;
			while ((aux != NULL) and (posAux < posicao)){
				ant = aux;
				aux = aux->proximo;
				posAux++;
			}
			if (aux==ultimo){
				ant->proximo = NULL;
				ultimo = ant;
				delete aux;
			}
			else{
				ant->proximo = aux->proximo;
				delete aux;
			}
			
			
		}
		tamanho--;
	}
	
	
}
void lista::insere2lista(lista l2){
	noh* aux = l2.primeiro;
	while (aux != NULL){
		this->insere(aux->dado);
		aux = aux->proximo;
	}
}
void lista::remove2lista(lista l3){
	noh* aux = l3.primeiro;
	while (aux != NULL){
		int pos = this->procura(aux->dado);
		if (pos == -1){
			cout << "nao existe o valor: "<< aux->dado<< " na lista 1"<<endl;
		}
		else{
			this->remove(pos);
		}
		aux = aux->proximo;
	}
}
void lista::intercala(lista l1, lista l2){
	noh* aux = l1.primeiro;
	noh* aux2 = l2.primeiro;
	
	while((aux != NULL) or (aux2!=NULL)){
		if (aux!= NULL){
			this->insere(aux->dado);
			aux= aux->proximo;
		}
		if (aux2!= NULL){
			this->insere(aux2->dado);
			aux2 = aux2->proximo;
		}
	}
}

void lista::imprimeReverso(){
	int posAux = 0;
	noh* aux = NULL;
	noh* aux2 = primeiro;
	while (posAux < tamanho){
		aux2 = primeiro;
		while (aux2->proximo != aux){
			aux2 = aux2->proximo;
		}
		aux = aux2;
		cout << aux2->dado << ' ';
		posAux++;
	}
	cout << endl;
}

void lista::trocaPosicao(int pos1, int pos2){
	noh* aux1 = primeiro;
    noh* antAux1 = primeiro;
    int posAux1 = 0;
    while(posAux1 < pos1){
        antAux1 = aux1;
        aux1 = aux1->proximo;
        posAux1++;
    }
    noh* aux2 = primeiro;
    noh* antAux2 = primeiro;
    int posAux2 = 0;
    while(posAux2 < pos2){
        antAux2 = aux2;
        aux2 = aux2->proximo;
        posAux2++;
    }
    if((pos1 != pos2-1) and (pos2 != pos1-1) and antAux1 != aux1){
        noh* aux3 = aux1->proximo;
        antAux1->proximo = aux2;
        antAux2->proximo = aux1;
        aux1->proximo = aux2->proximo;
        aux2->proximo = aux3;
    }
    else if(((pos1 == pos2-1) or (pos2 == pos1-1)) and antAux1 == aux1){
            aux1->proximo = aux2->proximo;
            aux2->proximo = aux1;
            primeiro = aux2;
         }
    else if((pos1 != pos2-1) and (pos2 != pos1-1) and (antAux1 == aux1)){
            noh* aux5 = aux1->proximo;
            aux1->proximo = aux2->proximo;
            aux2->proximo = aux5;
            antAux2->proximo = aux1;
            primeiro = aux2;
         }
    else {
        noh* aux4 = aux2->proximo;
        antAux1->proximo = aux2;
        aux2->proximo = aux1;
        aux1->proximo = aux4;
    }
}
void lista::insereOrdenado(Dado dado){
	if (tamanho == 0){
		insereNoInicio(dado);
	}
	else{
		noh* aux = primeiro;
		if (dado >aux->dado){
			int posaux = 0;
			while ((aux!=NULL)and (dado>aux->dado)){
				posaux++;
				aux = aux->proximo;
			}
			insereNaPosicao(posaux,dado);
		}
		else{
			insereNoInicio(dado);
		}
	}
}
int main(){
    lista l1;
    lista l2;
    lista l3;
    lista l4;
    lista l5;
    l1.insere(2);
    l1.insereNoFim(4);
    l1.insereNoInicio(1);
    l1.insereNaPosicao(2, 3);
    l1.imprime();
    cout << l1.procura(5) << endl;
    l1.remove(2);
    l1.imprime();
    l2.insere(6);
    l2.insere(7);
    l2.insere(10);
    l2.insere(70);
    l2.imprime();
    //l1.insere2lista(l2);
    l1.imprime();
    l3.insere(10);
    l3.insere(6);
    //l1.remove2lista(l3);
    //l1.imprime();
    l4.intercala(l1,l2);
    l4.imprime();
    //int vet[] = {3,54,7,53,2};
    //lista l5(vet, 5);
    //l5.imprime();
    l4.imprimeReverso();
    l4.trocaPosicao(1,3);
    l4.imprime();
    l5.insereOrdenado(3);
    l5.insereOrdenado(5);
    l5.insereOrdenado(6);
    l5.insereOrdenado(4);
    l5.imprime();
}
