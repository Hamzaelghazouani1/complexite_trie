void fusion(int *tab, int left[], int left_size, int right[], int right_size)
{
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size)
    {
        if (left[i] < right[j])
        {
            tab
                [k] = left[i];
            i++;
        }
        else
        {
            tab
                [k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size)
    {
        tab
            [k] = left[i];
        i++;
        k++;
    }

    while (j < right_size)
    {
        tab
            [k] = right[j];
        j++;
        k++;
    }
}
