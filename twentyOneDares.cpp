#include <iostream>

using namespace std;

int main()
{
    double knowledgeTable[21][3];
    
    for(int i = 0; i < 21; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            knowledgeTable[i][j] = 0.0;
        }        
    }

    int episodes = 100000;
    for(int episodeId = 0; episodeId < episodes; ++episodeId)
    {
        int state = 20;
        double randratio = 1 - (double)episodeId / (double)episodes;
        while(state > 0)
        {
            //cout << "state=" << state << ",";//DEBUG
            double rand1 = (double)rand() / RAND_MAX;
            int actionId; //TODO careful not to choose action > state

            //cout << rand1 << ",";//DEBUG
            if(rand1 < randratio)
            {
                double rand2 = (double)rand() / RAND_MAX;
                actionId = (int)(rand2 * 3);
                actionId = min(actionId, state - 1);
            }
            else
            {
                double actionMax = knowledgeTable[state][0];
                int actionMaxId = 0;

                for(int j = 1; j < 3; ++j)
                {
                    if(knowledgeTable[state][j] > actionMax)
                    {
                        actionMaxId = j; 
                    }
                }
                actionId = min(actionMaxId, state - 1);
            }
            int stateOpp = state - (actionId + 1);
            int actionOpp = min(stateOpp, 1 + (int)((double)rand() / RAND_MAX * 3.0));
            if(stateOpp == 2 || stateOpp == 3)
            {
                actionOpp = stateOpp - 1;
            }
            int stateNext = stateOpp - actionOpp;
            //cout << "stateNext=" << stateNext << ",";//DEBUG

            //Update knowledgeTable


            double stateNextMax = knowledgeTable[stateNext][0];

            for(int j = 1; j < 3; ++j)
            {
                if(knowledgeTable[stateNext][j] > stateNextMax)
                {
                    stateNextMax = knowledgeTable[stateNext][j];
                }
            }

            double reward = 0.0;
            double learningSpeed = 0.95;
            double discount = 0.9;

            if(stateOpp == 1)
            {
                reward = 100;
            }
            if(stateNext == 1)
            {
                reward = -100;
            }

            double knowldgeNextState = discount * (reward + stateNextMax);
            knowledgeTable[state][actionId] = (1.0- learningSpeed) * knowledgeTable[state][actionId] + learningSpeed * knowldgeNextState;  

            state = stateNext;
        }
    }

    for(int i = 0; i < 21; ++i)
    {
        cout << "[" << i << "]=";
        for(int j = 0; j < 3; ++j)
        {
            cout << knowledgeTable[i][j] << ",";
        }   
        cout << endl;
    }
    cout << endl;     

    
    

    return 0;
}
