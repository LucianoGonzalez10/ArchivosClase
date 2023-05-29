#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <ctype.h>

typedef struct
{
    char nombre[30];
    int edad;
    int documento;
} alumno;

void agregarElemento(alumno a);
void mostrarAlumnos(alumnos);

int main()
{
    alumno a;
    agregarElemento(a);
    mostrarAlumno(a);
    return 0;
}

void agregarElemento(alumno a)
{
    FILE* buffer = fopen("alumnos.txt", "ab");
    char flag = 's';
    if(buffer != NULL)
    {
        while(flag == 's')
        {

            printf("Ingrese el nombre del alumno \n");
            fflush(stdin);
            gets(a.nombre);

            printf("Ingrese la edad del alumno \n");
            scanf("%d", &a.edad);

            printf("Ingrese el documento del alumno \n");
            scanf("%d", &a.documento);

            printf("Desea seguir cargando datos? (s/n) \n");
            fflush(stdin);
            scanf("%c", &flag);

            fwrite (&a, sizeof(alumno), 1, buffer);
        }
    }
    fclose(buffer);
}

void mostrarAlumno(alumno a)
{

    printf("Nombre del Alumno: %s", a.nombre);

    printf("Edad del alumno: %d", a.edad);

    printf("Documento del Alumno: %d", a.documento);

    printf("---------------------------- \n");
}

void mostrarAlumnos(alumnos){
FILE *buffer;
alumno a;
buffer = fopen("alumnos.txt", "rb");
int i = 0;

if(buffer){
 while(!feof(buffer)){
    fread(&a, sizeof(alumno), 1, buffer);
    if(!feof(buffer)){
        printf("Registro numero %d", i++);
        mostrarAlumno(a);
    }
 }
}
fclose(buffer);
}
