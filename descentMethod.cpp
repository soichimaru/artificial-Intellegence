#include <iostream>

using namespace std;

double function(double x, double y)
{
    return x * x + y * y - 4 * x - 6 * y + 14;
}

int main()
{
    double x = 0.0;
    double y = 0.0;

    double epsilon = 1e-10;
    double lambda = 0.1;

    //update x, y;
    for(int i = 0; i < 100; ++i)
    {
        x -= (function(x + epsilon, y) - function(x - epsilon, y)) / (2 * epsilon) * lambda;
        y -= (function(x, y + epsilon) - function(x, y - epsilon)) / (2 * epsilon) * lambda;

        cout << x << "," << y << "," << function(x,y) << endl;
    }

    return 0; 
}