//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Ejercicio Programacion C #1 a)
//Pedir al usuario dos numeros enteros positivos a y b y averiguar si b es una potencia de a
//Es decir, b =a^n
//n mayor o igual que 0
//26 de Septiembre de 2017
//Se supone que los datos ingresados son correctos
//Alumno: Carlos Felipe Alonso Caro

#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	
int base1,base2,b,contador,k;

printf("Hola. Dame dos numeros y averiguare si el segundo es potencia del primero");
printf("\nDame el primer numero:\n");
scanf("%d",&base2);
printf("\nDe segundo numero:\n");
scanf("%d",&b);
base1=1;
if (b==1) 
	{
	k=1;
	printf("\nel numero 1 es potencia de %d por que %d^0 es igual a 1",base2,base2);
	}	
contador=1;
while (contador<(b/2))
	{
	base1=base2*base1;
	if (base1==b)	
		{
		printf("\nEl numero %d, es potencia de %d por que %d^%d es igual a %d",b,base2,base2,contador,b);
		k=1;
		}	
	contador=contador+1;
	}
if (k==0) printf("\nEl numero %d no es potencia de %d",b,base2);
	
	
	
}
