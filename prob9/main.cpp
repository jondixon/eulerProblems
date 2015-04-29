#include <iostream>
#include <math.h>

using namespace std;

int findC( int a, int b );


int main( )
{


    for( int a = 1; a < 1000; a++ )
    {
        for( int b = 0; b < 1000 - a; b++ )
        {
            int c = findC( a, b );

            if( c > 0 && (a + b + c) == 1000 )
            {
                cout << "SOLUTION FOUND: " << a*b*c << endl;
                return 0;
            }

        }
    }
}

int findC( int a, int b )
{
    int lhs = a*a + b*b;

    if( floor(sqrt(lhs)) == sqrt(lhs) )
    {
        return sqrt(lhs);
    }
    else
        return -1;
}