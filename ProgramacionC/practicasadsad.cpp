#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MCD   33    // Cantidad máxima de departamentos
#define MCC   33    // Cantidad máxima de capitales
#define MLND  30    // Máxima longitud del nombre de un departamento
#define MLNC  30    // Máxima longitud del nombre de una capital
#define CD	   3	// Cantidad de datos 

/* Escuela Colombiana de Ingeniería
   Algoritmos y programación de computadores (AYPC-1)
   Profesora: ingeniera Patricia Salazar Perdomo
   Estudiante: Nombre Apellidos
   Examen final 2017-1 (60% o 100%)
   10 de mayo de 2017
   
   Modifique el programa modular en lenguaje C que se da para que haga lo correspondiente a las opciones 2, 3, 4, 5 y 6:

	2.	Población total de Colombia.
	3.	Departamento con mayor población. Debe escribir los datos del departamento.
	4.	Densidad (hab/km2) promedio de los departamentos de Colombia.
	5.	Dado un nombre de departamento, escribir sus datos. Es posible que el departamento no exista.
	6.	Rango de cantidad de municipios de los departamentos.

	Todas las opciones valen lo mismo. 

   Este examen se aprueba con tres o más opciones desarrolladas correctamente.
*/

void titulo(const char [ ]);
int busca_dpto(char [MCD][MLND], int, char []); // Busca un departamento en el vector de departamentos y devuelve la posición en la que la encontró o -1 si no está
void cual_dpto(char [ ]); // Pide el nombre del departamento cuyos datos quiere conocer

int main(void)
{
char dptos[MCD][MLND]={"Amazonas", "Antioquia", "Arauca", "Atlantico", "Bogota D.C.", "Bolivar", "Boyaca", "Caldas", "Caqueta", "Casanare", "Cauca", "Cesar", "Choco", "Cordoba", "Cundinamarca", "Guainia", "Guaviare", "Huila", "La Guajira", "Magdalena", "Meta", "Nariño", "Norte de Santander", "Putumayo", "Quindio", "Risaralda", "San Andres y Providencia", "Santander", "Sucre", "Tolima", "Valle del Cauca", "Vaupes", "Vichada"};
char capitales[MCC][MLNC]={"Leticia", "Medellin", "Arauca", "Barranquilla", "Bogota D.C.", "Cartagena", "Tunja", "Manizales", "Florencia", "Yopal", "Popayan", "Valledupar", "Quibdo", "Monteria", "Bogota D.C.", "Puerto Inirida", "San Jose del Guaviare", "Neiva", "Riohacha", "Santa Marta", "Villavicencio", "Pasto", "Cucuta", "Mocoa", "Armenia", "Pereira", "San Andres", "Bucaramanga", "Sincelejo", "Ibague", "Cali", "Mitu", "Puerto Carreno"};
int datos_dep[MCD][CD] = {{2, 109665, 75388}, {125, 63612, 6378069}, {7, 23818, 259447}, {23, 3388, 2432145}, {1, 1605, 7776845}, {48, 25978, 2072976}, {123, 23189, 1274571}, {27, 7888, 986061}, {16, 88965, 471527}, {19, 44640, 350221}, {42, 29308, 1366937}, {25, 22905, 1016503}, {30, 46530, 495171}, {30, 25020, 1683792}, {116, 22605, 2639059}, {1, 56073, 40839}, {4, 53460, 109490}, {37, 19890, 1140585}, {15, 20848, 930165}, {30, 23188, 1247383}, {29, 85635, 943024}, {64, 33268, 1722999}, {40, 21658, 1344015}, {13, 24885, 341034}, {12, 1845, 562087}, {14, 4140, 946626}, {1, 44, 75801}, {87, 30537, 2051065}, {26, 10917, 843182}, {47, 23562, 1404268}, {42, 22140, 4566593}, {3, 54135, 43240}, {4, 100242, 70260}};
float densidad[MCD]={0.68, 100.26, 10.89, 717.88, 4845.38, 79.79, 54.96, 125.01, 5.30, 7.84, 46.64, 44.37, 10.64, 67.29, 116.74, 0.72, 2.04, 57.34, 44.61, 53.79, 11.01, 51.79, 62.05, 13.71	, 304.65, 228.65, 1722.75, 67.16, 77.23, 59.59, 206.25, 0.79, 0.70};

int cd = MCD, cc = MCC, cant_d = CD, opc; // cd: Cantidad de departamentos, cc: Cantidad de capitales

void muestra_datos(char [MCD][MLND], int, char [MCC][MLNC], int, int [MCD][CD], int, float []);
muestra_datos(dptos, cd, capitales, cc, datos_dep, cant_d, densidad);
void poblacion_total( int [MCD][CD], int);
void dpto_mas_poblado( int [MCD][CD], int, char [MCD][MLND], char [MCC][MLNC], float densidad[MCD]);
void densidad_promedio(float densidad[MCD], int cd);
void datos_dpto(int [MCD][CD], int , char [MCD][MLND], char [MCC][MLNC], float [MCD]);
void rango_cant_mcipios(int [MCD][CD], int);

    do{
        system("cls");
        printf("\n\n\t\t\tINFORMACI%cN DEPARTAMENTOS DE COLOMBIA (2014)\n",162);
        printf ("\n\t1. Ver datos de los departamentos\n");
        printf ("\n\t2. Poblaci%cn total de Colombia\n",162);
        printf ("\n\t3. Departamento con mayor poblaci%cn\n",162);
        printf ("\n\t4. Densidad promedio de los departamentos.\n",160);
        printf ("\n\t5. Datos de un departamento.\n");
        printf ("\n\t6. Rango - cantidad municipios de los departamentos.\n");
        printf ("\n\t7. Salir\n");
        printf ("\n\tD%c opci%cn >> ", 130, 162);
        scanf("%d",&opc);
        system("cls");
        switch (opc)
        {
               case 1: muestra_datos(dptos, cd, capitales, cc, datos_dep, cant_d, densidad);
                       break;
               case 2: poblacion_total(datos_dep, cd); // Obtiene y escribe la población total de Colombia
                       break;
               case 3: dpto_mas_poblado(datos_dep, cd, dptos, capitales, densidad); // Obtiene y escribe los datos del departamento con mayor población.
                       break;
               case 4: densidad_promedio(densidad, cd); // Obtiene y escribe la densidad promedio de los departamentos
                       break;
               case 5: datos_dpto(datos_dep, cd, dptos, capitales, densidad); // Escribe los datos de un departamento
                       break;
               case 6: rango_cant_mcipios(datos_dep,cd); // Obtiene y escribe el rango de cantidad de municipios de los departamentos
                       break;
        }
        system ("pause");
    }while (opc != 7); 
}

