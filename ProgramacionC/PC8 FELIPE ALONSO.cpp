//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Entrega por correo prueba corta#1
//pide numeros para guardarlos en un vector ademas de el tamaño del vector
//halla el producto de los numeros dados y el mayor de estos
//Finalmente, halla la suma de los numeros que sean primos y escribe todos los resultados
//06 de octubre de 2017
//Se supone que los datos ingresados son correctos
//Alumno: Carlos Felipe Alonso Caro



#include <stdio.h>
#include <stdlib.h>
#define MTV 20

int main(void)
{
int vector[MTV], tv, prod, sp, mayor;
/* Prototipos */
void datosvec(int [], int*);
int producto(int [],int);
int mayor_vec(int [],int);
int suma_primos(int [],int);
void resultados(int [ ], int, int, int, int);

printf ("\n\n%cHola! Este programita pide nucmeros y los escribe.\n\nTambien hace lo siguiente:\n1. Calcula el producto de los numeros que haya dado el usuario.\n2. Halla el mayor de todos.\n3. Suma los que sean primos.\n\n",173, 163, 130, 163  );
datosvec(vector, &tv);
prod = producto(vector,tv);
mayor = mayor_vec(vector,tv);
sp = suma_primos(vector,tv);
resultados(vector, tv, prod, mayor, sp);
printf("\n\nFin.\n\n");
system ("pause");
}

void datosvec(int v[], int *tv)
{
void pide_entero (int , int, int *, const char []);
void leevec(int [], int);

pide_entero (0, MTV, tv, "Cantidad de valores");
leevec(v, *tv);
}

void pide_entero (int min, int max, int *num, const char mensaje[ ])
{
do {
	printf ("%s (entre %d y %d) ",mensaje,min+1,max);
	scanf("%d",num);
	}
while (*num < min || *num > max);}

void leevec(int v[], int tv)
{
int pos;
printf("\nNucmeros:\n\n",163);
for (pos=0; pos < tv; pos++){
    printf("\n>> ",pos);
    scanf ("%d",&v[pos]);
}
}

int producto(int vector[],int tv)
{int p,cont;

cont=0;
p=1;
while (cont<=tv-1)
{
p=p*vector[cont];
cont++;	
}
 return p;	
}

int mayor_vec(int vector[],int tv)
{int m,cont;

cont=0;
m=vector[0];

while (cont<=tv-1)
{
if (vector[cont]<vector[cont+1]) m=vector[cont+1];
cont++;
}	
return m;
}


int suma_primos(int vector[],int tv)
{
int cont,s_p,es_p,n;	
void es_primo(int, int *);

cont=0;
s_p=0;
n=0;

while (cont<=tv-1)
	{
	 n=vector[cont];
	 es_primo(n,&es_p); 	
	 if (es_p==1) s_p=s_p+n;
	 cont++;
	}
return s_p;
}


void es_primo(int num, int * es_p)
{
int posdiv;
*es_p = 1;
posdiv = 2;
while (*es_p == 1 && posdiv <= num/2) {
      if ((num/posdiv)*posdiv == num) *es_p = 0;
      posdiv++;
}
}

void resultados(int vector[], int tv, int prod, int mayor, int sp) 
{
void escvec(int [ ], int);
printf ("\n\nDados los n%cmeros: \n\n",163);
escvec(vector, tv);
printf ("\n\nProducto = %d, mayor = %d y suma de los primos = %d\n",prod, mayor, sp);
}

void escvec(int v[], int tv)
{
int pos;
for (pos=0; pos < tv; pos++)
    printf("%d ",v[pos]);
}

