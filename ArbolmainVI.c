/************************************************************************************************
*    Programa: Guia de ejercicios LAB 04                                                           *
*    Objetivo:                                                                                  *
*    Autor/Grupo: Cristian Rojas Saavedra                                                       *
*    Asignatura: Estructura de datos     Sección: 652                                           *
*************************************************************************************************/ 

#include "arbolfun.h"


int main(int argc, char argv){
	nodoArbol *raiz, *_raiz;

	raiz = crear(9);
	orden(raiz,78);
	orden(raiz,6);
	orden(raiz,3);
	orden(raiz,7);
	orden(raiz,9);
	orden(raiz,5);
	orden(raiz,88);
	orden(raiz,10);
	orden(raiz,0);
	orden(raiz,1);
	orden(raiz,34);
	orden(raiz,22);
	orden(raiz,4);
	orden(raiz,2);
	orden(raiz,8);
	orden(raiz,45);
	orden(raiz,32);
	orden(raiz,65);
	orden(raiz,42);
	
	printf("\n");
	_raiz=buscarMin(raiz);
	printf("El nodo minimo --> %d\n", _raiz->elem->num);
	printf("\n");
	_raiz=buscarMax(raiz);
	printf("El nodo maximo --> %d\n", _raiz->elem->num);
	printf("\n");
	
	int Nivel=nivel(raiz);
	
	printf("El nivel del Arbol es --> %d\n", Nivel);
	printf("\n");	
	eliminar(raiz,88);
	eliminar(raiz,10);
	printf("\ninOrden");
	inorden(raiz);
	

	return 0;
}



