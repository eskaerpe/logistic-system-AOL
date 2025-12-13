#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Record.h"

void generateReport(){
    FILE *fp;
    int id;
    char namaBarang[100];
    int stock;
    int harga;
    
    fp = fopen("barang.txt", "r");
    if (fp == NULL) {
        printf("[!] Error: cannot open barang.txt\n");
        return;
    }
    
    printf("%-5s| %-30s| %-10s| %-10s| %-10s\n", "ID", "NAMA BARANG", "STOCK", "HARGA", "Keterangan");
    printf("-----|-------------------------------|-----------|-----------|--------------\n");
    while(fscanf(fp, " %d - %99[^-] - %d - %d", &id, namaBarang, &stock, &harga) == 4){
        printf("%-5d| %-30s| %-10d| %-10d| %-10s\n", id, namaBarang, stock, harga, stock < 5 ? "LOW STOCK!":"");
    }

    printf("\n\n");

    fclose(fp);
}
