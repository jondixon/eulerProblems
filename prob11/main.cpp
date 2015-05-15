#include <iostream>
#include <fstream>

using namespace std;

#define GRIDSIZE 20

int ** readFile( ifstream &fin );
int findMaxRows( int** grid );
int findMaxCols( int** grid );
int findMaxDR( int** grid );
int findMaxDL( int** grid );
int findMax( int** grid );


int main( )
{
    ifstream fin;

    fin.open("grid.txt");

    if( !fin )
    {
        cout << "Couldn't open file" << endl;
        return 0;
    }


    int** grid = readFile( fin );

    int max = findMax( grid );

    cout << "MAX: " << max << endl;
}

//********************//
//FUNCTION DEFINITIONS//
//********************//
int ** readFile( ifstream &fin )
{
    int** grid = new int*[GRIDSIZE];

    for( int i = 0; i < GRIDSIZE; i++ )
        grid[i] = new int[GRIDSIZE];

    for( int i = 0; i < GRIDSIZE; i++ )
    {
        for( int j = 0; j < GRIDSIZE; j++ )
        {
            fin >> grid[i][j];
        }
    }

    return grid;
}

int findMax( int** grid )
{
    int max1 = findMaxRows( grid );
    int max2 = findMaxCols( grid );
    int max3 = findMaxDR( grid );
    int max4 = findMaxDL( grid );

    max1 = max(max1, max2);
    max2 = max(max3, max4);

    return max(max1, max2);

}

int findMaxRows( int** grid )
{
    int max = 0;

    for( int x = 0; x < GRIDSIZE; x++ )
    {
        for( int y1 = 0; y1 < GRIDSIZE-3; y1++ )
        {
            int y2 = y1 + 1;
            int y3 = y1 + 2;
            int y4 = y1 + 3;

            int result = grid[x][y1] *
                         grid[x][y2] *
                         grid[x][y3] *
                         grid[x][y4];

            if( result > max )
                max = result;
        }
    }

    return max;
}

int findMaxCols( int** grid )
{
    int max = 0;

    for( int y = 0; y < GRIDSIZE; y++ )
    {
        for( int x1 = 0; x1 < GRIDSIZE-3; x1++ )
        {
            int x2 = x1 + 1;
            int x3 = x1 + 2;
            int x4 = x1 + 3;

            int result = grid[y][x1] *
                         grid[y][x2] *
                         grid[y][x3] *
                         grid[y][x4];

            if( result > max )
                max = result;
        }
    }

    return max;
}

int findMaxDR( int** grid )
{
    int max = 0;

    for( int x1 = 0; x1 < GRIDSIZE - 3; x1++ )
    {
        for( int y1 = 0; y1 < GRIDSIZE - 3; y1++ )
        {
            int x2 = x1 + 1;
            int y2 = y1 + 1;

            int x3 = x1 + 2;
            int y3 = y1 + 2;

            int x4 = x1 + 3;
            int y4 = y1 + 3;

            int result = grid[x1][y1] *
                         grid[x2][y2] *
                         grid[x3][y3] *
                         grid[x4][y4];

            if( result > max )
                max = result;
        }
    }

    return max;
}

int findMaxDL( int** grid )
{
    int max = 0;

    for( int x1 = 0; x1 < GRIDSIZE-3; x1++ )
    {
        for( int y1 = 3; y1 < GRIDSIZE; y1++ )
        {
            int x2 = x1 + 1;
            int y2 = y1 - 1;

            int x3 = x1 + 2;
            int y3 = y1 - 2;

            int x4 = x1 + 3;
            int y4 = y1 - 3;

            int result = grid[x1][y1] *
                         grid[x2][y2] *
                         grid[x3][y3] *
                         grid[x4][y4];

            if( result > max )
                max = result;
        }
    }

    return max;
}

