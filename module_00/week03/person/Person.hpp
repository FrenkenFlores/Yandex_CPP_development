#include <string>
#include <algorithm>
#include <vector>

class Person {
    public:
        void ChangeFirstName(int year, const std::string& first_name) {
        // добавить факт изменения имени на first_name в год year
            if (data.empty())
                data.push_back()
        }
        void ChangeLastName(int year, const std::string& last_name) {
        // добавить факт изменения фамилии на last_name в год year

        }
        std::string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year

        }
    private:
    // приватные поля
        struct info {
            std::string first_name;
            std::string second_name;
            std::pair<int, int> period;
        };
    std::vector<info> data;
};