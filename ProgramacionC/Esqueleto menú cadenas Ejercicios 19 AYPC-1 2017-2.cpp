#include <stdio.h>
#include <stdlib.h>
#define LC   15      // Máxima longitud de una cadena de caracteres más 1. 

/* Escuela Colombiana de Ingeniería
   Algoritmos y programación de computadores (AYPC-1)
   Profesora: ingeniera Patricia Salazar Perdomo
   Estudiante: Nombre Apellidos
   Ejercicios No. 19: 
   a. Agregue la siguiente directiva al compilador: #include <string.h>
   b. Remplace:
      mi_strlen por strlen
	  mi_strcat por strcat
      mi_strcpy por strcpy
	  mi_strcmp por strcmp
   c. ELIMINE los prototipos de mi_strlen, mi_strcat, mi_strcpy y mi_strcmp
   d. ELIMINE las rutinas mi_strlen, mi_strcat, mi_strcpy y mi_strcmp
   e. Compile el programa y pruébelo. ¿Cuál es el resultado?
   3 de noviembre de 2017
*/

int existenpal=0;	// Bandera que indica si las palabras fueron ingresadas

int main(void)
{
char pal1[LC], pal2[LC];
int opc;

void ingresa_pal(char [], char []);
void muestra_pal(char [], char []);
void long_pal(char []);
void pega_pal(char [], char []);
void copia_pal(char [], char []);
void compara_pal(char [], char []);

    do{
        system("cls");
        printf ("\n\n\t*** Operaciones con cadenas de caracteres ***\n");
        printf ("\n\t1. Ingresar palabras\n");
        printf ("\n\t2. Ver palabras\n");
        printf ("\n\t3. Longitud de la primera palabra\n");
        printf ("\n\t4. Pegar las palabras y dejarlas en la primera\n");
        printf ("\n\t5. Copiar la segunda palabra en la primera\n");
        printf ("\n\t6. Comparar las palabras\n");
        printf ("\n\t7. Salir\n");
        printf ("\n\tD%c opci%cn >> ", 130, 162);
        scanf("%d",&opc);
        system("cls");
        switch (opc)
        {
               case 1: ingresa_pal(pal1, pal2);
                       break;
               case 2: muestra_pal(pal1, pal2);
                       break;
               case 3: long_pal(pal1);
                       break;
               case 4: pega_pal(pal1, pal2);
                       break;
               case 5: copia_pal(pal1, pal2);
                       break;
               case 6: compara_pal(pal1, pal2);
                       break;
        }
        system ("pause");
    }while (opc != 7); 
}

void ingresa_pal(char p1[], char p2[])
{
     printf ("\n\tPalabra 1: ");
     scanf ("%s", p1);
     printf ("\n\tPalabra 2: ");
     scanf ("%s", p2);
     existenpal=1;
}

void muestra_pal(char pal1[], char pal2[])
{
if (existenpal == 1)
    printf("\n\n\tPalabra 1: %s\n\n\tPalabra 2: %s\n\n", pal1, pal2);
else
    printf("\n\n\tNo ha ingresado las palabras\n\n");
}

void long_pal(char p[])
{
int mi_strlen(char cad[ ]);

if (existenpal == 1)
    printf("\n\n\tLa longitud de la palabra %s es %d\n\n", p, mi_strlen(p));
else
    printf("\n\n\tNo ha ingresado las palabras\n\n");
}

int mi_strlen(char cad[ ])
{
int lc;
for (lc=0; cad[lc] != '\0'; lc++);
return lc;
}
 
void pega_pal(char p1[], char p2[])
{
void mi_strcat(char [], char []);

if (existenpal == 1)
    mi_strcat(p1, p2);   // Luego, escoja la opción 2 del menú
else
    printf("\n\n\tNo ha ingresado las palabras\n\n");
}

void mi_strcat(char cad1[ ], char cad2[ ])
{
int pos1, pos2;
int mi_strlen(char [ ]);

for (pos1=mi_strlen(cad1), pos2=0; cad2[pos2] != '\0'; pos1++, pos2++)
     cad1[pos1]=cad2[pos2];
cad1[pos1]='\0';
}
 
void copia_pal(char p1[], char p2[])
{
void mi_strcpy(char [], const char []);

if (existenpal == 1)
    mi_strcpy(p1, p2);   // Luego, escoja la opción 2 del menú
else
    printf("\n\n\tNo ha ingresado las palabras\n\n");
}

void mi_strcpy(char cad1[ ], const char cad2[ ])
{
int pos;

for (pos=0; cad2[pos] != '\0'; pos++)
     cad1[pos]=cad2[pos];
cad1[pos]='\0';
}

void compara_pal(char p1[], char p2[])
{
int mi_strcmp(char [], const char []);
int mi_strcpy(char [], const char []);
char res[10];
int comp;

if (existenpal == 1)
{
    comp = mi_strcmp(p1, p2);
    if (comp < 0)
       mi_strcpy(res, "menor");
    else
    {
        if (comp == 0)
           mi_strcpy(res, "igual");
        else           // comp > 0)
           mi_strcpy(res, "mayor");
    }
    printf("\n\n\t%s es %s que %s\n\n", p1, res, p2);
}
else
    printf("\n\n\tNo ha ingresado las palabras\n\n");
}

int mi_strcmp(char cad1[ ], const char cad2[ ])
{
int pos;
for (pos=0; cad1[pos] != '\0' && cad2[pos] != '\0'; pos++)
{
     if (cad1[pos] < cad2[pos])return -1;  // cadena 1 < cadena 2
     if (cad1[pos] > cad2[pos])return 1;   // cadena 1 < cadena 2
}
if (cad1[pos]=='\0' && cad2[pos]=='\0')    // cadenas iguales
    return 0;
else
{
    if (cad1[pos]=='\0') 
       return -1;
    else
        return 1;
}      
}
