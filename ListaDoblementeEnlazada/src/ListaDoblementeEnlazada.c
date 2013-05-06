#include<stdio.h>
typedef struct nodo{
	void *dato;
	struct nodo *sgte;
	struct nodo *ant;
}nodo;

int main(){
	int valor=1;
	nodo *lista=NULL;
	insertaNodo(lista,(void*)valor);
	return 0;
}

void insertaNodo(nodo *lista, void* dato){

}
