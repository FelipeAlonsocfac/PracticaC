#include <stdio.h>
#include <stdlib.h>
#define MP   15      // Máxima cantidad de palabras
#define MLP  20      // Máxima longitud de una palabra

/* Escuela Colombiana de Ingeniería
   Algoritmos y programación de computadores (AYPC-1)
   Profesora: ingeniera Patricia Salazar Perdomo
   Estudiante: Nombre Apellidos
   Tarea No. 13-B 2017-2. 
   3 de noviembre de 2017
   Se da una lista de palabras y una matriz de enteros que contiene en la columna 1 los subíndices de las palabras en orden ascendente 
   partiendo de -1 en la columna cero y los subíndices de las palabras en orden desscendente partiendo de -1 en la columna 1.
   En el ejemplo, si se quiere orden ascendente, se observa que la primera palabra es arándano (-1, 5) y que le sigue la 2 (5, 2), 
   es decir, fresa, y así, sucesivamente.
   
   En orden descendente, la primera palabra es uva (3, -1), le sigue pera (6,3), etc.
   
   Importante: 
   - No se está pidiendo que ordene la lista de palabras.
   - Las pruebas se podrían hacer con más o menos palabras.
*/

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
int cont,b;
int av_pos(int [MP+1][2], int, int);
int av_pos_1(int [MP+1][2], int , int);

if (opc==2)
{
	cont=0;
	b=-1;
	b=av_pos(orden_pal,b,cp);
	printf("\nPALABRAS EN ORDEN ASCENDENTE:\n\n\n\n");
	while (cont<cp)
	{
	 	printf("\t%d.%s\n",cont+1,pal[b]);
	 	b=av_pos(orden_pal,b,cp);
	 	cont ++;
	 	if (b==-1) cont=cp+1;	
	}		
}
if (opc==3)
{
	cont=0;
	b=-1;
	b=av_pos_1(orden_pal,b,cp);
	printf("\nPALABRAS EN ORDEN DESCENDENTE:\n\n\n\n");
	while (cont<cp)
	{
	 	printf("\t%d.%s\n",cont+1,pal[b]);
	 	b=av_pos_1(orden_pal,b,cp);
	 	cont ++;
	 	if (b==-1) cont=cp+1;
	
}
}
}


int av_pos(int orden_pal[MP+1][2], int b, int cp)
{
int cont,s;

s=0;
cont=0;
while (cont<=cp)
	{
	 if (b==orden_pal[cont][0]) s=orden_pal[cont][1];
	 cont ++;	
	}
return s;	
}




int av_pos_1(int orden_pal[MP+1][2], int b, int cp)
{
int cont1,s1;

s1=0;
cont1=0;
while (cont1<=cp)
	{
	 if (b==orden_pal[cont1][1]) s1=orden_pal[cont1][0];
	 cont1 ++;	
	}
return s1;	
}



void muestra_pal(char pal[MP][MLP], int cp)
{
int pos;
printf ("\n\nP A L A B R A S\n\n");
for (pos=0; pos<cp; pos++)		printf("\n\t%d. %s ",pos+1, pal[pos]);
printf("\n\n");
}
