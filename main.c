#include <stdio.h>
#include <stdlib.h>
#include "header/methodesTri.h"

// GNU-plot --> use fopen


int main(){
    int tab[] = {-12, -9, 4, 42, -17, 1, -7, -77, 8, -87, 68, 0};
    triFusion(tab, 12); 
    afficherTableau(tab, 12);
    return 0;
}