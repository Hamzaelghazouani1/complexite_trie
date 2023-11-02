#include "./fusion.c"

void triFusion(int *tab, int size)
{
    if (size < 2)
    {
        return;
    }

    int mid = size / 2;
    int *left = malloc(mid * sizeof(int));
    int *right = malloc((size - mid) * sizeof(int));

    for (int i = 0; i < mid; i++)
    {
        left[i] = tab[i];
    }

    for (int i = mid; i < size; i++)
    {
        right[i - mid] = tab[i];
    }

    triFusion(left, mid);
    triFusion(right, size - mid);
    fusion(tab, left, mid, right, size - mid);

    free(left);
    free(right);
}
