template<typename K, typename V>	map<K, V> Sqr(map<K, V> m);
template<typename K, typename V>	pair<K, V> Sqr(pair<K, V> p);
template<typename T>				vector<T> Sqr(vector<T> v);
template<typename T>				T Sqr(const T &x);

template<typename T>
T Sqr(const T &x) {
	return x * x;
}

template<typename T>
vector<T> Sqr(vector<T> v) {
	for (T &i : v) {
		i = Sqr(i);
	}
	return v;
}

template<typename K, typename V>
pair<K, V> Sqr(pair<K, V> p) {
	return make_pair(Sqr(p.first), Sqr(p.second));
}

template<typename K, typename V>
map<K, V> Sqr(map<K, V> m) {
	for (pair<const K, V> &i : m) {
		i.second = Sqr(i.second);
	}
	return m;
}