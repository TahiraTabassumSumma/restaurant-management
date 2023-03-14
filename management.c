#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 100
#define MAX_ORDER_ITEMS 50

// Structure to hold menu items
typedef struct MenuItem {
    char name[50];
    double price;
} MenuItem;

// Function to add a new menu item
void addMenuItem(MenuItem menu[], int *numItems) {
    char name[50];
    double price;

    printf("Enter the name of the menu item: ");
    scanf("%s", name);

    printf("Enter the price of the menu item: ");
    scanf("%lf", &price);

    MenuItem newItem;
    strcpy(newItem.name, name);
    newItem.price = price;

    menu[*numItems] = newItem;
    (*numItems)++;

    printf("Menu item added successfully!\n");
}

// Function to display the menu
void displayMenu(MenuItem menu[], int numItems) {
    printf("Menu:\n");

    for (int i = 0; i < numItems; i++) {
        printf("%s - $%.2lf\n", menu[i].name, menu[i].price);
    }
}

// Function to take a customer's order
void takeOrder(MenuItem menu[], int numItems) {
    char order[MAX_ORDER_ITEMS][50];
    double total = 0;

    printf("Enter your order (type 'done' when finished):\n");

    int numOrderItems = 0;
    char itemName[50];

    while (1) {
        scanf("%s", itemName);

        if (strcmp(itemName, "done") == 0) {
            break;
        }

        int itemIndex = -1;

        for (int i = 0; i < numItems; i++) {
            if (strcmp(itemName, menu[i].name) == 0) {
                itemIndex = i;
                break;
            }
        }

        if (itemIndex == -1) {
            printf("Sorry, that item is not on the menu.\n");
            continue;
        }

        strcpy(order[numOrderItems], itemName);
        total += menu[itemIndex].price;
        numOrderItems++;
    }

    printf("Your order:\n");

    for (int i = 0; i < numOrderItems; i++) {
        printf("%s\n", order[i]);
    }

    printf("Total: $%.2lf\n", total);
}

// Main function
int main() {
    MenuItem menu[MAX_MENU_ITEMS];
    int numItems = 0;

    while (1) {
        printf("1. Add menu item\n");
        printf("2. Display menu\n");
        printf("3. Take order\n");
        printf("4. Quit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMenuItem(menu, &numItems);
                break;
            case 2:
                displayMenu(menu, numItems);
                break;
            case 3:
                takeOrder(menu, numItems);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
