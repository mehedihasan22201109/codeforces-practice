#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string input;
    cin >> input;

    string vowels = "aoyeuiAOYEUI";
    string result = "";

    for (char ch : input) {
        // Convert to lowercase
        ch = tolower(ch);

        // Check if it's a vowel
        if (vowels.find(ch) == string::npos) {
            // Not a vowel → add ".<consonant>"
            result += '.';
            result += ch;
        }
    }

    cout << result << endl;
    return 0;
}

