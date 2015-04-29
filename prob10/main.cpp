#include <iostream>
#include <vector>

using namespace std;

int main( )
{
    vector<int> primes;

    primes.push_back( 2 );

    unsigned long long int primeSum = 0;


    for ( unsigned long long int i = 3; i > 0; i++ )
    {
        bool prime = true;

        if( i % 2 == 0 )
            prime = false;

        else
        {
            for ( unsigned long long int j = 0; j < primes.size() - 1; j++ )
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
            }


            if( i > 2000000 )
            {
                primes.pop_back();
                break;
            }
        }

    }

    cout << "SUM: " << primeSum << endl;
}