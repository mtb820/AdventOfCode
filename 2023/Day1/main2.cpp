
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> create(int size)
{
    vector<string> languages;
    languages.push_back("Rust");
    languages.push_back("C++");
    languages.push_back("C");
    languages.push_back("Python");
    languages.push_back("JavaScript");
    vector<string> randlanguages;
    randlanguages.resize(size);
    for(int i = 0; i < size; i++)
    {
        int random = rand() % 5;
        randlanguages[i] = languages[random];
    }
    return randlanguages;
}
void print(vector<string> print)
{
    for(int i = 0; i < print.size(); i++)
    {
        cout << print[i] << endl;
    }
}
void count(vector<string> &count_vec, string name);
{
    int count = 0
    for(int i = 0; i < count_vec.size(); i++)
    {
        if(count_vec[i] == name)
            count++;
    }
    cout << "There are " << count << " instances of " << word << endl;
}

int main()
{
    vector<string> randlanguages;
    randlanguages = create();
    print(randlanguages);
    count(randlanguages,"Rust");
    return 0;
}