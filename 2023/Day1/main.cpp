 /*
 *  main.cpp
 *  Created on: November 26, 2024
 *  Author: Matthew Brunsman
 */

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    //Set up the DataStorage Object
    cout << "RUNNING" << endl;
    int sum = 0, left = 0, right = 0;
    bool sawLeft = false, sawRight = false;
    string line;
    ifstream myfile;
    myfile.open("input.txt");
    while(myfile.good() && getline(myfile,line))
    {
        right = line.size() - 1;
        left = 0;
        sawLeft = false;
        sawRight = false;
        while(!sawLeft || !sawRight)
        {
            if(!sawLeft)
            {
                if(isdigit(line[left]))
                {
                    sum += ((line[left] - '0')*10);
                    sawLeft = true;
                }
                //zero case
                else if(line[left] == 'z' && (left + 3) < line.size())
                {
                    if(line[left+1] == 'e' && line[left+2] == 'r' && line[left+3] == 'o')
                    {
                        sawLeft = true;
                    }
                }
                //one case
                else if(line[left] == 'o' && (left + 2) < line.size())
                {
                    if(line[left+1] == 'n' && line[left+2] == 'e')
                    {
                        sum += 10;
                        sawLeft = true;
                    }
                }
                //two and three case
                else if(line[left] == 't')
                {
                    if(left + 2 < line.size())
                    {
                        if(line[left+1] == 'w' && line[left+2] == 'o')
                        {
                            sum += 20;
                            sawLeft = true;
                        }
                    }
                    if(left + 4 < line.size())
                    {
                        if(line[left+1] == 'h' && line[left+2] == 'r' && line[left+3] == 'e' && line[left+4] == 'e')
                        {
                            sum += 30;
                            sawLeft = true;
                        }
                    }
                }
                //four and five case
                else if(line[left] == 'f')
                {
                    if(left + 3 < line.size())
                    {
                        if(line[left+1] == 'o' && line[left+2] == 'u' && line[left+3] == 'r')
                        {
                            sum += 40;
                            sawLeft = true;
                        }
                        if(line[left+1] == 'i' && line[left+2] == 'v' && line[left+3] == 'e')
                        {
                            sum += 50;
                            sawLeft = true;
                        }
                    }
                }
                //six and seven case
                else if(line[left] == 's')
                {
                    if(left + 2 < line.size())
                    {
                        if(line[left+1] == 'i' && line[left+2] == 'x')
                        {
                            sum += 60;
                            sawLeft = true;
                        }
                    }
                    if(left + 4 < line.size())
                    {
                        if(line[left+1] == 'e' && line[left+2] == 'v' && line[left+3] == 'e' && line[left+4] == 'n')
                        {
                            sum += 70;
                            sawLeft = true;
                        }
                    }
                }
                //eight case
                else if(line[left] == 'e')
                {
                    if(left + 4 < line.size())
                    {
                        if(line[left+1] == 'i' && line[left+2] == 'g' && line[left+3] == 'h' && line[left+4] == 't')
                        {
                            sum += 80;
                            sawLeft = true;
                        }
                    }
                }
                //nine case
                else if(line[left] == 'n')
                {
                    if(left + 3 < line.size())
                    {
                        if(line[left+1] == 'i' && line[left+2] == 'n' && line[left+3] == 'e')
                        {
                            sum += 90;
                            sawLeft = true;
                        }
                    }
                }
            }
            if(!sawRight)
            {
                if(isdigit(line[right]))
                {
                    sum += (line[right] - '0');
                    sawRight = true;
                }
                //zero and two case
                else if(line[right] == 'o')
                {
                    if((right - 3) >= 0)
                    {
                        if(line[right-1] == 'r' && line[right - 2] == 'e' && line[right-3] == 'z')
                        {
                            sawRight = true;
                        }
                    }
                    if((right - 2) >= 0)
                    {
                        if(line[right-1] == 'w' && line[right - 2] == 't')
                        {
                            sum += 2;
                            sawRight = true;
                        }
                    }
                }
                //one, three, five, and nine case
                else if(line[right] == 'e')
                {
                    if((right - 2) >= 0)
                    {
                        if(line[right-1] == 'n' && line[right - 2] == 'o')
                        {
                            sum += 1;
                            sawRight = true;
                        }
                    }
                    if((right - 4) >= 0)
                    {
                        if(line[right-1] == 'e' && line[right - 2] == 'r' && line[right - 3] == 'h' && line[right - 4] == 't')
                        {
                            sum += 3;
                            sawRight = true;
                        }
                    }
                    if((right - 3) >= 0)
                    {
                        if(line[right-1] == 'v' && line[right - 2] == 'i' && line[right - 3] == 'f')
                        {
                            sum += 5;
                            sawRight = true;
                        }
                        if(line[right-1] == 'n' && line[right - 2] == 'i' && line[right - 3] == 'n')
                        {
                            sum += 9;
                            sawRight = true;
                        }
                    }
                }
                //four case
                else if(line[right] == 'r')
                {
                    if((right - 3) >= 0)
                    {
                        if(line[right-1] == 'u' && line[right - 2] == 'o' && line[right - 3] == 'f')
                        {
                            sum += 4;
                            sawRight = true;
                        }
                    }
                }
                //six case
                else if(line[right] == 'x')
                {
                    if((right - 2) >= 0)
                    {
                        if(line[right-1] == 'i' && line[right - 2] == 's')
                        {
                            sum += 6;
                            sawRight = true;
                        }
                    }
                }
                //seven case
                else if(line[right] == 'n')
                {
                    if((right - 4) >= 0)
                    {
                        if(line[right-1] == 'e' && line[right - 2] == 'v' && line[right - 3] == 'e' && line[right - 4] == 's')
                        {
                            sum += 7;
                            sawRight = true;
                        }
                    }
                }
                //eight case
                else if(line[right] == 't')
                {
                    if((right - 4) >= 0)
                    {
                        if(line[right-1] == 'h' && line[right - 2] == 'g' && line[right - 3] == 'i' && line[right - 4] == 'e')
                        {
                            sum += 8;
                            sawRight = true;
                        }
                    }
                }
            }
            left++;
            right--;
        }
    }
    //close file
    myfile.close();
    cout << "Sum = " << sum << endl;
    return 0;
}
