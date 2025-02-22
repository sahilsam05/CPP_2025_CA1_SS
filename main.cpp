#include <iomanip>
#include <iostream>

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

void display(const Stocks& stocks)
{
    cout << left << setw(15) << stocks.name;
    cout << setw(5) << stocks.category;
    cout << setw(10) << stocks.yearFounded;
    cout << setw(50) << stocks.moneyInvested;
    cout << setw(30) << stocks.returnOnInvestment;
    cout << endl;
}




int main()
{
    }

