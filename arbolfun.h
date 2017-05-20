/************************************************************************************************
*    Programa: Guia de ejercicios                                                           *
*    Objetivo: Libreria                                                                        *
*    Autor/Grupo: Cristian Rojas Saavedra                                                       *
*    Asignatura: Estructura de datos     Sección: 652                                           *
*************************************************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct info {
	int num;
	
}Info;

typedef struct nodoArbol{
	Info* elem;
	struct nodoArbol *izq;
	struct nodoArbol *der;
}nodoArbol;


nodoArbol* crear(int praiz){
	nodoArbol *nd=(nodoArbol*) malloc(sizeof(nodoArbol));
	nd->izq=NULL;
	nd->der=NULL;
	Info *dato =(Info*) malloc(sizeof(Info));
	dato->num=praiz;
	nd->elem=dato;
	return nd;	
}

void Hijoizq(nodoArbol* raiz, nodoArbol* num){
    raiz->izq = num;
}

void Hijoder(nodoArbol* raiz, nodoArbol* num){
    raiz->der = num;
}

void nArbol(nodoArbol *n1){
    printf(" %d ",n1->elem->num);
    
}

void preorden(nodoArbol* raiz){
    if(raiz != NULL){
        nArbol(raiz);
        preorden(raiz->izq);
        preorden(raiz->der);
    }
}

void inorden(nodoArbol* raiz){
    if(raiz != NULL){        
        inorden(raiz->izq);
        nArbol(raiz);
        inorden(raiz->der);
    }
}

void postorden(nodoArbol* raiz){
    if(raiz != NULL){        
        postorden(raiz->izq);        
        postorden(raiz->der);
        nArbol(raiz);
    }
}

int busNod(nodoArbol* raiz, int numero){
    int valor = 0;
    if(raiz == NULL){
        return 0;
    }else if(raiz->elem->num == numero){
        return 1;
    }else{
        valor =  busNod(raiz->izq, numero);
        if(valor != 1){
            valor = busNod(raiz->der,numero);
        }
    }
    
    return valor;
    
}

int Peso(nodoArbol* raiz){
    if(raiz == NULL){
        return 0;
    }
    
    return 1 + Peso(raiz->izq) + Peso(raiz->der);
}

int cantHojas(nodoArbol* raiz){
	if(raiz == NULL){
		return 0;
	}
    if(raiz->izq == NULL && raiz->der == NULL){
        return 1;
    }
	else{
        return cantHojas(raiz->izq) + cantHojas(raiz->der);
	}
}

int Full(nodoArbol* raiz){
    int valor = 0;
    
    if(raiz == NULL){
        return 0;
    }
	if((raiz->der == NULL ) + (raiz->izq == NULL) == 1){
        return 1;
    }else{
        valor = Full(raiz->izq);
        if(valor != 1){
            valor = Full(raiz->der);
        }
    }
    return valor;
}

int sumaArbol(nodoArbol* raiz){
    if(raiz == NULL){
        return 0;
    }
    return raiz->elem->num + sumaArbol(raiz->izq) + sumaArbol(raiz->der);
}

int Altura(nodoArbol* nodo){
	int Altizq=0, Altder=0;
	if (nodo==NULL){
		return 0;
	}
	else{
		Altizq= Altura(nodo->izq);
		Altder= Altura(nodo->der);
		if 	(Altizq>Altder){
			return Altizq+1;
		}
		else{
			return Altder+1;
		}
	}	
}

int Profundidad(nodoArbol* nodo){
	int profizq=0, profder=0;
	if (nodo==NULL){
		return 0;/* Arbol vacio*/
	}
	else{
		profizq= Profundidad(nodo->izq);
		profder= Profundidad(nodo->der);
		if 	(profizq>profder){
			return profizq+1;
		}
		else{
			return profder+1;
		}	
	}
}

bool mayor(int a, int b){
	if (a>b){
		return true;
	}
	else{
		return false;
	}
}
int max(int a, int b){
	if (a>b){
		return a;
	}
	else{
		return b;
	}
}

int nivel(nodoArbol* raiz){
    if(raiz == NULL){
        return 0;
    }else{
        return 1+ max(nivel(raiz->izq), nivel(raiz->der));
    }
}




void orden(nodoArbol* raiz, int numero){
	
    if(raiz == NULL){
        printf ("El arbol esta vacio");    
	}	
	if (mayor(numero,raiz->elem->num)==true){
		printf ("Es Mayor, %d > %d\n",numero,raiz->elem->num);
		if(raiz->der==NULL){
			printf ("Es NULL");	        	
	       	Hijoder(raiz,crear(numero));
	       	printf (" Ingresado a la derecha...\n");
		}
		else{
			printf ("NO NULL\n");
			orden(raiz->der,numero);
		}
	}
	else if(raiz->elem->num==numero){
		printf ("Es igual %d = %d\n\n",numero,raiz->elem->num);
		}
	else{
		printf ("Es menor %d < %d\n",numero,raiz->elem->num);
		if (raiz->izq==NULL){
			printf ("Es NULL");			
			Hijoizq(raiz,crear(numero));
			printf (" Ingresado a la izquierda...\n");
		}
		else{
			printf ("NO NULL\n");
			orden(raiz->izq,numero);			
		}
	}
}

bool eshoja(nodoArbol *raiz){
	if (raiz->izq==NULL&&raiz->der==NULL){
		return true;
	}
	else if(raiz->izq==NULL || raiz->der==NULL){
		return true;
	}
	else {
		return false;
	}
}

nodoArbol *buscarMin(nodoArbol *raiz){
	if (raiz==NULL){
		return NULL;
	}
	if (raiz->izq==NULL){
		return raiz;
	}else{
		return buscarMin(raiz->izq);
	}
}

nodoArbol *buscarMax(nodoArbol *raiz){
	if (raiz==NULL){
		return NULL;
	}
	if (raiz->der==NULL){
		return raiz;
	}else{
		return buscarMax(raiz->der);
	}
}



nodoArbol *eliminar(nodoArbol *raiz,int nodo){
	if (raiz==NULL){
		printf("Elemento no se encontro\n");
	}//seguir por la izquierda
	else if(nodo<raiz->elem->num){
		raiz->izq=eliminar(raiz->izq,nodo);
	}//seguir por la derecha
	else if(nodo>raiz->elem->num){
		raiz->der=eliminar(raiz->der,nodo);
	}
	else{//encotrado
		nodoArbol *aux;
		//nodo con 2 hijos
		if (raiz->der!=NULL && raiz->izq!=NULL){
			aux=buscarMin(raiz->der);
			raiz->elem->num=aux->elem->num;//copio nodo
			raiz->der= eliminar(raiz->der,aux->elem->num);
		}
		else{//con un hijo o es hoja
			aux=raiz;
			//solo un hijo derecho o sin hijos
			if (raiz->izq==NULL){
				raiz=raiz->der;
			}
			//solo un hijo izquierdo
			else if (raiz->der==NULL){
				raiz=raiz->izq;
			}free(aux);
		}
	}return raiz;
}
