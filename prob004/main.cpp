#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome( int numToCheck );

int main()
{
    vector<unsigned long long int> mulNums;

    for( int i = 998; i > 100; i-- )
    {
        for( int j = 998; j > 100; j--)
        {
            unsigned long long int x = i * j;

            if( isPalindrome( x ) )
                mulNums.push_back( x );
        }
    }

    sort( mulNums.begin(), mulNums.end() );

    cout << "Largest Palindrome: " << mulNums[mulNums.size() - 1] << endl;

}

bool isPalindrome( int numToCheck )
{
    string number = to_string(numToCheck);

    int i = 0, j = number.size() - 1;
    for( ; i < number.size()/2; i++, j-- )
        if( number[i] != number[j] )
            return false;

    return true;
}