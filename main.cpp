#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Stage 1 - Data Generated
// Stage 2 part 1 struct created

struct Stock
{
    string name;
    string category;
    int yearFounded;
    double moneyInvested;
    double returnValue;
};

// Stage 2 part 2 Read the CSV File

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
    if (index == -1) {
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
int findStockByName(const vector<Stock>& stocks, const string& name)
{
    for (size_t i = 0; i < stocks.size(); i++)
    {
        if (stocks[i].name == name)
            return i;
    }
    return -1;
}

int main()
{
    vector<Stock> stocks;
    readCSV("Stocks.csv", stocks);

    string Searchstock;
    cout << "Enter search stock name: ";
    getline(cin, Searchstock);

    int stockIndex = findStockByName(stocks, Searchstock);

    displayStocks(stocks, stockIndex);


    return 0;
}