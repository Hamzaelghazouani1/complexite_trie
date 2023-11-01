
// This function swaps the values of two integers pointed to by 'firstNum' and 'secondNum'.
void swapIntegers(int* firstNum, int* secondNum) {
    // Store the value pointed to by 'firstNum' in a temporary variable.
    int temporaryValue = *firstNum;

    // Replace the value pointed to by 'firstNum' with the value pointed to by 'secondNum'.
    *firstNum = *secondNum;

    // Replace the value pointed to by 'secondNum' with the original value stored in 'temporaryValue'.
    *secondNum = temporaryValue;
    }


// This function helps maintain the max heap property for a binary tree represented as an array.
void heapify(int T[], int size, int i) {
    int maxIdx = i;  // Initialize the maximum index as the current node.
    int leftChild = 2 * i + 1;  // Calculate the index of the left child.
    int rightChild = 2 * i + 2;  // Calculate the index of the right child.

    // Check if the left child exists and has a greater value than the current maximum.
    if (leftChild < size && T[leftChild] > T[maxIdx])
        maxIdx = leftChild;

    // Check if the right child exists and has a greater value than the current maximum.
    if (rightChild < size && T[rightChild] > T[maxIdx])
        maxIdx = rightChild;

    // If the maximum index has changed, swap elements and recursively heapify the affected subtree.
    if (maxIdx != i) {
        swapIntegers(&T[i], &T[maxIdx]);
        heapify(T, size, maxIdx);
        }
    }


// This function sorts an array 'T' of integers using the heap sort algorithm.
void heapSort(int T[], int size) {
    // First, create a max heap from the input array 'T'.
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(T, size, i);
        }

    // Perform the actual heap sort by repeatedly extracting the maximum element.
    for (int i = size - 1; i >= 0; i--) {
        // Swap the root (maximum element) with the last element in the array.
        swapIntegers(&T[0], &T[i]);

        // Re-heapify the remaining elements to maintain the max heap property.
        heapify(T, i, 0);
        }
    }
