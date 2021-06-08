#include <iostream>
#include <string>

bool check_free(int count, std::string seat, int index, bool back = false) {
	if (back == false) {
		if (count == 3 && seat[index] != '#' && seat[index + 1] != '#' && seat[index + 2] != '#') {
			return true;
		} else if(count == 2 && seat[index] != '#' && seat[index + 1] != '#') {
			return true;
		} else if(count == 1 && seat[index] != '#') {
			return true;
		}
	} else {
		if (count == 3 && seat[index] != '#' && seat[index - 1] != '#' && seat[index - 2] != '#') {
			return true;
		} else if(count == 2 && seat[index] != '#' && seat[index - 1] != '#') {
			return true;
		} else if(count == 1 && seat[index] != '#') {
			return true;
		}
	}
	return false;
}

void dump(std::string map[], int n) {
	int index = 0;
	char alpha[7] = {'A', 'B', 'C', '_', 'D', 'E', 'F'};
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 7; j++) {
			if (map[i][j] == 'X') {
				flag = true;
			}
		}
	}
	if (flag == false) {
		std::cout << "Cannot fulfill passengers requirements" << std::endl;
		return;
	}
	int u, t = 0;
	std::cout << "Passengers can take seats:";
	for (int u = 0; u < n; u++) {
		for (int t = 0; t < 7; t++) {
			if (map[u][t] == 'X') {
				std::cout << " ";
				int tmp = u;
				std::cout << u + 1 << alpha[t];
			}
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < n; i++) {
		std::cout << map[i] << std::endl;
		while ((index = map[i].find("X")) != std::string::npos) {
			map[i][index] = '#';
			flag = true;
		}
	}
}

int main() {
	int n, m;
	std::cin >> n;
	std::string map[n];
	int token[n];
	for (int i = 0; i < n; i++) {
		token[i] = 0;
		std::cin >> map[i];
		for (int j = 0; j < map[i].length(); ++j) {
			if (map[i][j] == '#') {
				token[i]++;
			}
		}
	}

	std::cin >> m;
	int num[m];
	std::string side[m];
	std::string position[m];
	for (int i = 0; i < m; i++) {
		std::cin >> num[i] >> side[i] >> position[i];
		if (num[i] > 3 || (side[i] != "left" && side[i] != "right") || (position[i] != "window" && position[i] != "aisle"))
			return -1;
	}
	if (n > 100 || n < 1 || m > 100 || m < 1)
		return -1;
	for (int i = 0; i < m; i++) {		//each passenger group
		for (int j = 0; j < n; j++) {	//each line
			if (num[i] >= token[j]) {	//if places are enough
				if (position[i] == "window") {
					if (check_free(num[i], map[j], 0) && side[i] == "left") {
						for (int k = 0; k < 3 && num[i] != 0; k++) {		//find a seat
							if (map[j][k] != '#') {
								map[j][k] = 'X';
								num[i]--;
							}
						}
					}
					else if (check_free(num[i], map[j], 6, true) && side[i] == "right") {
						for (int k = 6; k > 3 && num[i] != 0; k--) {        //find a seat
							if (map[j][k] != '#') {
								map[j][k] = 'X';
								num[i]--;
							}
						}
					}
				} else if (position[i] == "aisle") {
					if (check_free(num[i], map[j], 2, true) && side[i] == "left") {
						for (int k = 2; k >= 0 && num[i] != 0; k--) {		//find a seat
							if (map[j][k] != '#') {
								map[j][k] = 'X';
								num[i]--;
							}
						}
					}
					else if (check_free(num[i], map[j], 4) && side[i] == "right") {
						for (int k = 4; k >= 6 && num[i] != 0; k++) {		//find a seat
							if (map[j][k] != '#') {
								map[j][k] = 'X';
								num[i]--;
							}
						}
					}

				}

			}
		}
		dump(map, n);
	}

	return 0;
}