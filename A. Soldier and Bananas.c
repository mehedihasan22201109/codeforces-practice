#include <iostream>
using namespace std;

int main() {
    int k, n, w;
    cin >> k >> n >> w;

    // Total cost using arithmetic series sum formula: k * (1 + 2 + ... + w) = k * w * (w + 1) / 2
    int total_cost = k * w * (w + 1) / 2;

    int borrow = total_cost - n;

    // If the soldier has enough money, he doesn't need to borrow
    if (borrow <= 0)
        cout << 0 << endl;
    else
        cout << borrow << endl;

    return 0;
}
