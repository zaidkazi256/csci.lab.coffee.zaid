#include <stdio.h>
#include <string.h>

int beans = 1000, water = 1000, milk = 1000, chocolate = 1000;// Initial ingredient stock and prices
float espresso_price = 3.5, cappuccino_price = 4.5, mocha_price = 5.5;
float total_sales = 0.0; // Keeps track of total sales amount

void order_coffee();// Function prototypes 
void admin_mode();

int main() {
    int option;
    
    while (1) { // Infinite loop for the main menu
        printf("1. Order Coffee\n");
        printf("2. Admin Mode\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        if (option == 1) { // Handle user choices
            order_coffee(); // Call the coffee order 
        } else if (option == 2) {
            admin_mode(); // Call the admin mode
        } else if (option == 3) {
            printf("Exiting...\n"); // Exit message
            break; // Break the loop and exit
        } else {
            printf("Invalid option. Try again.\n"); // Error for invalid choice
        }
    }
    
    return 0; // End main function
}

void order_coffee() {
    int coffee_choice;
    float money_inserted = 0.0, coffee_price = 0.0; // Initialize payment variables
    
    printf("1. Espresso (%.2f AED)\n", espresso_price);// Display coffee options with prices
    printf("2. Cappuccino (%.2f AED)\n", cappuccino_price);
    printf("3. Mocha (%.2f AED)\n", mocha_price);
    printf("Enter your coffee choice: ");
    scanf("%d", &coffee_choice);
    
    if (coffee_choice == 1) {// Check if the selected coffee can be made available ingredients
        coffee_price = espresso_price; // Set price for espresso
        if (beans < 8 || water < 30) { // Check ingredient availability
            printf("Not enough ingredients for Espresso.\n");
            return; // Exit if not enough ingredients
        }
    } else if (coffee_choice == 2) {
        coffee_price = cappuccino_price; // Set price for cappuccino
        if (beans < 8 || water < 30 || milk < 70) { // Check availability
            printf("Not enough ingredients for Cappuccino.\n");
            return; // Exit if not enough ingredients
        }
    } else if (coffee_choice == 3) {
        coffee_price = mocha_price; // Set price for mocha
        if (beans < 8 || water < 39 || milk < 160 || chocolate < 30) { // Check availability
            printf("Not enough ingredients for Mocha.\n");
            return; // Exit if not enough ingredients
        }
    } else {
        printf("Invalid coffee choice.\n"); // Error for invalid choice
        return; // Exit if invalid choice
    }

    while (money_inserted < coffee_price) {// Handle the payment process
        float coin;
        printf("Insert coin (0.5 or 1 AED): "); // Prompt for coin insertion
        scanf("%f", &coin);
        if (coin == 0.5 || coin == 1.0) {
            money_inserted += coin; // Add valid coin to total
        } else {
            printf("Invalid coin. Try again.\n"); // Error for invalid coin
        }
    }

    printf("Coffee ready! Change: %.2f AED\n", money_inserted - coffee_price);
    
    if (coffee_choice == 1) { // Update ingredients based on the selected coffee
        beans -= 8; // Reduce beans for espresso
        water -= 30; // Reduce water for espresso
    } else if (coffee_choice == 2) {
        beans -= 8; // Reduce beans for cappuccino
        water -= 30; // Reduce water for cappuccino
        milk -= 70; // Reduce milk for cappuccino
    } else if (coffee_choice == 3) {
        beans -= 8; // Reduce beans for mocha
        water -= 39; // Reduce water for mocha
        milk -= 160; // Reduce milk for mocha
        chocolate -= 30; // Reduce chocolate for mocha
    }
    
    total_sales += coffee_price; // Update total sales
}

void admin_mode() {
    printf("Beans: %d, Water: %d, Milk: %d, Chocolate: %d\n", beans, water, milk, chocolate);
    printf("Total sales: %.2f AED\n", total_sales);
    
    printf("Do you want to refill ingredients? (1 for Yes, 0 for No): ");
    int refill;
    scanf("%d", &refill);
    
    if (refill == 1) { // Refill ingredients if chosen
        beans = 1000; // Reset beans to a defined amount
        water = 1000; // Reset water to a defined amount
        milk = 1000; // Reset milk to a defined amount
        chocolate = 100; // Reset chocolate to a defined amount
        printf("Ingredients refilled.\n");
    }
}
