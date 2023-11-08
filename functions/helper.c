#include <time.h>
#include <string.h>
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
    int* tabl = (int*)malloc(lenght * sizeof(int));
    for (int i=0; i<lenght; i++){
        tabl[i] = tab[i];
    }
    return tabl;
}

void calcTri(void (*trier[])(int[], int), int *tab, int length) {
    for (int i = 0; i < 6; i++) {
        int *tabclone = cloneTab(tab, length);
        mesures[length][i] = counterTime(trier[i], tabclone, length);
        free(tabclone);
    }
}


void matrixMesures(int *tab, int lenght){
    RandomInit(tab, lenght);
    void (*trier[])(int[], int) = {triBulle, triInsertion, triRapide, triFusion, selectionSort, heapSort};
    for (int i=0; i<lenght; i++)
        calcTri(trier , tab, i);
}

void afficherMatrix(int lenght){
    for (int i=0; i<lenght; i++){
        for (int j=0; j<nb_methode; j++)
            printf("%0.2f | ", mesures[i][j]);
        printf("\n");
    }
}

void writeToFiles(int nb_points, int nb_methode){
    char FILE_NAME[100];  // Define a character array to hold the file name

    for (int j = 0; j < nb_methode; j++) {
        // Use snprintf to create a unique file name for each iteration
        snprintf(FILE_NAME, sizeof(FILE_NAME), "data%d.txt", j+1);

        FILE* file = fopen(FILE_NAME, "w");
        if (file != NULL) {
            for(int i=0; i<nb_points; i++){
                fprintf(file, "%d %f\n", i, mesures[i][j]);
            }
        fclose(file);
        } else {
            printf("Failed to open the file.\n");
            exit(1);
        }
    }
}

void gnuPlot() {
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w"); // Open a pipe to Gnuplot

    if (gnuplotPipe) {
        // Send Gnuplot commands to create the graph with bezier smoothing and other custom settings
        fprintf(gnuplotPipe, "set key left top\n"); // Set the legend position to top left
        fprintf(gnuplotPipe, "set style line 1 lc rgb 'red' lt 1 lw 3\n"); // Line style for 'Tri a Bull'
        fprintf(gnuplotPipe, "set style line 2 lc rgb 'blue' lt 2 lw 3\n"); // Line style for 'Tri par Insertion'
        fprintf(gnuplotPipe, "set style line 3 lc rgb 'green' lt 3 lw 3\n"); // Line style for 'Tri Rapide'
        fprintf(gnuplotPipe, "set style line 4 lc rgb 'purple' lt 4 lw 3\n"); // Line style for 'Tri par Fusion'
        fprintf(gnuplotPipe, "set style line 5 lc rgb 'orange' lt 5 lw 3\n"); // Line style for 'Tri par Selection'
        fprintf(gnuplotPipe, "set style line 6 lc rgb 'magenta' lt 6 lw 3\n"); // Line style for 'Tri par Tas'
        fprintf(gnuplotPipe, "plot 'data1.txt' smooth bezier with lines ls 1 title 'Tri a Bull', 'data2.txt' smooth bezier with lines ls 2 title 'Tri par Insertion', 'data3.txt' smooth bezier with lines ls 3 title 'Tri Rapide', 'data4.txt' smooth bezier with lines ls 4 title 'Tri par Fusion', 'data5.txt' smooth bezier with lines ls 5 title 'Tri par Selection', 'data6.txt' smooth bezier with lines ls 6 title 'Tri par Tas'\n");

        // Close the Gnuplot pipe
        pclose(gnuplotPipe);
    } else {
        perror("Could not open Gnuplot pipe");
    }
}
