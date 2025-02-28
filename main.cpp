#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>

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
        string token;
        Stock stock;

        // Read each column
        getline(ss, stock.name, ',');
        getline(ss, stock.category, ',');
        getline(ss, token, ',');
        stock.yearFounded = stoi(token);
        getline(ss, token, ',');
        stock.moneyInvested = stod(token);
        getline(ss, token, ',');
        stock.returnValue = stod(token);

        stocks.push_back(stock);
    }
}

// Stage 3 -  part 1 display the functions neatly

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


        for (const auto& stock : stocks)
        {
            cout << left << setw(35) << stock.name
                 << setw(20) << stock.category
                 << setw(15) << stock.yearFounded
                 << setw(18) << fixed << setprecision(2) << stock.moneyInvested
                 << setw(15) << fixed << setprecision(2) << stock.returnValue << endl;
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
    for (size_t i = 0; i < stocks.size(); i++)
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

    for (const auto& stock : stocks)
    {
        sum += stock.yearFounded;

        if (stock.yearFounded > highest.yearFounded)
            highest = stock;

        if (stock.yearFounded < lowest.yearFounded)
            lowest = stock;
    }

    return sum / stocks.size(); // Return average as int
}



int main()
{
    vector<Stock> stocks;
    readCSV("Stocks.csv", stocks);

    string Searchstock;
    cout << "Enter search stock name: ";
    getline(cin, Searchstock);

    int stockIndex = findStockByName(stocks, Searchstock);  // Search for stock by name

    displayStocks(stocks, stockIndex);

    // // Count the occurrences of each category
    // map<string, int> categoryCount = findStockByCategory(stocks);
    //
    // // Display the category counts
    // cout << "\nCategory counts:" << endl;
    // for (const auto& entry : categoryCount)
    // {
    //     cout << entry.first << ": " << entry.second << endl;
    // }
    //
    // return 0;

    Stock highestStock, lowestStock;
    int averageYear = findStats(stocks, highestStock, lowestStock);

    if (averageYear != -1) // Ensure data exists
    {
        cout << "\nStock Year Statistics:\n";
        cout << "Average Year Founded: " << averageYear << endl;

        cout << "\nOldest Company:\n";
        cout << "Name: " << lowestStock.name << " | Year Founded: " << lowestStock.yearFounded << endl;

        cout << "\nNewest Company:\n";
        cout << "Name: " << highestStock.name << " | Year Founded: " << highestStock.yearFounded << endl;
    }


}