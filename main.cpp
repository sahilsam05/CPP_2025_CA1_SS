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

void load(string filename, vector<Stocks> &data)
{
    ifstream file(filename);

    if (file)
        {
         string line;
        while (getline(file, line))
            {
            Stocks stock;
            parseLine(line, stock);
            data.push_back(stock);
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

void writeToFile(const vector<Stocks> &data)
{

}




int main()
{
    }

