#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void itemOut(const char *filename) {
    FILE *file;
    int idFile, stock, price;
    char name[100];

    int searchID;
    int keluarStock;
    int found = 0;

    // File exist validation
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("File \"%s\" tidak ditemukan!\n", filename);
        return;
    }
    fclose(file);

    char foundName[100];
    int foundStock, foundPrice;

    // Loop untuk validasi ID
    do {
        printf("\nMasukkan ID Barang : ");
        scanf("%d", &searchID);

        file = fopen(filename, "r");
        found = 0;
        while (fscanf(file, " %d - %99[^-] - %d - %d",
                      &idFile, name, &stock, &price) == 4) {
            if (idFile == searchID) {
                found = 1;
                strcpy(foundName, name);
                foundStock = stock;
                foundPrice = price;
                // printf("Detail produk: ID %d\nNama %s\nStock %d\nPrice %d\n", idFile, name, stock, price);
                system("cls");
                printTable(idFile, name, stock, price);
                break;
            }
        }
        fclose(file);

        if (!found) {
            printf("ID Barang tidak ditemukan! Silakan coba lagi.\n");
        }
    } while (!found);

    

    // Sekarang prompt jumlah
    do {
        printf("Jumlah Barang Keluar : ");
        scanf("%d", &keluarStock);
    } while (keluarStock <= 0);

    // Cek stock cukup
    if (foundStock < keluarStock) {
        printf("Stok tidak mencukupi!\n");
        return;
    }

    // Sekarang update file
    file = fopen(filename, "r");
    char buffer[100][200];
    int count = 0;

    while (fscanf(file, " %d - %99[^-] - %d - %d",
                  &idFile, name, &stock, &price) == 4) {
        if (idFile == searchID) {
            stock -= keluarStock;
        }
        sprintf(buffer[count], "%d - %s - %d - %d\n",
                idFile, name, stock, price);
        count++;
    }

    fclose(file);

    // Tulis ulang file
    file = fopen(filename, "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s", buffer[i]);
    }
    fclose(file);
    printTable(searchID, foundName, foundStock - keluarStock, foundPrice);
    printf("Stok barang berhasil dikurangi!\n");
}
