   #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Constants for coffee types
#define ESPRESSO_BEANS 8
#define ESPRESSO_WATER 30
#define ESPRESSO_MILK 0
#define ESPRESSO_CHOCOLATE 0
#define ESPRESSO_PRICE 3.5

#define CAPPUCCINO_BEANS 8
#define CAPPUCCINO_WATER 30
#define CAPPUCCINO_MILK 70
#define CAPPUCCINO_CHOCOLATE 0
#define CAPPUCCINO_PRICE 4.5

#define MOCHA_BEANS 8
#define MOCHA_WATER 39
#define MOCHA_MILK 160
#define MOCHA_CHOCOLATE 30
#define MOCHA_PRICE 5.5

#define ADMIN_PASSWORD "admin123"
#define LOW_THRESHOLD 10

// Global variables to track ingredient levels and sales
float total_amount = 0.0;
int coffee_beans = 100;
int water = 1000;
int milk = 500;
int chocolate_syrup = 100;

// Function declarations
void alert_if_low();
void order_coffee();
void admin_mode();
void display_ingredients();
void replenish_ingredients();
void change_coffee_price();
void process_payment(float price);

int main() {
    int option;
    while (1) {
        printf("\nCoffee Maker Menu:\n");
        printf("1. Order a coffee type\n");
        printf("2. Admin mode for the coffee maker operator\n");
        printf("3. End the application execution\n");
        printf("Enter your option (1-3): ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                order_coffee();
                break;
            case 2:
                admin_mode();
                break;
            case 3:
                printf("Exiting the application. Thank you!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }
}

// Function to alert if any ingredient is low
void alert_if_low() {
    if (coffee_beans <= LOW_THRESHOLD) {
        printf("Alert: Coffee Beans low!\n");
    }
    if (water <= LOW_THRESHOLD) {
        printf("Alert: Water low!\n");
    }
    if (milk <= LOW_THRESHOLD) {
        printf("Alert: Milk low!\n");
    }
    if (chocolate_syrup <= LOW_THRESHOLD) {
        printf("Alert: Chocolate Syrup low!\n");
    }
}

// Function to order coffee
void order_coffee() {
    int choice;
    float price = 0.0;

    printf("Available Coffee Types:\n");
    printf("1. Espresso