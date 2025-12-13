#include <stdio.h>
#include <stdlib.h>

// #include "printTable.c"  // Removed to avoid redefinition

void addItem(const char *filename) {
    FILE *file;
    char line[265]; // ini buffer buat ngebaca satu baris penuh
    char id[50], name[100];
    int stock, price;

    int i;
    int j;

    // ini variabel untuk barang baru
    char newID[50]; // GANTI INI
    char newName[100];
    int newStock, newPrice;

    // ini variabel untuk barang yang sudah ada 
    int idFile, stockFile, hargaFile;
    char namaFile[100];
    
    int found = 0;


    // Input data user disini bos
INPUT_DATA:
    printf("Masukkan ID barang   : ");
    scanf("%49s", newID); // GANTI INI DARI "d" jadi "s"
    getchar(); // ini buat buang newline setelah scanf

    printf("Masukkan nama barang: ");
    fgets(newName, sizeof(newName), stdin);

    // Hapus newline pake loop
    for (i = 0; newName[i] != '\0'; i++) {
        if (newName[i] == '\n') {
            newName[i] = '\0';
            break;
        }
    }

    printf("Masukkan stock baru  : ");
    scanf("%d", &newStock);

    printf("Masukkan harga       : ");
    scanf("%d", &newPrice);


    // Coba buka file untuk dibaca
    file = fopen(filename, "r");

    // Kalo file belum ada -> buat baru, langsung tulis data
    if (file == NULL) {
        file = fopen(filename, "w");
        fprintf(file, "%-6s - %-20s - %6d - %8d\n", newID, newName, newStock, newPrice); // GANTI %d -> %s
        fclose(file);
        printf("Barang baru ditambahkan (file baru dibuat).\n");
        return;
    }

    // ====================================================================
    // FILE ADA? CEK APAKAH ID ATAU NAMA SUDAH ADA ? kalau ada: input ulang
    // ====================================================================
    found = 0;
    while (fscanf(file, " %49[^-] - %99[^-] - %d - %d",
                  id, name, &stock, &price) == 4)
    {
        // Bersihkan spasi depan ID (geser manual)
        while (id[0] == ' ') {
            for (j = 0; id[j] != '\0'; j++)
                id[j] = id[j + 1];
        }

        // Bersihkan spasi depan NAMA (geser manual)
        while (name[0] == ' ') {
            for (j = 0; name[j] != '\0'; j++)
                name[j] = name[j + 1];
        }

        // Hapus spasi belakang ID
        i = strlen(id) - 1;
        while (i >= 0 && id[i] == ' ') {
            id[i] = '\0';
            i--;
        }

        // Hapus spasi belakang NAMA
        i = strlen(name) - 1;
        while (i >= 0 && name[i] == ' ') {
            name[i] = '\0';
            i--;
        }

        // Kalo ID atau Nama sudah ada, suruh input ID atau Nama lain/baru.
        if (strcmp(id, newID) == 0 || strcmp(name, newName) == 0) {
            printf("\nID dan Nama sudah terdapat dalam database!\n");
            printf("Mohon memasukan \"ID - Nama\" yang lain/baru!\n\n");

            fclose(file);
            goto INPUT_DATA;
        }
    }

    fclose(file);

    // ============================================
    // Penulisan data baru dilakukan setelah input 
    // dipastikan ID dan Nama yang diinput tidak 
    // sudah terdapat dalam file
    // ============================================
    file = fopen(filename, "a"); // a itu append, untuk membuka file dan menulis di akhir file tanpa menghapus data lama
    // fprintf(file, "%-6s - %-20s - %6d - %8d\n", newID, newName, newStock, newPrice); // GANTI %d -> %s
    fprintf(file, "%s-%s-%d-%d\n", newID, newName, newStock, newPrice);
    fclose(file);

    printTable(atoi(newID), newName, newStock, newPrice);
    printf("Barang baru berhasil ditambahkan.\n");
}
//
//int main() {
//    addItem("barang.txt");
//    return 0;
//}