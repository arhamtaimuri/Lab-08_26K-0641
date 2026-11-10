
#include <stdio.h>
#include <stdlib.h>

void displayStock(int *stock, int size) {
    printf("\nCurrent Stock:\n");

    for (int i = 0; i < size; i++) {
        printf("Item %d: %d\n", i + 1, stock[i]);
    }
}

void showSummary(int *stock, int size) {
    int total = 0;
    int lowest = *stock;

    for (int i = 0; i < size; i++) {
        total += *(stock + i);

        if (*(stock + i) < lowest) {
            lowest = *(stock + i);
        }
    }

    printf("\nTotal Stock: %d\n", total);
    printf("Lowest Stock: %d\n", lowest);
}

int main() {
    int n;

    printf("Enter the starting number of items (3 to 8): ");
    scanf("%d", &n);

    while (n<3 || n>8) {
        printf("Invalid size! Enter a number between 3 and 8: ");
        scanf("%d", &n);
    }

  
    int *stock = (int *)malloc(n * sizeof(int));

    if (stock == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter stock quantities:\n");

    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &stock[i]);

        while (stock[i] < 0) {
            printf("Stock cannot be negative. Enter again: ");
            scanf("%d", &stock[i]);
        }
    }

    int choice;
    int position;
    int value;
    int *newStock;
    int temp;

    do {
        printf("\n========== STOCK MENU ==========\n");
        printf("1. Display Stock\n");
        printf("2. Update Stock of One Item\n");
        printf("3. Insert a New Item\n");
        printf("4. Delete an Item\n");
        printf("5. Sort Stock\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                displayStock(stock, n);
                break;

            case 2:
                printf("Enter item position to update (1 to %d): ", n);
                scanf("%d", &position);

                if (position < 1 || position > n) {
                    printf("Invalid position!\n");
                }
                else {
                    printf("Enter new stock value: ");
                    scanf("%d", &value);

                    while (value < 0) {
                        printf("Stock cannot be negative. Enter again: ");
                        scanf("%d", &value);
                    }

                    stock[position - 1] = value;

                    printf("Stock updated successfully!\n");
                    displayStock(stock, n);
                    showSummary(stock, n);
                }
                break;

            case 3:
                printf("Enter position for the new item (1 to %d): ", n + 1);
                scanf("%d", &position);

                if (position < 1 || position > n + 1) {
                    printf("Invalid position!\n");
                }
                else {
                    printf("Enter stock value for new item: ");
                    scanf("%d", &value);

                    while (value < 0) {
                        printf("Stock cannot be negative. Enter again: ");
                        scanf("%d", &value);
                    }

               
                    newStock = (int *)malloc((n + 1) * sizeof(int));

                    if (newStock == NULL) {
                        printf("Memory allocation failed!\n");
                        break;
                    }

                  
                    for (int i = 0; i < position - 1; i++) {
                        newStock[i] = stock[i];
                    }

                
                    newStock[position - 1] = value;

                
                    for (int i = position; i < n + 1; i++) {
                        newStock[i] = stock[i - 1];
                    }

            
                    free(stock);

                    stock = newStock;
                    n++;

                    printf("New item inserted successfully!\n");
                    displayStock(stock, n);
                    showSummary(stock, n);
                }
                break;

            
            case 4:
                if (n == 1) {
                    printf("At least one item must remain in stock!\n");
                    break;
                }

                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &position);

                if (position < 1 || position > n) {
                    printf("Invalid position!\n");
                }
                else {
                    newStock = (int *)malloc((n - 1) * sizeof(int));

                    if (newStock==NULL) {
                        printf("Memory allocation failed!\n");
                        break;
                    }

                   
                    for (int i = 0, j = 0; i < n; i++) {
                        if (i != position - 1) {
                            newStock[j] = stock[i];
                            j++;
                        }
                    }

                    free(stock);

                    stock = newStock;
                    n--;

                    printf("Item deleted successfully!\n");
                    displayStock(stock, n);
                    showSummary(stock, n);
                }
                break;
            case 5:
                for (int pass = 0; pass < n - 1; pass++) {
                    int *ptr = stock;

                    for (int j = 0; j < n - pass - 1; j++) {
                        if (*ptr > *(ptr + 1)) {
                            temp = *ptr;
                            *ptr = *(ptr + 1);
                            *(ptr + 1) = temp;
                        }

                        ptr++;
                    }
                }

                printf("Stock sorted in ascending order!\n");
                displayStock(stock, n);
                showSummary(stock, n);
                break;

            case 6:
                printf("Exiting \n");
                printf("Thankyou for choosing us!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 6);

 
    free(stock);
    stock = NULL;

    printf("\nMemory released successfully!\n");

    return 0;
}
