# Warehouse Logistic Management System

A simple warehouse management system written in C for managing inventory items.

## Features

-   **Generate Report**: Display all items in a table format with stock levels and low stock warnings.
-   **Sort Report**: Sort and display items by ID, Name, Stock, or Price.
-   **Add New Item**: Add new items to the inventory.
-   **Item In**: Increase stock of existing items.
-   **Item Out**: Decrease stock of existing items.
-   **Search Item**: Search for items by name.

## User Roles

-   **Admin**: Full access to all features (password: admin123)
-   **Staff**: Access to Generate Report, Search Item, Item In, Item Out (password: staff123)
-   **Visitor**: Read-only access to Generate Report and Search Item (no password required)

## Requirements

-   GCC compiler (or any C compiler)
-   Windows (for system("cls") command)

## Compilation

Compile all C files together:

```
gcc LogisticSystemAOL.c generateReport.c addNewItem.c itemIn.c itemOut.c searchItem.c sortReport.c printTable.c -o LogisticSystemAOL.exe
```

## Running the Program

Run the executable:

```
./LogisticSystemAOL.exe
```

Select your user role (Admin, Staff, or Visitor) and enter the required password if prompted. Then follow the menu prompts to navigate through the system.

## Data File

-   `barang.txt`: Stores item data in the format `ID - Name - Stock - Price`

## File Structure

-   `LogisticSystemAOL.c`: Main program with menu system
-   `generateReport.c`: Report generation functionality
-   `sortReport.c`: Sorting functionality
-   `addNewItem.c`: Add new items
-   `itemIn.c`: Increase item stock
-   `itemOut.c`: Decrease item stock
-   `searchItem.c`: Search items
-   `printTable.c`: Table printing utilities- `Record.h`: Structure definitions
-   `barang.txt`: Data file- `barang.txt`: Data file

## Notes

-   The system uses a simple text file for data storage.
-   Low stock warning appears for items with stock < 5.
-   All operations are performed via console input/output.
