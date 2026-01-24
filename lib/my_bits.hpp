#pragma once
#include <bits/stdc++.h>
using namespace std;

// --- setup ---
inline void setup_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15); 
}

// --- macro ---
#define rep(i,x,limit) for (int i = (int)x; i < (int)limit; i++)
#define REP(i,x,limit) for (int i = (int)x; i <= (int)limit; i++)
#define repd(i,x,limit) for (int i = (int)x; i > (int)limit; i--)
#define REPD(i,x,limit) for (int i = (int)x; i >= (int)limit; i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define el '\n'
#define spa " "
#define Yes cout << "Yes" << el
#define No cout << "No" << el
#define YES cout << "YES" << el
#define NO cout << "NO" << el
#define yes cout << "yes" << el
#define no cout << "no" << el
#define eps (1e-10)
#define Equals(a,b) (abs((a) - (b)) < eps )

// --- timer ---
class Timer{
    chrono::system_clock::time_point start;
    public:
        Timer() : start(chrono::system_clock::now()) {}
        double count(){
            chrono::duration<double> Time_ = chrono::system_clock::now() - start;
            return Time_.count();
        }
        bool is_under(double x){
            return (this -> count()) < x;
        }
};

#ifdef DEBUG
    inline Timer _global_timer;
    #define debug(x) cerr << "[DEBUG] " << #x << " = " << x << " (L" << __LINE__ << ")" << el
    #define TIME cerr << "[TIME] " << _global_timer.count() << "s" << el
    #define BENCH(process) \
        { Timer _t; process; cerr << "[BENCH] " << #process << ": " << _t.count() << "s" << el; }
#else
    #define debug(x)
    #define TIME
    #define BENCH(process) process
#endif

// --- type alias ---
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

// --- numbers/ strings ---
const double pi = 3.141592653589793238;
const int inf = 1073741823; // 2^30 - 1
const ll infl = 1LL << 60;
constexpr string_view ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr string_view abc = "abcdefghijklmnopqrstuvwxyz";
