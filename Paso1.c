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
//#define P1
#ifdef P1

/**
 * Inclusiones de encabezados comunes a todos los proyectos del práctico
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
 * Macros y Constantes Simbólicas
 */


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


    /** Configuración de consola en Español
     */
    setlocale(LC_ALL, "spanish");

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

    return 0;
}


/**
 * Definiciones de Funciones
 */







#endif // P1

