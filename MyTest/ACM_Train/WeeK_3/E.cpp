#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1;

    while (getline(cin, s1)) {
        if (s1 == "#") {
            break;
        }

        set<string> unique_words;
        istringstream cins(s1);
        string word;

        while (cins >> word) {
            unique_words.insert(word);
        }

        cout << unique_words.size() << endl;
    }

    return 0;
}