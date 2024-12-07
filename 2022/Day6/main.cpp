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
    char cur;
    string cur_string;
    ifstream myfile;
    int count = 0;
    myfile.open("input.txt");
    while(myfile.good() && myfile >> cur)
    {
        count++;
        for(int i = 0; i < cur_string.size(); i++)
        {
            if(cur_string[i] == cur)
            {
                cur_string.clear();
                break;
            }
        }
        cur_string.push_back(cur);
        if(cur_string.size() == 14)
        {
            break;
        }
    }

    cout << "Count = " << count << endl;
    //close file
    myfile.close();

    return 0;
}
