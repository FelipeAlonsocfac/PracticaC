//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Prueba Corta Programacion C #6
//inicializar dos vectores
//inicializar una matriz (fila,columna) en la que cada posicion es a^b
//Siendo 'a' la suma de la posicion fila en el vector 1 y columna en el 2
//Y siendo 'b' la suma de los valores de fila y columna
//01 de Noviembre de 2017
//Se supone que los datos ingresados son correctos
//Alumno: Carlos Felipe Alonso Caro



#include<stdio.h>
#include<stdlib.h>

#define N 20	

int main(void)
{
int vec1[N],vec2[N],mat[N][N],tv;

int ped_tam(void);
void llen_vec(int [N], int);
void llen_mat(int [N], int [N], int [N][N],int); 	
void final(int [N], int [N], int [N][N],int);

printf("Hola. Este programa inicializa dos vectores dados por ti");
printf("\n\nLuego inicializa una matriz (fila,columna) en la que cada posicion es a^b");
printf("\n\nSiendo 'a' la suma de la posicion fila en el vector 1 y columna en el 2");
printf("\n\nY siendo 'b' la suma de los valores de fila y columna");

tv=ped_tam();
printf("\n\n-Vector 1:\n");
llen_vec(vec1,tv);
printf("\n\n-Vector 2:\n");
llen_vec(vec2,tv);
llen_mat(vec1,vec2,mat,tv);
final(vec1,vec2,mat,tv);
}



int ped_tam(void)
{
int tv;

printf("\n\nDe que orden seran los vectores (y la matriz)\n\n:");
scanf("%d",&tv);

return tv;
}



void llen_vec(int vec[N],int tam)
{
int cont;

cont=0;
while (cont<tam)	
	{
	 printf("\n\nDe posicion #%d\n",cont+1);
	 scanf("%d",&vec[cont]);
	 cont ++;	
	}
}



void llen_mat(int vec1[N], int vec2[N], int mat[N][N],int tv)
{
int	a,b,c,cont1,cont2;

int a_a_la_b(int, int);

cont1=0;
cont2=0;

while (cont1<tv)
	{
	 while (cont2<tv)
	 	{
	 	 a=vec1[cont1]+vec2[cont2];
		 b=cont1+cont2;
		 mat[cont1][cont2]=a_a_la_b(a,b); 	
		 cont2 ++;
		}	
	 cont2=0;
	 cont1 ++;
	}	
}
int a_a_la_b(int a, int b)
{
int c,cont;

cont=1;
c=1;

while (cont<=b)
	{
	 c=c*a;
	 cont ++;
	}
return c;
}


void final(int vec1[N], int vec2[N], int mat[N][N],int tv)
{
void esc_vec(int [N], int);
void esc_mat(int [N][N], int);

printf("\n\n\nDados los vectores:\n\n");
esc_vec(vec1,tv);
printf("\n\nY\n\n");
esc_vec(vec2,tv);
printf("\n\nY teniendo en cuenta las condiciones iniciales del programa, la matriz inicializada es:\n\n\n");
esc_mat(mat,tv);
printf("F I N");	
}

void esc_vec(int vec[N],int tv)
{
int cont;				

cont=0;
while (cont<tv)
	{
	 printf("%d, ",vec[cont]);
	 cont ++;	
	}	
}

void esc_mat(int mat[N][N], int tv)
{
int cont1,cont2;

cont1=0;
cont2=0;
while (cont1<tv)
	{
	 while (cont2<tv)
	 	{
		 printf("%d   ",mat[cont1][cont2]);
		 cont2 ++;
		}
	 printf("\n\n");
	 cont1 ++;
	 cont2=0;	
	}
}
