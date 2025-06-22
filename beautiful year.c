
#include <iostream>
#include <set>
using namespace std;

// Function to check if all digits in the year are unique
bool hasDistinctDigits(int year) {
    set<char> digits;
    string s = to_string(year);
    for (char c : s) {
        if (digits.count(c)) return false;
        digits.insert(c);
    }
    return true;
}

int main() {
    int y;
    cin >> y;

    while (true) {
        y++;
        if (hasDistinctDigits(y)) {
            cout << y << endl;
            break;
        }
    }

    return 0;
}
