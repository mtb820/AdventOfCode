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
    vector<int> first, last, page;
    int cur, goodSum = 0, badSum = 0;
    char seperator;
    bool good;
    vector<vector<int> > prints, goodPrints, badPrints; 
    myfile.open("input.txt");
    while(myfile.good() && getline(myfile,line))
    {
        if(line != "")
        {
            stringstream ss(line);
            ss >> cur;
            ss >> seperator;
            if(seperator =='|')
            {
                first.push_back(cur);
                ss >> cur;
                last.push_back(cur);
            }
            else
            {
                page.clear();
                page.push_back(cur);
                while(ss >> cur)
                {
                    page.push_back(cur);
                    ss >> seperator;
                }
                prints.push_back(page);
            }
        }
    }
    //close file
    myfile.close();

    for(int i = 0; i < prints.size(); i++)
    {
        good = true;
        for(int j = 0; j < prints[i].size(); j++)
        {
            for(int x = 0; x < last.size(); x++)
            {
                if(prints[i][j] == first[x])
                {
                    for(int z = 0; z < j; z++)
                    {
                        if(prints[i][z] == last[x])
                        {
                            good = false;
                            break;
                        }
                    }
                }
                if(prints[i][j] == last[x])
                {
                    for(int y = prints[i].size()-1; y > j; y--)
                    {
                        if(prints[i][y] == first[x])
                        {
                            good = false;
                            break;
                        }
                    }
                }
                if(!good)
                {
                    break;
                }
            }
            if(!good)
            {
                break;
            }
        }
        if(good)
        {
            goodPrints.push_back(prints[i]);
        }
        else
        {
            badPrints.push_back(prints[i]);
        }
    }

    for(int i = 0; i < badPrints.size(); i++)
    {
        do{
            good = true;
            for(int j = 0; j < badPrints[i].size(); j++)
            {
                for(int x = 0; x < last.size(); x++)
                {
                    if(badPrints[i][j] == first[x])
                    {
                        for(int z = 0; z < j; z++)
                        {
                            if(badPrints[i][z] == last[x])
                            {
                                good = false;
                                swap(badPrints[i][j],badPrints[i][z]);
                            }
                        }
                    }
                    if(badPrints[i][j] == last[x])
                    {
                        for(int y = badPrints[i].size()-1; y > j; y--)
                        {
                            if(badPrints[i][y] == first[x])
                            {
                                good = false;
                                swap(badPrints[i][j],badPrints[i][y]);
                            }
                        }
                    }
                }
            }
        }while(!good);
    }
    


    //middle sums
    for(int g = 0; g < goodPrints.size(); g++)
    {
        goodSum+=goodPrints[g][goodPrints[g].size()/2];
    }
    for(int b = 0; b < badPrints.size(); b++)
    {
        badSum+=badPrints[b][badPrints[b].size()/2];
    }
    //print results
    cout << "goodPrints middle sum = " << goodSum << endl;
    cout << "badPrints middle sum = " << badSum << endl;
    cout << "DONE" << endl;
    return 0;
}
