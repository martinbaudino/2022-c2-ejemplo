/*************************************************************************
 *
 *  Facultad de Ingenier�a - Universidad Nacional de La Pampa
 *  C�tedra: Computaci�n 2
 *  A�o: 2022
 *
 *************************************************************************
 *
 *  Punteros y Memoria Din�mica en C: Ejemplo Integral
 *
 *  Modificar el c�digo del punto "f" del Ejemplo Integral del TP1A para
 *  que cumpla con las siguientes especificaciones:
 *  a. Modificar las funciones cargar_mat e imp_mat_color para que
 *     las matrices se pasen por referencia.
 *  b. Modificar la estructura "complejo" para que, en vez de un n�mero
 *     complejo, contenga las dimensiones de la matriz. Solicitar estos
 *     valores por consola y modificar el tipo de datos de los elementos
 *     de la matriz para que sean caracteres. Eliminar el c�digo innecesario.
 *  c. Modificar la funci�n cargar_mat para que reserve din�micamente el
 *     almacenamiento y retorne el puntero correspondiente. Generar
 *     caracteres aleatorios entre '0' y '~'
 *  d. Implementar la funci�n borrar_mat que libere la memoria antes de
 *     salir.
 *
 *
 ************************************************************************/
#define P6
#ifdef P6

/**
 * Inclusiones de encabezados comunes a todos los proyectos del pr�ctico
 */
#include <locale.h>
#include <stdio.h>

/**
 * Inclusiones de encabezados del ejercicio
 */
#include <math.h>
#include <stdlib.h>
#include <windows.h>

/**
 * Macros y Constantes Simb�licas
 */


/** Definiciones de colores para la consola
 */
#define T_DEF "\033[0m"
#define T_AMA "\033[93m"
#define T_ROJ "\033[91m"
#define T_VER "\033[92m"


/**
 * Declaraciones de Funciones
 */
typedef struct dim
{
    int fils, cols;
} dimensiones;

dimensiones tomar_dato(void);

char **cargar_mat(dimensiones fils_cols);
void imp_mat_color(char **matriz, dimensiones fils_cols);
void borrar_mat(char **matriz, dimensiones fils_cols);


/**
 * Aplicaci�n Principal
 */
int main(void)
{
    dimensiones fils_cols;

    char **mat;


    /** Configuraci�n de consola en Espa�ol y a colores
     */
    setlocale(LC_ALL, "spanish");
    system("reg add HKEY_CURRENT_USER\\Console /v VirtualTerminalLevel /t REG_DWORD /d 0x00000001 /f");


    printf("\n%sResoluci�n ejercicio de Ejemplo U1B:\n\n%s", T_VER, T_DEF);

    fils_cols = tomar_dato();

    mat = cargar_mat(fils_cols);

    imp_mat_color(mat, fils_cols);

    printf("%s\n\nPuntero a la matriz: %p\tPrimer elemento: %d\n%s",T_VER, *mat, mat[0][0], T_DEF); // Qu� pasa aqu�?
    borrar_mat(mat, fils_cols);
    printf("%s\n\nPuntero a la matriz: %p\tPrimer elemento: %d\n%s",T_ROJ, *mat, mat[0][0], T_DEF); // Qu� pasa aqu�?


    return 0;
}


/**
 * Definiciones de Funciones
 */
dimensiones tomar_dato(void)
{
    /** Variables para captura de n�mero complejo
     */
    dimensiones dato;
    int valido;

    valido = 0;
    while(!valido)
    {
        printf("Ingrese el tama�o de la matriz que desea generar en formato n_filas n_columnas: ");

        valido = scanf("%d %d", &dato.fils, &dato.cols);
        printf("Capturados %d valores v�lidos.\n", valido);

        if (valido != 2 )
        {
            printf("El dato ingresado no es v�lido.\n");
            valido = 0;
        }
        fflush(stdin);
    }
    printf("Se crear� una matriz de [%d][%d].\n", dato.fils, dato.cols);

    return dato;
}


char **cargar_mat(dimensiones fils_cols)
{
    int i, j;
    char **matriz;

    matriz = (char **) malloc(fils_cols.fils * sizeof(char *));

    for(i=0; i<fils_cols.fils; i++)
    {
        matriz[i] = (char *) malloc(fils_cols.cols * sizeof(char));
        for(j=0; j<fils_cols.cols; j++)
        {
            matriz[i][j] = (rand() % ('~' - '0' + 1)) + '0';
        }
    }
    return matriz;
}

void imp_mat_color(char **matriz, dimensiones fils_cols)
{
    int i, j;

    printf("\n%s----------------\n", T_AMA);
    printf("Matriz procesada:\n");
    printf("%s----------------%s\n", T_AMA, T_DEF);
    for(i=0; i<fils_cols.fils; i++)
    {
        for(j=0; j<fils_cols.cols; j++)
        {
            printf("%s%3c%s", T_VER,  matriz[i][j], T_DEF);
        }
        printf("\n");
    }
}

void borrar_mat(char **matriz, dimensiones fils_cols)
{
    int i;

    for(i=0; i<fils_cols.fils; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;
}


#endif // P6

