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
    int val = 0, cur = 0;
    vector<int> max(3,0);
    string line;
    ifstream myfile;
    myfile.open("input.txt");
    while(myfile.good() && getline(myfile,line))
    {
        if(line != "")
        {
            stringstream ss(line);
            ss >> val;
            cur += val;
        }
        else
        {
            if(cur > max[2])
            {
                max[0] = max[1];
                max[1] = max[2];
                max[2] = cur;
            }
            else if(cur > max[1])
            {
                max[0] = max[1];
                max[1] = cur;
            }
            else if(cur > max[0])
                max[0] = cur;
            cur = 0;
        }
    }
    //close file
    myfile.close();
    int final = max[2] + max[1] + max[0];
    cout << "Max = " << final << endl;
    return 0;
}
