#include "../functions/tri/triBulle.c"
#include "../functions/tri/triFusion.c"
#include "../functions/tri/triInsertion.c"
#include "../functions/tri/triRapide.c"
#include "../functions/tri/triSelection.c"
#include "../functions/tri/triTas.c"
#include "../functions/helper.c"

void triBulle(int[], int);
void triInsertion(int[], int);
void triRapide(int[], int);
void triFusion(int[], int);
void selectionSort(int[], int);
void heapSort(int[], int);
void afficherTableau(int [], int);
void RandomInit(int [], int);

void (*trier)(int[], int);