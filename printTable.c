#include <stdio.h>
#include <stdlib.h>

void printTable(int id, char* namaBarang, int stock, int harga){
    printf("\n");
    printf("%-5s| %-25s| %-10s| %-10s| %-10s\n", "ID", "NAMA BARANG", "STOCK", "HARGA", "Keterangan");
	printf("-----|--------------------------|-----------|-----------|--------------\n");
	printf("%-5d| %-25s| %-10d| %-10d| %-10s\n", id, namaBarang, stock, harga, stock < 5 ? "LOW STOCK!":"");
    printf("\n");
}