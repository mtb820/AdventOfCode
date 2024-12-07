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

    for(int i = 0; i < puzzle.size(); i++)
    {
        for(int j = 0; j < puzzle[i].size(); j++)
        {
            if(puzzle[i].at(j) == 'X')
            {
                //check right
                if(j < puzzle[i].size()-3)                    
                {
                    if(puzzle[i].at(j+1) == 'M' && puzzle[i].at(j+2) == 'A' && puzzle[i].at(j+3) == 'S')
                    {
                        count++;
                    }
                }
                //check left
                if(j > 2)
                {
                    if(puzzle[i].at(j-1) == 'M' && puzzle[i].at(j-2) == 'A' && puzzle[i].at(j-3) == 'S')
                    {
                        count++;
                    }
                }
                //check all up configurations
                if(i > 2)
                {
                    //straight up
                    if(puzzle[i-1].at(j) == 'M' && puzzle[i-2].at(j) == 'A' && puzzle[i-3].at(j) == 'S')
                    {
                        count++;
                    }
                    //up and left
                    if(j > 2)
                    {
                        if(puzzle[i-1].at(j-1) == 'M' && puzzle[i-2].at(j-2) == 'A' && puzzle[i-3].at(j-3) == 'S')
                        {
                            count++;
                        }
                    }
                    //up and right
                    if(j < puzzle[i].size()-3)
                    {
                        if(puzzle[i-1].at(j+1) == 'M' && puzzle[i-2].at(j+2) == 'A' && puzzle[i-3].at(j+3) == 'S')
                        {
                            count++;
                        }
                    }
                }
                //check all down configurations
                if(i < puzzle.size()-3)
                {
                    //straight down
                    if(puzzle[i+1].at(j) == 'M' && puzzle[i+2].at(j) == 'A' && puzzle[i+3].at(j) == 'S')
                    {
                        count++;
                    }
                    //down and left
                    if(j > 2)
                    {
                        if(puzzle[i+1].at(j-1) == 'M' && puzzle[i+2].at(j-2) == 'A' && puzzle[i+3].at(j-3) == 'S')
                        {
                            count++;
                        }
                    }
                    //down and right
                    if(j < puzzle[i].size()-3)
                    {
                        if(puzzle[i+1].at(j+1) == 'M' && puzzle[i+2].at(j+2) == 'A' && puzzle[i+3].at(j+3) == 'S')
                        {
                            count++;
                        }
                    }
                }
            }
        }
    }

    //print results
    cout << "total XMAS = " << count << endl;
    cout << "DONE" << endl;
    return 0;
}
