#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main() {
	int N;
	std::cin >> N;
	std::vector<std::string> A;
	std::string str;
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> str;
		A.push_back(str);
	}
	
	std::sort(std::begin(A), std::end(A), [](std::string x, std::string y) {
		size_t i;
		for (i = 0; x[i] != '\0' && y[i] != '\0'; i++) {
			if (std::tolower(x[i]) != std::tolower(y[i]))
				break;
		}
		return (std::tolower(x[i]) < std::tolower(y[i]));
	});
	for (std::string i : A){
		std::cout << i << ' ';
	}
	std::cout << std::endl;
	return 0;
}
