//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Tarea Programacion C #1.a
//Construir rutina modular que escriba una secuencia regresiva de numeros
//n es conocido. La secuencia comienza con solo n si es impar y con nn si es par 
//Aumenta de 2 en 2 (n,n-1 n-1 n-1, n-2 n-2 n-2 n-2 n-2...)
//04 de octubre de 2017
//Se supone que los datos ingresados son correctos
//Alumno: Carlos Felipe Alonso Caro

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int n;
void esc_sec(int);
n=6;
esc_sec(n);
}


esc_sec(int n)
{
int p,q,r,k;
q=0;
p=1;
r=n;
k=q;
if ((n/2)*2==n)
	{
 printf("%d,",n);
	while (p<=r+1)
			{
		 	p++;
	 	 	while (q<=p)
	 			 {
	 			  printf("%d",n);	
				  q++;
				 }
		 	printf(",");
		 	q=k-1;
		 	k=k-1;
		 	n=n-1;  
			}	
	}
else 
{
 while (q<=p)
 	{
 	 printf("%d",n);	
	 q++;
	}
	printf(",");
	q=k-1;
	k=k-1;
	n=n-1;	
 while (p<=r)
 	{p++;
	 	 	while (q<=p)
	 			 {
	 			  printf("%d",n);	
				  q++;
				 }
		 	printf(",");
 	q=k-1;
	k=k-1;
	n=n-1;	 
	 
	}
}
}
