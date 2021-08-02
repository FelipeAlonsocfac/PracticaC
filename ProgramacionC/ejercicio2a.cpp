//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Ejercicio Programacion C #2.a
//Aaveriguar si dos numeros enteros son amigos
//27 de Septiembre de 2017
//Se supone que los datos ingresados son correctos
//Alumno: Carlos Felipe Alonso Caro
  
  
#include <stdio.h>
#include <stdlib.h>
  
int main(void)
{
int n1,n2,sd1,sd2;
  
void pide_num(int *, int *);
void suma_divisores(int,int *,int,int *);
void verifica(int,int,int,int);
  
printf("Averiguo si dos numero enteros son amigos.");
printf("\nEs decir, si la suma de los divisores del primero es igual a la suma de los divisores del segundo y viceversa");

pide_num(&n1,&n2);
suma_divisores(n1,&sd1,n2,&sd2);
verifica(n1,sd1,n2,sd2);
  
printf("\nFin");	
}
   
 
 
 
 
 
 
 
void pide_num(int *n1, int*n2)
{
printf("\nPrimer numero:\n");
scanf("%d",n1);
printf("\nSegundo numero:\n");
scanf("%d",n2);
}
 
 
void suma_divisores(int n1,int *sd1,int n2,int *sd2)
{
void suma_div(int,int *);
suma_div(n1,sd1);
suma_div(n2,sd2);		
}
  
 
void suma_div(int n,int *sd)
{
int pd;	
*sd=1;
pd=2;
while (pd<=(n/2))
{
if ((n/pd)*pd==n) *sd=*sd+pd;	
pd=pd+1;	
}
  
}
  
  
void verifica(int n1,int sd1,int n2,int sd2)
{
printf("\nLos numeros %d y %d",n1,n2);
if (n1!=sd2 || n2!=sd1) printf("\nNo");
printf(" son amigos");	
}
 
  
  
  
  
  

  
