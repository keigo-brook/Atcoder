#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    if (a < b) {
        cout << "Better" << endl;
    } else {
        cout << "Worse" << endl;
    }
    return 0;
}