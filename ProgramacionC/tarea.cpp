//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Tarea Programacion C #1. Parte A
//Pedir las longitudes de los cuatro lados de un cuadrilatero y hallar su perimetro.
//Si es un cuadrado hallar su Área
//Si es un rectángulo hallar su lado mas largo
//
//21 de Septiembre de 2017
//Se supone que los datos ingresados son correctos

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
float l1,l2,l3,l4,perimetro,area,lgrande;
printf("Si me da las longitudes de los cuatro lados de un cuadrilatero,hago lo siguiente:");
printf("\na.hallo el perimetro");
printf("\nb.supongo que se trata de un cuadrado si los lados son iguales y hallo su area");
printf("\nc.hallo el lado mas largo si no es un cuadrado");
printf("\nIngrese longitud del lado 1:");
scanf("%f",&l1);
printf("\nIngrese longitud del lado 2:");
scanf("%f",&l2);
printf("\nIngrese longitud del lado 3:");
scanf("%f",&l3);
printf("\nIngrese longitud del lado 4:");
scanf("%f",&l4);
perimetro=l1+l2+l3+l4;
printf("\nEl perimetro del cuadrilatero de lados %f, %f, %f, %f   es: %f.",l1,l2,l3,l4,perimetro);
if (l1==l2 && l2==l3 && l3==l4)  
	{
	area=l1*l2;
	printf("\nel area del cuadrado es %f",area);
	}
else 
	{
	lgrande=l1;
	if (l2>=l1 && l2>=l3 && l2>=l4) lgrande=l2;
	if (l3>=l1 && l3>=l2 && l3>=l4) lgrande=l3;
	if (l4>=l1 && l4>=l2 && l4>=l3) lgrande=l4;
	printf("\nEl lado mas largo mide: %f",lgrande);
	}
printf("\nFin de la tarea.");	
	
}



