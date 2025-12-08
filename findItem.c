#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "printTable.c"

// void findItem(char* filename){
//     FILE* fp;
//     int id;
//     char namaBarang[100];
//     int stock;
//     int harga;
//     int searchID;
//     int found = 0;

//     // File exist validation
//     fp = fopen(filename, "r");
//     if (fp == NULL) {
//         printf("[!] Error: cannot open %s\n", filename);
//         return;
//     }
//     fclose(fp);

//     // Loop untuk validasi ID
//     do {
//         printf("\nMasukkan ID Barang : ");
//         scanf("%d", &searchID);

//         fp = fopen(filename, "r");
//         found = 0;
//         while (fscanf(fp, " %d - %99[^-] - %d - %d",
//                       &id, namaBarang, &stock, &harga) == 4) {
//             if (id == searchID) {
//                 found = 1;
//                 system("cls");
//                 printTable(id, namaBarang, stock, harga);
//                 break;
//             }
//         }
//         fclose(fp);

//         if (!found) {
//             printf("ID Barang tidak ditemukan! Silakan coba lagi.\n");
//         }
//     } while (!found);
// }

void findItemByName(char* filename){
    FILE* fp;
    int id;
    char namaBarang[100];
    int stock;
    int harga;
    char searchName[100];
    int found = 0;

    // File exist validation
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("[!] Error: cannot open %s\n", filename);
        return;
    }
    fclose(fp);

    // Loop untuk validasi Name
    do {
        printf("\nMasukkan Nama Barang : ");
        getchar(); // clear newline
        scanf("%99[^\n]", searchName);

        // Hapus newline
        for (int i = 0; searchName[i] != '\0'; i++) {
            if (searchName[i] == '\n') {
                searchName[i] = '\0';
                break;
            }
        }

        fp = fopen(filename, "r");
        found = 0;
        while (fscanf(fp, " %d - %99[^-] - %d - %d",
                      &id, namaBarang, &stock, &harga) == 4) {
            if (strcmp(namaBarang, searchName) == 0) {
                found = 1;
                system("cls");
                printTable(id, namaBarang, stock, harga);
                break;
            }
            printf("Debug: comparing '%s' with '%s'\n", namaBarang, searchName);
        }
        fclose(fp);

        if (!found) {
            printf("Barang %s tidak ditemukan! Silakan coba lagi.\n", searchName);
        }
    } while (!found);
}

int main(){
    findItemByName("barang.txt");
    return 0;
}