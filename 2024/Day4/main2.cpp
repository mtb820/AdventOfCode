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
#include <iterator>

using namespace std;

int main()
{
    //Set up objects
    cout << "RUNNING" << endl;
    string line;
    ifstream myfile;
    int count = 0;
    vector<string> puzzle;
    myfile.open("input.txt");
    while(myfile.good() && getline(myfile,line))
    {
        puzzle.push_back(line);
    }
    //close file
    myfile.close();

    for(int i = 1; i < puzzle.size()-1; i++)
    {
        for(int j = 1; j < puzzle[i].size()-1; j++)
        {
            if(puzzle[i].at(j) == 'A')
            {
                //Ms on left
                if(puzzle[i-1].at(j-1) == 'M' && puzzle[i+1].at(j-1) == 'M' && puzzle[i-1].at(j+1) == 'S' && puzzle[i+1].at(j+1) == 'S')
                {
                    count++;
                }
                //Ms on right
                if(puzzle[i-1].at(j-1) == 'S' && puzzle[i+1].at(j-1) == 'S' && puzzle[i-1].at(j+1) == 'M' && puzzle[i+1].at(j+1) == 'M')
                {
                    count++;
                }
                //Ms on bottom
                if(puzzle[i-1].at(j-1) == 'S' && puzzle[i+1].at(j-1) == 'M' && puzzle[i-1].at(j+1) == 'S' && puzzle[i+1].at(j+1) == 'M')
                {
                    count++;
                }
                //Ms on top
                if(puzzle[i-1].at(j-1) == 'M' && puzzle[i+1].at(j-1) == 'S' && puzzle[i-1].at(j+1) == 'M' && puzzle[i+1].at(j+1) == 'S')
                {
                    count++;
                }
            }
        }
    }

    //print results
    cout << "total cross MAS = " << count << endl;
    cout << "DONE" << endl;
    return 0;
}
