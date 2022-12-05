#include <iostream>

using namespace std;

int main()
{
    int tries = 1000; 
    int minutesTable[tries];

    //assign 0 to all integers in array
    for(int i = 0; i < tries; ++i)
    {
        minutesTable[i] = 0;
    }

    for(int i = 0; i < tries; ++i)
    {        
        bool escapeStatus = false; //true: escaped; false: stuck;
        int minutesCount = 0;
    
        while (escapeStatus == false)
        {
            int tunnelId = rand() % 3;
            int tunnel = tunnelId + 1;

            if(tunnel == 1)
            {
                escapeStatus = true;
                ++minutesCount;
            }
            else
            {
                escapeStatus = false;
                ++minutesCount;
            }
        }

        minutesTable[i] = minutesCount;
    }

    double average = 0;

    for (int i = 0; i < tries; ++i)
    {
        average = average + minutesTable[i];
    }
    
    average = average / tries;
    
    for(int i = 0; i < tries; ++i)
    {
        cout << i << " " <<  minutesTable[i] << endl;
    }

    cout << "Average: " << average << endl;

    return 0;
}