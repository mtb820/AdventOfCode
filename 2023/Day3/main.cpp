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
    vector<char> matches;
    string line,line2,line3;
    bool found = false;
    ifstream myfile;
    myfile.open("input.txt");
    while(myfile.good() && getline(myfile,line))
    {
        getline(myfile,line2);
        getline(myfile,line3);
        found = false;
        for(int i = 0; i < line.size(); i++)
        {
            for(int j = 0; j < line2.size(); j++)
            {
                if(line[i] == line2[j])
                {
                    for(int k = 0; k < line3.size(); k++)
                    {
                        if(line3[k] == line[i])
                        {
                            found = true;
                            matches.push_back(line[i]);
                            break;
                        }
                    }
                    if(found)
                    {
                        break;
                    }
                }
            }
            if(found)
            {
                break;
            }
        }
    }
    //close file
    myfile.close();
    int final = 0;
    for(int i = 0; i < matches.size(); i++)
    {
        if(isupper(matches[i]))
        {
            final += matches[i] - 38;
        }
        else
        {
            final += matches[i] - 96;
        }
    }
    cout << "final = " << final << endl;
    return 0;
}
