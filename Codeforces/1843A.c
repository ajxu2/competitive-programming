#include <stdio.h>
#include <stdlib.h>

int a[100];

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void solve() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    qsort(a, n, sizeof(int), compare);
    int ans = 0;
    for (int i = 0; i < n/2; i++) ans += a[n-1-i] - a[i];
    printf("%d\n", ans);
}

int main(void) {
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}
