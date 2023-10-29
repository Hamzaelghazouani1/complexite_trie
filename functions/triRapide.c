
void triRapide(int *tab, int fin) {
    int parcours = 0, suivant = fin, tmp;
    int pivot = tab[fin];
    while (parcours <= suivant) {
        while (pivot > tab[parcours])
            parcours++;
        while (tab[suivant] > pivot)
            suivant--;
        if (parcours <= suivant) {
            tmp = tab[parcours];
            tab[parcours] = tab[suivant];
            tab[suivant] = tmp;
            parcours++;
            suivant--;
        }
    }
    if (suivant > 0)
        triRapide(tab, suivant);
    if (parcours < fin)
        triRapide(tab+parcours, fin-parcours);
}