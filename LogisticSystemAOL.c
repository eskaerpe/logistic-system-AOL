#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "printTable.c"
#include "generateReport.c"
#include "addNewItem.c"
#include "itemIn.c"
#include "itemOut.c"
#include "searchItem.c"
#include "sortReport.c"

void mainMenu();
void spaceToClear();
void generateReport();
void printHeadTitle(char* words);

int main(){
	int selected = -1;
	while(selected != 0){
		mainMenu();
		printf("Select Menu: ");
		scanf("%d", &selected);
				
		switch(selected){
		case 1:
			system("cls");
			printHeadTitle("DATA REPORT");
			generateReport();
			spaceToClear();
			break;
		case 2:
			system("cls");
			printHeadTitle("SORT REPORT");
			sortAndDisplayReport("barang.txt");
			spaceToClear();
			break;
		case 3:
			system("cls");
			printHeadTitle("ADD NEW ITEM");
			addItem("barang.txt");
			spaceToClear();
			break;
		case 4:
			system("cls");
			printHeadTitle("ITEM IN");
			generateReport();
			itemIn("barang.txt");
			spaceToClear();
			break;
		case 5:
			system("cls");
			printHeadTitle("ITEM OUT");
			generateReport();
			itemOut("barang.txt");
			spaceToClear();
			break;	
		case 6:
			system("cls");
			printHeadTitle("SEARCH ITEM");
			searchItem("barang.txt");
			spaceToClear();
			break;
		default:
			printf("No choice");
		}
		system("cls");
	}
	printf("Byebye!");

	
	return 0;
}

void mainMenu(){
	printf("========================\n");
	printf("Menu: \n");
	printf("1. Generate Report\n");
	printf("2. Sort Report\n");
	printf("3. Add Item\n");
	printf("4. Item In\n");
	printf("5. Item Out\n");
	printf("6. Search Item\n");
	printf("0. Exit\n");
	printf("========================\n");
}
	
void spaceToClear(){
	printf("\n\n\n");
	printf("Press 'space' to go back to main menu.");
	if(getch() == ' '){
		system("cls");
}}

	



void printHeadTitle(char* words){
	printf("==============================\n");
	printf("\t%s\n", words);
	printf("==============================\n");
	printf("\n");
	printf("\n");
}