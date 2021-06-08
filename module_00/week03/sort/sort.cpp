#include <iostream>
#include <algorithm>
int main() {
	int N;
	std::cin >> N;
	int A[N];
	for (int &i : A){
		std::cin >> i;
	}
	std::sort(A, A + N, [](int x, int y){ return abs(x) < abs(y); });
	for (const int &i : A) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return 0;
}
