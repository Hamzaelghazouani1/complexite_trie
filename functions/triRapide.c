
void triRapide(int* tab, int lenght) {
    if (lenght <= 1) return;

    int index = -1, parcours = 0, tmp;
    int pivot = tab[lenght - 1];

    while (parcours < lenght - 1) {
        if (tab[parcours] < pivot) {
            index++;
            tmp = tab[index];
            tab[index] = tab[parcours];
            tab[parcours] = tmp;
            }
        parcours++;
        }

    tmp = tab[lenght - 1];
    tab[lenght - 1] = tab[++index];
    tab[index] = tmp;

    triRapide(tab, index);
    triRapide(tab + index + 1, lenght - index);

    }




