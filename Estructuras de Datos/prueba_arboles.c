#include <stdio.h>
#include <stdlib.h>
#include "arboles.h"
#define PAUSA "pause>nul"
#define LIMPIAR "cls"

int main()
{
    // leer cadena de numeros sin enter like club algoritmia
    Arbol t1, t2;
    crearArbol(&t1);
    crearArbol(&t2);
//    agregarNodo(&t1, 20);
//    agregarNodo(&t1, 10);
//    agregarNodo(&t1, 30);
//    agregarNodo(&t1, 1);
//    agregarNodo(&t1, 15);
//    agregarNodo(&t1, 25);
//    agregarNodo(&t1, 35);
//    printf("\n\n");
//    imprimirPreOrder(t1);
//    printf("\n\n");
//    imprimirInOrder(t1);
//    printf("\n\n");
//    imprimirPostOrder(t1);
//    printf("Nodos: %d\n", numNodos(t1));
//    printf("Hojas: %d\n", numHojas(t1));
//    copiarArbol(t1, &t2);
//    if(buscarValor(t1, 0))
//        printf("Encontrado");
//    if(compararArboles(t1, t2))
//        printf("Son iguales\n");
//    agregarNodo(&t2, 90);
//    if(!compararArboles(t1, t2))
//        printf("Ya no son iguales");
//    printf("Altura: %d\n", alturaArbol(t2));
//    imprimirPorNivel(t1);
//    printf("%d\n", numNodosInteriores(t1));
//    mirrorArbol(t1, &t2);
//    imprimirPorNivel(t1);
//    printf("\n");
//    imprimirPorNivel(t2);
    //borrarNodo(&t1, 75);
//    imprimirPorNivel(t1);
    int opcion, opc, value, cantidad, datos[50];
    while(1)
    {
        system(LIMPIAR);
        fflush(stdin);
        printf("\t1. Agregar datos\n\t2. Imprimir Preorder\n\t3. Imprimir Inorder\n\t4. Imprimir Postorder\n\t5. Copiar arbol\n\t6. Comparar arboles\n\t7. Buscar valor\n\t8. Altura de un arbol\n\t9. Imprimir por niveles\n\t10. Numero de nodos\n\t11. Numero de hojas\n\t12. Numero de nodos interiores\n\t13. Arbol espejo\n\t14. Borrar nodo\n\t15. Salir\n\n");
        printf("\tOpcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                system(LIMPIAR);
                printf("Cantidad de elementos a meter: ");
                fflush(stdin);
                scanf("%d", &cantidad);
                for(opc = 0; opc < cantidad; opc++)
                {
                    scanf("%d", &datos[opc]);
                    agregarNodo(&t1, datos[opc]);
                }
                break;
            case 2:
                system(LIMPIAR);
                printf("\t1. Arbol 1\n\t2. Arbol 2\n\n\tOpcion: ");
                fflush(stdin);
                scanf("%d", &opc);
                if(opc == 1)
                    imprimirPreOrder(t1);
                else if(opc == 2)
                    imprimirPreOrder(t2);
                else
                    printf("\n\nArbol no existente");
                system(PAUSA);
                break;
            case 3:
                system(LIMPIAR);
                printf("\t1. Arbol 1\n\t2. Arbol 2\n\n\tOpcion: ");
                fflush(stdin);
                scanf("%d", &opc);
                if(opc == 1)
                    imprimirInOrder(t1);
                else if(opc == 2)
                    imprimirInOrder(t2);
                else
                    printf("\n\nArbol no existente");
                system(PAUSA);
                break;
            case 4:
                system(LIMPIAR);
                printf("\t1. Arbol 1\n\t2. Arbol 2\n\n\tOpcion: ");
                fflush(stdin);
                scanf("%d", &opc);
                if(opc == 1)
                    imprimirPostOrder(t1);
                else if(opc == 2)
                    imprimirPostOrder(t2);
                else
                    printf("\n\nArbol no existente");
                system(PAUSA);
                break;
            case 5:
                system(LIMPIAR);
                copiarArbol(t1, &t2);
                printf("Arbol 1 copiado al arbol 2");
                system(PAUSA);
                break;
            case 6:
                system(LIMPIAR);
                if(compararArboles(t1, t2))
                    printf("Ambos arboles son iguales");
                else
                    printf("Los arboles son distintos");
                system(PAUSA);
                break;
            case 7:
                system(LIMPIAR);
                printf("\t1. Arbol 1\n\t2. Arbol 2\n\n\tOpcion: ");
                fflush(stdin);
                scanf("%d", &opc);
                printf("\n\nValor a buscar: ");
                fflush(stdin);
                scanf("%d", &value);
                if(opc == 1)
                {
                    if(buscarValor(t1, value))
                        printf("Valor encontrado");
                    else
                        printf("Valor no encontrado");
                }
                else if(opc == 2)
                {
                    if(buscarValor(t2, value))
                        printf("Valor encontrado");
                    else
                        printf("Valor no encontrado");
                }
                else
                    printf("\n\nArbol no existente");
                system(PAUSA);
                break;
            case 8:
                system(LIMPIAR);
                printf("\t1. Arbol 1\n\t2. Arbol 2\n\n\tOpcion: ");
                fflush(stdin);
                scanf("%d", &opc);
                if(opc == 1)
                    printf("\n\nAltura: %d", alturaArbol(t1));
                else if(opc == 2)
                    printf("\n\nAltura: %d", alturaArbol(t2));
                else
                    printf("\n\nArbol no existente");
                system(PAUSA);
                break;
            case 9:
                system(LIMPIAR);
                printf("\t1. Arbol 1\n\t2. Arbol 2\n\n\tOpcion: ");
                fflush(stdin);
                scanf("%d", &opc);
                if(opc == 1)
                    imprimirPorNivel(t1);
                else if(opc == 2)
                    imprimirPorNivel(t2);
                else
                    printf("\n\nArbol no existente");
                system(PAUSA);
                break;
            case 10:
                system(LIMPIAR);
                printf("\t1. Arbol 1\n\t2. Arbol 2\n\n\tOpcion: ");
                fflush(stdin);
                scanf("%d", &opc);
                if(opc == 1)
                    printf("\n\nCantidad de nodos: %d", numNodos(t1));
                else if(opc == 2)
                    printf("\n\nCantidad de nodos: %d", numNodos(t2));
                else
                    printf("\n\nArbol no existente");
                system(PAUSA);
                break;
            case 11:
                system(LIMPIAR);
                printf("\t1. Arbol 1\n\t2. Arbol 2\n\n\tOpcion: ");
                fflush(stdin);
                scanf("%d", &opc);
                if(opc == 1)
                    printf("\n\nCantidad de hojas: %d", numHojas(t1));
                else if(opc == 2)
                    printf("\n\nCantidad de hojas: %d", numHojas(t2));
                else
                    printf("\n\nArbol no existente");
                system(PAUSA);
                break;
            case 12:
                system(LIMPIAR);
                printf("\t1. Arbol 1\n\t2. Arbol 2\n\n\tOpcion: ");
                fflush(stdin);
                scanf("%d", &opc);
                if(opc == 1)
                    printf("\n\nCantidad de nodos interiores: %d", numNodosInteriores(t1));
                else if(opc == 2)
                    printf("\n\nCantidad de nodos interiores: %d", numNodosInteriores(t2));
                else
                    printf("\n\nArbol no existente");
                system(PAUSA);
                break;
            case 13:
                system(LIMPIAR);
                mirrorArbol(t1, &t2);
                printf("\n\nEl arbol 2 ahora es espejo del 1");
                system(PAUSA);
                break;
            case 14:
                system(LIMPIAR);
                printf("\t1. Arbol 1\n\t2. Arbol 2\n\n\tOpcion: ");
                fflush(stdin);
                scanf("%d", &opc);
                printf("\n\nValor a borrar: ");
                fflush(stdin);
                scanf("%d", &value);
                if(opc == 1)
                    borrarNodo(&t1, value);
                else if(opc == 2)
                    borrarNodo(&t2, value);
                else
                    printf("\n\nArbol no existente");
                system(PAUSA);
                break;
            case 15:
                exit(0);
                break;
            default:
                break;
        }
    }
    return 0;
}
