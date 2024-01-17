# Inventory-Management-System

## Description: 
  Develop a C++ program for tracking inventory in a departmental store. The system should update inventory with each transaction.

## Introduction:
  The project involves creating an Inventory Management System using C++ to meet the functional requirements of a departmental store.

## Algorithm and Code Description:

### Main Function:
Utilizes a do-while loop to create a menu for departmental store functions.
Each option corresponds to a function that runs on selection.

### Create Function:
Opens an existing file or creates a new one named "Storage."
User inputs the number of records for items, and the data is stored in the file.

### Read-Record Function:
Opens the "Storage" file and uses vectors and string manipulation to read and compare records.
User inputs a barcode, and the system prints the details of the matching record.

### M-Update-Record Function:
Modifies stock by opening "Storage" and creating a new file "Storagenew."
User inputs a barcode, and the system updates the stock quantity based on user input.
The modified data is stored in "Storagenew," and file names are swapped.

### C-Update-Record Function:
Modifies stock and price, similar to M-Update-Record, but also calculates the total price of items to be purchased.
Prints the total price, and if stock is zero, displays "out of stock."

### Delete-Record Function:
Deletes a record by asking the user to input a barcode.
Creates a new file "Storagenew" without the record to be deleted, and file names are swapped.

### Conclusion:
The project successfully utilizes C++ features such as file handling, conditional statements, loops, and functions to implement a fully functional departmental store system for inventory management.
