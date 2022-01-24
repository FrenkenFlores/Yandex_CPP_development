#include <iostream>
#include <vector>

int main() {
	std::vector<int64_t> day_temp;

	// Store the number of days
	size_t n;
	std::cin >> n;
	if (n < 0) return 1;

	// Fill day_temp with temperature
	int64_t temperature;
	for (size_t i = 0; i < n; i++) {
		std::cin >> temperature;
		day_temp.push_back(temperature);
	}

	// Calculate the average temperature
	int64_t avg = 0;
	for (int64_t temp : day_temp) {
		avg += temp;
	}
	avg = avg / static_cast<int>(n);

	// Store index of days with temperature higher than average
	std::vector<int64_t> results;
	for (size_t i = 0; i < n; i++) {
		if (day_temp[i] > avg) {
			results.push_back(i);
		}
	}

	// Print number of days and the corresponding day indexes
	std::cout << results.size() << std::endl;
	for (size_t i = 0; i < results.size(); i++) {
		std::cout << results[i];
		if (i + 1 < results.size()) std::cout << " ";
		else std::cout << std::endl;
	}
	return 0;
}