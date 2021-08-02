// Escuela Colombiana de Ingeniería
// Asignatura: Algoritmos y programación de computadores (AYPC-1)
// Profesora: ingeniera Patricia Salazar Perdomo
// 27 de septiembre de 2017
// Ejemplo de programita modular en C: pide un número que debe pertenecer a un intervalo y lo escribe.

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int num;
// Prototipo
void pide_entero(int, int, int *, char [ ]);
void esc_entero(int);

pide_entero(1, 20, &num, "Cantidad de estudiantes"); // Se espera un número que pertenece a [1,20]. 
esc_entero(num);

printf ("\n\n\tTrabajo terminado.\n\n");
system("pause");
}

// Definición
void pide_entero(int min, int max, int *num, char mens[ ])
{
*num = min - 1; // Fuerza la entrada a la estructura while
while (*num < min || *num > max)
{
	printf ("\n\t%s (entre %d y %d): ",mens,min,max);
	scanf("%d",num);
}
}

void esc_entero(int num)
{
    printf ("\n\tEl n%cmero dado fue %d.\n\n",163,num);    
}
