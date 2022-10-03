#include <unordered_map>
#include <iostream>
using std::string;

template<typename K, typename V>
class dict : public std::unordered_map<K, V> {
    public:
    using std::unordered_map<K, V>::unordered_map;
    
    V& operator[](string key) {
        return (*(this->find(key))).second;
    };
};

int main(void)
{
    dict<string, string> mydict {
        { "Man", "Partner" },
        { "Bro", "Brosies" }
    };

    std::cout << mydict["Bro"] << "\n"; // Prints Brosies
    mydict["Bro"] = "Dude";
    std::cout << mydict["Bro"] << "\n"; // Prints "Dude"

    string& man = mydict["Bro"];
    man = "Nope";
    std::cout << mydict["Bro"] << "\n"; // Prints "Dude"
}