void muestra_datos(char dptos[MCD][MLND], int cd, char capitales[MCC][MLNC], int cc, int datos_dep[MCD][CD], int cant_d, float densidad[])
{
int dep, cont_dep;
printf("\n\n\t\t\tINFORMACI%cN GENERAL DE LOS DEPARTAMENTOS DE COLOMBIA\n",162);
printf ("\nNo.    %-25s  %-25sMunicipios\tKm2  Habitantes Hab/km2\n\n","Departamento","Capital");
for (dep=0; dep < cd; dep++)
{
    printf("%4d   %-25s  %-22s  ",dep+1,dptos[dep],capitales[dep]);
    for (cont_dep=0; cont_dep < cant_d; cont_dep++)
	     printf ("%8d ",datos_dep[dep][cont_dep]);
    printf(" %8.2f\n", densidad[dep]);
}
 printf("\n\n");
}





int busca_dpto(char dptos[MCD][MLND], int cd, char dpto_busc[]) // Busca un departamento en el vector de departamentos y devuelve la posición en la que la encontró o -1 si no está
{
int pd;
for (pd=0; pd < cd; pd++)
	if (strcmp(dptos[pd],dpto_busc) == 0) return pd; // El departamento está en la posición pd
return -1; // El departamento no está 
}






void cual_dpto(char d[ ]) // Pide el nombre de un departamento
{
	printf ("\n\nD%c el nombre del departamento cuyos datos quiere conocer: ");
	scanf ("%s",d);
}






