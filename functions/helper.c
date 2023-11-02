#include <time.h>
#include "../header/calculs.h"

void afficherTableau(int *tab, int lenght){
    for (int i=0; i<lenght; i++)
        printf("%d | ",tab[i]);
    printf("\n");
}

void RandomInit(int *tab, int lenght){
    srand(time(NULL));
    for (int i=0; i<lenght; i++){
        tab[i] = (rand() % 100) - (rand() % 100);
    }
}

float counterTime(void (*trier)(int[], int), int *tab, int lenght){
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    trier(tab, lenght);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    return cpu_time_used;
}

int* cloneTab(int *tab, int lenght){
    int * tabl = malloc(lenght * sizeof(int));
    for (int i=0; i<lenght; i++){
        tabl[i] = tab[i];
    }
    return tabl;
}

void calcTri(void (*trier)(int[], int),
             void (*trier1)(int[], int),
             void (*trier2)(int[], int),
             void (*trier3)(int[], int),
             void (*trier4)(int[], int),
             void (*trier5)(int[], int),
             int *tab, int lenght){
    mesures[lenght][0] = counterTime(trier, cloneTab(tab,lenght), lenght);
    mesures[lenght][1] = counterTime(trier1, cloneTab(tab,lenght), lenght);
    mesures[lenght][2] = counterTime(trier2, cloneTab(tab,lenght), lenght);
    mesures[lenght][3] = counterTime(trier3, cloneTab(tab,lenght), lenght);
    mesures[lenght][4] = counterTime(trier4, cloneTab(tab,lenght), lenght);
    mesures[lenght][5] = counterTime(trier5, cloneTab(tab,lenght), lenght);
}

void matrixMesures(int *tab, int lenght){
    RandomInit(tab, lenght);
    for (int i=0; i<lenght; i++)
        calcTri(triBulle, triInsertion, triRapide, triFusion, selectionSort, heapSort, tab, i);
    
}

void afficherMatrix(int lenght){
    for (int i=0; i<lenght; i++){
        for (int j=0; j<nb_methode; j++)
            printf("%f | \n", mesures[i][j]);
        printf("\n");
    }
}