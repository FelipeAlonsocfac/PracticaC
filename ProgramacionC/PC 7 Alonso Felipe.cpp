#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MF   12      // Máxima cantidad de filas
#define MC   12      // Máxima cantidad de columnas
#define MP   15      // Máxima cantidad de palabras
#define MLP  20      // Máxima longitud de una palabra

/* Escuela Colombiana de Ingeniería
   Algoritmos y programación de computadores (AYPC-1)
   Profesora: ingeniera Patricia Salazar Perdomo
   Estudiante: Carlos Felipe Alonso Caro
   Prueba corta No. 7 (vale por dos)
   11 de noviembre de 2017
   Se da una matriz de números reales y una lista de palabras. Debe hacer lo siguiente:
   - 1. Calcular el producto de los números que hay en la matriz tabla. Escribir la matriz y el producto.
   - 3. Copiar en un vector las palabras de cierto tamaño dado por el usuario. Luego, escribir dicho vector.
   - 4. Contar y escribir las vocales de cada palabra.
   - 5. Unir todas las palabras en una sola cadena y luego escribirla.
   - 6. Averiguar si una palabra está en la lista de palabras. Si está, decir en qué posición la encontró.      
   
   Importante: 
   - Debe utilizar las rutinas strlen, strcpy, strcat y strcmp, según corresponda.
   - Cada punto vale una unidad. 
   - La evaluación la haré con otros datos de entrada en los que pueden cambiar las dimensiones de los arreglos.
   - Debe hacer mínimo las opciones 1, 4 y (3, 5 o 6) para obtener 5.0. Máxima calificación: 6.0
*/

int main(void)
{
float tabla[MF][MC]={{1,2,3,1},{4,3,5,6},{2,1,3,1}};
int nf = 3, nc = 4;

char pal[MP][MLP]={"silencio","nervios","dudas","arrepentimiento","seguridad","felicidad","tranquilidad","balance","estres","presion"};
char todas_pal[MP*MLP];

int vocales[MP];
int cp=10,opc;

void producto_mat(float [MF][MC], int, int);
void muestra_pal(char [MP][MLP], int);
void pal_x_tam(void);
void cuenta_voc(char [MP][MLP],int [MP],int );
void une_pal(char [MP][MLP],char [MP*MLP],int);
void averigua_pal(char [MP][MLP], int); 

    do{
        system("cls");
        printf ("\n\n\tArreglos y cadenas de caracteres\n",130);
        printf ("\n\t1. Producto - matriz\n");
        printf ("\n\t2. Ver palabras\n");
        printf ("\n\t3. Copia en un vector las palabras de cierto tama%co\n",164);
        printf ("\n\t4. Cuenta vocales por palabra\n");
        printf ("\n\t5. Une todas las palabras en una sola\n");
        printf ("\n\t6. Averigua por una palabra\n"); 
        printf ("\n\t7. Salir\n");
        printf ("\n\tD%c opci%cn >> ", 130, 162);
        scanf("%d",&opc);
        system("cls");
        switch (opc)
        {
               case 1: producto_mat(tabla, nf, nc);
                       break;
               case 2: muestra_pal(pal, cp);
                       break;
               case 3: pal_x_tam();
                       break;
               case 4: cuenta_voc(pal,vocales,cp);
                       break;
               case 5: une_pal(pal,todas_pal,cp);
                       break;
               case 6: averigua_pal(pal,cp);
                       break;
        }
        system ("pause");
    }while (opc != 7); 
    printf ("\n\nF I N.");
}



void producto_mat(float tabla[MF][MC], int nf, int nc)
{
int prod;	
	
void muestra_mat(float [MF][MC], int, int);
int prod_mat(float [MC][MC], int, int);


printf ("\n\nDada la matriz:\n\n");
muestra_mat(tabla,nf,nc);
prod=prod_mat(tabla,nf,nc);
printf("\n\nSu producto es %d\n\n",prod);
}

int prod_mat(float tabla[MC][MC], int nf, int nc)
{
int cont1,cont2,p;

cont1=0;
cont2=0;
p=1;
while (cont1<nf)
	{
	 while (cont2<nc)
		{
		 p=p*tabla[cont1][cont2];
		 cont2 ++;	
		}
	cont2=0;
	cont1 ++;
	}	
return p;	
}





void muestra_mat(float tabla[MF][MC], int nf, int nc)
{
int f, c;
printf ("\n\n\t\tTabla\n\n\t");
for (f=0; f<nf; f++)
{
    for (c=0; c<nc; c++)
    	printf ("%3.1f   ",tabla[f][c]);
    printf("\n\t");
}
printf("\n\n");
}





void pal_x_tam(void)
{
int lp;
void pide_entero (int , int, int *, const char [ ]);
pide_entero (0, MLP, &lp, "Longitud de las palabras");
printf ("\n\npal_x_tam EN CONSTRCCION\n\n");
}





void pide_entero (int min, int max, int *num, const char mensaje[ ])
{
do 
{
	printf ("%s (entre %d y %d) ",mensaje,min+1,max);
	scanf("%d",num);
}
while (*num < min || *num > max);
}





void cuenta_voc(char pal[MP][MLP],int vocales[MP],int cp)
{
int cont;
int n_vocales(char [MP][MLP], int);

cont=0;
while (cont<cp)
	{
	 vocales[cont]=n_vocales(pal,cont);	
	 printf("\n\t%s , %d",pal[cont],vocales[cont]);
	 cont++;	
	}
printf("\n\n");	
}

int n_vocales(char pal[MP][MLP], int cont)
{
int cont1,n;

n=0;
cont1=0;
while(cont!='/0')
	{
	 if (pal[cont][cont1]=='a' || pal[cont][cont1]=='e' || pal[cont][cont1]== 'i' || pal[cont][cont1]=='o' || pal[cont][cont1]=='u') n=n+1;
	 cont1 ++;	
	}
return n;	
}




void une_pal(char pal[MP][MLP],char todas_pal[MP*MLP],int cp)
{
int cont;

todas_pal[0]=':';
cont=0;	
while(cont<cp)
	{
	 strcat(todas_pal, pal[cont]);
	 cont ++;
	}
printf("\n\n%s\n\n",todas_pal);
 }







void averigua_pal(char pal[MP][MLP], int cp)
{
int cont1,cont2,tip,x;	
char usuario[MLP];

void pide_una_pal(char [MLP]);


pide_una_pal(usuario);

cont1=0;
cont2=0;
while (cont1<cp)
	{
	 tip=strcmp(pal[cont1], usuario);	
	 cont1++;
	 if (tip==0) 
	 	{
	 	 x=cont1;	
		 cont1=cp+1;
		 
		}
	}

if (tip==0) printf("La palabra %s esta en la posicion %d\n\n",usuario,x);
else printf("la palabra %s no esta contenida\n\n",usuario);
}

void pide_una_pal(char palabra[MLP])
{
	printf ("\n\nIngrese palabra ");
	scanf ("%s",palabra);
}












void muestra_pal(char pal[MP][MLP], int cp)
{
int pos;
printf ("\n\nP A L A B R A S\n\n");
for (pos=0; pos<cp; pos++)
      printf("\n\t%2d. %s ",pos+1, pal[pos]);
printf("\n\n");
}
