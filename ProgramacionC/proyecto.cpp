//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Proyecto para parqueadero ECI en el que se organiza dependiendo de la persona y el vehiculo 
//08 de mayo del 2018
//Se supone que los datos ingresados son correctos
//Alumno: Nicolas Moreno


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MCC   109  //maxima cantidad de carros  
#define MCM   15   //maxima cantidad de motos
#define PLK   7    //placa 
#define MCB   240       //maxima cantidad de bicis 
#define MCD   2
#define BH1C  28   // a partir de aqui se asigna el numero maximo de carros, motos, bicis y discapacitados en cada park ( C para carros, M para motos, B para bicis y D para disc)    
#define BH1M  0
#define BH1B  0
#define BH1D  0
#define BH2C  27
#define BH2M  0
#define BH2B  0
#define BH2D  0
#define BH3C  42
#define BH3M  0
#define BH3B  0
#define BH3D  2
#define BH4C  31 
#define BH4M  0
#define BH4B  0
#define BH4D  0
#define BH5C  36
#define BH5M  0
#define BH5B  0
#define BH5D  0
#define IC    64 
#define IM    240
#define IB    25
#define ID    4
#define COLC  91
#define COLM  8
#define COLB  0
#define COLD  2
#define ENTC  109
#define ENTM  125
#define ENTB  192
#define ENTD  5

system (color.70);
struct park
{                                         //cada parking tiene un numero de carros, motos, bicis y estacionamientos para discapacitados maximos, al igual que cada uno tiene su placa
	int carros[MCC];
	int motos[MCM];
	int bicis[MCB];
	int disc[MCD];
	char placacar[MCC][PLK];
	char placamot[MCM][PLK];
	char placabic[MCB][PLK];
	char placadisc[MCD][PLK];
};


int main(void)
{
struct park bh1,bh2,bh3,bh4,bh5,I,col,ent;
int opc;


void cero_todo(struct park *, int , int , int , int);
void cero_todo_p(struct park *, int , int , int , int);
void ingr_vehi(struct park *, struct park *, struct park *, struct park *, struct park *, struct park *, struct park *, struct park *);
void sac_vehi(struct park *, struct park *, struct park *, struct park *, struct park *, struct park *, struct park *, struct park *); 
void leer_park(struct park, struct park, struct park, struct park, struct park, struct park, struct park, struct park); 


cero_todo(&bh1, BH1C, BH1M, BH1B, BH1D);            // inicializamos las bahias en 0 (esto es, vacio) y todas las placas en 0.
cero_todo(&bh2, BH2C, BH2M, BH2B, BH2D);         
cero_todo(&bh3, BH3C, BH3M, BH3B, BH3D);
cero_todo(&bh4, BH4C, BH4M, BH4B, BH4D);             //nota: un 0 en una posicion significa libre y un 1 significa lleno.
cero_todo(&bh5, BH5C, BH5M, BH5B, BH5D);
cero_todo(&I, IC, IM, IB, ID);
cero_todo(&col,COLC, COLM, COLB, COLD);
cero_todo(&ent, ENTC, ENTM, ENTB, ENTD); 

   
	do{
        system("cls");
        printf ("\n\n\t ""Bienvenido""\n");
        printf ("\n\tI. Ingresar un vehiculo\n");        
        printf ("\n\tII. Sacar un vehiculo\n");                                      
        printf ("\n\tIII. Ver el estado de los parqueaderos\n");
        printf("\n\tIV. Salir\n");
	   printf ("\n\tDe opcion >> ", 130, 162);
        scanf("%d",&opc);
        system("cls");
        switch (opc)
        {
               case 1: ingr_vehi(&bh1, &bh2, &bh3, &bh4, &bh5, &I, &col, &ent);            
				   break;
               case 2: sac_vehi(&bh1, &bh2, &bh3, &bh4, &bh5, &I, &col, &ent);
                       break;
               case 3: leer_park(bh1, bh2, bh3, bh4, bh5, I, col, ent);
				   break;       
        }
        system ("pause");
    }while (opc!=4); 
}

