//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Ejercicio Programacion C #1 b)
//Pedir un numero entero al usuario
//Escribir cada uno de sus digitos
//decir cuantos lo componen
//26 de Septiembre de 2017
//Se supone que los datos ingresados son correctos
//Alumno: Carlos Felipe Alonso Caro

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int num,suma,cf,cf2,contador,k,digitos;
printf("Hola. Dame un numero y te escribire sus digitos");
printf("\nAdemas te dire cuantos lo componen");
printf("\nDame el numero:\n");
scanf("%d",&num);	
k=0;
contador=1;
cf=1;
digitos=1;
while (contador>k)	
{
if ((num/cf)<9) k=2;
else 
	{
	digitos=digitos+1;
	cf=cf*10;
	}
 }	
printf("\nEl numero dado esta compuesto por:\n");
cf2=cf;
printf("%d,",num/cf);
contador=1;
k=0;
while (contador>k)
{
cf=cf/10;
printf("%d,",num%cf2/cf);
cf2=cf2/10;
if (cf==1) k=2;
}
printf("ademas tiene un total de %d digitos",digitos);	
printf("\nEspero haber sido de ayuda");	
}

