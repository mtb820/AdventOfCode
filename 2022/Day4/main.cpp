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
    int first1, first2, last1, last2;
    char useless;
    int count = 0;
    ifstream myfile;
    myfile.open("input.txt");
    while(myfile.good() && myfile >> first1)
    {
        myfile >> useless;
        myfile >> last1;
        myfile >> useless;
        myfile >> first2;
        myfile >> useless;
        myfile >> last2;
        if(first1 > first2)
        {
            if(first1 <= last2)
            {
                count++;
            }
        }
        else if(first1 < first2)
        {
            if(first2 <= last1)
            {
                count++;
            }
        }
        else
        {
            count++;
        }
    }
    cout << "Count = " << count << endl;
    //close file
    myfile.close();

    return 0;
}
