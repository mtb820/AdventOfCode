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
    bool isSafe = true, isReallySafe = true;
    string line;
    ifstream myfile;
    int cur = 0, prev = -1, prev2 = -1, safeCount = 0, shouldIncrease = 0;
    myfile.open("input.txt");
    while(myfile.good() && getline(myfile,line))
    {
        //take in a value
        if(line != "")
        {
            prev = -1;
            prev2 = -1;
            isSafe = true;
            isReallySafe = true;
            shouldIncrease = 0;
            stringstream ss(line);
            while(ss >> cur && isReallySafe)
            {
                if(isSafe)
                {
                    if(prev != -1)
                    {
                        if(shouldIncrease == 0)
                        {
                            if(cur > prev)
                            {
                                shouldIncrease = 1;
                            }
                            else if(cur < prev)
                            {
                                shouldIncrease = -1;
                            }
                            else
                            {
                                isSafe = false;
                            }
                        }
                        else if(shouldIncrease == 1)
                        {
                            if(cur <= prev)
                            {
                                isSafe = false;
                            }
                        }
                        else
                        {
                            if(cur >= prev)
                            {
                                isSafe = false;
                            }
                        }
                        if(abs(cur - prev) > 3)
                        {
                            isSafe = false;
                        }
                    }
                    if(!isSafe)
                    {
                        prev2 = prev;
                    }
                    prev = cur;
                }
                else
                {
                    if(prev2 != -1)
                    {
                        if(shouldIncrease == 0)
                        {
                            if(cur > prev)
                            {
                                shouldIncrease = 1;
                            }
                            else if(cur < prev)
                            {
                                shouldIncrease = -1;
                            }
                            else
                            {
                                prev = prev2;
                            }
                        }
                        else if(shouldIncrease == 1)
                        {
                            if(cur <= prev)
                            {
                                prev = prev2;
                            }
                        }
                        else
                        {
                            if(cur >= prev)
                            {
                                prev = prev2;
                            }
                        }
                        if(shouldIncrease == 0)
                        {
                            if(cur > prev)
                            {
                                shouldIncrease = 1;
                            }
                            else if(cur < prev)
                            {
                                shouldIncrease = -1;
                            }
                            else
                            {
                                isReallySafe = false;
                            }
                        }
                        else if(shouldIncrease == 1)
                        {
                            if(cur <= prev)
                            {
                                isReallySafe = false;
                            }
                        }
                        else
                        {
                            if(cur >= prev)
                            {
                                isReallySafe = false;
                            }
                        }
                        if(abs(cur - prev) > 3)
                        {
                            isReallySafe = false;
                        }
                    }
                }
            }
            if(isReallySafe)
            {
                safeCount++;
            }
        }
    }
    //close file
    myfile.close();

    //print results
    cout << "safe levels = " << safeCount << endl;
    cout << "DONE" << endl;
    return 0;
}
