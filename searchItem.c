#include <stdio.h>
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

    // Cari keyword di setiap baris
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, keyword) != NULL) {
            int id, stock, price;
            char name[100];
            
            // Parse line untuk ambil data
            if (sscanf(line, "%d - %99[^-] - %d - %d", &id, name, &stock, &price) == 4) {
                printTable(id, name, stock, price);
                found = 1;
                break;
            }
        }
    } 

    // Jika tidak ditemukan
    if (!found) {
        printf("\nData \"%s\" tidak ditemukan.\n", keyword);
    }

    fclose(file);
}
