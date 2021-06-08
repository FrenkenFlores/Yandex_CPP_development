#include <iostream>
int main() {
	int n, k;
	std::cin >> n >> k;
	int a[n];
	int S[n - 1];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i, j = 0; i < n; i++, j++) {
		if (j != i)
			S[j] = a[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; i++) {
			sum = sum + a[i] - S[j];
			if (sum < 0)
				sum = sum * -1;
		}
		std::cout << sum;
	}
}