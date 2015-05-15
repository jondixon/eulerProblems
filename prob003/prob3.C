#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define BIGNUM 600851475143

vector<unsigned long long int> primes;

bool isPrime( unsigned long long int numToCheck );
vector<int> findPrimeFactors(unsigned long long int numToCheck);


int main()
{
    

    primes.push_back( 2 );


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
            primes.push_back( i );

            if( primes.size() == 10001 ) break;
        }

    }

    vector<int> finalResult = findPrimeFactors( BIGNUM );
    sort( finalResult.begin(), finalResult.end() );
    cout << "RESULT: " << finalResult[finalResult.size() - 1] << endl; 

}

vector<int> findPrimeFactors(unsigned long long int numToCheck)
{
    if( isPrime(numToCheck) )
    {
        vector<int> retVal;
        retVal.push_back(numToCheck);
        return retVal;
    }
    else
    {
        for( auto &primeVal : primes )
        {
            if( numToCheck % primeVal == 0 )
            {
                vector<int> retVal, valueReceived;
                retVal.push_back(primeVal);
                valueReceived = findPrimeFactors( numToCheck/primeVal );
                retVal.insert( retVal.end(), valueReceived.begin(), valueReceived.end() );
                return retVal;            
            } 
        }
    }
}

bool isPrime( unsigned long long int numToCheck )
{
    vector<int>::iterator it;

   // it = find(primes.begin(), primes.end(), numToCheck);

    if( find( primes.begin(), primes.end(), numToCheck)  != primes.end() )
        return true;

    return false;
}

