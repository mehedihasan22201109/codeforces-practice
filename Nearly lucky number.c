
#include <iostream>
#include <string>
using namespace std;

// Helper function to check if a number is lucky
bool isLucky(int num) {
    if (num == 0) return false;
    while (num > 0) {
        int digit = num % 10;
        if (digit != 4 && digit != 7)
            return false;
        num /= 10;
    }
    return true;
}

int main() {
    string n;
    cin >> n;

    int luckyCount = 0;
    for (char c : n) {
        if (c == '4' || c == '7')
            luckyCount++;
    }

    if (isLucky(luckyCount))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
