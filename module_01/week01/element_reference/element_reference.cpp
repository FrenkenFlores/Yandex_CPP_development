#include <stdexcept>

template<typename T, typename K> T &GetRefStrict(map<K, T> &m, K k);

template<typename T, typename K>
T &GetRefStrict(map<K, T> &m, K k) {
	if (m.count(k))
		return m.at(k);
	else
		throw runtime_error("No key found");
}