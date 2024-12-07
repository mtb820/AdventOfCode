 /*
 *  main.cpp
 *  Created on: December 1, 2024
 *  Author: Matthew Brunsman
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    //Set up the DataStorage Object
    cout << "RUNNING" << endl;
    vector<int> left, right;
    string line;
    ifstream myfile;
    int val, similarity = 0;
    myfile.open("input.txt");
    while(myfile.good() && getline(myfile,line))
    {
        //make a left and right vector
        if(line != "")
        {
            stringstream ss(line);
            ss >> val;
            left.push_back(val);
            ss >> val;
            right.push_back(val);
        }
    }
    //close file
    myfile.close();

    //find similar
    for(int i = 0; i < left.size(); i++)
    {
        int count = 0;
        for(int j = 0; j < right.size(); j++)
        {
            if(left[i] == right[j])
                count++;
        }
        similarity += left[i]*count;
    }

    //print and end
    cout << "similarity = " << similarity << endl;
    cout << "DONE" << endl;
    return 0;
}