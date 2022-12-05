#include <iostream>

using namespace std;

int main()
{
    double pointIn = 0;
    double pointTotal = 10000000;

    for(int i = 0; i < pointTotal; ++i)
    {
        double pointX = ((rand() / (double)RAND_MAX) * 2) -1;
        double pointY = ((rand() / (double)RAND_MAX) * 2) -1;
    
        if((pointX * pointX + pointY * pointY) <= 1)
        {
            pointIn += 1.0;
        }    
    }

    double pi = (pointIn/pointTotal) * 4;
    cout << pi << endl;

    return 0;
}