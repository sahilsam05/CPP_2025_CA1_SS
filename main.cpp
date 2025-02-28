#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

struct Stock
{
    string name;
    string category;
    int yearFounded;
    double moneyInvested;
    double returnValue;
};

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

void displayStocks(const vector<Stock>& stocks)
{
    cout << left << setw(20) << "Name"
       << setw(20) << "Category"
       << setw(15) << "Year Founded"
       << setw(15) << "Money Invested"
       << setw(15) << "Return Value" << endl;
    cout << string(80, '-') << endl;

    for (const auto& stock : stocks) {
        cout << "Name: " << stock.name << "\n"
             << "Category: " << stock.category << "\n"
             << "Year Founded: " << stock.yearFounded << "\n"
             << "Money Invested: " << stock.moneyInvested << "\n"
             << "Return: " << stock.returnValue << "\n\n";
    }
}

int main()
{
    vector<Stock> stocks;
    readCSV("Stocks.csv", stocks);
    displayStocks(stocks);
    return 0;
}