void cero_todo(struct park *bah, int limc, int limm, int limb, int limd)
{
void cero_cosa(int [MCB], int );
void cero_cosa_p(char [MCB][PLK], int );

cero_cosa((*bah).carros, limc);
cero_cosa((*bah).motos, limm);
cero_cosa((*bah).bicis, limb);
cero_cosa((*bah).disc, limd);

cero_cosa_p((*bah).placacar, limc);
cero_cosa_p((*bah).placamot, limm);
cero_cosa_p((*bah).placabic, limb);
cero_cosa_p((*bah).placadisc, limd);	
}

void cero_cosa (int x[], int lim)
{
int cont=0;

while (cont < lim)
	{
	 x[cont] = 0;	
	 cont = cont + 1;
	}
} 

void cero_cosa_p (char x[MCB][PLK], int lim)
{
int cont1=0;
int cont2=0;

while (cont1 < lim)
{
cont2 = 0;
	while (cont2 <= PLK)
		{
	 	 x[cont1][cont2] = 0;	
	 	 cont2 = cont2 + 1;
		}
cont1 ++;
}
}



//da preferencia a discapacitados, luego a los profesores ( en el edificio I) y finalmente, a los estudiantes. 



void ingr_vehi(struct park *bh1, struct park *bh2, struct park *bh3, struct park *bh4, struct park *bh5, struct park *I, struct park *col, struct park *ent)
{		
int disp=8,disca=8,prof=8,opc=8;	
void dispo(int *, int [MCB], int ,char [MCB][PLK]);


label:
printf("\n\t Es usted discapacitado?\n\t 1.SI.\n\t 0.NO.\n\t>>");
scanf("%d",&disca);

if (disca == 1)
	{
	 dispo(&disp , (*bh3).disc , BH3D, (*bh3).placadisc);
	 if (disp == 1) 
	 	{	
		 printf("\n\n\tProceda a la bahia 3");
		 goto finish;
		}
      
	 else dispo(&disp , (*I).disc, ID, (*I).placadisc);
	 
	 if (disp == 1) 
	 	{
		 printf("\n\n\tProceda al edificio I");
		 goto finish;
		}
	 else dispo(&disp , (*col).disc , COLD , (*col).placadisc);
	 
	 if (disp == 1) 
	 	{
		 printf("\n\n\tProceda al coliseo");
		 goto finish;
		}	
		
	 else dispo( &disp , (*ent).disc, ENTD, (*ent).placadisc);
	 
	 if (disp == 1) 
	 	{
		 printf("\n\n\tProceda a la entrada");
		 goto finish;
		}
	 else goto nositio;
	
	}
if (disca == 0)
{
label2:
printf("\n\tEs usted profesor?\n\t 1. SI.\n\t0.NO.\n\t>>");
scanf("%d",&prof);
if (prof == 1)
	{
	 printf("\n\n\tTiene usted carro, moto o bici ?\n\t 1.Carro   2.Moto. 3.Bici  \n\t>>");	
	 scanf("%d",&opc);
	 if (opc == 1)
	 	{
	 	 nositio:	
	 	 dispo(&disp, (*I).carros, IC, (*I).placacar);
		 if (disp == 0) goto llen_rest1;
		 else printf("\n\tProceda al edificio I");	
		}
	 if (opc == 2)
	 	{
	 	 dispo(&disp , (*I).motos, IM, (*I).placamot);
		 if (disp == 0) goto llen_rest2;
		 else printf("\n\tProceda al edificio I");	
		}
	 if (opc == 3)
	 	{
	 	 dispo(&disp, (*I).bicis, IB, (*I).placabic);
		 if (disp == 0) goto llen_rest3;
		 else printf("\n\tProceda al edificio I");	
		}
	}	
if (prof == 0)
	{
	 printf("\n\n\tTiene usted carro, moto o bici ?\n\t 1.Carro   2.Moto. 3.Bici  \n\t>>");	
	 scanf("%d",&opc);
	 if (opc ==1)
	 	{
	 	 llen_rest1:	
	 	 dispo(&disp, (*bh1).carros, BH1C, (*bh1).placacar);
	 	 if (disp == 1) 
		  {
		  printf("\n\t Proceda a la bahia 1");
		  goto f;
		  }
		 else dispo(&disp, (*bh2).carros, BH2C, (*bh2).placacar);
		 
		 if (disp == 1) 
		 {
		  printf("\n\t Proceda a la bahia 2");
		  goto f;
		 }
		 else dispo(&disp,(*bh3).carros, BH3C, (*bh3).placacar);
		 
		 if (disp == 1) 
		 {
		  printf("\n\t Proceda a la bahia 3");
		  goto f;
		 }
		 else dispo(&disp, (*bh4).carros, BH4C, (*bh4).placacar);
		 
		 if (disp == 1) 
		 {
		  printf("\n\t Proceda a la bahia 4");
		  goto f;
		 }
		 else dispo(&disp, (*bh5).carros, BH5C, (*bh5).placacar);
		 
		 if (disp == 1) 
		 {
		  printf("\n\t Proceda a la bahia 5");
		  goto f;
		 }
		 else dispo(&disp, (*col).carros, COLC, (*bh5).placacar);
		 
		 if (disp == 1) 
		 {
		 printf("\n\t Proceda al coliseo");
		 goto f;
		 }
		 else dispo(&disp, (*ent).carros, ENTC, (*ent).placacar);
		 
		 if (disp == 1) 
		 {
		  printf("\n\t Proceda al parking de la entrada");
		  goto f;
		 }
		 else printf("\n\t No hay espacio");
		 
		 f: 
		 ;  
		}	
	 
	 if (opc ==2)
	 	{
	 	 llen_rest2:	
	 	 dispo(&disp, (*col).motos, COLM, (*col).placamot);
		 if (disp == 1) 
		 {
		 printf("\n\t Proceda al coliseo");
		 goto f2;
		 }
		 else dispo(&disp, (*ent).motos, ENTM, (*ent).placamot);
		 
		 if (disp == 1) 
		 {
		  printf("\n\t Proceda al parking de la entrada");
		  goto f2;
		 }
		 else printf("\n\t No hay espacio");
		 
		 f2:
		 ;	
		}
	 if (opc ==3)
	 	{
	 	 llen_rest3:	
	 	 dispo(&disp, (*ent).bicis, ENTB, (*ent).placabic);
		 if (disp == 1) printf("\n\t Proceda al parking de la entrada");
		 else printf("\n\t No hay espacio");
		}	
		
	}
printf("\n\n");
}


 	
	 
finish:
;	
}


