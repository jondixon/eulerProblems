#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    unsigned long long int sumOfSquares = 0;
    unsigned long long int squareOfSums = 0;

    for( int i = 1; i <= 100; i++ )
    {
        squareOfSums += i;
        sumOfSquares += pow(i, 2);
    }

    squareOfSums *= squareOfSums;

    cout << "Sum of Squares: " << sumOfSquares << endl;
    cout << "Square of Sums: " << squareOfSums << endl;
    cout << "Result: " << squareOfSums - sumOfSquares  << endl;
}