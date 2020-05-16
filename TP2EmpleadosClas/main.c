#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "arrayEmployees.h"

#define TAM 1000
#define TAMSEC 6

int menuOpciones();

int main()
{
    int proximoId = 1000;
    int opcionMenu;
    int flagCase1=0;

    eEmployees employees[TAM];
    initEmployees(employees, TAM);
    eSector sectores[TAMSEC]={{1, "Sistemas"}, {2, "RR.HH"}, {3, "Ventas"}, {4, "Compras"}, {5, "Contable"}, {6, "Marketing"}};



    do{
        opcionMenu = menuOpciones();

        switch(opcionMenu){
            case 1:
                if(addEmployee(employees, TAM, proximoId, sectores, TAMSEC) == 0){
                    proximoId++;
                    flagCase1=1;
                    printf("\nEmpleado ingresado con exito\n\n");
                }else{
                    printf("No se ha podido aniadir el empleado\n\n\n");
                }
                break;
            case 2:
                if(flagCase1==1){

                    if(modifyEmployee(employees, TAM, sectores, TAMSEC) == 0){
                        printf("\nOperacion realizada con exito\n\n");

                    }else{
                        printf("\nNo se pudo realizar la Operacion\n\n");
                    }

                }else{
                    printf("\nPrimero debe ingresar un empleado\n\n");
                }
                break;
            case 3:
                if(flagCase1==1){

                    if(removeEmployee(employees, TAM, sectores, TAMSEC) == 0){
                        printf("\nOperacion realizada con exito\n\n");
                        int flag = 0;

                        for(int i=0; i<TAM; i++){
                            if(employees[i].isEmpty==0){
                                flag=1;
                                break;
                            }
                        }
                        if(!flag){
                            flagCase1=0;
                        }
                    }else{
                        printf("\nNo se pudo realizar la Operacion\n\n");
                    }

                }else{
                    printf("\nPrimero debe ingresar un empleado\n\n");
                }
                break;
            case 4:
                if(flagCase1==1){
                    if(inform(employees, TAM, sectores, TAMSEC) == 0){
                        printf("\nOperacion realizada con exito\n\n");
                    }else{
                        printf("\nNo se pudo realizar la Operacion\n\n");
                    }

                }else{
                    printf("\nPrimero debe ingresar un empleado\n\n");
                }
                break;

        }

    }while(opcionMenu!=5);


}

int menuOpciones()
{
    int opcion;

    printf("***Menu***\n\n");
    printf("1. Alta empleado\n");
    printf("2. Modificar empleado\n");
    printf("3. Baja empleado\n");
    printf("4. Informar\n");
    printf("5. Salir\n\n");

    utn_getNumeroEntero(&opcion, "Ingrese opcion: ", "Error. ", 1, 5, 10);

    return opcion;

}



