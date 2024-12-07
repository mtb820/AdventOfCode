 /*
 *  main.cpp
 *  Created on: December 6, 2024
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

bool canSolve(long long &testValue, vector<long long> &inputNums);

int main()
{
    //Set up objects
    cout << "RUNNING" << endl;
    string line;
    ifstream myfile;
    char colon;
    long long testValue, sum = 0, curVal;
    long long maxVal = 0;
    vector<long long> inputNums;
    myfile.open("input.txt");
    while(myfile.good() && getline(myfile,line))
    {
        inputNums.clear();
        if(line != "")
        {
            stringstream ss(line);
            ss >> testValue;
            ss >> colon;
            while(ss >> curVal)
            {
                inputNums.push_back(curVal);
            }
            if(canSolve(testValue, inputNums))
            {
                sum+=testValue;
            }
        }
    }
    //close file
    myfile.close();
            
    //print results
    cout << "Sum of possible test Values = " << sum << endl;
    cout << "DONE" << endl;
    return 0;
}

bool canSolve(long long &testValue, vector<long long> &inputNums)
{
    vector<long long> possibleValues;
    possibleValues.push_back(inputNums[0]);
    
    for(long long i = 1; i < inputNums.size(); i++)
    {
        long long curSize = possibleValues.size();
        for(long long j = 0; j < curSize; j++)
        {
            if(possibleValues[j] <= testValue)
            {
                long long sum = possibleValues[j]+inputNums[i];
                long long multiplication = possibleValues[j]*inputNums[i];
                long long concatenate;    
                stringstream ss;
                ss << possibleValues[j];
                ss << inputNums[i];
                ss >> concatenate;
                possibleValues[j] = sum;
                possibleValues.push_back(multiplication);
                possibleValues.push_back(concatenate);
            }
        }
    }

    for(long long x = 0; x < possibleValues.size(); x++)
    {
        if(possibleValues[x] == testValue)
        {
            return true;
        }
    }
    return false;
}

