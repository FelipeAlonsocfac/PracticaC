//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Tarea Programacion C #1. Parte B
//Solicitar al usuario limites enteros positivos de un intervalo
//Si son pares, escribir los impares dentro del intervalo
//Si no escribir los primeros n multiplos del numeros
//"par impar"
//21 de Septiembre de 2017
//Se supone que los datos ingresados son correctos


#include<stdio.h>
#include<stdlib.h>

int main(void)
{
int li,ls,numimpar,impar,cantmul,cm,p;
printf("Dados los limites de un intervalo, hago lo siguiente: Si los limites son pares, escribo los numeros impares que pertenecen al intervalo.");
printf("\nEn caso contrario, escribo los primeros n multiplos del numero par mas pequeño que pertenece al intervalo");
printf("\nIngrese limite inferior:");
scanf("%d",&li);
printf("\nIngrese limite superior:");
scanf("%d",&ls);	
if ((li/2)*2==li && (ls/2)*2==ls)
{
	impar=li+1;
	printf("\nimpares que pertenecen al intervalo[%d,%d] Son:",li,ls);
	while (impar<=ls)
		{
		printf("%d,",impar);
		impar=impar+2;
		}
			
}
else 
	{
		if ((li/2)*2==li)
		numimpar=li+1;
		else 
		numimpar=li;
		
	printf("\nCuantos multiplos de %d quiere que escriba:",numimpar);
	scanf("%d",&cantmul);
	printf("Los primeros %d multiplos de %d, el impar mas pequeño que pertenece a [%d,%d] Son:",cantmul,numimpar,li,ls);
	cm=1;

	while (cm<=cantmul)
		{
		p=numimpar*cm;
		printf("%d,",p);
		cm=cm+1;
		}
	}

printf("\nF I N");
	
}
