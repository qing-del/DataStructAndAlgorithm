#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair
{
    string val;
    bool istrue = false;
};

vector<string> output = {"Equilateral triangle", "Isosceles triangle", "Obtuse triangle", "Acute triangle", "Right triangle", "Not triangle"};

int main()
{
    vector<int> bian(3);
    cin >> bian[0] >> bian[1] >> bian[2];
    vector<Pair> triangles(6);
    for(int i = 0; i < 6; i++) triangles[i].val = output[i];

    sort(bian.begin(), bian.end());
    if(bian[0] + bian[1] <= bian[2])
    {
        cout << output[5] << endl;
        return 0;
    }

    if(bian[0] == bian[1] && bian[1] == bian[2]) triangles[0].istrue = true;
    if(bian[0] == bian[1]) triangles[1].istrue = true;
    if(bian[0] * bian[0] + bian[1] * bian[1] == bian[2] * bian[2])
    {
        triangles[4].istrue = true;
    } else if (bian[0] * bian[0] + bian[1] * bian[1] < bian[2] * bian[2])
    {
        triangles[2].istrue = true;
    } else if (bian[0] * bian[0] + bian[1] * bian[1] > bian[2] * bian[2])
    {
        triangles[3].istrue = true;
    }

    for(int i = 5; i >= 0; i--)
    {
        if(triangles[i].istrue) cout << triangles[i].val << endl;
    }

    return 0;
}