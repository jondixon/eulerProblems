#include <iostream>
#include <fstream>

using namespace std;

int main( )
{
    ifstream fin;

    fin.open("longNum.txt");

    string longNum;

    fin >> longNum;

}