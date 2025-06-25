
#include <iostream>
#include <string>
#include <set>
#include <cctype> // for tolower
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    set<char> letters;

    for (char c : s) {
        letters.insert(tolower(c)); // Convert to lowercase and insert into set
    }

    if (letters.size() == 26) {
        cout << "YES" << endl; // All letters from a to z are present
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
