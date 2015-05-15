#include <iostream>

using namespace std;

int main()
{
    int num1 = 1, num2 = 2, num3;

    long long int sum = 2;

    while( num1 < 4000000 && num2 < 4000000 && num3 < 4000000 )
    {
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
 
        cout << num3 << " ";

        if( num3 % 2 == 0 ) sum += num3;
    }

    cout << "\nSUM: " << sum << endl;
}
