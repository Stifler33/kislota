#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;
void result(int value)
{
    ofstream file("output.txt");
    file << value;
}
int main() {
    ifstream file("..\\input.txt");
    int tank;
    vector<int> value;
    int max = 0;
    int min = INT8_MAX;
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
    if (value.size() != tank) {
        result(-1);
        return 0;
    }
    if (max == min) {
        result(0);
        return 0;
    }
    if (*value.begin() == max) {
        result(-1);
        return -1;
    }
    auto posMax = find(value.begin(), value.end(), max);
    for (auto i = value.begin(); i != value.end(); i++)
    {
        if (*i != max && *i != min) {
            result(-1);
            return -1;
        }
        if (i >= value.begin() && i < posMax)
        {
            if (*i != min) {
                result(-1);
                return -1;
            }
        }
        if (i >= posMax && i < value.end())
        {
            if (*i != max) {
                result(-1);
                return -1;
            }
        }
    }
    result(max - min);
    return 0;
}