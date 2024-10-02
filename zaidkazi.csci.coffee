#include <stdio.h>

#define ESPRESSO_BEANS = 8
#define ESPRESSO_WATER = 30
#define ESPRESSO_MILK = 0
#define ESPRESSO_CHOCOLATE = 0
#define ESPRESSO_PRICE = 3.5
#define CAPPUCCINO_BEANS = 8
#define CAPPUCCINO_WATER = 30
#define CAPPUCCINO_MILK = 70
#define CAPPUCCINO_CHOCOLATE = 0
#define CAPPUCCINO_PRICE = 4.5
#define MOCHA_BEANS = 8
#define MOCHA_WATER = 39
#define MOCHA_MILK = 160
#define MOCHA_CHOCOLATE = 30
#define MOCHA_PRICE = 5.5
#define ADMIN_PASSWORD "admin"
#define LOW_THRESHOLD = 20

float total_amount = 0.0;
int beans_quantity = 100;
int water_quantity = 500;
int milk_quantity = 300;
int chocolate_quantity = 100
 
 void admin_login() {
    char password[20];
    printf("Enter admin password: ");
    scanf("%s", password);

    if (strcmp(password, ADMIN_PASSWORD) == 0) {
        printf("Admin logged in. Total sales: AED %.2f\n", total_amount);
    } else {
        printf("Invalid password!\n");
    }
}     