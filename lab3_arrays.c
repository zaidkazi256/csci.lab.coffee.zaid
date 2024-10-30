#include <stdio.h> 
#include <stdbool.h> 

// Constants for array size
#define SIZE 24
#define nRows 8
#define nCols 3

// Function prototypes
void print_array(int array[], int length);
void print_matrix(int mat[][nCols], int rows);
void remove_element(int arr[], int length, int pos);

int main() {
    int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // Initialize first 10 elements for testing
    int arr2d[nRows][nCols] = {0};  // Initialize 2D array with zeros

    printf("Initial 1D Array:\n");
    print_array(arr, SIZE);

    // Removing an element at a valid position
    printf("\nRemoving element at position 3:\n");
    remove_element(arr, SIZE, 3);
    print_array(arr, SIZE - 1);  // Print with updated length

    // Attempt to remove an element from an invalid position
    printf("\nAttempting to remove element at invalid position 30:\n");
    remove_element(arr, SIZE, 30);

    return 0;
}

// Function to print a 1D array
void print_array(int array[], int length) {
    for (int i = 0; i < length; i++)
        printf("array[%d] = %d\n", i, array[i]);
}

// Function to print a 2D matrix
void print_matrix(int mat[][nCols], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < nCols; j++)
            printf("mat[%d][%d] = %d ", i, j, mat[i][j]);
        puts("");  // Print a newline after each row
    }
}

// Function to remove an element from a 1D array at a given position
void remove_element(int arr[], int length, int pos) {
    if (pos < 0 || pos >= length) {
        printf("Error: Position %d is out of bounds.\n", pos);
        return;
    }

    // Shift elements to the left from the given position
    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Optional: Set the last element to 0 (or some placeholder) after shifting
    arr[length - 1] = 0;

    printf("Element at position %d removed successfully.\n", pos);
}

