#include <iostream>
// Calculate mass by size and density
int main() {
	// n- number of blocks, r- density of blocks
	size_t n, r;
	std::cin >> n >> r;

	// w- width, d- depth, h- height
	u_int64_t w, h, d, mass=0;
	for (size_t i = 0; i < n; i++) {
		std::cin >> w >> h >> d;
		mass += w * h * d * r;
	}
	// Print the sum of all blocks
	std::cout << mass << std::endl;
}