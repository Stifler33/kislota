#include <iostream>
#include "header.h"
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    ifstream file("..\\input.txt");
    if (file.is_open()){
        cout << "file open\n";
    }else{
        cerr << "file not open\n";
        return -1;
    }
    int tank;
    vector<int> value;
    int max = 0;
    int min = INT_MAX;
    while(!file.eof())
    {
        if (file.tellg() == 0) {
            file >> tank;
        }else{
            int i;
            file >> i;
            if (i > max) max = i;
            if (i < min) min = i;
            value.push_back(i);
        }

    }

    return 0;
}
