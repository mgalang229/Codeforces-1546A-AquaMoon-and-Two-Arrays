#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		// calculate the sum of elements in array 'a'
		int sum1 = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum1 += a[i];
		}
		// calculate the sum of elements in array 'b'
		int sum2 = 0;
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			sum2 += b[i];
		}
		// check if 'sum1' is NOT equal to 'sum2'
		if (sum1 != sum2) {
			// if yes, OUTPUT -1 and continue the loop
			cout << "-1\n";
			continue;
		}
		vector<pair<int, int>> v;
		while (true) {
			for (int i = 0; i < n; i++) {
				// find the an element in 'a' wherein it is greater than 0 
				// and greater than its corresponding element in array 'b'
				if (a[i] > b[i] && a[i] > 0) {
					// if it is found, then decrement th element
					a[i]--;
					// start a nested loop where in it avoids the current value of 'i'
					for (int j = 0; j < n; j++) {
						if (j == i) {
							// if 'j' is equal to 'i', then skip this index
							continue;
						}
						// check if the current element in array 'a' in this nested loop is less than the
						// its corresponding element in array 'b'
						if (a[j] < b[j]) {
							// if yes, then increment this element
							a[j]++;
							// store the two indices ('i' + 1 and 'j' + 1) in the vector
							v.emplace_back(make_pair(i + 1, j + 1));
							break;
						}
					}
					break;
				}
			}
			// check if array 'a' is EXACTLY equal to array 'b'
			bool checker = true;
			for (int i = 0; i < n; i++) {
				if (a[i] != b[i]) {
					checker = false;
					break;
				}
			}
			if (checker) {
				// if yes, then break this while-loop
				break;
			}
		}
		cout << (int) v.size() << '\n';
		for (int i = 0; i < (int) v.size(); i++) {
			cout << v[i].first << " " << v[i].second << '\n';
		}
	}
	return 0;
}
