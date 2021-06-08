#include <iostream>


int main() {
	int n;
	std::cin >> n;
	int a[n];
	int diff[n];
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) {
			std::cout << -1 << std::endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		diff[i] = a[n - 1] - a[i];
	}
	int max = diff[0];
	for (int i = 0; i < n; i++) {
		if (diff[i] > max)
			max = diff[i];
	}
	std::cout << max << std::endl;
	return 0;
}