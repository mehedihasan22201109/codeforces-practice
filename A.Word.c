
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;

    int lower = 0, upper = 0;

    for (char c : s) {
        if (islower(c))
            lower++;
        else
            upper++;
    }

    if (upper > lower)
        for (char &c : s) c = toupper(c);
    else
        for (char &c : s) c = tolower(c);

    cout << s << endl;
    return 0;
}
