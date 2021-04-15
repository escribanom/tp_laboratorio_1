#ifndef MENU_H_
#define MENU_H_
int menuCalculadora();
/**\brief muestra opciones
 *\param
 * \return devuelve opcion
 */
float ingresarNumero();
/**\brief ingresa numero
 *\param
 * \return
 */
float suma(float *numeroUno, float *numeroDos);
/**\brief recibe los numeros
 *\param hace la suma
 * \return muestra el resultado
 */
float resta(float *numeroUno, float *numeroDos);
/**\brief recibe los numeros
 *\param hace el proceso
 * \return muestra los resultados
 */
float division(float *numeroUno, float *numeroDos);
/**\brief recibe los numeros
 *\param hace el proceso si el numero 2 no es 0
 * \return muestra los resultados
 */
long long int factorialNumUno(float *numeroUno);
/**\brief recibe el numero 1
 *\param si es mayor a 0 lo factorea
 * \return muestra el resultado
 */
long long int factorialNumDos(float *numeroDos);
/**\brief recibe el numero 2
 *\param si es mayor a 0 lo factorea
 * \return muestra el resultado
 */
float multiplicacion(float *numeroUno, float *numeroDos);
/**\brief ingresa los numeros
 *\param hace la multiplicacion
 * \return muestra el resultado
 */

#endif /* MENU_H_ */
