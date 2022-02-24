#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
	NewBus,
	BusesForStop,
	StopsForBus,
	AllBuses
};

struct Query {
	QueryType type;
	string bus;
	string stop;
	vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	return is;
}

struct BusesForStopResponse {
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	return os;
}

struct StopsForBusResponse {
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	return os;
}

struct AllBusesResponse {
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	return os;
}

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops) {
	}

	BusesForStopResponse GetBusesForStop(const string& stop) const {
	}

	StopsForBusResponse GetStopsForBus(const string& bus) const {
	}

	AllBusesResponse GetAllBuses() const {
	}
};


int main() {
	int query_count;
	Query q;

	cin >> query_count;

	BusManager bm;
	for (int i = 0; i < query_count; ++i) {
		cin >> q;
		switch (q.type) {
			case QueryType::NewBus:
				bm.AddBus(q.bus, q.stops);
				break;
			case QueryType::BusesForStop:
				cout << bm.GetBusesForStop(q.stop) << endl;
				break;
			case QueryType::StopsForBus:
				cout << bm.GetStopsForBus(q.bus) << endl;
				break;
			case QueryType::AllBuses:
				cout << bm.GetAllBuses() << endl;
				break;
		}
	}

	return 0;
}