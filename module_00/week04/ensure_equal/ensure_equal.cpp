#include <exception>
#include <string>
using namespace std;

void EnsureEqual(const string& left, const string& right) {
	if (left != right) {
		throw std::runtime_error(left + " != " + right);
	}
}