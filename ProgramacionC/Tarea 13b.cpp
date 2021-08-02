/* 
Escuela Colombiana de Ingeniería
Algoritmos y programación de computadores (AYPC-1)
Profesora: ingeniera Patricia Salazar Perdomo
Estudiante: Carlos Felipe Alonso Caro
Tarea No. 13-B 2017-2. 
5 de noviembre de 2017
Se da una lista de palabras y una matriz de enteros que contiene en la columna 1 los subíndices de las palabras en orden ascendente 
partiendo de -1 en la columna cero y los subíndices de las palabras en orden desscendente partiendo de -1 en la columna 1.
*/
#include <stdio.h>
#include <stdlib.h>
#define MP   15      // Máxima cantidad de palabras
#define MLP  20      // Máxima longitud de una palabra



int main(void)
{
int orden_pal[MP+1][2]={{1,4},{-1,5},{0,7},{6,3},{5,2},{3,-1},{4,6},{2,0},{7,1}};
char pal[MP][MLP]={"guayaba","manzana","fresa","uva","naranja","arandano","pera","mandarina"};
int cp=8,opc;

void muestra_pal(char [MP][MLP], int);
void muestra_pal_asc_desc(int [MP+1][2], char [MP][MLP],int, int );

    do{
        system("cls");
        printf ("\n\n\tPALABRAS, orden alfab%ctico ascendente y descendente\n",130);
        printf ("\n\t1. Ver palabras\n");
        printf ("\n\t2. Palabras - ascendente\n");
        printf ("\n\t3. Palabras - descendente\n");
        printf ("\n\t4. Salir\n");
        printf ("\n\tDe opcion >> ", 130, 162);
        scanf("%d",&opc);
        system("cls");
        switch (opc)
        {
               case 1: muestra_pal(pal, cp);
                       break;
               case 2: muestra_pal_asc_desc(orden_pal,pal,cp,opc);
                       break;
               case 3: muestra_pal_asc_desc(orden_pal,pal,cp,opc);
                       break;
        }
        system ("pause");
    }while (opc != 4); 
}

void muestra_pal_asc_desc(int orden_pal[MP+1][2], char pal[MP][MLP], int cp, int opc)
{
int cont,b,x,y;
int av_pos(int [MP+1][2], int, int, int, int);

cont=0;
b=-1;

if (opc==2)
{	x=0;
	y=1;	
}

else
{	x=1;
	y=0;
}

b=av_pos(orden_pal,b,cp,x,y);
printf("\nPALABRAS, opcion %d:\n\n\n\n",opc);
while (cont<cp)
	{
	printf("\t%d.%s\n",cont+1,pal[b]);
	b=av_pos(orden_pal,b,cp,x,y);
	cont ++;
	if (b==-1) cont=cp+1;	
	}	
}



int av_pos(int orden_pal[MP+1][2], int b, int cp, int x, int y)
{
int cont,s;

s=0;
cont=0;
while (cont<=cp)
	{
	 if (b==orden_pal[cont][x]) s=orden_pal[cont][y];
	 cont ++;	
	}
return s;	
}



void muestra_pal(char pal[MP][MLP], int cp)
{
int pos;
printf ("\n\nP A L A B R A S\n\n");
for (pos=0; pos<cp; pos++)		printf("\n\t%d. %s ",pos+1, pal[pos]);
printf("\n\n");
}
