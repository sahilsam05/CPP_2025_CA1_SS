#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Stage 1 - Data Generated
// Stage 2 part 1 struct created

// reference notes
// https://github.com/delboy8080/FileIO_Struct_SD2a/blob/master/main.cpp


struct Stock
{
    string name;
    string category;
    int yearFounded;
    double moneyInvested;
    double returnValue;
};

// Stage 2 part 2 Read the CSV File

// Reference
// https://github.com/delboy8080/FileIO_Struct_SD2a/blob/master/main.cpp


void readCSV(const string& filename, vector<Stock>& stocks)
{
    ifstream file(filename);
    string line;

    // Skip the header line
    getline(file, line);

    while (getline(file, line))
        {
        stringstream ss(line);
        string temp; // Declaring a temporary string variable
        Stock stock;

        // Read each column
        getline(ss, stock.name, ',');
        getline(ss, stock.category, ',');
        getline(ss, temp, ',');
        stock.yearFounded = stoi(temp);
        getline(ss, temp, ',');
        stock.moneyInvested = stod(temp);
        getline(ss, temp, ',');
        stock.returnValue = stod(temp);

        stocks.push_back(stock); //After push_back(stock) is called:

       // The stock object is added to the stocks vector.
       // The stocks vector now contains one Stock object.
    }
}

// Stage 3 -  part 1 display the functions neatly
// used a vector
// implemented a function to populate vector

void displayStocks(const vector<Stock>& stocks, int index = -1)
{
    if (index == -1)
    {
        cout << left << setw(35) << "Name"
       << setw(20) << "Category"
       << setw(15) << "Year Founded"
       << setw(18) << "Money Invested"
       << setw(15) << "ROI" << endl;
        cout << string(103, '-') << endl;


        for (int i = 0; i < stocks.size(); i++)
        {
            cout << left << setw(35) << stocks[i].name
                 << setw(20) << stocks[i].category
                 << setw(15) << stocks[i].yearFounded
                 << setw(18) << fixed << setprecision(2) << stocks[i].moneyInvested
                 << setw(15) << fixed << setprecision(2) << stocks[i].returnValue << endl;
        }
    }
    else if (index >= 0 && index < stocks.size())
    {
        cout << left << setw(35) << "Name"
       << setw(20) << "Category"
       << setw(15) << "Year Founded"
       << setw(18) << "Money Invested"
       << setw(15) << "ROI" << endl;
        cout << string(103, '-') << endl;

       const Stock& stock = stocks[index];
        cout << left << setw(35) << stock.name
              << setw(20) << stock.category
              << setw(15) << stock.yearFounded
              << setw(18) << fixed << setprecision(2) << stock.moneyInvested
              << setw(15) << fixed << setprecision(2) << stock.returnValue << endl;
    }
    else
    {
        cout << "STOCK NOT FOUND" << endl;
    }
}

// Stage 3 - Search Function

// Reference
// https://github.com/logued/cpp-sam205/blob/master/main.cpp
// https://github.com/delboy8080/STL_Exercises/blob/master/Solutions.cpp

int findStockByName(const vector<Stock>& stocks, const string& name)
{
    for (int i = 0; i < stocks.size(); i++)
    {
        if (stocks[i].name == name)
            return i;
    }
    return -1;
}

// Stage 3 - part 3 category
// https://github.com/delboy8080/STL_Exercises/blob/master/Solutions.cpp

// map<string, int> findStockByCategory(const vector<Stock>& stocks)
// {
//     map<string, int> categoryCount;
//     for (auto& stock : stocks)
//     {
//         categoryCount[stock.category]++;
//     }
//     return categoryCount;
// }

// https://stackoverflow.com/questions/40617450/highest-and-lowest-average-c

// Stage 3 - part 5

int findStats(const vector<Stock>& stocks, Stock& highest, Stock& lowest)
{
    if (stocks.empty())
    {
        cout << "No data available.\n";
        return -1; // Indicate that no data is present
    }

    highest = stocks[0];
    lowest = stocks[0];
    int sum = 0;

    for (int i = 0; i < stocks.size(); i++)
    {
        sum += stocks[i].yearFounded;

        if (stocks[i].yearFounded > highest.yearFounded)
            highest = stocks[i];

        if (stocks[i].yearFounded < lowest.yearFounded)
            lowest = stocks[i];
    }

    return sum / stocks.size(); // Return average as int
}

// Stage 3 part 7

// Reference
// https://github.com/delboy8080/STL_Exercises/blob/master/Solutions.cpp
// Q5


// Function to display a subset of data (stocks by category)

void displayStocksByCategory(const vector<Stock>& stocks, const string& category)
{
    cout << left << setw(35) << "Name"
         << setw(20) << "Category"
         << setw(15) << "Year Founded"
         << setw(18) << "Money Invested"
         << setw(15) << "ROI" << endl;
    cout << string(103, '-') << endl;

    // Loop through stocks and print those that match the category
    for (int i = 0; i < stocks.size(); i++)
    {
        if (stocks[i].category == category)
        {
            cout << left << setw(35) << stocks[i].name
                 << setw(20) << stocks[i].category
                 << setw(15) << stocks[i].yearFounded
                 << setw(18) << fixed << setprecision(2) << stocks[i].moneyInvested
                 << setw(15) << fixed << setprecision(2) << stocks[i].returnValue << endl;
        }
    }
}


// Function to display menu

void displayMenu()
{
    cout << "\nStock Management System\n";
    cout << "1. Display all stocks\n";
    cout << "2. Search for a stock by name\n";
    cout << "3. Display stocks by category\n";
    cout << "4. Find highest, lowest, and average year founded\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}


int main()
{
    vector<Stock> stocks;
    readCSV("Stocks.csv", stocks);

    // https://cplusplus.com/forum/beginner/21033/

    int choice;
    do
    {
        displayMenu();

        cin >> choice;
        cin.ignore(); // Clear input buffer
        //  cin.ignore() tells the input stream to ignore (or discard) one character from the input buffer.
        //  By default, it discards one character, which is usually the newline character ('\n'),
        //  and clears the buffer for the next input operation.
        //  This prevents the newline from interfering with subsequent inputs.
        if (choice == 1)
        {
            displayStocks(stocks);
        }
        else if (choice == 2)
        {
            string searchName;
            cout << "Enter stock name: ";
            getline(cin, searchName);

            int index = findStockByName(stocks, searchName);
            displayStocks(stocks, index);
        }
        else if (choice == 3)
        {
            string category;
            cout << "Enter category to search for: ";
            getline(cin, category);
            displayStocksByCategory(stocks, category);
        }
        else if (choice == 4)
        {
            Stock highest, lowest;
            int avgYear = findStats(stocks, highest, lowest);

            if (avgYear != -1)
            {
                cout << "\nStock Year Statistics:\n";
                cout << "Average Year Founded: " << avgYear << endl;
                cout << "Oldest Company: " << lowest.name << " (Founded: " << lowest.yearFounded << ")\n";
                cout << "Newest Company: " << highest.name << " (Founded: " << highest.yearFounded << ")\n";
            }
        }
        else if (choice == 5)
        {
            cout << "Exiting program. Goodbye!\n";
        }
        else
        {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}