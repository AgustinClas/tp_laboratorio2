#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

} eEmployees;

typedef struct
{
    int id;
    char descripcion[20];

} eSector;

#endif // ARRAYEMPLOYEES_H_INCLUDED


/** \brief Para indicar que todas las posiciones del array estan vacias,
 *         esta funcion pone la bandera isEmpty en true en todas las posicones del array
 *
 *
 * \param array de empleados
 * \param tamanio del array de empleados
 *
 */

void initEmployees(eEmployees employees[], int len);

/** \brief imprimer el array de sectores en forma encolumnada
 *
 * \param array de sectores
 * \param  tamanio del array de sectores
 *
 */

void mostrarSectores(eSector sectores[], int len);

/** \brief carga la descricpcion del sector al que pertenece un empleado
 *
 * \param  variable tipo char donde se guardara la descripcion
 * \param id correspondiente al sector
 * \param array de sectores
 * \param tamanio del array de sectores
 *
 * \return 0 en caso de error y 1 si encuentra la descripcion del sector correspondiente
 *
 */

int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int len);

/** \brief agrega en un array de empleados existente los calores recibidos como parametro en la primer posicion libre
 *
 * \param array de empleados
 * \param tamanio del array de empleados
 * \param id el cual se le asignara al nuevo empleado
 * \param array de sectores
 * \param tamanio del array de sectores
 *
 * \return -1 en caso de error y 0 si se cargo el empleado
 *
 */

int addEmployee(eEmployees employees[], int len, int proximoId, eSector sectores[], int lenSec);

/** \brief buscar la primer posicion libre (isEmpty = 0) del array de vectores
 *
 * \param array de empleados
 * \param tamanio del array de empleados
 *
 * \return el indice de la primer posicion libre dentro del array o -1 en caso de que el array este completo
 *
 */

int buscarLibre(eEmployees vec[], int len);

/** \brief busca un empleado recibiendo como parametro de busca su id
 *
 * \param id del empleado que se busca
 * \param array de empleados
 * \param tamanio del array de empleados
 *
 * \return el indice donde se encuentra el empleado dentro del array o -1 si no hay ningun empleado con ese id
 *
 */

int findEmployeeById(int id, eEmployees employees[], int len);

/** \brief permite modificar los datos cargados a un empleado
 *
 * \param array de empleados
 * \param tamanio del array de empleados
 * \param array de sectores
 * \param tamanio del array de sectores
 *
 * \return -1 en caso de error y 0 si el empleado se modifico correctamente
 *
 */

int modifyEmployee(eEmployees employees[], int len, eSector sectores[], int lenSec);

/** \brief elimina de manera logica un empleado (isEmpty = 1) a traves de su id
 *
 * \param array de empleados
 * \param tamanio del array de empleados
 * \param array de sectores
 * \param  tamanio del array de sectores
 *
 * \return -1 en caso de error y 0 en caso de que se haya dado de baja el empleado correctamente
 *
 */

int removeEmployee(eEmployees employees[], int len, eSector sectores[], int lenSec);

/** \brief ordena el array de empleados por sectores y nombre de manera ascendente o descendente
 *
 * \param array de empleados
 * \param tamanio del array de empleados
 * \param orden en el que se ordenara el array (1 si es ascendente y 0 si es descendente)
 * \param array de sectores
 * \param  tamanio del array de sectores
 *
 */

void sortEmployees(eEmployees employees[], int len, int order, eSector sectores[], int lenSec);

/** \brief muestra todos los empleados activos (isEmpty = 0) del array de empleados
 *
 * \param array de empleados
 * \param tamanio del array de empleados
 * \param array de sectores
 * \param tamanio del array de sectores
 *
 */

void printEmployees(eEmployees employees[], int len, eSector sectores[], int lenSec);

/** \brief informar el total de los salarios, el salario promedio y cuantos empleados superan el salario promedio
 *
 * \param array de empleados
 * \param tamanio del array de empleados
 *
 */

void salarios(eEmployees employees[], int len);

/** \brief le da a elegir al usuario sobre dos informes posibles
 *
 * \param array de empleados
 * \param tamanio del array de empleados
 * \param array de sectores
 * \param tamanio del array de sectores
 *
 * \return -1 en caso de error y 0 si pudo informar correctamente lo pedido por el usuario
 *
 */

int inform(eEmployees employees[],int len,  eSector sectores[], int lenSec);
