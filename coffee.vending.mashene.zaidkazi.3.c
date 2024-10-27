#include <stdio.h>
#include <string.h>

#define ADMIN_PASSWORD "uowd" // Defining the admin password
#define ESPRESSO_BEANS 8 // Number of beans needed for an espresso
#define ESPRESSO_WATER 30 // Water needed for an espresso
#define CAPPUCCINO_BEANS 8 // Beans needed for cappuccino
#define CAPPUCCINO_WATER 30 // Water needed for cappuccino
#define CAPPUCCINO_MILK 70 // Milk needed for cappuccino
#define MOCHA_BEANS 8 // Beans for mocha
#define MOCHA_WATER 39 // Water for mocha
#define MOCHA_MILK 160 // Milk for mocha
#define MOCHA_CHOCOLATE 30 // Chocolate for mocha

// Initializing ingredient stock
int beans = 1000, water = 1000, milk = 1000, chocolate = 1000;
float espresso_price = 3.5, cappuccino_price = 4.5, mocha_price = 5.5; // Prices of coffee
float total_sales = 0.0; // Total sales amount

// Function prototypes
void order_coffee(); // Function to order coffee
void admin_mode(); // Function for admin tasks
void check_low_thresholds(); // Function to check if ingredients are low

int main() {
    int option; // Variable to store user option
    
    // Main loop for menu
    while (1) {
        printf("1. Order Coffee\n");
        printf("2. Admin Mode\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option); // User input for choice
        
        // Call functions based on user choice
        if (option == 1) {
            order_coffee(); // Function to order coffee
        } else if (option == 2) {
            admin_mode(); // Admin mode for management
        } else if (option == 3) {
            printf("Exiting...\n"); // Message for exiting
            break; // Break the loop to exit
        } else {
            printf("Invalid option. Try again.\n"); // Error for invalid input
        }
    }
    
    return 0; // End of main function
}

void order_coffee() {
    int coffee_choice; // Variable for coffee selection
    float money_inserted = 0.0, coffee_price = 0.0; // Initializing payment variables
    
    // Display coffee options
    printf("1. Espresso (%.2f AED)\n", espresso_price);
    printf("2. Cappuccino (%.2f AED)\n", cappuccino_price);
    printf("3. Mocha (%.2f AED)\n", mocha_price);
    printf("Enter your coffee choice: ");
    scanf("%d", &coffee_choice); // User input for coffee choice
    
    // Check ingredient availability
    if (coffee_choice == 1) {
        coffee_price = espresso_price; // Set price for espresso
        if (beans < ESPRESSO_BEANS || water < ESPRESSO_WATER) { // Check if ingredients are sufficient
            printf("Not enough ingredients for Espresso.\n");
            return; // Exit if not enough ingredients
        }
    } else if (coffee_choice == 2) {
        coffee_price = cappuccino_price; // Set price for cappuccino
        if (beans < CAPPUCCINO_BEANS || water < CAPPUCCINO_WATER || milk < CAPPUCCINO_MILK) {
            printf("Not enough ingredients for Cappuccino.\n");
            return; // Exit if not enough ingredients
        }
    } else if (coffee_choice == 3) {
        coffee_price = mocha_price; // Set price for mocha
        if (beans < MOCHA_BEANS || water < MOCHA_WATER || milk < MOCHA_MILK || chocolate < MOCHA_CHOCOLATE) {
            printf("Not enough ingredients for Mocha.\n");
            return; // Exit if not enough ingredients
        }
    } else {
        printf("Invalid coffee choice.\n"); // Error for invalid coffee choice
        return; // Exit if invalid choice
    }

    // Handle payment process
    while (money_inserted < coffee_price) {
        float coin; // Variable for coin input
        printf("Insert coin (0.5 or 1 AED): "); // Prompt user for coin
        scanf("%f", &coin); // User input for coin
        if (coin == 0.5 || coin == 1.0) {
            money_inserted += coin; // Add valid coin to total
        } else {
            printf("Invalid coin. Try again.\n"); // Error for invalid coin
        }
    }

    printf("Coffee ready! Change: %.2f AED\n", money_inserted - coffee_price); // Display change
    
    // Update ingredients based on selection
    if (coffee_choice == 1) {
        beans -= ESPRESSO_BEANS; // Reduce beans for espresso
        water -= ESPRESSO_WATER; // Reduce water for espresso
    } else if (coffee_choice == 2) {
        beans -= CAPPUCCINO_BEANS; // Reduce beans for cappuccino
        water -= CAPPUCCINO_WATER; // Reduce water for cappuccino
        milk -= CAPPUCCINO_MILK; // Reduce milk for cappuccino
    } else if (coffee_choice == 3) {
        beans -= MOCHA_BEANS; // Reduce beans for mocha
        water -= MOCHA_WATER; // Reduce water for mocha
        milk -= MOCHA_MILK; // Reduce milk for mocha
        chocolate -= MOCHA_CHOCOLATE; // Reduce chocolate for mocha
    }
    
    total_sales += coffee_price; // Update total sales
    check_low_thresholds(); // Check if any ingredients are low
}

void check_low_thresholds() {
    // Check for low ingredient levels
    if (beans <= 10) printf("Alert: Low on beans!\n");
    if (water <= 10) printf("Alert: Low on water!\n");
    if (milk <= 10) printf("Alert: Low on milk!\n");
    if (chocolate <= 10) printf("Alert: Low on chocolate!\n");
}

void admin_mode() {
    char password[20]; // Variable for admin password
    printf("Enter admin password: ");
    scanf("%s", password); // User input for password
    
    // Check if password is correct
    if (strcmp(password, ADMIN_PASSWORD) != 0) {
        printf("Incorrect password.\n");
        return; // Exit if password is wrong
    }

    int option; // Variable for admin menu option
    while (1) {
        printf("1. Display quantities and total sales\n");
        printf("2. Refill ingredients\n");
        printf("3. Change coffee prices\n");
        printf("0. Exit Admin Mode\n");
        printf("Enter your choice: ");
        scanf("%d", &option); // User input for admin option
        
        // Handle admin options
        if (option == 1) {
            printf("Beans: %d, Water: %d, Milk: %d, Chocolate: %d\n", beans, water, milk, chocolate);
            printf("Total sales: %.2f AED\n", total_sales); // Display total sales
        } else if (option == 2) {
            beans = 1000; // Reset beans to maximum
            water = 1000; // Reset water to maximum
            milk = 1000; // Reset milk to maximum
            chocolate = 1000; // Reset chocolate to maximum
            printf("Ingredients refilled.\n");
        } else if (option == 3) {
            float new_price; // Variable for new price
            printf("Enter new price for Espresso: ");
            scanf("%f", &new_price); // User input for new price
            espresso_price = new_price; // Update price
            printf("New price set for Espresso: %.2f AED\n", espresso_price); // Confirm new price
        } else if (option == 0) {
            break; // Exit admin mode
        } else {
            printf("Invalid option. Try again.\n"); // Error for invalid option
        }
    }
}

