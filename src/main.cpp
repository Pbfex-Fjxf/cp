#include "my_bits.hpp"
#include "my_utils.hpp" 
// #include "my_ds.hpp"
// #include "my_algo.hpp"

int main() {
    setup_io();

    // --- code ---
    string s;
    cin >> s;
    int p=count(all(s),'+');debug(p);
    int m=count(all(s),'-');debug(m);
    cout << 1+p - m << el;

    TIME;
    return 0;
}
