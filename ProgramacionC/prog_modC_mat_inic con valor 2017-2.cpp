/* ESCUELA COLOMBIANA DE INGENIERÍA
   Algoritmos y programación de computadores (AYPC-1)
   Profesora: ingeniera Patricia Salazar Perdomo
   Programita modular en lenguaje C que llena una matrizcon cierto valor.
   4 de octubre de 2017
*/

#include <stdio.h>
#include <stdlib.h>
#define MF 10
#define MC 10

int main(void)
{
int tablero[MF][MC], nf, nc;
/* PROTOTIPOS */
void inic_tab(int [MF][MC], int*, int*);
void escribe_mat(int [MF][MC], int, int, const char [ ]);

printf ("\n\nHola... Este programita llena un tablero con cierto valor.\n\n");
inic_tab(tablero, &nf, &nc);
escribe_mat(tablero, nf, nc, "Tablero");
printf("\n\nAdi%cs.\n\n", 162);
system ("pause");
}

void inic_tab(int m[MF][MC], int *nf, int *nc)
{
void pide_entero (int , int, int *, const char []);
void llena_mat_valor(int [MF][MC], int, int, int);

pide_entero (0, MF, nf, "Filas de la matriz");
pide_entero (0, MC, nc, "Columnas de la matriz");
llena_mat_valor(m, *nf, *nc, 10);
}

void pide_entero (int min, int max, int *num, const char mensaje[])
{
do {
	printf ("%s (entre %d y %d) ",mensaje,min+1,max);
	scanf("%d",num);
}
while (*num < min || *num > max);
}

void llena_mat_valor(int m[MF][MC], int nf, int nc, int valor)
{
int fil, col;
for (fil=0; fil < nf; fil++)
    for (col=0; col < nc; col++)		
		m[fil][col] = valor;
}


void escribe_mat(int m[MF][MC], int f, int c, const char cual_mat[ ])
{
int fil, col;
printf("\n\n**** %s ****\n\n",cual_mat);
for (fil=0; fil < f; fil++)
{
    for (col=0; col < c; col++)
	     printf ("%d ",m[fil][col]);
    printf("\n");
}
}
