
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    // Check for 7 or more consecutive 0's or 1's
    if (s.find("0000000") != string::npos || s.find("1111111") != string::npos)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
