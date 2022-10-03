#include <unordered_map>
#include <iostream>
using std::string;

template<typename K, typename V>
class dict : std::unordered_map<K, V> {
    public:
    using std::unordered_map<K, V>::unordered_map;
    
    string operator[](string key) {
        return (*(this->find(key))).second;
    };
};

int main(void)
{
    dict<string, string> mydict {
        { "Man", "mybro" },
        { "Bro", "Brosies" }
    };

    std::cout << mydict["Bro"];
}