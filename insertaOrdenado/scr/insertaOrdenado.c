#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	void *data;
	struct nodo *next;
} nodo;


void mostrarLista(nodo*,void(*)(void*));
void eliminarLista(nodo**);
void mostrarNodoInt(void*);
void mostrarNodoChar(void*data);
void insertarNodoOrdenado(nodo**,void*,int(*)(void*,void*));
int compararParaCriterio(void*,void*);

int main(void) {

	nodo *lista=NULL,*lista2=NULL;
	int a=3;
	//char b='z';
	int c=10;
	int d=6;
	//char e='a';
	//char g='b';
	//int f=6;

	insertarNodoOrdenado(&lista,(void*)a,compararParaCriterio);
	insertarNodoOrdenado(&lista,(void*)c,compararParaCriterio);
	insertarNodoOrdenado(&lista,(void*)d,compararParaCriterio);
	mostrarLista(lista,mostrarNodoInt);
	mostrarLista(lista2,mostrarNodoChar);
	eliminarLista(&lista);
	eliminarLista(&lista2);

	return 0;
}

void mostrarLista(nodo *lista,void(*func)(void*)){
nodo *aux;

if(lista==NULL){
	printf("lista vacia. Presione cualquier letra para salir");
	getchar();
	exit(0);
}
		aux=lista;
		while(aux!=NULL){
			(*func)(aux->data);
			aux=aux->next;
		}
}


void eliminarLista(nodo **lista){

	nodo *aux;

	if(*lista==NULL){
		printf("Advertencia al querer liberar la memoria de la lista. La lista se encontro vacia.\nPresione cualquier letra para salir");
		getchar();
		exit(0);
	}
	aux=*lista;
	while(aux!=NULL){
				aux=aux->next;
				//free((*lista)->data);
				free(*lista);
				*lista=aux;
	}
}

void insertarNodoOrdenado(nodo** lista,void* data,int(*compara)(void*,void*))
{
	nodo* nuevo;
	nodo* aux;
	nodo* aux1;

	aux=*lista;

	if(*lista==NULL || compara(data,(*lista)->data)) //O porque la lista está vacía o porque el nodo a insertar es menor al único nodo existente
	{
		nuevo=malloc(sizeof(nodo)); //Se está inicializando el nodo nuevo
		nuevo->data=data;//Se guardan los datos en el nodo nuevo

		*lista=nuevo;
		nuevo->next=aux;

		return ;
	}

	while(aux->next!=NULL && !(compara(data,(aux->next)->data)))
	{
		aux=aux->next;
	}
	aux1=aux->next;
	nuevo=malloc(sizeof(nodo)); //Se está inicializando el nodo nuevo
	nuevo->data=data;//Se guardan los datos en el nodo nuevo
	aux->next=nuevo;
	nuevo->next=aux1;

}
void mostrarNodoInt(void*data){
	printf("El valor del nodo es: %d\n",(int)data);
}
void mostrarNodoChar(void*data){
	printf("El valor del nodo es: %c\n",*((char*)data));
}


int compararParaCriterio(void* dataAux,void* dataNuevo)
{
	if ((int)dataAux<(int)dataNuevo)
		return 1;//v-> Entra al if
	else
		return 0;
}
