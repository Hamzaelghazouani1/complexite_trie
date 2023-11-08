void swapIntegers(int *firstNum, int *secondNum)
{
    int temporaryValue = *firstNum;

    *firstNum = *secondNum;

    *secondNum = temporaryValue;
}

void heapify(int T[], int size, int i)
{
    int maxIdx = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < size && T[leftChild] > T[maxIdx])
        maxIdx = leftChild;

    if (rightChild < size && T[rightChild] > T[maxIdx])
        maxIdx = rightChild;

    if (maxIdx != i)
    {
        swapIntegers(&T[i], &T[maxIdx]);
        heapify(T, size, maxIdx);
    }
}

void triTas(int T[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(T, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        swapIntegers(&T[0], &T[i]);
        heapify(T, i, 0);
    }
}
