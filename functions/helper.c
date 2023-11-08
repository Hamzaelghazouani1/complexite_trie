#include <time.h>
#include <string.h>
#include "../header/calculs.h"

void afficherTableau(int *tab, int longueur){
    for (int i=0; i<longueur; i++)
        printf("%d | ",tab[i]);
    printf("\n");
}

void randomInit(int *tab, int longueur){
    srand(time(NULL));
    for (int i=0; i<longueur; i++)
        tab[i] = (rand() % 100) - (rand() % 100);
}

float counterTime(void (*trier)(int[], int), int *tab, int longueur){
    clock_t debut, fin;
    double cpu_temp_utilise;
    debut = clock();
    trier(tab, longueur);
    fin = clock();
    cpu_temp_utilise = ((double) (debut - fin)) / CLOCKS_PER_SEC;
    return cpu_temp_utilise;
}

int* cloneTab(int *tab, int longueur){
    int* tab_clon = (int*)malloc(longueur * sizeof(int));
    for (int i=0; i<longueur; i++)
        tab_clon[i] = tab[i];
    return tab_clon;
}

void calcTri(void (*trier[])(int[], int), int *tab, int longueur) {
    for (int i = 0; i < 6; i++) {
        int *tab_clon = cloneTab(tab, longueur);
        mesures[longueur][i] = counterTime(trier[i], tab_clon, longueur);
        free(tab_clon);
    }
}


void matrixMesures(int *tab, int longueur){
    randomInit(tab, longueur);
    void (*trier[])(int[], int) = {triBulle, triInsertion, triRapide, triFusion, triSelection, triTas};
    for (int i=0; i<longueur; i++)
        calcTri(trier , tab, i);
}

void afficherMatrix(int longueur){
    for (int i=0; i<longueur; i++){
        for (int j=0; j<nb_methode; j++)
            printf("%f | ", mesures[i][j]);
        printf("\n");
    }
}

void writeToFiles(int nb_points, int nb_methode){
    char nom_fich[100];

    for (int j = 0; j < nb_methode; j++) {
        snprintf(nom_fich, sizeof(nom_fich), "data%d.txt", j+1);

        FILE* fich = fopen(nom_fich, "w");
        if (fich != NULL) {
            for(int i=0; i<nb_points; i++){
                fprintf(fich, "%d %f\n", i, mesures[i][j]);
            }
        fclose(fich);
        } else {
            printf("Impossible d'ouvrir le fichier.\n");
            exit(1);
        }
    }
}

void gnuPlot() {
    FILE *gnuplot_pipe = popen("gnuplot -persistent", "w");

    if (gnuplot_pipe) {
        fprintf(gnuplot_pipe, "set key left top\n");
        fprintf(gnuplot_pipe, "set style line 1 lc rgb 'red' lt 1 lw 3\n");
        fprintf(gnuplot_pipe, "set style line 2 lc rgb 'blue' lt 2 lw 3\n");
        fprintf(gnuplot_pipe, "set style line 3 lc rgb 'green' lt 3 lw 3\n");
        fprintf(gnuplot_pipe, "set style line 4 lc rgb 'purple' lt 4 lw 3\n");
        fprintf(gnuplot_pipe, "set style line 5 lc rgb 'orange' lt 5 lw 3\n");
        fprintf(gnuplot_pipe, "set style line 6 lc rgb 'magenta' lt 6 lw 3\n");
        fprintf(gnuplot_pipe, "plot 'data1.txt' smooth bezier with lines ls 1 title 'Tri a Bull', 'data2.txt' smooth bezier with lines ls 2 title 'Tri par Insertion', 'data3.txt' smooth bezier with lines ls 3 title 'Tri Rapide', 'data4.txt' smooth bezier with lines ls 4 title 'Tri par Fusion', 'data5.txt' smooth bezier with lines ls 5 title 'Tri par Selection', 'data6.txt' smooth bezier with lines ls 6 title 'Tri par Tas'\n");

        pclose(gnuplot_pipe);
    } else {
        perror("Impossible d'ouvrir le pipe Gnuplot");
    }
}
