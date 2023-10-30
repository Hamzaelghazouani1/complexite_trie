void tribulle(int *t, int n)
{
    int i, j, tmp;
    if (n == 1)
    {
        return;
    }
    while (n > 0)
    {
        i = 0;
        for (j = i; j < n - 1; j++)
        {
            if (t[j + 1] < t[j])
            {
                tmp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tmp;
            }
        }
        n--;
    }
}