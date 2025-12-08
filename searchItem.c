#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #include "printTable.c"

void searchItem(char* filename) {
    FILE *file;
    char line[265];
    char keyword[100];
    
    getchar(); // clear newline from buffer
    printf("Insert ID or Name: ");
    scanf("%99[^\n]", keyword);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File \"%s\" tidak ditemukan.\n", filename);
        return;
    }

    int found = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, keyword) != NULL) {
            int id, stock, price;
            char name[100];
            
            if (sscanf(line, "%d - %99[^-] - %d - %d", &id, name, &stock, &price) == 4) {
                printTable(id, name, stock, price);
                found = 1;
                break;
            }
        }
    } 

    if (!found) {
        printf("\nData \"%s\" tidak ditemukan.\n", keyword);
    }

    fclose(file);
}

// int main() {
//     searchItem("barang.txt");
//     return 0;
// }