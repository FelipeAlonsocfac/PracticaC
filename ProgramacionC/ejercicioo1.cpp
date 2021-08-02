//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Ejercicio Programacion C #1
//pedir  n estudiantes nombre y cantidad de años que sus padres llevan juntos
//Luego averiguar cuantos ya cumplieron bodas de plata, los de cual estudiante estan proximo y los decual le falta mass
//indicar cuantos años les falta
//22 de Septiembre de 2017
//Se supone que los datos ingresados son correctos
//Alumno: Carlos Felipe Alonso Caro

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int t_juntos[60],contador,numero_estudiantes,bodas,mayor,menor,cas_mas,cas_menos;
char nom_est[60][20];

printf("Hola. Dame los nombres de los estudiantes y cuantos años llevan casados sus padres");
printf("\nLuego te dire cuantos ya cumplieron bodas de plata, el que esta mas cerca y mas lejos de cumplirlas");
contador=0;
printf("\nCuantos estudiantes son?:\n");
scanf("%d",&numero_estudiantes);
while (contador<=numero_estudiantes-1)
	{
	printf("\nDe #%d nombre:\n",contador+1);	
	scanf("%s",nom_est[contador]);
	printf("\nCuantos años llevan casados sus padres?:\n");
	scanf("%d",&t_juntos[contador]);
	contador=contador+1;
	}
bodas=0;
contador=0;
menor=25;
mayor=25-t_juntos[0];
	while (contador<=numero_estudiantes-1)
		{
		if (t_juntos[contador]>=25) 
			{
				bodas=bodas+1;
			}	
			else 
			{
				if(t_juntos[contador]>25-menor) 
				{
					menor=25-t_juntos[contador];
					cas_menos=contador;
				} 
				if(t_juntos[contador]<25-mayor) 
				{
					mayor=25-t_juntos[contador];
					cas_mas=contador;
				}
			}
		contador=contador+1;
		}	
printf("\nLos papas de %d estudiantes ya cumplieron las bodas de plata.",bodas);
printf("\nA los papas de %s es a los que mas les falta ,%d años,",nom_est[cas_mas],mayor);
printf("\nA los papas de %s es a los que menos les falta ,%d años,",nom_est[cas_menos],menor);
printf("\nEspero haber sido de ayuda");
	
}
