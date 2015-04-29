#include <iostream>
#include <vector>

using namespace std;

int main( )
{

    vector<unsigned long long int> primes;

    primes.push_back( 3 );


    for ( unsigned long long int i = 2; i > 0; i++ )
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
            primes.push_back( i );

            if( primes.size() % 100 == 0 )
                cout << primes.size() << " Primes Found" << endl;

            if( primes.size() == 10001 ) break;
        }

    }


    cout << primes[primes.size() - 1] << endl;
}