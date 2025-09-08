#include <stdio.h>

#define MAX 100

int insertBeginning(int arr[], int size, int element) {
    if (size >= MAX) {
        printf("Array is full\n");
        return size;
    }
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = element;
    size++;
    printf("After inserting %d at beginning: ", element);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return size;
}

int insertEnd(int arr[], int size, int element) {
    if (size >= MAX) {
        printf("Array is full\n");
        return size;
    }
    arr[size] = element;
    size++;
    printf("After inserting %d at end: ", element);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return size;
}

int insertAtPosition(int arr[], int size, int element, int position) {
    if (size >= MAX) {
        printf("Array is full\n");
        return size;
    }
    if (position < 0 || position > size) {
        printf("Invalid position\n");
        return size;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    size++;
    printf("After inserting %d at position %d: ", element, position);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return size;
}

int deleteBeginning(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty\n");
        return size;
    }
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("After deleting from beginning: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return size;
}

int deleteEnd(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty\n");
        return size;
    }
    size--;
    printf("After deleting from end: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return size;
}

int deleteAtPosition(int arr[], int size, int position) {
    if (size == 0) {
        printf("Array is empty\n");
        return size;
    }
    if (position < 0 || position >= size) {
        printf("Invalid position\n");
        return size;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("After deleting from position %d: ", position);
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return size;
}

void linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("Linear search: %d found at position %d\n", key, i);
            return;
        }
    }
    printf("Linear search: %d not found\n", key);
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array after sorting for binary search: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            printf("Binary search: %d found at position %d\n", key, mid);
            return;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Binary search: %d not found\n", key);
}

void traverse(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }
    printf("Traversing array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX];
    int size;

    printf("Enter the number of elements (max %d): ", MAX);
    scanf("%d", &size);
    if (size < 0 || size > MAX) {
        printf("Invalid size\n");
        return 1;
    }
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Initial array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
   
    size = insertBeginning(arr, size, 10);
    
    size = insertEnd(arr, size, 20);

    
    size = insertAtPosition(arr, size, 15, 2);

    
    size = deleteBeginning(arr, size);

   
    size = deleteEnd(arr, size);

   
    size = deleteAtPosition(arr, size, 1);

    
    int searchKey = (size > 0) ? arr[0] : 10;
    linearSearch(arr, size, searchKey);

    
    bubbleSort(arr, size);
    binarySearch(arr, size, searchKey);

    traverse(arr, size);

    return 0;
}