#include <iostream>
using namespace std;

int main()
{
    int yuan, jiao;
    cin >> yuan >> jiao;
    int count = 0;
    while(yuan >= 1)
    {
        if(yuan == 1 && jiao < 9 ) break;
        jiao -= 19;
        count++;
        while(jiao < 0) 
        {
            yuan--;
            jiao += 10;
        }
    }
    cout << count << endl;
    return 0;
}