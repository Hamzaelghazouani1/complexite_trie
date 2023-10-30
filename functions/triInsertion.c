void triInsertion(int *tab, int fin)
{
    int i, j, tmp;
    for (i = 1; i <= fin; i++)
    {
        tmp = tab[i];
        j = i;
        while (j > 0 && tab[j - 1] > tmp)
        {
            tab[j] = tab[j - 1];
            j--;
        }
        tab[j] = tmp;
    }
}