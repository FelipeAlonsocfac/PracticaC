/* 	Escuela Colombiana de Ingeniería
	Algoritmos y programación de computadores (AYPC), grupo 1	
	Profesora: ingeniera Patricia Salazar Perdomo
	Estudiante: 
	Completar este programita modular en lenguaje C con vectores para que haga lo siguiente,
	invocando lo que se especifica (función o procedimiento):
	a.	Función que calcule el producto escalar de los dos vectores.
	b.	Procedimiento que halle el menor del primer vector y diga en qué posición está.
	c.	Función o procedimiento que sume las potencias de 2 que hay en el segundo vector. Debe usar la función es_pot_de_2 que se da. 
	Fecha actual: 11 de octubre de 2017
	Examen del segundo tercio, parte 3 (30%)
*/
#include <stdio.h>
#include <stdlib.h>
#define MTV 20

int main(void)
{
int vector1[MTV], vector2[MTV],tv, prod_esc, menor, pos_menor, s_pot2;
/* Prototipos */
void datosvectores(int [ ], int [ ], int*);
int producto_esc(void);
void menorypos(void);
void suma_pot2(void);	// El estudiante decide si implementa una función o un procedimiento
void resultados(int [ ], int [ ], int);

printf ("\n\nEste programita pide dos vectores num%cricos y los escribe.\n",130);
printf ("Tambi%cn calcula el producto escalar, halla y escribe el menor que hay en el primer vector y la posici%cn en la que est%c.\n",130,162,160);
printf ("Finalmente, suma las potencias de 2 que hay en el segundo vector.\n\n");
datosvectores(vector1, vector2, &tv);
prod_esc = producto_esc();
menorypos();
suma_pot2();	// El estudiante decide si implementa una función o un procedimiento
resultados(vector1, vector2, tv);
printf("\n\nFin.\n\n");
system ("pause");
}

datosvectores(int v1[ ], int v2[ ], int *tv)
{
void pide_entero (int , int, int *, const char [ ]);
void leevec(int [ ], int);

pide_entero (0, MTV, tv, "Cantidad de valores");
leevec(v1, *tv);
leevec(v2, *tv);
}

void pide_entero (int min, int max, int *num, const char mensaje[ ])
{
do {
	printf ("%s (entre %d y %d) ",mensaje,min+1,max);
	scanf("%d",num);
}
while (*num < min || *num > max);}

void leevec(int v[ ], int tv)
{
int pos;
printf("\nN%cmeros enteros:\n\n",163);
for (pos=0; pos < tv; pos++){
    printf("\n>> ",pos);
    scanf ("%d",&v[pos]);
}
}

int producto_esc(void)
{
	
}

void menorypos(void)
{
	
}

void suma_pot2(void)
{
int es_pot_de_2(int);	

}

int es_pot_de_2(int num) // Averigua si num es potencia de 2
{
int valor;

valor = 1;
while(valor < num)
    valor = valor * 2;

if(valor == num)
	return 1;	// num es potencia de 2
else 
	return 0;   // num no es potencia de 2
}

void resultados(int v1[ ], int v2[ ], int tv) 
{
void escvec(int [ ], int, const char [ ]);
printf ("\n\nDados: \n\n");
escvec(v1, tv, "Vector 1");
printf ("\ny: \n");
escvec(v2, tv, "Vector 2");
// printf ("\n\nProducto escalar = %d, menor del vector 1 = %d, ubicado en la posición %d, y suma de las potencias de 2 en vector 2 = %d\n",prod_esc, menor, posmenor, suma_pot2);
}

void escvec(int v[ ], int tv, const char cual_vec[ ])
{
int pos;
printf ("\n%s\n", cual_vec);
for (pos=0; pos < tv; pos++)
    printf("%d ",v[pos]);
}

