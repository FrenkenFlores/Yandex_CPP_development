#include <set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// class SortedStrings {
//     private:
//         std::multiset<std::string> container;

//     public:
//         void AddString(std::string str) { container.insert(str); }
//         std::multiset<std::string> GetSortedStrings() { return container; }
// };

class SortedStrings {
public:
  void AddString(const string& s) {
    data.push_back(s);
  }
  vector<string> GetSortedStrings() {
    sort(begin(data), end(data));
    return data;
  }
private:
  vector<string> data;
};