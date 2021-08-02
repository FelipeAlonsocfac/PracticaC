//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Tarea Programacion C #1.a
//Construir rutina modular que inicialice y escriba un vector de tamaño max. 20
//inicializa otro vector con la cantidad de primos que hay entre 2 y cada posicion del vector anterior
//finalmente guardar una variable entera del segundo vector leido de izquierda a derecha
//04 de octubre de 2017
//Se supone que los datos ingresados son correctos
//Alumno: Carlos Felipe Alonso Caro

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
int vec1[20],vec2[20],tv,gen;

void saludo(void);
void ped_tam(int *);
void ped_vec1(int [],int);
void llen_vec2(int [],int [],int);
void gen_entero(int[],int,int *);	
	
saludo();
ped_tam(&tv);
ped_vec1(vec1,tv);
llen_vec2(vec2,vec1,tv);
gen_entero(vec2,tv,&gen);

printf("Fin de la tarea");	
}


void saludo(void)
{
printf("Hola. Dame un vector y te escribire otro con la cantidad de primos entre dos y cada posicion del vector anterior");	
}


 

