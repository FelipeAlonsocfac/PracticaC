#include <stdio.h>
#include <stdlib.h>

struct complejo{
	float real;
    float imag;
};

int main(void)
{
struct complejo num1, num2, suma;
void pedir_compl(struct complejo *, struct complejo *);
void sum_compl(struct complejo, struct complejo, struct complejo*);
void esc_suma(struct complejo, struct complejo, struct complejo);

pedir_compl(&num1, &num2);
sum_compl(num1, num2, &suma);
esc_suma(num1, num2, suma);
}

void pedir_compl(struct complejo * n1, struct complejo * n2)
{
void pide_un_compl(float *, float *);
//void pide_un_compl(struct complejo *);

pide_un_compl(&(*n1).real, &(*n1).imag);
pide_un_compl(&(*n2).real, &(*n2).imag);

//pide_un_compl(n1);
//pide_un_compl(n2);

}

void pide_un_compl(float * real, float * imag)
{
printf ("\nParte real >> ");
scanf("%f",real);
printf ("\nParte imaginaria >> ");	
scanf("%f",imag);
}

/*void pide_un_compl(struct complejo * n)
{
printf ("\nParte real >> ");
scanf("%f",&(*n).real);
printf ("\nParte imaginaria >> ");	
scanf("%f",&(*n).imag);
}
*/	
void sum_compl(struct complejo n1, struct complejo n2, struct complejo * s)
{
(*s).real = n1.real + n2.real;
(*s).imag = n1.imag + n2.imag;
}

void esc_suma(struct complejo n1, struct complejo n2, struct complejo s)
{
void esc_un_compl(struct complejo);

printf ("\n\nLa suma de los números complejos: ");
esc_un_compl(n1);
printf ("\ny ");
esc_un_compl(n2);
printf ("\n es ");
esc_un_compl(s);
}

void esc_un_compl(struct complejo n)
{
printf("(%.1f + %.1fi)",n.real, n.imag);
}

