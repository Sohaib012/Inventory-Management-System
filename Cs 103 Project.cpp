//Sohaib Nasir
//Reg no: 2021609

//including the required libraries for my code
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//function to show inventory of the store
void showrecs()
{
	//fin being an object of class fstream
	fstream fin;
	
	//opening file with objective to number of records
	//being known
	fin.open("Storage.csv", ios::in);
	
	string line, word;
	
	int size = 0;
	
	vector<string> row;
	
	//storing number of records 
	while(fin)
	{
		getline(fin,line);
		size++;
	}
	fin.close();
	
	fin.open("Storage.csv", ios::in);
	
	//printing inventory
	cout << endl << "The inventory is: "<< endl;
	cout << "Barcode :: Name "<< endl;
	

	for(int i = 0; i < size - 1; i++)
    {
        row.clear();

        getline(fin, line);

        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }   
        cout << row[0] << " -- " << row[1] << endl;
	}
}

//function to create a record of an item
void create()
{
    // fout an object of class fstream
    fstream fout;

    // opens an existing csv file or creates a new file.
    fout.open("storage.csv", ios::out | ios::app);
    //ios::app will not let old data to be deleted but will
    //add new data at the end

    //Declaring variables
    int amt_rec, i, bc, noi, price;
    string name;

    cout << "How many records will you be creating? :"<< endl;
    cin >> amt_rec;

    cout << "Enter details"
        << " (barcode name stock price :" << endl;


    // Read the input
    for (i = 0; i < amt_rec; i++)
    {

        cin >> bc
            >> name
            >> noi
            >> price;


        // Insert the data to file
        fout << bc << ","
            << name << ","
            << noi << ","
            << price << endl;
    }
    fout.close();
}

void read_record()
{
    // fout an object of class fstream
    fstream fin;

    // Open an existing file
    fin.open("storage.csv", ios::in);

    // Get the barcode
    // of which the data is required
    int bcnum, bc2, count = 0;
    cout << "Enter the barcode number of item to display details: ";
    cin >> bcnum;

    // Read the Data from the file
    // as String Vector

    vector<string> row;
    string line, word;

    while (!fin.eof())
    {

        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {
            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        // stoi convert string to integer for comparision
        bc2 = stoi(row[0]);

        // Compare the barcode number
        if (bc2 == bcnum)
        {

            // Print the found data
            count = 1;
            cout << "Details of Barcode: " << row[0] << endl;
            cout << "Name of item: " << row[1] << endl;
            cout << "Stock of item: " << row[2] << endl;
            cout << "Price of item: " << row[3] << endl;

            break;
        }
    }
    if (count == 0)
    {
        cout << "Record not found!\n";
    }
    fin.close();         
}

//function to update stock by the manager
void m_update_record()
{

    // fout an object of class fstream
    fstream fin, fout;

    // Open an existing record
    fin.open("storage.csv", ios::in);

    // Create a new file to store updated data
    fout.open("storagenew.csv", ios::out);

    //Declaring variables
    int bcnum, bc1, found = 0, i;
    char opt;
    int index;
    string line, word;
    vector<string> row;
    int noi2;
    int noi;
    int size = 0;
    index = 2;

    //using loop to get no of columns
    while (fin)
    {
        getline(fin, line);
        size++;
    }
    fin.close();
    //closing and opening file again as after the loop it will
    //be pointing to end of file
    fin.open("storage.csv", ios::in);

    //Get the barcode number from the user to display
    cout << "Enter the barcode number to change: ";
    cin >> bcnum;


    //getting no of items to add or subtract from user to stock
    cout << "Enter the no of items to add or remove from stock: ";
    cin >> noi2;

    for (int j = 0; j < size - 1; j++)
    {

        row.clear();
        getline(fin, line);

        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        bc1 = stoi(row[0]);
        int row_size = row.size();

        if (bc1 == bcnum)
        {
            found = 1;
            stringstream convert;

            noi = stoi(row[index]);

            cout << "Do you want to add or remove from the stock? (A/R): ";
            cin >> opt;

            if (opt == 'a' || opt == 'A')
            {
                noi = noi + noi2;
            }
            else if (opt == 'r' || opt == 'R')
            {
                noi = noi - noi2;
            }
            else
            {
                cout << "WRONG INPUT!" << endl;
            }

            //putting in the updated stock to convert
            convert << noi;

            //turning updated stock to string and storing it to vector
            row[index] = convert.str();

            //storing data in file again
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {

                    // write the updated data
                    // into a new file 'resultnew.csv'
                    // using fout
                    fout << row[i] << ",";
                }

                fout << row[row_size - 1] << endl;
            }
        }
        else {
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {

                    // writing other existing records
                    // into the new file using fout.
                    fout << row[i] << ",";
                }

                // the last column data ends with a '\n'
                fout << row[row_size - 1] << endl;
            }
        }
        if (fin.eof())
            break;
    }
    if (found == 0)
    {
        cout << "Record not found!" << endl;
    }

    fin.close();
    fout.close();

    // removing the existing file
    remove("storage.csv");
    // renaming the updated file with the existing file name
    rename("storagenew.csv", "storage.csv");
}

