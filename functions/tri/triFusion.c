void fusion(int tab[], int debut, int milieu, int fin) {
    int taille1 = milieu - debut + 1;
    int taille2 = fin - milieu;

    int tableauGauche[taille1];
    int tableauDroit[taille2];

    for (int i = 0; i < taille1; i++) {
        tableauGauche[i] = tab[debut + i];
    }
    for (int j = 0; j < taille2; j++) {
        tableauDroit[j] = tab[milieu + 1 + j];
    }

    int i = 0, j = 0, k = debut;
    while (i < taille1 && j < taille2) {
        if (tableauGauche[i] <= tableauDroit[j]) {
            tab[k] = tableauGauche[i];
            i++;
        } else {
            tab[k] = tableauDroit[j];
            j++;
        }
        k++;
    }

    while (i < taille1) {
        tab[k] = tableauGauche[i];
        i++;
        k++;
    }

    while (j < taille2) {
        tab[k] = tableauDroit[j];
        j++;
        k++;
    }
}

void triFusion(int tab[], int taille) {
    if (taille < 2)
        return;

    int milieu = taille / 2;
    triFusion(tab, milieu);
    triFusion(tab + milieu, taille - milieu);
    fusion(tab, 0, milieu - 1, taille - 1);
}
