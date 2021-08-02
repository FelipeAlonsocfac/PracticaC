
















#include <stdio.h>
#include <stdlib.h>

int main(void)
{
int a, b, c, d, total;

void que_hace(void);
void pidedatos(int *, int *, int *, int *);
int eval_exp(int, int, int, int);
void esc_res(int, int, int, int, int);
void fin(void);

que_hace( );
pidedatos(&a, &b, &c, &d);
total=eval_exp(a, b, c, d);
esc_res(a,b,c,d,total);
fin( );
}


void que_hace(void)	
{
printf("\nHola. Evaluo la expresion (a+b)^(c+d) + 3\n\n");
}

void fin(void)
{
printf("\n\nF I N.\n\n");
system("pause");
}

void pidedatos(int *a, int *b, int *c, int *d)
{
int f_lee_ent (char);

*a=f_lee_ent('a');
*b=f_lee_ent('b');
*c=f_lee_ent('c');
*d=f_lee_ent('d');
}

int f_lee_ent(char p)
{

int num;
	
printf("\nDe el valor de %c ",p);
scanf("%d",&num);

return num;
}

int eval_exp(int a, int b, int c, int d)
{
int s1, s2, subt,r;

int f_suma(int, int);
int f_exp(int, int);

s1=f_suma(a,b);
s2=f_suma(c,d);
subt=f_exp(s1, s2);
r=f_suma(subt,3);

return r;
}

int f_suma(int num1, int num2)
{
int suma;
	
suma=num1+num2;

return suma;
}

int f_exp(int m, int n)
{
int veces,res;
res=1;
for (veces=1; veces<=n; veces++)
     res=res*m;

return res;
}

void esc_res(int a, int b, int c, int d, int total)
{
printf("\n\n\n(%d + %d)^(%d + %d) + 3 = %d", a,b,c,d,total);
}

