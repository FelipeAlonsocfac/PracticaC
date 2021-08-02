//Escuela Colombiana de Ingeniería 
//Asignatura: Algoritmos y programacion de computadores(AYPC-1)
//Profesora: Ingeniera Patricia Salazar Perdomo
//Construir un menu en el que el usuario ingrese dos numeros complejos
//Ademas de tener la opcion de sumarlos, restarlos, multiplicarlos y dividirlos
//13 de noviembre de 2017
//Se supone que los datos ingresados son correctos
//Alumno: Carlos Felipe Alonso Caro


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MCC   20  
#define LC    15   


struct complejo 
{
	float real;
    float imag;
};


int main(void)
{
struct complejo num1, num2, suma, mult, div;
int opc, most;
void pedir_compl(struct complejo *, struct complejo *);
void sum_compl(struct complejo, struct complejo, struct complejo *, int);
void resta_compl(struct complejo, struct complejo, struct complejo *, int);
void mult_compl(struct complejo, struct complejo, struct complejo *, int);
void div_compl(struct complejo, struct complejo, struct complejo *, int);


    
	do{
        system("cls");
        printf ("\n\n\t*** Operaciones con numeros complejos\n");
        printf ("\n\t1. Introducir complejos\n");        
        printf ("\n\t2. Suma complejos\n");                                      
        printf ("\n\t3. Resta complejos\n");
        printf("\n\t4. Multiplica Complejos\n");
        printf("\n\t5. Divide complejos\n");
        printf("\n\t6. Salir.\n");
		printf ("\n\tDe opcion >> ", 130, 162);
        scanf("%d",&opc);
        system("cls");
        switch (opc)
        {
               case 1: pedir_compl(&num1,&num2);
               		   most=1;
                       break;
               case 2: sum_compl(num1,num2,&suma,most);
                       break;
               case 3: resta_compl(num1,num2,&suma,most);
					   break;
			   case 4: mult_compl(num1,num2,&mult,most);
			   		   break;
			   case 5: div_compl(num1,num2,&div,most);
			   		   break;       
        }
        system ("pause");
    }while (opc!=6); 
}





void pedir_compl(struct complejo * n1, struct complejo * n2)     //pide numeros
{
printf("\n\t\t\tPRIMER NUMERO:\n\n");
printf("\n\tParte real>>\t");
scanf("%f",&(*n1).real);
printf("\n\tParte imaginaria>>\t");
scanf("%f",&(*n1).imag);

printf("\n\t\t\tSegundo NUMERO:\n\n");
printf("\n\tParte real>>\t");
scanf("%f",&(*n2).real);
printf("\n\tParte imaginaria>>\t");
scanf("%f",&(*n2).imag);
}





void sum_compl(struct complejo n1, struct complejo n2, struct complejo *sum, int most)    //suma y escribe el resultado
{
void esc_suma(struct complejo, struct complejo, struct complejo);

if (most==1)
	{
	 (*sum).real=(n1).real+(n2).real;
	 (*sum).imag=(n1).imag+(n2).imag;
	 esc_suma(n1, n2, *sum);
	}

else printf("\n\n No ha ingresado datos\n\n");
}


void esc_suma(struct complejo n1, struct complejo n2, struct complejo sum)
{
printf("\nLa suma de los numeros\n");

	if((n1).imag<0)	    printf("\n\t(%f%fi) ",(n1).real,(n1).imag);	
	else printf("\n\t(%f+%fi) ",(n1).real,(n1).imag);

	if((n2).imag<0)	    printf("y (%f%fi)",(n2).real,(n2).imag);	
	else printf("y (%f+%fi)",(n2).real,(n2).imag);

	if((sum).imag<0)	    printf(" = (%f%fi)\n\n",(sum).real,(sum).imag);	
	else printf(" = (%f+%fi)\n\n",(sum).real,(sum).imag);
}





void resta_compl(struct complejo n1, struct complejo n2, struct complejo *sum, int most)      //resta y escribe el resultado
{
void esc_resta(struct complejo, struct complejo, struct complejo);

if (most==1)
	{
	 (*sum).real=(n1).real-(n2).real;
	 (*sum).imag=(n1).imag-(n2).imag;
	 esc_resta(n1, n2, *sum);
	}

else printf("\n\n No ha ingresado datos\n\n");
}

void esc_resta(struct complejo n1, struct complejo n2, struct complejo sum)
{
printf("\nLa resta de los numeros\n");

	if((n1).imag<0)	    printf("\n\t(%f%fi) ",(n1).real,(n1).imag);	
	else printf("\n\t(%f+%fi) ",(n1).real,(n1).imag);

	if((n2).imag<0)	    printf("y (%f%fi)",(n2).real,(n2).imag);	
	else printf("y (%f+%fi)",(n2).real,(n2).imag);

	if((sum).imag<0)	    printf(" = (%f%fi)\n\n",(sum).real,(sum).imag);	
	else printf(" = (%f+%fi)\n\n",(sum).real,(sum).imag);
}





void mult_compl(struct complejo n1, struct complejo n2, struct complejo *mult, int most)      //multiplica y escribe el resultado
{
void esc_mult(struct complejo, struct complejo, struct complejo);

if (most==1)
	{
	 (*mult).real= (n1).real*(n2).real  -  (n1).imag*(n2).imag;        //a*c-b*d     
	 (*mult).imag= (n1).real*(n2).imag  +  (n1).imag*(n2).real;        //a*d+b*c
	 esc_mult(n1, n2, *mult);
	}

else printf("\n\n No ha ingresado datos\n\n");	
}

void esc_mult(struct complejo n1, struct complejo n2, struct complejo mult)
{
printf("\nLa multiplicacion de los numeros\n");

	if((n1).imag<0)	    printf("\n\t(%f%fi) ",(n1).real,(n1).imag);	
	else printf("\n\t(%f+%fi) ",(n1).real,(n1).imag);

	if((n2).imag<0)	    printf("y (%f%fi)",(n2).real,(n2).imag);	
	else printf("y (%f+%fi)",(n2).real,(n2).imag);

	if((mult).imag<0)	    printf(" = (%f%fi)\n\n",(mult).real,(mult).imag);	
	else printf(" = (%f+%fi)\n\n",(mult).real,(mult).imag);	
}





void div_compl(struct complejo n1, struct complejo n2, struct complejo *div, int most)      //divide y escribe el resultado
{
void esc_div(struct complejo, struct complejo, struct complejo);	

if (most==1)
	{
	 (*div).real= ( (n1).real*(n2).real + (n1).imag*(n2).imag)  /  ( (n2).real*(n2).real + (n2).imag*(n2).imag);
	 (*div).imag= ( (n1).imag*(n2).real - (n1).real*(n2).imag)  /  ( (n2).real*(n2).real + (n2).imag*(n2).imag);
	 esc_div(n1, n2, *div);
	}

else printf("\n\n No ha ingresado datos\n\n");
}

void esc_div(struct complejo n1, struct complejo n2, struct complejo div)
{
printf("\nLa division de los numeros\n");

	if((n1).imag<0)	    printf("\n\t(%f%fi) ",(n1).real,(n1).imag);	
	else printf("\n\t(%f+%fi) ",(n1).real,(n1).imag);

	if((n2).imag<0)	    printf("y (%f%fi)",(n2).real,(n2).imag);	
	else printf("y (%f+%fi)",(n2).real,(n2).imag);

	if((div).imag<0)	    printf(" = (%f%fi)\n\n",(div).real,(div).imag);	
	else printf(" = (%f+%fi)\n\n",(div).real,(div).imag);	
}

