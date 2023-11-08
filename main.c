#include <stdio.h>
#include <stdlib.h>
#include "header/methodesTri.h"

int main(){
    printf("entrer le nombre d'element du tableau : ");
    scanf("%d", &nb_points);
    int tab[nb_points];
    nb_methode = 6;
    matrixMesures(tab, nb_points);
    writeToFiles(nb_points, nb_methode);
    gnuPlot();
    return 0;
}