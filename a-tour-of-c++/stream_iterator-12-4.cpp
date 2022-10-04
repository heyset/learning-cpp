#include <vector>
#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector, std::string;
// using std::string;

int main(int argc, char** argv)
{
    (void) argc;
    string from { argv[1] };
    string to { argv[2] };

    std::ifstream fin { from };
    std::istream_iterator<string> fin_begin { fin };
    std::istream_iterator<string> fin_end { };


    std::ofstream fout { to };
    std::ostream_iterator<string> fout_begin { fout, "\n" };
    std::transform(fin_begin, fin_end, fout_begin, [=](string line) {
        string new_line;

        for (auto c : line)
            new_line += toupper(c);
        
        return new_line;
    });

    // std::copy(fin_begin, fin_end, fout_begin);

    // vector<string> myvec { fin_begin, fin_end };

    // for (auto x : myvec)
    //     std::cout << x << "\n";
}
