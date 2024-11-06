#include <stdio.h>

void process_transactions(int transactions[], int size) {
    int balance = 1000;  // Pre-set initial balance in AED
    int tobeprocessed[100];  // Array to store unprocessed transactions
    int tobeprocessed_size = 0;  // Counter for the size of tobeprocessed array

    for (int i = 0; i < size; i++) {
        int transaction = transactions[i];

        // Display the current balance before processing the transaction
        printf("Current balance: %d AED\n", balance);
        
        // Check if the transaction is a withdrawal and exceeds the current balance
        if (transaction < 0 && -transaction > balance) {
            printf("Transaction %d is invalid: Insufficient balance.\n", transaction);
            tobeprocessed[tobeprocessed_size++] = transaction;  // Store the invalid transaction
            continue;  // Skip to the next transaction
        }

        // Update the balance for valid transactions
        balance += transaction;

        // If the balance reaches 0 or less, stop processing and store the remaining transactions
        if (balance <= 0) {
            printf("Balance reached 0. No further transactions will be processed.\n");
            tobeprocessed[tobeprocessed_size++] = transaction;  // Store the unprocessed transaction
            break;  // Exit the loop as no more transactions should be processed
        }
    }

    // Final output
    printf("Final balance: %d AED\n", balance);
    printf("Unprocessed transactions: ");
    for (int i = 0; i < tobeprocessed_size; i++) {
        printf("%d ", tobeprocessed[i]);
    }
    printf("\n");
}

int main() {
    int size;

    // Ask the user to input the number of transactions
    printf("Enter the number of transactions: ");
    scanf("%d", &size);

    int transactions[size];

    // Ask the user to input the transactions
    printf("Enter the transactions (positive for deposits, negative for withdrawals):\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &transactions[i]);
    }

    // Call the function to process the transactions
    process_transactions(transactions, size);

    return 0;
}
