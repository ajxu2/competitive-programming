#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    stack<int> mono;
    mono.push(0);
    for (int i = 1; i < n; i++) {
        // get the distance to the first element to the left that is larger
        while (!mono.empty() && a[mono.top()] < a[i]) mono.pop();
        if (!mono.empty()) ans += (i - mono.top() + 1);
        mono.push(i);
    }
    while (!mono.empty()) mono.pop();
    // do the same but in reverse
    mono.push(n-1);
    for (int i = n-2; i >= 0; i--) {
        while (!mono.empty() && a[mono.top()] < a[i]) mono.pop();
        if (!mono.empty()) ans += (mono.top() - i + 1);
        mono.push(i);
    }
    cout << ans << "\n";
}
