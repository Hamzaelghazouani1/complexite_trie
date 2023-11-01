// This function performs the Selection Sort algorithm to sort an array 'arr' of integers.

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the current index is the minimum.

        // Find the index of the minimum element in the unsorted part of the array.
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                }
            }

        // Swap the minimum element found with the first element in the unsorted part.
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        }
    }
