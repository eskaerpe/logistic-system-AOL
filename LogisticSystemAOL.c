#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "printTable.c"
#include "generateReport.c"
#include "addNewItem.c"
#include "itemIn.c"
#include "itemOut.c"
#include "searchItem.c"
#include "sortReport.c"

void mainMenu();
void staffMenu();
void visitorMenu();
void spaceToClear();
void generateReport();
void printHeadTitle(char* words);

int main(){
	// User role selection
	printHeadTitle("LOGISTIC SYSTEM");
	int role;
	printf("Select User Role:\n");
	printf("========================\n");
	printf("1. Admin\n");
	printf("2. Staff\n");
	printf("3. Visitor\n");
	printf("========================\n");
	printf("Enter choice (1, 2, or 3): ");
	scanf("%d", &role);
	while (getchar() != '\n'); // Clear the input buffer

	// little password check for admin
	if(role == 1){
		char password[20];
		printf("Enter admin password: ");
		scanf("%[^\n]", password);
		while (getchar() != '\n'); // Clear buffer after password input
		if(strcmp(password, "admin123") != 0){
			printf("Incorrect password. Exiting...\n");
			return 0;
		}
		system("cls");

		mainMenu();
	}else if(role == 2){
		char password[20];
		printf("Enter staff password: ");
		scanf("%[^\n]", password);
		while (getchar() != '\n'); // Clear buffer after password input
		if(strcmp(password, "staff123") != 0){
			printf("Incorrect password. Exiting...\n");
			return 0;
		}
		system("cls");
		staffMenu();
	}else if(role == 3){
		system("cls");
		visitorMenu();
	}else{
		printf("Invalid role selection. Exiting...\n");
		return 0;
	}

	
	return 0;
}

void mainMenu(){
	int selected = -1;
	while(selected != 0){
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
}
	

void visitorMenu(){
	int selected = -1;
	while(selected != 0){
		printf("==============================\n");
		printf("Welcome to Logistic System\n");
		printf("==============================\n");
		printf("1. Generate Report\n");
		printf("2. Search Item\n");
		printf("0. Exit\n");
		printf("==============================\n");
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
			printHeadTitle("SEARCH ITEM");
			searchItem("barang.txt");
			spaceToClear();
			break;
		default:
			printf("No choice");
		}
		system("cls");
	}
}

void staffMenu(){
	int selected = -1;
	while(selected != 0){
		printf("==============================\n");
		printf("Welcome to Logistic System\n");
		printf("==============================\n");
		printf("1. Generate Report\n");
		printf("2. Search Item\n");
		printf("3. Item In\n");
		printf("4. Item Out\n");
		printf("0. Exit\n");
		printf("==============================\n");
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
			printHeadTitle("SEARCH ITEM");
			searchItem("barang.txt");
			spaceToClear();
			break;
		case 3:
			system("cls");
			printHeadTitle("ITEM IN");
			generateReport();
			itemIn("barang.txt");
			spaceToClear();
			break;
		case 4:
			system("cls");
			printHeadTitle("ITEM OUT");
			generateReport();
			itemOut("barang.txt");
			spaceToClear();
			break;	
		default:
			printf("No choice");
		}
		system("cls");
	}
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
}