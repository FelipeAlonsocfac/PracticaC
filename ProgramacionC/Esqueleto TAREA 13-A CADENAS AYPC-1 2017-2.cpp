#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MCC   20      // Máxima cantidad de cadenas
#define LC    15      // Máxima longitud de una cadena de caracteres más 1. 

/* Escuela Colombiana de Ingeniería
   Algoritmos y programación de computadores (AYPC-1)
   Profesora: ingeniera Patricia Salazar Perdomo
   Estudiante: Nombre Apellidos
   Tarea No. 13 A: cadenas de caracteres, muy básico. Desarrolle la opción 2.
   3 de noviembre de 2017
*/

int main(void)
{
char palabras[MCC][LC]={"partido","democracia","sentido", "silencio", "compromiso", "impunidad","lucidez","valores","solidaridad", "poder", "intereses", "castigo","prebenda"};
char una_pal[LC+8]="De cantidad de letras";
int cant_pal=13, opc;

void lista_pal(char [MCC][LC], int); // Palabras existentes
void cambia_lista(char [MCC][LC],int , char [LC]);             // Cambia la lista de Palabras

    do{
        system("cls");
        printf ("\n\n\t*** Operaciones con cadenas de caracteres ***\n");
        printf ("\n\t1. Listar palabras\n");        
        printf ("\n\t2. Cambiar la lista de palabras\n");    // Dos rutinas, una que las halla y otra que las escribe.                                    
        printf ("\n\t3. Salir\n");
        printf ("\n\tDe opcion >> ", 130, 162);
        scanf("%d",&opc);
        system("cls");
        switch (opc)
        {
               case 1: lista_pal(palabras, cant_pal);
                       break;
               case 2: cambia_lista(palabras, cant_pal,una_pal);
                       break;
        }
        system ("pause");
    }while (opc != 3); 
}

void lista_pal(char pal[MCC][LC], int cp)                                                   
{
int pp;
system("cls");
printf("\n\n\tP A L A B R A S\n\n");
for (pp=0; pp < cp; pp++) 
    printf("%2d. %s\n", pp+1, pal[pp]);
}

void cambia_lista(char pal[MCC][LC], int cant_pal, char una_pal[LC])
{
int pide_entero(int , int, const char [LC]);
void pide_pal(char [MCC][LC],int);
int cp;

cp=pide_entero(0,cant_pal,una_pal);
pide_pal(pal,cp);
}                              

int pide_entero (int min, int max, const char mensaje[LC])
{
int num;
do {
	printf ("%s (entre %d y %d) ",mensaje,min+1,max);
	scanf("%d",&num);
}
while (num < min || num > max);
return num;
}
                                  
void pide_pal(char pal[MCC][LC], int cp)
{
int cont;

cont=0;
printf("\n\n");
while (cont<cp)
	{
	 printf("\nDe palabra #%d:\n\t",cont+1);
	 scanf("%s",pal[cont]);
	 cont ++;	
	}
}

