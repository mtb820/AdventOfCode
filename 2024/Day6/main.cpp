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

bool shouldCheck(int &x, int &y, vector<int> &xAlreadyExists, vector<int> &yAlreadyExists);
bool thisLoops(int x, int y, string direction, vector<string> map);
bool hitExists(vector<int> &xHits, vector<int> &yHits, vector<string> &directionHits);

int main()
{
    //Set up objects
    cout << "RUNNING" << endl;
    string line, direction = "none";
    ifstream myfile;
    vector<string> map;
    vector<int> xAlreadyExists, yAlreadyExists;
    bool leftArea = false, obstacleHit = false;
    int x = 0, y = 0, count = 0, obstacles = 0;
    myfile.open("input.txt");
    while(myfile.good() && getline(myfile,line))
    {
        if(line != "")
        {
            map.push_back(line);
        }
    }
    //close file
    myfile.close();

    //find starting point
    for(int i = 0; i < map.size(); i++)
    {
        for(int j = 0; j < map[i].size(); j++)
        {
            if(map[i][j] == '^')
            {
                direction = "up";
                x = j;
                y = i;
                xAlreadyExists.push_back(x);
                yAlreadyExists.push_back(y);
                break;
            }
        }
        if(direction != "none")
        {
            break;
        }
    }
    //move through changing to x
    while(!leftArea)
    {
        obstacleHit = false;
        if(map[y][x] != 'X')
        {
            count++;
            map[y][x] = 'X';
        }
        if(direction == "up")
        {
            if(y == 0)
            {
                leftArea = true;
            }
            else if(map[y-1][x] == '#')
            {
                obstacleHit = true;
                direction = "right";
            }
            else
            {
                y--;
            }
        }
        else if(direction == "down")
        {
            if(y == map.size()-1)
            {
                leftArea = true;
            }
            else if(map[y+1][x] == '#')
            {
                obstacleHit = true;
                direction = "left";
            }
            else
            {
                y++;
            }   
        }
        else if(direction == "left")
        {
            if(x == 0)
            {
                leftArea = true;
            }
            else if(map[y][x-1] == '#')
            {
                obstacleHit = true;
                direction = "up";
            }
            else
            {
                x--;
            }
        }
        else if(direction == "right")
        {
            if(x == map[y].size()-1)
            {
                leftArea = true;
            }
            else if(map[y][x+1] == '#')
            {
                obstacleHit = true;
                direction = "down";
            }
            else
            {
                x++;
            }
        }
        if(!obstacleHit && shouldCheck(x,y,xAlreadyExists,yAlreadyExists))
        {
            xAlreadyExists.push_back(x);
            yAlreadyExists.push_back(y);
            if(thisLoops(x,y,direction,map))
            {
                obstacles++;
            }   
        }
    }

    //print results
    cout << "guard total places visited = " << count << endl;
    cout << "obstacles that create infinite loops = " << obstacles << endl;
    cout << "DONE" << endl;
    return 0;
}

bool shouldCheck(int &x, int &y, vector<int> &xAlreadyExists, vector<int> &yAlreadyExists)
{
    for(int i = 0; i < xAlreadyExists.size(); i++)
    {
        if(xAlreadyExists[i] == x && yAlreadyExists[i] == y)
        {
            return false;
        }
    }
    return true;
}

bool thisLoops(int x, int y, string direction, vector<string> map)
{
    vector<int> xHits, yHits;
    vector<string> directionHits;
    map[y][x] = '#';
    if(direction == "up")
    {
        y++;
    }
    else if(direction == "right")
    {
        x--;
    }
    else if(direction == "down")
    {
        y--;
    }
    else if(direction == "left")
    {
        x++;
    }
    //move through and see if you reach the same point going the same direction
    while(true)
    {
        if(direction == "up")
        {
            if(y == 0)
            {
                return false;
            }
            else if(map[y-1][x] == '#')
            {
                xHits.push_back(x);
                yHits.push_back(y);
                directionHits.push_back(direction);
                if(hitExists(xHits,yHits,directionHits))
                {
                    return true;
                }
                direction = "right";
            }
            else
            {
                y--;
            }
        }
        else if(direction == "down")
        {
            if(y == map.size()-1)
            {
                return false;
            }
            else if(map[y+1][x] == '#')
            {
                xHits.push_back(x);
                yHits.push_back(y);
                directionHits.push_back(direction);
                if(hitExists(xHits,yHits,directionHits))
                {
                    return true;
                }
                direction = "left";
            }
            else
            {
                y++;
            }   
        }
        else if(direction == "left")
        {
            if(x == 0)
            {
                return false;
            }
            else if(map[y][x-1] == '#')
            {
                xHits.push_back(x);
                yHits.push_back(y);
                directionHits.push_back(direction);
                if(hitExists(xHits,yHits,directionHits))
                {
                    return true;
                }
                direction = "up";
            }
            else
            {
                x--;
            }
        }
        else if(direction == "right")
        {
            if(x == map[y].size()-1)
            {
                return false;
            }
            else if(map[y][x+1] == '#')
            {
                xHits.push_back(x);
                yHits.push_back(y);
                directionHits.push_back(direction);
                if(hitExists(xHits,yHits,directionHits))
                {
                    return true;
                }
                direction = "down";
            }
            else
            {
                x++;
            }
        }
    }
}

bool hitExists(vector<int> &xHits, vector<int> &yHits, vector<string> &directionHits)
{
    int lastIndex = xHits.size()-1;
    for(int i = 0; i < lastIndex; i++)
    {
        if(xHits[i] == xHits[lastIndex] && yHits[i] == yHits[lastIndex] && directionHits[i] == directionHits[lastIndex])
        {
            return true;
        }
    }
    return false;
}