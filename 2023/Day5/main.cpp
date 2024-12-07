 /*
 *  main.cpp
 *  Created on: November 30, 2022
 *  Author: Matthew Brunsman
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    //Set up the DataStorage Object
    cout << "RUNNING" << endl;
    vector<string> containers;
    containers.push_back("FDBZTJRN");
    containers.push_back("RSNJH");
    containers.push_back("CRNJGZFQ");
    containers.push_back("FVNGRTQ");
    containers.push_back("LTQF");
    containers.push_back("QCWZBRGN");
    containers.push_back("FCLSNHM");
    containers.push_back("DNQMTJ");
    containers.push_back("PGS");
    string useless;
    int amount, source, dest;
    ifstream myfile;
    myfile.open("input.txt");
    while(myfile.good() && myfile >> useless)
    {
        myfile >> amount;
        myfile >> useless;
        myfile >> source;
        myfile >> useless;
        myfile >> dest;
        for(int i = 0; i < amount; i++)
        {
            containers[dest - 1].push_back(containers[source - 1][containers[source - 1].size() - amount + i]);
        }
        
        for(int j = 0; j < amount; j++)
        {
            containers[source - 1].pop_back();
        }
    }
    for(int j = 0; j < containers.size(); j++)
    {
        cout << "Containter " << j << " = " << containers[j] << endl;
    }
    //close file
    myfile.close();

    return 0;
}