//escanea el vector para ver si esta disponible ( tiene algun 0)
void dispo (int *disp , int x[MCB],int lim, char y[MCB][PLK])
{
int cont;
cont = 0;
while (cont < lim)
	{
	 if (x[cont] == 0)
	 	{
		 *disp = 1;
		 x[cont] = 1;
		 printf("\n\t De su placa o si es bicicleta, de el carnet\n\t >>");
		 scanf("%s",y[cont]);
		 goto l; 
		}
	 cont = cont +1;	
	}

l:
;	
}




//pide la placa del vehiculo o el carnet si es una bicicleta, si esta registrada, libera ese espacio y quita esa placa. Si no, envia error

void sac_vehi(struct park *bh1, struct park *bh2, struct park *bh3, struct park *bh4, struct park *bh5, struct park *I, struct park *col, struct park *ent)
{
void lib_esp(int [MCB], int ,char [MCB][PLK] );
int compar_vector(char [MCB][PLK], char [PLK], int );

int igu = 9;
int tip;
char plk[PLK];	
	
printf("\n\tHola. De el numero de placa o carnet si es bicicleta\n\t");
scanf("%s",plk);	

igu = compar_vector( (*bh1).placacar, plk, BH1C);

if (igu == 0)
	{
	 lib_esp( (*bh1).carros, BH1C, (*bh1).placacar);	
	 printf("Vuelva pronto. Retirando vehiculo den bahia 1");
	 goto final;
	}
else igu = compar_vector( (*bh2).placacar, plk, BH2C);

if (igu == 0)
	{
	 lib_esp((*bh2).carros, BH2C, (*bh2).placacar);
	 printf("Vuelva pronto. Retirando vehiculo en bahia 2");
	 goto final;	
	}
else igu = compar_vector( (*bh3).placacar, plk, BH3C);

if (igu == 0)
	{
	 lib_esp((*bh3).carros, BH3C, (*bh3).placacar);
	 printf("Vuelva pronto. Retirando vehiculo en bahia 3");	
	 goto final;
	}
else igu = compar_vector( (*bh4).placacar, plk, BH4C);

if (igu == 0)
	{
	 lib_esp((*bh4).carros, BH4C, (*bh4).placacar);
	 printf("Vuelva pronto. Retirando vehiculo en bahia 4");	
	 goto final;
	}
else igu = compar_vector( (*bh5).placacar, plk, BH5C);

if (igu == 0)
	{
	 lib_esp((*bh5).carros, BH5C, (*bh5).placacar);
	 printf("Vuelva pronto. Retirando vehiculo en bahia 5");	
	 goto final;
	}
else igu = compar_vector( (*I).placacar, plk, IC);

if (igu == 0)
	{
	 lib_esp((*I).carros, IC, (*I).placacar);
	 printf("Vuelva pronto. Retirando vehiculo en edificio I");	
	 goto final;
	}
else igu = compar_vector( (*col).placacar, plk, COLC);

if (igu == 0)
	{
	 lib_esp((*col).carros, COLC, (*col).placacar);
	 printf("Vuelva pronto. Retirando vehiculo en coliseo");	
	 goto final;
	}
else igu = compar_vector( (*ent).placacar, plk, ENTC);

if (igu == 0)
	{
	 lib_esp((*ent).carros, ENTC, (*ent).placacar);
	 printf("Vuelva pronto. Retirando vehiculo en entrada");	
	 goto final;
	}

else igu = compar_vector( (*I).placamot, plk, IM);

if (igu == 0)
	{
	 lib_esp((*I).motos, IM, (*I).placamot);
	 printf("Vuelva pronto. Retirando vehiculo en edificio I");	
	 goto final;
	}
else igu = compar_vector( (*col).placamot, plk, COLM);

if (igu == 0)
	{
	 lib_esp( (*col).motos, COLM, (*col).placamot);
	 printf("Vuelva pronto. Retirando vehiculo en coliseo");	
	 goto final;
	}
else igu = compar_vector( (*ent).placamot, plk, ENTM);

if (igu == 0)
	{
	 lib_esp( (*ent).motos, ENTM, (*ent).placamot);
	 printf("Vuelva pronto. Retirando vehiculo de entrada");	
	 goto final;
	} 
else igu = compar_vector( (*I).placabic, plk, IB);

if (igu == 0)
	{
	 lib_esp((*I).bicis, IB, (*I).placabic);
	 printf("Vuelva pronto. Retirando vehiculo en edificio I");	
	 goto final;
	}
else igu = compar_vector( (*ent).placabic, plk, ENTB);

if (igu == 0)
	{
	 lib_esp((*ent).bicis, ENTB, (*ent).placabic);
	 printf("Vuelva pronto. Retirando vehiculo de entrada");	
	 goto final;
	}	
else igu = compar_vector( (*bh3).placadisc, plk, BH3D);

if (igu == 0)
	{
	 lib_esp( (*bh3).disc, BH3D, (*bh3).placadisc );
	 printf("Vuelva pronto. Retirando vehiculo en bahia 3");	
	 goto final;
	}
else igu = compar_vector( (*I).placadisc, plk, ID);

if (igu == 0)
	{
	 lib_esp((*I).disc, ID, (*I).placadisc);	
	 printf("Vuelva pronto. Retirando vehiculo en edificio I");
	 goto final;
	}
else igu = compar_vector( (*col).placadisc, plk, COLD);

if (igu == 0)
	{
	 lib_esp((*col).disc, COLD, (*col).placadisc);
	 printf("Vuelva pronto. Retirando vehiculo en coliseo");	
	 goto final;
	}
else igu = compar_vector( (*ent).placadisc, plk, ENTD);

if (igu == 0) 
	{
	 lib_esp((*ent).disc, ENTD, (*ent).placadisc);
	 printf("Vuelva pronto. Retirando vehiculo de entrada");			
	 goto final;
	}
else printf("\n\t Error. No coincide con ninguna placa o carnet\n\t");


final:

printf("\n\n");
}

