#include <iostream>

using namespace std;

int totalSum = 0;

int main()
{
    for( int i = 0; i < 1000; i++ )
    {
        if( i % 3 == 0 || i % 5 == 0 )
            totalSum += i;
    }

    cout << "Total: " << totalSum << endl;
}
