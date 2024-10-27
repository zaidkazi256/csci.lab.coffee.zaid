#include <stdio.h>
#include <string.h>

#define ADMIN_PASSWORD "uowd"
#define ESPRESSO_BEANS 8
#define ESPRESSO_WATER 30
#define CAPPUCCINO_BEANS 8
#define CAPPUCCINO_WATER 30
#define CAPPUCCINO_MILK 70
#define MOCHA_BEANS 8
#define MOCHA_WATER 39
#define MOCHA_MILK 160
#define MOCHA_CHOCOLATE 30

int beans = 1000, water = 1000, milk = 1000, chocolate = 1000;
float espresso_price = 3.5, cappuccino_price = 4.5, mocha_price = 5.5;
float total_sales = 0.0;

void order_coffee();
void admin_mode();
void check_low_thresholds();

int main() {
    int option;
    
    while (1) {
        printf("1. Order Coffee\n");
        printf("2. Admin Mode\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        if (option == 1) {
            order_coffee();
        } else if (option == 2) {
            admin_mode();
        } else if (option == 3) {
            printf("Exiting...\n");
            break;
        } else {
            printf("Invalid option. Try again.\n");
        }
    }
    
    return 0;
}

void order_coffee() {
    int coffee_choice;
    float money_inserted = 0.0, coffee_price = 0.0;
    
    printf("1. Espresso (%.2f AED)\n", espresso_price);
    printf("2. Cappuccino (%.2f AED)\n", cappuccino_price);
    printf("3. Mocha (%.2f AED)\n", mocha_price);
    printf("Enter your coffee choice: ");
    scanf("%d", &coffee_choice);
    
    // Check ingredient availability
    if (coffee_choice == 1) {
        coffee_price = espresso_price;
        if (beans < ESPRESSO_BEANS || water < ESPRESSO_WATER) {
            printf("Not enough ingredients for Espresso.\n");
            return;
        }
    } else if (coffee_choice == 2) {
        coffee_price = cappuccino_price;
        if (beans < CAPPUCCINO_BEANS || water < CAPPUCCINO_WATER || milk < CAPPUCCINO_MILK) {
            printf("Not enough ingredients for Cappuccino.\n");
            return;
        }
    } else if (coffee_choice == 3) {
        coffee_price = mocha_price;
        if (beans < MOCHA_BEANS || water < MOCHA_WATER || milk < MOCHA_MILK || chocolate < MOCHA_CHOCOLATE) {
            printf("Not enough ingredients for Mocha.\n");
            return;
        }
    } else {
        printf("Invalid coffee choice.\n");
        return;
    }

    // Handle payment
    while (money_inserted < coffee_price) {
        float coin;
        printf("Insert coin (0.5 or 1 AED): ");
        scanf("%f", &coin);
        if (coin == 0.5 || coin == 1.0) {
            money_inserted += coin;
        } else {
            printf("Invalid coin. Try again.\n");
        }
    }

    printf("Coffee ready! Change: %.2f AED\n", money_inserted - coffee_price);
    
    // Update ingredients
    if (coffee_choice == 1) {
        beans -= ESPRESSO_BEANS;
        water -= ESPRESSO_WATER;
    } else if (coffee_choice == 2) {
        beans -= CAPPUCCINO_BEANS;
        water -= CAPPUCCINO_WATER;
        milk -= CAPPUCCINO_MILK;
    } else if (coffee_choice == 3) {
        beans -= MOCHA_BEANS;
        water -= MOCHA_WATER;
        milk -= MOCHA_MILK;
        chocolate -= MOCHA_CHOCOLATE;
    }
    
    total_sales += coffee_price;
    check_low_thresholds();
}

void check_low_thresholds() {
    if (beans <= 10) printf("Alert: Low on beans!\n");
    if (water <= 10) printf("Alert: Low on water!\n");
    if (milk <= 10) printf("Alert: Low on milk!\n");
    if (chocolate <= 10) printf("Alert: Low on chocolate!\n");
}

void admin_mode() {
    char password[20];
    printf("Enter admin password: ");
    scanf("%s", password);
    
    if (strcmp(password, ADMIN_PASSWORD) != 0) {
        printf("Incorrect password.\n");
        return;
    }

    int option;
    while (1) {
        printf("1. Display quantities and total sales\n");
        printf("2. Refill ingredients\n");
        printf("3. Change coffee prices\n");
        printf("0. Exit Admin Mode\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        
        if (option == 1) {
            printf("Beans: %d, Water: %d, Milk: %d, Chocolate: %d\n", beans, water, milk, chocolate);
            printf("Total sales: %.2f AED\n", total_sales);
        } else if (option == 2) {
            beans = 1000; // Resetting to a defined maximum
            water = 1000;
            milk = 1000;
            chocolate = 1000;
            printf("Ingredients refilled.\n");
        } else if (option == 3) {
            float new_price;
            printf("Enter new price for Espresso: ");
            scanf("%f", &new_price);
            espresso_price = new_price;
            printf("New price set for Espresso: %.2f AED\n", espresso_price);
        } else if (option == 0) {
            break; // Exit admin mode
        } else {
            printf("Invalid option. Try again.\n");
        }
    }
}
