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
    string cur;
    bool run = true;
    size_t pos = 0, pos2 = 0, pos3 = 0;
    int first = 0, second = 0, product = 0;
    myfile.open("input.txt");
    while(myfile.good() && getline(myfile,line))
    {
        //take in a value
        if(line != "")
        {
            stringstream ss(line);
            while(ss >> cur)
            {
                pos = 0;
                pos2 = 0;
                pos3 = 0;
                while(pos != cur.npos || pos2 != cur.npos || pos3 != cur.npos)
                {
                    first = 0;
                    second = 0;
                    pos = cur.find("mul(");
                    pos2 = cur.find("do()");
                    pos3 = cur.find("don't()");
                    if(pos2 < pos && pos2 < pos3)
                    {
                        cur.erase(0, pos2+4);
                        run = true;
                    }
                    else if(pos3 < pos && pos3 < pos2)
                    {
                        cur.erase(0, pos3+7);
                        run = false;
                    }
                    else if(pos != cur.npos)
                    {
                        cur.erase(0,pos+4);
                        if(cur.size() >= 4 && run)
                        {
                            if(isdigit(cur[0]))
                            {
                                if(isdigit(cur[1]))
                                {
                                    if(isdigit(cur[2]) && cur[3] == ',')
                                    {
                                        first = ((cur[0]-'0')*100)+((cur[1]-'0')*10)+(cur[2]-'0');
                                        cur.erase(0,4);
                                    }
                                    else if(cur[2] == ',')
                                    {
                                        first = ((cur[0]-'0')*10)+(cur[1]-'0');
                                        cur.erase(0,3);
                                    }
                                }
                                else if(cur[1] == ',')
                                {
                                    first = (cur[0]-'0');
                                    cur.erase(0,2);
                                }
                            }
                        }
                        if(cur.size() >= 2 && run)
                        {
                            if(isdigit(cur[0]))
                            {
                                if(isdigit(cur[1]))
                                {
                                    if(isdigit(cur[2]) && cur[3] == ')')
                                    {
                                        second = ((cur[0]-'0')*100)+((cur[1]-'0')*10)+(cur[2]-'0');
                                        cur.erase(0,4);
                                    }
                                    else if(cur[2] == ')')
                                    {
                                        second = ((cur[0]-'0')*10)+(cur[1]-'0');
                                        cur.erase(0,3);
                                    }
                                }
                                else if(cur[1] == ')')
                                {
                                    second = (cur[0]-'0');
                                    cur.erase(0,2);
                                }
                            }
                        }
                        product+=(first*second);
                    }
                }
            }
        }
    }
    //close file
    myfile.close();

    //print results
    cout << "total product = " << product << endl;
    cout << "DONE" << endl;
    return 0;
}
