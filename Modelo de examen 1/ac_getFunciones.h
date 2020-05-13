#ifndef AC_GETFUNCIONES_H_INCLUDED
#define AC_GETFUNCIONES_H_INCLUDED

/** \brief ac_getInt Pide integro por consola dentro del rango especificado,lo guarda en una variable, y retorna 1. Si se supera el numero maximo de intentos, no guarda nada en la variable y retorna -1.
 *
 * \param Direccion de memoria de variable tipo "int" en donde se va a guardar el numero obtenido
 * \param Limite minimo del numero pedido
 * \param Limite maximo del numero pedido
 * \param Mensaje a mostrar por consola para pedir el numero
 * \param Numero maximo de intentos
 * \return 1 si se pudo guardar un numero en la variable. -1 si no se pudo guardar nada en la variable.
 *
 */
int ac_getInt(int *num,int minimo,int maximo,char mensaje[],int tries);

/** \brief ac_getFloat Pide flotante por consola dentro del rango especificado,lo guarda en una variable, y retorna 1. Si se supera el numero maximo de intentos, no guarda nada en la variable y retorna -1.
 *
 * \param Direccion de memoria de variable tipo "float" en donde se va a guardar el numero obtenido
 * \param Limite minimo del numero pedido
 * \param Limite maximo del numero pedido
 * \param Mensaje a mostrar por consola para pedir el numero
 * \param Numero maximo de intentos
 * \return 1 si se pudo guardar un numero en la variable. -1 si no se pudo guardar nada en la variable.
 *
 */
int ac_getFloat(float *num,float minimo,float maximo,char mensaje[],int tries);

/** \brief ac_getChar Pide caracter por consola y lo valida con hasta 5 caracteres ingresados por parametros.Si pudo guardar el caracter en la variable indicada retorna 1. Si se supera el numero maximo de intentos, no guarda nada en la variable y retorna -1.
 *
 * \param Direccion de memoria de variable tipo "char" en donde se va a guardar el caracter obtenido
 * \param Mensaje a mostrar por consola para pedir el caracter.
 * \param Validacion 1. caracter ' '. si se ingresa '0' entonces no hace validación (el usuario puede ingresar cualquier caracter).
 * \param Validacion 2. caracter ' '.
 * \param Validacion 3. caracter ' '.
 * \param Validacion 4. caracter ' '.
 * \param Validacion 5. caracter ' '.
 * \param Numero maximo de intentos
 * \return 1 si se pudo guardar un caracter en la variable. -1 si se supero el maximo de intentos y no se pudo guardar nada en la variable.
 *
 */
int ac_getChar (char* a,char mensaje[],char b, char c, char d, char e, char f,int tries);

/** \brief ac_getDate Pide una fecha por consola (dd/mm/aaaa) dentro del rango de años especificado,lo guarda en una variable, y retorna 1. Si se supera el numero maximo de intentos, no guarda nada en la variable y retorna -1.
Nota: Esta función no valida si el año ingresado es bisiesto por lo que siempre deja ingresar el 29/02/xxxx como fecha valida.
 *
 * \param Direccion de memoria de variable tipo "int" en donde se va a guardar el dia obtenido (1 a 29 para febrero, 1 a 30/31 para el resto de los meses)
 * \param Direccion de memoria de variable tipo "int" en donde se va a guardar el mes obtenido (1 a 12)
 * \param Direccion de memoria de variable tipo "int" en donde se va a guardar el año obtenido
 * \param Mensaje a mostrar por consola para pedir la fecha
 * \param Año minimo valido
 * \param Año maximo valido
 * \param Numero maximo de intentos
 * \return 1 si se pudieron guardar los 3 numeros de la fecha en las variables. -1 si se supero el maximo de intentos y no se pudieron guardar los numeros en las variables.
 *
 */
int ac_getDate (int* d,int* m, int* a,char mensaje[], int minYear, int maxYear,int tries);

/** \brief Pide cadena de caracteres por consola de una longitud maxima a ingresar por parametro,la guarda en una variable tipo char [], y retorna 1. Si se supera el numero maximo de intentos, no guarda nada en la variable y retorna -1.
 *
 * \param Direccion de memoria de variable tipo char [] en donde se va a guardar la cadena de caracteres obtenida.
 * \param Longitud maxima posible de la cadena a pedir.
 * \param Numero maximo de intentos
 * \param Mensaje a mostrar por consola para pedir la cadena.
 * \return 1 si se pudo guardar una cadena en la variable. -1 si se supero el maximo de intentos y no se pudo guardar nada en la variable.
 *
 */
int ac_getString(char chain[],int lenght,int tries,char mensaje[]);

#endif // AC_GETFUNCIONES_H_INCLUDED

