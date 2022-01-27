#include <map>
bool operator<(const Region &lhs, const Region &rhs) {
	return std::tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
		   std::tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

// Takes more memory
int FindMaxRepetitionCount(const vector<Region>& regions) {
	// compare number of times region occurs in regions
	int max_count = 0;
	std::map<const Region, int> regions_count;
	for (const Region &region : regions) {
		regions_count[region]++;
		max_count=std::max(max_count, regions_count[region]);
	}
	return max_count;
}
/************FindMaxRepetitionCount_v2************/
bool operator==(const Region &lhs, const Region &rhs) {
	return std::tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) ==
		   std::tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

// Takes longer time
int FindMaxRepetitionCount_v2(const vector<Region>& regions) {
	// compare number of times region occurs in regions
	int max_count = 0;
	for (const Region &region : regions) {
		int tmp_max_count = 0;
		for (const Region &comparison_region : regions) {
			if (region == comparison_region) {
				tmp_max_count += 1;
			}
		}
		if (max_count < tmp_max_count)
			max_count = tmp_max_count;
	}
	return max_count;
}