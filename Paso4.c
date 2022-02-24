/*************************************************************************
 *
 *  Facultad de Ingeniería - Universidad Nacional de La Pampa
 *  Cátedra: Computación 2
 *  Año: 2022
 *
 *************************************************************************
 *
 *  Revisión del Lenguaje C: Ejemplo Integral
 *
 *  Capturar un número complejo "z" con el formato "(a + bj)"
 *  y generar una matriz de 15x5 números aleatorios de tipo flotante
 *  cuyos valores varíen entre "-|z|" y "+|z|".
 *  a. El formato debe tolerar espacios entre los números y los símbolos.
 *  b. Imprimir la matriz generada separando sus valores por tabulaciones.
 *  c. Imprimir la matriz en formato tabular de celdas fijas de 15
 *     caracteres justificados a la derecha.
 *  d. Expresar los valores en formato exponencial, con 3 decimales.
 *  e. Mostrar los valores positivos de color verde y los negativos de
 *     color rojo.
 *  f. Implementar la validación del número, el cálculo de su módulo, la
 *     generación de números aleatorios y las impresiones de la matriz
 *     en distintas funciones:
 *     - tomar_dato: captura los valores y los devuelve en una estructura
 *       de tipo complejo.
 *     - modulo: recibe un valor complejo y devuelve su módulo.
 *     - cargar_mat: recibe una matriz y un valor límite, y carga los
 *       elementos de la matriz con números generados aleatoriamente
 *       entre -límite y + límite.
 *     - imp_mat_simple: recibe una matriz y realiza una impresión
 *       como en el punto “b”.
 *     - imp_mat_color: recibe una matriz y realiza una impresión como
 *       en los puntos “c” a “e”.
 *
 ************************************************************************/
//#define P4
#ifdef P4

/**
 * Inclusiones de encabezados comunes a todos los proyectos del práctico
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
 * Declaraciones de Funciones
 */


/**
 * Macros y Constantes Simbólicas
 */
/** Definiciones para matris de FILS x COLS
 */
#define FILS 15
#define COLS  5

/** Definiciones de colores para la consola
 */
#define T_DEF "\033[0m"
#define T_AMA "\033[93m"
#define T_ROJ "\033[91m"
#define T_VER "\033[92m"


/**
 * Aplicación Principal
 */
int main(void)
{
    /** Variables para captura de número complejo
     */
    float real, imaginario;
    char signo, jota;
    int valido;

    /** Variables para generación de números aleatorios
     */
    float escala, modulo;

    /** Variables para Matriz de FILS x COLS
     */
    float matriz[FILS][COLS];
    int i, j;

    /** Configuración de consola en Español y a colores
     */
    setlocale(LC_ALL, "spanish");
    system("reg add HKEY_CURRENT_USER\\Console /v VirtualTerminalLevel /t REG_DWORD /d 0x00000001 /f");


    printf("Resolución ejercicio de Ejemplo U1A:\n\n");

    /** a. Validación de dato capturado con formato arbitrario "(a + bj)"
     *
     *  Primero definir qué elementos de la cadena hace falta capturar:
     *    a: validar que sea un número real
     *    b: validar que sea un número real
     *    signo: validar que el carácter de signo sea '+' o '-' y modificar "b"
     *    parte imaginaria: debe contener el sufijo 'j', o en su defecto 'i'
     */
    valido = 0;
    while(!valido)
    {
        printf("Ingrese un número complejo con el formato \"(a + bj)\","
               "siendo a y b números reales: ");

        valido = scanf("(%f %c %f %c)", &real, &signo, &imaginario, &jota);
        printf("Capturados %d valores válidos.\n", valido);

        if (valido == 4 && (signo == '+' || signo == '-'))
        {
            if (signo == '-')
            {
                imaginario = -imaginario;
            }
            if(jota != 'j' && jota != 'i')
            {
                printf("El dato ingresado no es válido.\n");
                valido = 0;
            }
        }
        else
        {
            printf("El dato ingresado no es válido.\n");
            valido = 0;
        }
        fflush(stdin);
    }
    printf("Operador: %c \nSímbolo Imaginario: %c\n", signo, jota);
    printf("El número complejo ingresado es: z = (%f ; %f)\n", real, imaginario);


    /** Cálculo del módulo del número complejo
     *  |z| = sqrt(a^2 + b^2)
     */
    modulo = sqrt(real * real + imaginario * imaginario);
    printf("Su módulo es: |z| = %f\n\n", modulo);

    /** Carga de números aleatorios en la Matriz
     *  rand() genera un número entre 0 y RAND_MAX. Una forma de llevarlo al rango
     *  [-|z| : +|z|] es:
     *  Primero escalarlo de a valores [0.0 : 1.0]
     *  Luego multiplicarlo por 2 * |z| para desplazarlo [0.0 : 2 |z|]
     *  Y finalmente restarle |z| para desplazarlo [-|z| : |z|]
     */
    for(i=0; i<FILS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            escala = (float)rand() / RAND_MAX;              // [0:1.0]
            matriz[i][j] = ( escala * 2 * modulo) -  modulo; // [-modulo:+modulo]
        }
    }

    /** b. Impresión de Matriz en formato sencillo
     */
    printf("Matriz Original:\n");
    for(i=0; i<FILS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            printf("%f\t", matriz[i][j]);                   // '\t' separa las columnas
        }
        printf("\n");   // Separa las filas
    }

    /** Impresión de Matriz en formato complejo y con colores
     *  c. Las celdas de tamaño fijo se crean con "%15f"
     *  d. La precisión de cada valor se fija con "%.3f"
     *  e. Los colores se cambian utilizando secuencias de escape a códigos de colores ANSI
     */
    printf("\n%s----------------\n", T_AMA);
    printf("Matriz procesada:\n");
    printf("%s----------------%s\n", T_AMA, T_DEF);
    for(i=0; i<FILS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            printf("%s%15.3e%s",(matriz[i][j]) >=0? T_VER: T_ROJ,  matriz[i][j], T_DEF);
        }
        printf("\n");
    }

    return 0;
}


/**
 * Definiciones de Funciones
 */


#endif // P4

