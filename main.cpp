#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


// reference notes
// https://github.com/delboy8080/FileIO_Struct_SD2a/blob/master/main.cpp

struct Stocks
{
    string name;
    string category;
    int yearFounded;
    float moneyInvested;
    float returnOnInvestment;
};

void displayStocks(const vector<Stocks>& stockList)
{
    cout << left << setw(25) << "Stock Name"
         << setw(15) << "Category"
         << setw(15) << "Year Founded"
         << setw(20) << "Money Invested"
         << setw(15) << "ROI" << endl;
    cout << string(90, '-') << endl;
}

void parseLine(string line,Stocks &stocks) {
    stringstream ss(line);
    getline(ss, stocks.name, ',');
    getline(ss, stocks.category, ',');
    stocks.yearFounded = stoi(stocks.name);
    stocks.moneyInvested = stoi(stocks.category);
    stocks.returnOnInvestment = stoi(stocks.name);

}

//https://github.com/delboy8080/FileIO_Struct_SD2a/blob/master/main.cpp

// Function to read CSV file and store data in a vector
void readCSV(const string& filename, vector<Stocks>& stockList)
{
    ifstream file(filename);
    if (file)
    {
        string line;
        while (getline(file, line))
            {
                Stocks stock;
            parseLine(line, stock);
            stockList.push_back(stock);
        }
        file.close();
    }
    else
    {
        cout << "File could not be opened" << endl;
    }
}

int searchStockByName(const vector<Stocks>& stockList,const string& name)
{
    for (int i = 0; i < stockList.size(); i++)
        {
        if (stockList[i].name == name)
            return i;
    }
}



int main()
{

    vector<Stocks> stockList;
    readCSV("Stocks.csv", stockList);
    displayStocks(stockList);
    return 0;

}

