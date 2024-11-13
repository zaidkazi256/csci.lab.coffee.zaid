#include <stdio.h>
#include <stdbool.h>

// Function Prototypes
bool isValid(const int arr[], int length, int pos);
void remove_element(int arr[], int length, int pos);
void insert_element(int arr[], int length, int pos, int value);
void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[nRows][nCols]);
void trans_matrix(int nRows, int nCols, const int mat[nRows][nCols], int mat_transp[nCols][nRows]);
bool found_duplicate(int arr[], int length);

// Function Implementations
bool isValid(const int arr[], int length, int pos) {
    return pos >= 0 && pos < length;
}

void remove_element(int arr[], int length, int pos) {
    if (!isValid(arr, length, pos)) {
        printf("Error: Invalid position for removal.\n");
        return;
    }
    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[length - 1] = 0; // Optional: set the last element to zero for clarity
}

void insert_element(int arr[], int length, int pos, int value) {
    if (!isValid(arr, length, pos)) {
        printf("Error: Invalid position for insertion.\n");
        return;
    }
    for (int i = length - 1; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
}

void reshape(const int arr[], int length, int nRows, int nCols, int arr2d[nRows][nCols]) {
    if (length != nRows * nCols) {
        printf("Error: Array length does not match matrix dimensions.\n");
        return;
    }
    int k = 0;
    for (int col = 0; col < nCols; col++) {
        for (int row = 0; row < nRows; row++) {
            arr2d[row][col] = arr[k++];
        }
    }
}

void trans_matrix(int nRows, int nCols, const int mat[nRows][nCols], int mat_transp[nCols][nRows]) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nCols; j++) {
            mat_transp[j][i] = mat[i][j];
        }
    }
}

bool found_duplicate(int arr[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

// Main Function for Testing
int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int arr2d[2][5];
    int transpose[5][2];

    // Testing remove_element
    printf("Testing remove_element:\n");
    remove_element(arr, 10, 2);  // Should remove element at index 2 (30)
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Testing insert_element
    printf("Testing insert_element:\n");
    insert_element(arr, 10, 2, 80);  // Should insert 80 at index 2
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Testing reshape
    printf("Testing reshape:\n");
    reshape(arr, 10, 2, 5, arr2d);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", arr2d[i][j]);
        }
        printf("\n");
    }

    // Testing trans_matrix
    printf("Testing trans_matrix:\n");
    trans_matrix(2, 5, arr2d, transpose);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    // Testing found_duplicate
    printf("Testing found_duplicate:\n");
    printf("Found duplicate: %s\n", found_duplicate(arr, 10) ? "Yes" : "No");

    return 0;
}
