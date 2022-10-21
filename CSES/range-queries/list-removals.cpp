// created: 10-21-2022 Fri 12:12 AM

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<
	T, null_type, less<T>,
	rb_tree_tag, tree_order_statistics_node_update
>;

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;
	Tree<int> t; // the indices left
	for (int i = 0; i < n; i++) t.insert(i);
	for (int i = 0; i < n; i++) {
		int q; cin >> q; q--;
		auto it = t.find_by_order(q);
		cout << a[*it] << " \n"[i == n-1];
		t.erase(it);
	}
	return 0;
}
