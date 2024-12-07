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
    //Set up objects
    cout << "RUNNING" << endl;
    vector<int> left, right;
    string line;
    ifstream myfile;
    int val, distance = 0, similarity = 0;
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

    //sort vectors
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    //find distance
    for(int i = 0; i < left.size(); i++)
    {
        distance += abs(left[i] - right[i]);
        int count = 0;
        //find similarity
        for(int j = 0; j < right.size(); j++)
        {
            if(left[i] == right[j])
                count++;
        }
        similarity += left[i]*count;
    }

    //print results
    cout << "distance = " << distance << endl;
    cout << "similarity = " << similarity << endl;
    cout << "DONE" << endl;
    return 0;
}
