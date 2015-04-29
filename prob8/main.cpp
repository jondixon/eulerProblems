#include <iostream>
#include <fstream>

using namespace std;

int main( )
{
    ifstream fin;

    fin.open("longNum.txt");

    if( !fin )
    {
        cout << "DID NOT OPEN FILE " << endl;
        return(0);
    }

    string longNum;

    fin >> longNum;


    long long int maxProduct = 0;


    for( int i = 0; i < 1000 - 5; i++ )
    {
        long long int currentProduct = 1;

        for( int j = i; j < i + 4; j++ )
        {
            cout << "j: " << j << " i: " << i << endl;
            currentProduct *= (longNum[i] - '0');
        }

        if( currentProduct > maxProduct )
        {
            maxProduct = currentProduct;
            cout << "NEW MAX: " << maxProduct << endl;
        }
    }

    cout << "MAX: " << maxProduct << endl;

    fin.close();
}