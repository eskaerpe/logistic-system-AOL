#include <stdio.h>
#include <string.h>

// Record struct is expected to be declared in generateReport.c

void printRecords(Record recs[], int count);
void swapRecords(Record* a, Record* b);
void sortById(Record recs[], int count);
void sortByName(Record recs[], int count);
void sortByStock(Record recs[], int count);
void sortByPrice(Record recs[], int count);

void sortAndDisplayReport(char* filename) {
    FILE *fp;
    Record recs[200]; // struct nya dari generateReport.c
    int count = 0;
    int id;
    char namaBarang[100];
    int stock;
    int harga;
    int sortChoice;

    // Buka file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("[!] Error: cannot open %s\n", filename);
        return;
    }

    // Print original table tanpa disort
    printf("Original list:\n");
    printf("%-5s| %-30s| %-10s| %-10s| %-10s\n", "ID", "NAMA BARANG", "STOCK", "HARGA", "Keterangan");
    printf("-----|-------------------------------|-----------|-----------|--------------\n");

    while (fscanf(fp, " %d - %99[^-] - %d - %d", &id, namaBarang, &stock, &harga) == 4) {
        if (count < 200) {
            recs[count].id = id;
            strncpy(recs[count].name, namaBarang, sizeof(recs[count].name) - 1);
            recs[count].name[sizeof(recs[count].name) - 1] = '\0';
            recs[count].stock = stock;
            recs[count].price = harga;
            count++;
        }
        printf("%-5d| %-30s| %-10d| %-10d| %-10s\n", id, namaBarang, stock, harga, stock < 5 ? "LOW STOCK!" : "");
    }

    fclose(fp);
    printf("\n\n");

    // Pilihan untuk sort
    printf("Sorting options:\n");
    printf("1. Sort by ID (ascending)\n");
    printf("2. Sort by Name (A-Z)\n");
    printf("3. Sort by Stock (Low -> High)\n");
    printf("4. Sort by Price (High -> Low)\n");
    printf("0. Cancel\n");
    printf("Choose option: ");

    // validation untuk pilihan sorting
    if (scanf("%d", &sortChoice) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("Input tidak valid, kembali ke menu utama.\n");
        return;
    }

    if (sortChoice == 0) {
        printf("Kembali ke menu utama.\n");
        return;
    }

    if (sortChoice < 0 || sortChoice > 4) {
        printf("Pilihan tidak dikenal, kembali ke menu utama.\n");
        return;
    }
    // end of validation


    if (sortChoice == 1) {
        sortById(recs, count);
    } else if (sortChoice == 2) {
        sortByName(recs, count);
    } else if (sortChoice == 3) {
        sortByStock(recs, count);
    } else if (sortChoice == 4) {
        sortByPrice(recs, count);
    }

    system("cls");
    printf("Sorted results:\n");
    printf("%-5s| %-30s| %-10s| %-10s| %-10s\n", "ID", "NAMA BARANG", "STOCK", "HARGA", "Keterangan");
    printf("-----|-------------------------------|-----------|-----------|--------------\n");
    printRecords(recs, count);
    printf("\n\n");
}

void printRecords(Record recs[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%-5d| %-30s| %-10d| %-10d| %-10s\n", recs[i].id, recs[i].name, recs[i].stock, recs[i].price, recs[i].stock < 5 ? "LOW STOCK!" : "");
    }
}

void swapRecords(Record* a, Record* b) {
    Record tmp = *a;
    *a = *b;
    *b = tmp;
}

void sortById(Record recs[], int count) { // Bubble Sort for ID
    for (int outer = 0; outer < count - 1; outer++) {
        for (int i = 0; i < count - 1 - outer; i++) {
            if (recs[i].id > recs[i + 1].id) {
                swapRecords(&recs[i], &recs[i + 1]);
            }
        }
    }
}

void sortByName(Record recs[], int count) { // Bubble Sort for Name
    for (int outer = 0; outer < count - 1; outer++) {
        for (int i = 0; i < count - 1 - outer; i++) {
            if (strcmp(recs[i].name, recs[i + 1].name) > 0) {
                swapRecords(&recs[i], &recs[i + 1]);
            }
        }
    }
}

void sortByStock(Record recs[], int count) { // Bubble Sort for Stock
    for (int outer = 0; outer < count - 1; outer++) {
        for (int i = 0; i < count - 1 - outer; i++) {
            if (recs[i].stock > recs[i + 1].stock) {
                swapRecords(&recs[i], &recs[i + 1]);
            }
        }
    }
}

void sortByPrice(Record recs[], int count) { // Bubble Sort for Price
    for (int outer = 0; outer < count - 1; outer++) {
        for (int i = 0; i < count - 1 - outer; i++) {
            if (recs[i].price < recs[i + 1].price) {
                swapRecords(&recs[i], &recs[i + 1]);
            }
        }
    }
}