void poblacion_total(int datos_dep[MCD][CD], int cd)
{
	titulo("POBLACION TOTAL");
	int sum_pos_vec(int [MCD][CD], int);
	int pob_tot;
	pob_tot=sum_pos_vec(datos_dep, cd);
	
	printf("\n\nLa poblacion total de colombia, teniendo en cuenta los datos del DANE en 2014 es de:");
	printf("\n\n%d personas\n\n",pob_tot);
}


int sum_pos_vec(int datos_dep[MCD][CD], int cd)
{
	int cont,s=0;
	
	for (cont=0;cont<cd;cont ++)
		{
		 s=s+datos_dep[cont][2];
		}
 return s;
}



void dpto_mas_poblado(int datos_dep[MCD][CD], int cd, char dptos[MCD][MLND], char capitales[MCC][MLNC], float densidad[MCD])
{
	titulo("DEPARTAMENTO CON MAYOR POBLACION");
	void halla_dpto(int [MCD][CD], int, int *, int *);
	void most_dato(int [MCD][CD], char [MCD][MLND], char [MCC][MLNC], float [MCD], int);
	int m,n;
	
	
	halla_dpto(datos_dep, cd, &m, &n);
	most_dato(datos_dep, dptos, capitales, densidad, n);
	printf("\n\nTeniendo en cuenta los datos del DANE en 2014, el departamento mas poblado de colombia es:");
}

void halla_dpto(int datos_dep[MCD][CD], int cd, int *m, int *n)
{
int cont;
*m=0;
	for (cont=0;cont<cd;cont ++)
		{
		 if ( datos_dep[cont][2] > *m)
			{
			  *m=datos_dep[cont][2];
			  *n=cont;
			}
		}
}

void most_dato(int datos_dep[MCD][CD], char dptos[MCD][MLND], char capitales[MCC][MLNC], float densidad[MCD], int n)
{
printf("\n\nDepartamento: %s\n\nCapital: %s\n\nMunicipios: %d\n\nSuperficie: %d km2\n\nHabitantes: %d\n\nDensidad: %f habitantes/km2\n\n", dptos[n], capitales[n], datos_dep[n][0], datos_dep[n][1], datos_dep[n][2], densidad[n]);	
}




void densidad_promedio(float densidad[MCD], int cd)
{
	titulo("DENSIDAD PROMEDIO DE LOS DEPARTAMENTOS");
	int cont;
	float s=0;
	
	for (cont=0;cont<cd;cont ++)
		{
		 s=s+densidad[cont];
		}
	s=s/cd;
	printf("\n\nDensidad (hab./km2) promedio de los departamentos de Colombia: %f\n\n",s);
}



void datos_dpto(int datos_dep[MCD][CD], int cd, char dptos[MCD][MLND], char capitales[MCC][MLNC], float densidad[MCD])
{
	titulo("DATOS DE UN DEPARTAMENTO");
	char nom[MLND];
	int cont,s,l;
	
	printf("\n\nDe el departamento del que quiere los datos >>");
	scanf("%s",nom);
	for (cont=0;cont<cd;cont ++)
		{
		 l=strcmp(dptos[cont],nom);
		 if (l==0) s=cont;
		}

	printf("\n\nDepartamento: %s\n\nCapital: %s\n\nMunicipios: %d\n\nSuperficie: %d km2\n\nHabitantes: %d\n\nDensidad: %f habitantes/km2\n\n", dptos[s], capitales[s], datos_dep[s][0], datos_dep[s][1], datos_dep[s][2], densidad[s]);
}





void rango_cant_mcipios(int datos_dep[MCD][CD], int cd)
{
	titulo("RANGO DE CANTIDAD DE MUNICIPIOS DE LOS DEPARTAMENTOS");
	int men, may;
	int menor(int [MCD][CD], int );
	int mayor(int [MCD][CD], int);
	
	men=menor(datos_dep, cd);
	may=mayor(datos_dep, cd);
	
	printf("\n\nRango de cantidad de municipios de los departamentos: [%d,%d]",men,may);
}

int menor(int datos_dep[MCD][CD], int cd)
{
}


int mayor(int datos_dep[MCD][CD], int cd)
{
	
}





void titulo(const char titulo[ ])
{
system("cls");
printf("\n\n\t\t%s\n\n",titulo);
}
