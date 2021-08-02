//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Tarea Programacion C #11.b
//Dado un programa modular en lenguaje C en el que existe una matriz de ventas correspondiente a nv vendedores cm meses. 
//Se completa para que obtenga en qué mes vendió más cada vendedor y cuál fue el monto de esa venta. luego, se escriben los resultados en una lista enumerada.
//26 de octubre de 2017
//Alumno: Carlos Felipe Alonso Caro
    


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
int may_vent[MV][1],num_mes[MV][1];
int num[MV][1]={{1},{2},{3},{4},{5},{6},{7},{8}};

void busca_mayor_venta(int [MV][NM],int,int,int *,int *,int *);
void esc_resultado(int [MV][NM], int, int,int ,int ,int );
void llen_may_vent(int [MV][1], int);
void llen_tabla(int [MV][NM],int,int,int [MV][1],int [MV][1]);
void imp_tabla(int [MV][1], int [MV][1], int [MV][1], int);

printf ("\n\nEste programa obtiene la mayor venta y dice que vendedor la hizo y en que mes.\n\n\n",130,130);
printf("\n\nLuego,escribe una tabla con el mes en que vendio mas cada vendedor y cual fue el monto de esa venta\n\n");

esc_ventas(ventas, cv, cm);
busca_mayor_venta(ventas, cv, cm, &may_ven, &num_vend, &mes);
esc_resultado(ventas, cv, cm, may_ven, num_vend, mes);
llen_may_vent(may_vent,cv);
llen_tabla(ventas, cv, cm,may_vent,num_mes);
imp_tabla(num,may_vent,num_mes,cv);

printf("\n\nFIN.Espero haber sido de ayuda.\n\n\t");
system ("pause");
}


void imp_tabla(int num[MV][1], int may_vent[MV][1],int num_mes[MV][1],int cv)
{
void imp(int [MV][1], int [MV][1], int [MV][1], int);

printf("\n\nVendedor    Venta     Mes\n\n");
imp(num,may_vent,num_mes,cv);	
}


void imp(int num[MV][1], int may_vent[MV][1], int num_mes[MV][1], int cv)
{
int cont;

cont=0;
while (cont<cv)
	{
	 printf("%d.          $%d      %d\n",num[cont][0],may_vent[cont][0],num_mes[cont][0]);
	 cont ++;	
	}
	
}




void llen_tabla (int ventas[MV][NM],int cv,int cm,int may_vent[MV][1],int num_mes[MV][1])
{
int cont1, cont2;

cont1=0;
cont2=0;
while (cont1<cv)
	{
	 while (cont2<cm)
	 	{	
	 	 if (ventas[cont1][cont2]>may_vent[cont1][0]) 
	 	 	{
			 may_vent[cont1][0]=ventas[cont1][cont2];
			 num_mes[cont1][0]=cont2+1;
			}
		 cont2 ++;	
		}
	 cont2=0;
	 cont1 ++;	
	}
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
     printf("\n\n\tR E S U L T A D O S\n\n");
     printf("\n\nDe acuerdo con esta matriz de ventas: \n\n");
     esc_ventas(ventas, cv, cm);
     printf("\n\nLa mayor venta fue de $%d y la hizo el vendedor %d en el mes %d.",may_ven,num_vend+1,mes+1);
}

void llen_may_vent(int may_vent[MV][1], int cv)

{
int cont;

cont=0;
while (cont<cv)
	{
	 may_vent[cont][0]=0;
	 cont ++;
	}	
}

