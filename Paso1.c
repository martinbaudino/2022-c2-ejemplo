/*************************************************************************
 *
 *  Facultad de Ingenier�a - Universidad Nacional de La Pampa
 *  C�tedra: Computaci�n 2
 *  A�o: 2022
 *
 *************************************************************************
 *
 *  Revisi�n del Lenguaje C: Ejemplo Integral
 *
 *  Capturar un n�mero complejo "z" con el formato "(a + bj)"
 *  y generar una matriz de 15x5 n�meros aleatorios de tipo flotante
 *  cuyos valores var�en entre "-|z|" y "+|z|".
 *  a. El formato debe tolerar espacios entre los n�meros y los s�mbolos.
 *  b. Imprimir la matriz generada separando sus valores por tabulaciones.
 *  c. Imprimir la matriz en formato tabular de celdas fijas de 15
 *     caracteres justificados a la derecha.
 *  d. Expresar los valores en formato exponencial, con 3 decimales.
 *  e. Mostrar los valores positivos de color verde y los negativos de
 *     color rojo.
 *  f. Implementar la validaci�n del n�mero, el c�lculo de su m�dulo, la
 *     generaci�n de n�meros aleatorios y las impresiones de la matriz
 *     en distintas funciones:
 *     - tomar_dato: captura los valores y los devuelve en una estructura
 *       de tipo complejo.
 *     - modulo: recibe un valor complejo y devuelve su m�dulo.
 *     - cargar_mat: recibe una matriz y un valor l�mite, y carga los
 *       elementos de la matriz con n�meros generados aleatoriamente
 *       entre -l�mite y + l�mite.
 *     - imp_mat_simple: recibe una matriz y realiza una impresi�n
 *       como en el punto �b�.
 *     - imp_mat_color: recibe una matriz y realiza una impresi�n como
 *       en los puntos �c� a �e�.
 *
 ************************************************************************/
//#define P1
#ifdef P1

/**
 * Inclusiones de encabezados comunes a todos los proyectos del pr�ctico
 */
#include <locale.h>
#include <stdio.h>

/**
 * Inclusiones de encabezados del ejercicio
 */




/**
 * Declaraciones de Funciones
 */


/**
 * Macros y Constantes Simb�licas
 */


/**
 * Aplicaci�n Principal
 */
int main(void)
{
    /** Variables para captura de n�mero complejo
     */
    float real, imaginario;
    char signo, jota;
    int valido;


    /** Configuraci�n de consola en Espa�ol
     */
    setlocale(LC_ALL, "spanish");

    printf("Resoluci�n ejercicio de Ejemplo U1A:\n\n");

    /** a. Validaci�n de dato capturado con formato arbitrario "(a + bj)"
     *
     *  Primero definir qu� elementos de la cadena hace falta capturar:
     *    a: validar que sea un n�mero real
     *    b: validar que sea un n�mero real
     *    signo: validar que el car�cter de signo sea '+' o '-' y modificar "b"
     *    parte imaginaria: debe contener el sufijo 'j', o en su defecto 'i'
     */
    valido = 0;
    while(!valido)
    {
        printf("Ingrese un n�mero complejo con el formato \"(a + bj)\","
               "siendo a y b n�meros reales: ");

        valido = scanf("(%f %c %f %c)", &real, &signo, &imaginario, &jota);
        printf("Capturados %d valores v�lidos.\n", valido);

        if (valido == 4 && (signo == '+' || signo == '-'))
        {
            if (signo == '-')
            {
                imaginario = -imaginario;
            }
            if(jota != 'j' && jota != 'i')
            {
                printf("El dato ingresado no es v�lido.\n");
                valido = 0;
            }
        }
        else
        {
            printf("El dato ingresado no es v�lido.\n");
            valido = 0;
        }
        fflush(stdin);
    }
    printf("Operador: %c \nS�mbolo Imaginario: %c\n", signo, jota);
    printf("El n�mero complejo ingresado es: z = (%f ; %f)\n", real, imaginario);

    return 0;
}


/**
 * Definiciones de Funciones
 */







#endif // P1

