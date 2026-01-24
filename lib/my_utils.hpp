#pragma once
#include "my_bits.hpp"

// chmax(a,b); chmin(a,b);
template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) {
    if (a < b) { a = b; return true; }
    return false;
}
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) {
    if (a > b) { a = b; return true; }
    return false;
}

template<typename T> inline void print_vec(const vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << (i == (int)v.size() - 1 ? "" : spa);
    }
    cout << el;
}

#ifdef DEBUG
template<typename T> inline void debug_vec(const vector<T> &v) {
    cerr << "{ ";
    for (int i = 0; i < (int)v.size(); i++) {
        if constexpr(is_integral<T>::value) {
            if (v[i] >= inf/2) cerr << "INF"; // infに近い値もINF扱い
            else cerr << v[i];
        } else {
            cerr << v[i];
        }
        cerr << (i == (int)v.size() - 1 ? " " : ", ");
    }
    cerr << "}" << el;
}
#else
#define debug_vec(v)
#endif
