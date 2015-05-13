#include <iostream>
#include <vector>

using namespace std;

int main( )
{
    vector<unsigned long long> primes;

    primes.push_back( 2 );

    unsigned long long  primeSum = 2;


    for ( unsigned long long  i = 3; i > 0; i++ )
    {
        bool prime = true;

        if( i % 2 == 0 )
            prime = false;

        else
        {
            for ( unsigned long long  j = 0; j < primes.size() - 1; j++ )
            {
                if( i % primes[j] == 0 )
                {
                    prime = false;
                    break;
                }
            }
        }

        if( prime )
        {
            if( i < 2000000 )
            {
                primes.push_back( i );
                primeSum += i;
                cout << i << endl;
            }


            if( i > 2000000 )
            {
                break;
            }
        }

    }


    cout << "\nSUM: " << primeSum << endl;
}