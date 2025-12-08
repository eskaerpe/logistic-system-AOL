#include <stdio.h>
#include <string.h>

// Note: Record struct is defined in generateReport.c
void sortAndDisplayReport(char* filename);
int getSortChoice();
void sortRecords(Record recs[], int count, int sortChoice);
void printSortedResults(Record recs[], int count);


// Complete sorting report function with filename parameter
void sortAndDisplayReport(char* filename) {
    FILE *fp;
    int id;
    char namaBarang[100];
    int stock;
    int harga;

    // Load records into array
    Record recs[200];
    int count = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("[!] Error: cannot open %s\n", filename);
        return;
    }

    printf("%-5s| %-30s| %-10s| %-10s| %-10s\n", "ID", "NAMA BARANG", "STOCK", "HARGA", "Keterangan");
    printf("-----|-------------------------------|-----------|-----------|--------------\n");
    while(fscanf(fp, " %d - %99[^-] - %d - %d", &id, namaBarang, &stock, &harga) == 4){
        printf("%-5d| %-30s| %-10d| %-10d| %-10s\n", id, namaBarang, stock, harga, stock < 5 ? "LOW STOCK!":"");
        if (count < 200) {
            recs[count].id = id;
            strncpy(recs[count].name, namaBarang, sizeof(recs[count].name)-1);
            recs[count].name[sizeof(recs[count].name)-1] = '\0';
            recs[count].stock = stock;
            recs[count].price = harga;
            count++;
        }
    }

    printf("\n\n");

    // Sorting option
    int sortChoice = getSortChoice();

    if (sortChoice == -1) { // Error in input
        fclose(fp);
        return;
    }

    if (sortChoice == 0) {
        fclose(fp);
        return;
    }

    if (sortChoice < 0 || sortChoice > 4) {
        printf("Invalid choice. Returning to main menu.\n");
        fclose(fp);
        return;
    }

    // Sort the records
    sortRecords(recs, count, sortChoice);

    // Print sorted results
    printSortedResults(recs, count);

    fclose(fp);
}

// Function to sort records based on user's choice
void sortRecords(Record recs[], int count, int sortChoice) {
    // simple bubble sort for clarity
    for (int i = 0; i < count-1; i++) {
        for (int j = 0; j < count-i-1; j++) {
            int swap = 0;
            switch (sortChoice) {
                case 1: // by ID ascending
                    if (recs[j].id > recs[j+1].id) swap = 1;
                    break;
                case 2: // by Name A-Z
                    if (strcmp(recs[j].name, recs[j+1].name) > 0) swap = 1;
                    break;
                case 3: // by Stock Low -> High
                    if (recs[j].stock > recs[j+1].stock) swap = 1;
                    break;
                case 4: // by Price High -> Low
                    if (recs[j].price < recs[j+1].price) swap = 1;
                    break;
                default:
                    break;
            }
            if (swap == 1) {
                Record tmp = recs[j];
                recs[j] = recs[j+1];
                recs[j+1] = tmp;
            }
        }
    }
}

// Function to display sorting menu and get user choice
int getSortChoice() {
    int sortChoice;
    printf("================================\n");
    printf("SORTING OPTIONS:\n");
    printf("1. Sort by ID (ascending)\n");
    printf("2. Sort by Name (A-Z)\n");
    printf("3. Sort by Stock (Low -> High)\n");
    printf("4. Sort by Price (High -> Low)\n");
    printf("0. Return to Main Menu\n");
    printf("================================\n");
    printf("Select sorting method (0-4): ");

    if (scanf("%d", &sortChoice) != 1) {
        int c;
        while((c = getchar()) != '\n' && c != EOF); // clear input buffer
        printf("Invalid input. Returning to main menu.\n");
        return -1; // indicate error
    }

    return sortChoice;
}

// Function to print sorted results
void printSortedResults(Record recs[], int count) {
    system("cls");
    printf("Sorted results:\n");
    printf("%-5s| %-30s| %-10s| %-10s| %-10s\n", "ID", "NAMA BARANG", "STOCK", "HARGA", "Keterangan");
    printf("-----|-------------------------------|-----------|-----------|--------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d| %-30s| %-10d| %-10d| %-10s\n",
               recs[i].id, recs[i].name, recs[i].stock, recs[i].price,
               recs[i].stock < 5 ? "LOW STOCK!":"");
    }
    printf("\n\n");
}