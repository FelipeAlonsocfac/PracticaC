//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Tarea Programacion C #3.a,b
//a. Llenar una matriz de 20 filas y 10 columnas con el número 10.
//b. Llenar una matriz de 20 filas y 10 columnas con los números reales que dé el usuario.
//Prototipo, ejemplo de invocacion y definicion
//05 de Octubre de 2017
//Se supone que los datos ingresados son correctos
//Alumno: Carlos Felipe Alonso Caro

#include <stdio.h>
#include <stdlib.h>
#define MF 20
#define MC 10

int main(void)
{
int mat1[MF][MC];
float mat2[MF][MC],nf,nc;;	
	
//prototipo a
void llen_matra (int [MF][MC]);
//prototipo b
void ped_matrb (float [MF][MC],float ,float );

printf("Dame el numero de filas");
scanf("%d",&nf);
printf("\nAhora el numero de columnas");
scanf("%d",&nc);

//invocacion a
llen_matra (mat1);	
//invocacion b	
ped_matrb (mat2,nf,nc);	
}

//definicion a

void llen_matra (int mat1[MF][MC])
{ 
int mf,mc;

mf=0;
mc=0;
while (mf<MF)
	{
	 while (mc<MC)
	 	{
		 mat1[mf][mc]=10;
		 mc++;
		}
	 mf++;	
	}  		
}

// definicion b

void ped_matrb (float mat2[MF][MC],float nf,float nc)
{
float mf,mc;

mf=0;
mc=0;

while (mf<nf)
	{
	 while (mc<nc)
	 	{
		 printf("dame el numero de la fila %d y columna %d",mf+2,mc+2);
		 scanf("%f",mat2[mf][mc]);
		 mc=mc+1;
		}
	 mf=mf+1;	
	}  		
 	
}
