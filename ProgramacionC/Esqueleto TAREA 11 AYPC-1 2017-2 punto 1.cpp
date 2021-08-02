//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Tarea Programacion C #1.a
//Construir rutina modular que escriba una secuencia regresiva de numeros
//n es dado por el usuario. La secuencia comienza con solo n si es impar y con nn si es par 
//Aumenta de 2 en 2 (n,n-1 n-1 n-1, n-2 n-2 n-2 n-2 n-2...)
//04 de octubre de 2017
//Se supone que los datos ingresados son correctos
//Alumno: Carlos Felipe Alonso Caro


//Se da este programa modular en lenguaje C en el que existe una matriz de ventas correspondiente a nv vendedores y cm meses. 
//Complételo para que obtenga la mayor venta, qué vendedor la hizo y en qué mes. LUEGO, escriba los resultados.
   


#include <stdio.h>
#include <stdlib.h>
#define MV 10      // Máxima cantidad de vendedores
#define NM 12      // Meses del año


void esc_ventas(int [MV][NM], int, int);

int main(void)
{
int ventas[MV][NM]={{100, 150, 200, 10, 750, 100, 150, 200, 10, 750, 100, 150},{320, 550, 600, 610, 630, 705, 731, 801, 850, 856, 903,925}, {800, 80, 500, 45, 22, 800, 80, 500, 45, 22, 800, 80}, {190, 300, 340, 390, 410, 190, 300, 340, 390, 410, 190, 300}, {100, 150, 200, 280, 350, 400, 450, 600, 601, 630, 635, 638}, {10, 150, 40, 100, 75, 10, 150, 40, 100, 75, 10, 150}, {65, 67, 94, 101, 110, 65, 67, 94, 101, 110, 65, 67}, {100, 102, 120, 135, 137, 140, 150, 170, 171, 173, 175, 180}};
int cv=8, cm=12; // cv: cantidad de vendedores, cm: cantidad de meses
int may_ven,num_vend,mes;

void busca_mayor_venta(int [MV][NM],int,int,int *,int *,int *);
void esc_resultado(int [MV][NM], int, int,int ,int ,int );

printf ("\n\nEste programa obtiene la mayor venta y dice que vendedor la hizo y en que mes.\n\n\n",130,130);
esc_ventas(ventas, cv, cm);
busca_mayor_venta(ventas,cv,cm,&may_ven,&num_vend,&mes);
esc_resultado(ventas, cv, cm,may_ven,num_vend,mes);
printf("\n\nFIN.Espero haber sido de ayuda.\n\n");
system ("pause");
}



void esc_ventas(int ventas[MV][NM], int cv, int cm)
{
int v, m;

printf("\n\n\t**** VENTAS (en millones de pesos) ****\n\n\t\t1    2    3    4    5    6    7    8    9   10   11   12\n\n\t");

for (v=0; v < cv; v++)
{
	printf("%d --> ",v+1);
    for (m=0; m < cm; m++)
	     printf("%4d ",ventas[v][m]);
    printf("\n\n\t");
}
}



void busca_mayor_venta(int ventas[MV][NM],int cv,int cm,int *may_ven,int *num_vend,int *mes)
{
int cont1,cont2;

*may_ven=0;
cont1=0;
cont2=0;
while (cont1<cv)
	{
	 while (cont2<cm)
	 	{
		 if (ventas[cont1][cont2]>*may_ven) 
		 	{
			 *may_ven=ventas[cont1][cont2];
			 *num_vend=cont1;
			 *mes=cont2;
			}
		 cont2 ++;	
		}
	cont2=0;	
	cont1 ++;
	}
}

void esc_resultado(int ventas[MV][NM], int cv, int cm,int may_ven,int num_vend,int mes)
{
     int v;
	 system("cls");
     printf("\n\n\tR E S U L T A D O S\n\n");
     printf("\n\nDe acuerdo con esta matriz de ventas: \n\n");
     esc_ventas(ventas, cv, cm);
     printf("\n\nLa mayor venta fue de $%d y la hizo el vendedor %d en el mes %d",may_ven,num_vend+1,mes+1);
}
