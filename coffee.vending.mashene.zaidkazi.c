#include <stdio.h>
#include <string.h>

// Ingredient stock and prices
int beans = 100, water = 100, milk = 100, chocolate = 100;
float espresso_price = 3.5, cappuccino_price = 4.5, mocha_price = 5.5;
float total_sales = 0.0;

void order_coffee();
void admin_mode();

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
    
    if (coffee_choice == 1) {
        coffee_price = espresso_price;
        if (beans < 8 || water < 30) {
            printf("Not enough ingredients for Espresso.\n");
            return;
        }
    } else if (coffee_choice == 2) {
        coffee_price = cappuccino_price;
        if (beans < 8 || water < 30 || milk < 70) {
            printf("Not enough ingredients for Cappuccino.\n");
            return;
        }
    } else if (coffee_choice == 3) {
        coffee_price = mocha_price;
        if (beans < 8 || water < 39 || milk < 160 || chocolate < 30) {
            printf("Not enough ingredients for Mocha.\n");
            return;
        }
    } else {
        printf("Invalid coffee choice.\n");
        return;
    }

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
        beans -= 8;
        water -= 30;
    } else if (coffee_choice == 2) {
        beans -= 8;
        water -= 30;
        milk -= 70;
    } else if (coffee_choice == 3) {
        beans -= 8;
        water -= 39;
        milk -= 160;
        chocolate -= 30;
    }
    
    total_sales += coffee_price;
}

void admin_mode() {
    printf("Beans: %d, Water: %d, Milk: %d, Chocolate: %d\n", beans, water, milk, chocolate);
    printf("Total sales: %.2f AED\n", total_sales);
    
    printf("Do you want to refill ingredients? (1 for Yes, 0 for No): ");
    int refill;
    scanf("%d", &refill);
    
    if (refill == 1) {
        beans = 100;
        water = 100;
        milk = 100;
        chocolate = 100;
        printf("Ingredients refilled.\n");
    }
}