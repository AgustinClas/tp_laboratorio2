#include "arrayEmployees.h"
#include "UTN.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


void initEmployees(eEmployees employees[], int len)
{
    for(int i=0; i<len; i++)
    {
        employees[i].isEmpty = 1;
    }
}

void mostrarSectores(eSector sectores[], int len)
{

    printf(" Id         Sectores\n");

    for(int i=0; i<len; i++)
    {
                printf(" %d   %15s   \n", sectores[i].id, sectores[i].descripcion);

    }
}

int cargarDescripcionSector(char descripcion[], int id, eSector sectores[], int len)
{
    int retornoOk=0;

    for(int i=0; i<len; i++)
    {
        if(sectores[i].id==id){
            strcpy(descripcion,sectores[i].descripcion);
            retornoOk=1;
        }
    }

   return retornoOk;
}

int buscarLibre(eEmployees vec[], int len)
{

    int indice=-1;
    for(int i=0; i<len; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int addEmployee(eEmployees employees[], int len, int proximoId, eSector sectores[], int lenSec)
{
    system("cls");
    int ok = -1;
    int contadorOk=0;
    int indiceLibre;
    eEmployees auxEmployee;

    printf("***Alta empleado***\n");

    indiceLibre=buscarLibre(employees, len);

    if(indiceLibre==-1)
    {
        printf("\nSistema completo\n");
    }
    else
    {
        auxEmployee.id = proximoId;

        if((utn_getString(auxEmployee.name, "Ingrese el nombre: ", "Error. ", 10)) == 0){
            formalizarString(auxEmployee.name);
            contadorOk++;
        }

        if(contadorOk == 1 ){
            if(utn_getString(auxEmployee.lastName, "Ingrese el Apellido: ", "Error. ", 10)==0){
                formalizarString(auxEmployee.lastName);
                contadorOk++;
            }
        }

        if(contadorOk == 2){
            if(utn_getNumeroFlotante(&auxEmployee.salary, "Ingrese el sueldo: ", "Error. ", 1, 1000000, 10) == 0){
                contadorOk++;
            }
        }

        if(contadorOk == 3){
            mostrarSectores(sectores, lenSec);
            if(utn_getNumeroEntero(&auxEmployee.sector, "Ingrese el sector: ", "Error. ", 1, 6, 10) == 0){
                auxEmployee.isEmpty = 0;
                employees[indiceLibre]  = auxEmployee;
                ok = 0;
            }
        }else{
            printf("Ocurrio un error en el sistema\n\n");
        }
    }

    return ok;
}

int findEmployeeById(int id, eEmployees employees[], int len)
{
    int indice=-1;

    for(int i=0; i<len; i++)
    {
        if(employees[i].id==id && employees[i].isEmpty == 0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int modifyEmployee(eEmployees employees[], int len, eSector sectores[], int lenSec)
{
    int returnOk=-1;
    int id;
    int indice=-1;
    int opcion;
    char descripcionSector[20];


    system("cls");
    printf("***Modificar empleado***\n\n");

    if(utn_getNumeroEntero(&id, "Ingrese id: ", "Error. ", 1000, 3000, 10) == 0){
        indice = findEmployeeById(id, employees, len);
    }

    if(indice==-1)
    {
        printf("\nEste id no existe\n");
    }
    else
    {
        cargarDescripcionSector(descripcionSector, employees[indice].sector, sectores, lenSec);

        printf("\nQue desea modificar?\n");
        printf("1. Nombre: %s\n", employees[indice].name);
        printf("2. Apellido: %s\n", employees[indice].lastName);
        printf("3. Sector: %s\n", descripcionSector);
        printf("4. Sueldo: %.2f\n", employees[indice].salary);

        utn_getNumeroEntero(&opcion, "Elija una opcion: ", "Error. ", 1, 4, 10);

        switch(opcion){
            case 1:
                if(utn_getString(employees[indice].name, "Ingrese el nombre: ", "Error. ", 10)==0){
                    formalizarString(employees[indice].name);
                    returnOk = 0;
                }
                break;
            case 2:
                if(utn_getString(employees[indice].lastName, "Ingrese el Apellido: ", "Error. ", 10)==0){
                    formalizarString(employees[indice].lastName);
                    returnOk = 0;
                }
                break;
            case 3:
                mostrarSectores(sectores, lenSec);
                if(utn_getNumeroEntero(&employees[indice].sector, "Ingrese el sector: ", "Error. ", 1, 6, 10) == 0){
                    returnOk = 0;
                }
                break;
            case 4:
                if(utn_getNumeroFlotante(&employees[indice].salary, "Ingrese el sueldo: ", "Error. ", 1, 1000000, 10) == 0){
                    returnOk = 0;
                }
                break;
        }
    }

    return returnOk;
}

int removeEmployee(eEmployees employees[], int len, eSector sectores[], int lenSec)
{
    int id;
    int indice = -1;
    int retorno = -1;
    char confirmacion;
    char descripcionSector[20];

    system("cls");
    printf("***Baja empleado***\n");

    if(utn_getNumeroEntero(&id, "Ingrese id: ", "Error. ", 1000, 3000, 10) == 0){
        indice = findEmployeeById(id, employees, len);
    }

    if(indice == -1)
    {
        printf("Este id no existe\n");
    }
    else
    {
        cargarDescripcionSector(descripcionSector, employees[indice].sector, sectores, lenSec);

        //se le muestran al usuario los datos del empleado que quiere dar de baja y se pide confirmacion
        printf("\nDesea dar de baja este empleado?\n");
        printf("1. Nombre: %s\n", employees[indice].name);
        printf("2. Apellido: %s\n", employees[indice].lastName);
        printf("3. Sector: %s\n", descripcionSector);
        printf("4. Sueldo: %.2f\n", employees[indice].salary);
        utn_getCharacter(&confirmacion,"\nSeguro que desea dar de baja este empleado? s/n: ", "Error. ", 's', 'n', 10 );

        if(confirmacion=='s')
        {
            employees[indice].isEmpty = 1;
            retorno = 0;
        }
        else
        {
            printf("Se cancela la operacion");
        }
    }

    return retorno;
}

void sortEmployees(eEmployees employees[], int len, int order, eSector sectores[], int lenSec)
{
    eEmployees auxEmployee;
    system("cls");

    //ordena de manera ascendente
    if(order == 1){
        for(int i=0; i<len -1; i++){
            for(int j=i+1; j<len; j++){
                if(employees[i].sector > employees[j].sector){
                    auxEmployee = employees[i];
                    employees[i] = employees[j];
                    employees[j] = auxEmployee;

                }else if(employees[i].sector == employees[j].sector){
                    if(strcmp(employees[i].lastName, employees[j].lastName) == 1){
                        auxEmployee = employees[i];
                        employees[i] = employees[j];
                        employees[j] = auxEmployee;

                    }else if(strcmp(employees[i].lastName, employees[j].lastName) == 0){
                        if(strcmp(employees[i].name, employees[j].name) == 1){
                            auxEmployee = employees[i];
                            employees[i] = employees[j];
                            employees[j] = auxEmployee;
                        }
                    }
                }
            }
        }

    //ordena de manera descendente
    }else if(order == 0){
        for(int i=0; i<len -1; i++){
            for(int j=i+1; j<len; j++){
                if(employees[i].sector < employees[j].sector){
                    auxEmployee = employees[i];
                    employees[i] = employees[j];
                    employees[j] = auxEmployee;

                }else if(employees[i].sector == employees[j].sector){
                    if(strcmp(employees[i].lastName, employees[j].lastName) == -1){
                        auxEmployee = employees[i];
                        employees[i] = employees[j];
                        employees[j] = auxEmployee;

                    }else if(strcmp(employees[i].lastName, employees[j].lastName) == 0){
                        if(strcmp(employees[i].name, employees[j].name) == -1){
                            auxEmployee = employees[i];
                            employees[i] = employees[j];
                            employees[j] = auxEmployee;
                        }
                    }
                }
            }
        }
    }

    printEmployees(employees, len, sectores, lenSec);

}

void printEmployees(eEmployees employees[], int len, eSector sectores[], int lenSec)
{
    char descripcionSector[20];

    printf("\n Id            Nombre         Apellido       salario            sector\n\n");

    for(int i=0; i<len; i++){
        if(employees[i].isEmpty == 0){
            cargarDescripcionSector(descripcionSector, employees[i].sector, sectores, lenSec);
            printf("%5d %15s %15s       %.2f   %15s\n", employees[i].id, employees[i].name, employees[i].lastName, employees[i].salary, descripcionSector);
        }
    }

}

void salarios(eEmployees employees[], int len)
{
    float acumuladorSalarios=0;
    int contadorEmpleados=0;
    int contadorSueldosExcedentes=0;
    float salarioPromedio;

    for(int i=0; i<len; i++){
        if(employees[i].isEmpty == 0){
            contadorEmpleados++;
            acumuladorSalarios += employees[i].salary;
        }
    }

    //no es necesario verificar que el contadorEmpleados sea distinto de 0 porque si no hubiera empleados en el sistema no se podria haber accedido a esta funcion

    salarioPromedio = acumuladorSalarios / contadorEmpleados;

    for(int i=0; i<len; i++){
        if(employees[i].salary > salarioPromedio && employees[i].isEmpty == 0){
            contadorSueldosExcedentes++;
        }
    }

    printf("\n\nTotal salarios: %.2f\n", acumuladorSalarios);
    printf("Salario promedio: %.2f\n", salarioPromedio);
    printf("Empleados que exceden el salario promedio: %d\n\n\n", contadorSueldosExcedentes);

}

int inform(eEmployees employees[],int len,  eSector sectores[], int lenSec)
{
    system("cls");

    int opcion;
    int order;
    int retorno = -1;

    system("cls");
    printf("***Informar***\n\n");
    printf("1. Empleados ordenados por sector y nombre\n");
    printf("2. Sueldos totales, sueldo promedio y empleados que exceden el sueldo promedio\n");
    if(utn_getNumeroEntero(&opcion, "Ingrese una opcion: ", "Error. ", 1, 2, 10) == 0){

        switch(opcion){
            case 1:
                printf("\nDesea hacerlo de manera ascendente o descendente?\n");
                printf("1.Descendente\n2.Ascendente\n");
                if(utn_getNumeroEntero(&order, "Ingrese una opcion: ", "Error. ", 1,2,10) == 0){
                    retorno = 0;
                    //order - 1 para cumplir con los paremetros de la funcion
                    sortEmployees(employees, len, order-1, sectores, lenSec);
                }
                break;
            case 2:
                salarios(employees, len);
                retorno = 0;
        }
    }

    return retorno;
}


