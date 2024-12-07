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
    int score = 0;
    char input, opponent;
    ifstream myfile;
    bool first = true;
    myfile.open("input.txt");
    while(myfile.good() && myfile >> input)
    {
        if(first)
        {
            opponent = input;
        }
        else
        {
            if(input == 'X')
            {
                if(opponent == 'A')
                    score += 3;
                else if(opponent == 'B')
                    score += 1;
                else
                    score += 2;
            }
            else if(input == 'Y')
            {
                if(opponent == 'A')
                    score += 4;
                else if(opponent == 'B')
                    score += 5;
                else
                    score += 6;
            }
            else if(input == 'Z')
            {
                if(opponent == 'A')
                    score += 8;
                else if(opponent == 'B')
                    score += 9;
                else
                    score += 7;
            }
            else
                cout << "BAD INPUT? = " << input <<  endl;
        }
        first = !first;
    }
    //close file
    myfile.close();
    cout << "Score = " << score << endl;
    return 0;
}