//compara vectores
int compar_vector(char V1[MCB][PLK], char V2[PLK],int cf)
{
int cont=0,iguales=9;

while (cont < cf)
	{
	 iguales = strncmp(V1[cont],V2,PLK-1);
	 if (iguales == 0) {
	 goto leb;}
	 cont ++;
	}
leb:	
return iguales;	
}

//libera espacio y quita la placa
void lib_esp(int v1[MCB], int lim, char v2[MCB][PLK] )
{
int cont = 0;
int cont1 = 0;
while (cont <= lim)
	{
	 if (v1[cont] == 1) 
	 	{
		 v1[cont] =0;
	 	 goto sal;
	 	}
	 cont ++;	
	}

sal:
if (v1[cont] == 0)
{		
	while (cont1 < PLK)
		{
		 v2[cont][cont1] = 0;
		 cont1 ++;
		}
}	

}
	





//simplemente lee cuantos 0 hay en cada parking y devuelve el numero de 0 (disponibles) de cada parking y cada tipo de vehiculo
void leer_park(struct park bh1, struct park bh2, struct park bh3, struct park bh4, struct park bh5, struct park I, struct park col, struct park ent)
{
void cont_espacios(int [MCB], int , char [MCM], char [MCM]);
char b1[MCM]="bahia1" , b2 [MCM] = "bahia2", b3 [MCM] = "bahia3" , b4[MCM] = "bahia4" , b5[MCM] = "bahia5" , edi[MCM] = "edificio I" , coli[MCM] = "coliseo", entr[MCM] = "entrada";	
char car[MCM] = "carros", mot[MCM] = "motos", bic[MCM] = "bicicletas", disc[MCM] = "carros de disc"; 



cont_espacios((bh1).carros, BH1C, car, b1);	
cont_espacios((bh1).motos, BH1M, mot, b1);
cont_espacios((bh1).bicis, BH1B, bic, b1);
cont_espacios((bh1).disc, BH1D, disc, b1);
cont_espacios((bh2).carros, BH2C, car, b2);
cont_espacios((bh2).motos, BH2M, mot, b2);
cont_espacios((bh2).bicis, BH2B, bic, b2);
cont_espacios((bh2).disc, BH2D, disc, b2);
cont_espacios((bh3).carros, BH3C, car, b3);
cont_espacios((bh3).motos, BH3M, mot, b3);
cont_espacios((bh3).bicis, BH3B, bic, b3);
cont_espacios((bh3).disc, BH3D, disc, b3);
cont_espacios((bh4).carros, BH4C, car, b4);
cont_espacios((bh4).motos, BH4M, mot, b4);
cont_espacios((bh4).bicis, BH4B, bic, b4);
cont_espacios((bh4).disc, BH4D, disc, b4);
cont_espacios((bh5).carros, BH5C, car, b5);
cont_espacios((bh5).motos, BH5M, mot, b5);
cont_espacios((bh5).bicis, BH5B, bic, b5);
cont_espacios((bh5).disc, BH5D, disc, b5);
cont_espacios((I).carros, IC, car, edi);
cont_espacios((I).motos, IM, mot, edi);
cont_espacios((I).bicis, IB, bic, edi);
cont_espacios((I).disc, ID, disc, edi);
cont_espacios((col).carros, COLC, car, coli);
cont_espacios((col).motos, COLM, mot, coli);
cont_espacios((col).bicis, COLB, bic, coli);
cont_espacios((col).disc, COLD, disc, coli);
cont_espacios((ent).carros, ENTC, car, entr);
cont_espacios((ent).motos, ENTM, mot, entr);
cont_espacios((ent).bicis, ENTB, bic, entr);
cont_espacios((ent).disc, ENTD, disc, entr);

}

void cont_espacios (int vector[MCB] , int lim, char mm[PLK], char ss[PLK])
{
int cont=0;	
int l=0;

	
while (cont < lim )
	{
	 if (vector[cont] == 0)
	 {
	  l = l+1;	
	 }
	 cont ++;
	}
printf("\n\t El numero de sitios libres para %s en %s es: %d\n\n",mm,ss,l);
}