//function to print price and update stock of item
void c_update_record()
{

    // fout an object of class fstream
    fstream fin, fout;

    // Open an existing record
    fin.open("storage.csv", ios::in);

    // Create a new file to store updated data
    fout.open("storagenew.csv", ios::out);


    //declaring variables
    int bcnum, bc1, found = 0, i;
    int index, index_p;
    string line, word;
    vector<string> row;
    int noi2;
    int noi;
    int price;
    int price2;
    int size = 0;
    index = 2;
    index_p = 3;

    //using loop to get no of columns
    while (fin)
    {
        getline(fin, line);
        size++;
    }
    fin.close();
    fin.open("storage.csv", ios::in);



    // Get the barcode number from the user
    cout << "Enter the barcode number to transact: ";
    cin >> bcnum;

    // Get the data to be updated
    cout << "Enter the no of items you want to buy: ";
    cin >> noi2;

    for (int j = 0; j < size - 1; j++)
    {

        row.clear();

        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ','))
        {
            row.push_back(word);
        }

        bc1 = stoi(row[0]);
        int row_size = row.size();

        if (bc1 == bcnum)
        {
            found = 1;
            stringstream convert;

            noi = stoi(row[index]);
            price2 = stoi(row[index_p]);

            //updating by removing stock from storage
            noi = noi - noi2;
            
            if(noi == 0)
            {
            	cout<<" Out of stock";
			}
			else
			{
			
            //calculating price for the removed storage
            price = noi2 * price2;

            //printing the price
            cout << "The price is :" << price << "$" << endl;

            //turning updated stock to string and storing it to vector
            convert << noi;
            row[index] = convert.str();
            }

            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {

                    // write the updated data
                    // into a new file 'storagenew.csv'
                    // using fout
                    fout << row[i] << ",";
                }

                fout << row[row_size - 1] << endl;
            }
        }
        else {
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {

                    // writing other existing records
                    // into the new file using fout.
                    fout << row[i] << ",";
                }

                // the last column data ends with a '\n'
                fout << row[row_size - 1] << endl;
            }
        }
        if (fin.eof())
            break;
    }
    if (found == 0)
        cout << "Record not found!" << endl;

    fin.close();
    fout.close();

    // removing the existing file
    remove("storage.csv");
    // renaming the updated file with the existing file name
    rename("storagenew.csv", "storage.csv");
}

//function to remove an item from the inventory
void delete_record()
{

    // Open FIle pointers
    fstream fin, fout;

    // Open the existing file
    fin.open("storage.csv", ios::in);

    // Create a new file to store the non-deleted data
    fout.open("storagenew.csv", ios::out);

    int bcnum, bc1, marks, count = 0, i;
    char sub;
    int index;
    string line, word;
    vector<string> row;

    // Get the barcode number
    // to decide the data to be deleted
    cout << "Enter the barcode number: ";
    cin >> bcnum;
    cout << endl;

    // Check if this record exists
    // If exists, leave it and
    // add all other data to the new file
    while (!fin.eof()) 
    {

        row.clear();
        getline(fin, line);
        stringstream s(line);

        while (getline(s, word, ',')) 
        {
            row.push_back(word);
        }

        int row_size = row.size();
        bc1 = stoi(row[0]);

        // writing all records,
        // except the record to be deleted,
        // into the new file 'resultnew.csv'
        // using fout pointer
        if (bc1 != bcnum)
        {
            if (!fin.eof())
            {
                for (i = 0; i < row_size - 1; i++)
                {
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << endl;
            }
        }
        else {
            count = 1;
        }
        if (fin.eof())
            break;
    }
    if (count == 1)
        cout << "Record deleted!" << endl;
    else
        cout << "Record not found!" << endl;

    // Close the files
    fin.close();
    fout.close();

    // removing the existing file
    remove("storage.csv");

    // renaming the new file with the existing file name
    rename("storagenew.csv", "storage.csv");
}

int main()
{
	cout << "*******WELCOME TO THE DEPARTMENTAL STORE SYSTEM*********** " << endl;
    int opt_r;
    int exit = 1;
    
    //function to show inventory of items
    showrecs();
    
    do
    {
    	cout << endl;
        cout << "Press 1 to create a record of an item (For manager only)" << endl;
        cout << "Press 2 to read a display details of an item " << endl;
        cout << "Press 3 to change record of an item (For manager only)" << endl;
        cout << "Press 4 to transact an item (For customer only)" << endl;
        cout << "Press 5 to delete a record of an item (For manager only)" << endl;
        cin >> opt_r;
        if (opt_r == 1)
        {
            create();
        }
        else if (opt_r == 2)
        {
            read_record();
        }
        else if (opt_r == 3)
        {
            m_update_record();
        }
        else if (opt_r == 4)
        {
            c_update_record();
        }
        else if (opt_r == 5)
        {
            delete_record();
        }
        else
        {
            cout << "Wrong input!!" << endl;
        }
        cout << "Do you want to continue? {If yes press 1 ,if not press 0}" << endl;
        cin >> exit;

    } while (exit != 0);

    cout << "The system has closed";

    return 0;
}
