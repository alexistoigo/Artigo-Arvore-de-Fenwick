#include <bits/stdc++.h>

#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define MAX int32_t(1e5+10)
//const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
using namespace std::chrono;

int n;

int main() {

    IO

#ifndef ONLINE_JUDGE
    FIN
//    FOUT
#endif

    auto start = high_resolution_clock::now();

    cin >> n;
    int x;
    char op;

    vector<ll> buggies(n);

    for (int i = 0; i < n; i++) {
        cin >> buggies[i];
    }

    while (cin >> op >> x) {
        if (op == '?') {
            ll sum = 0;
            for (int i = 0; i < x - 1; i++) sum += buggies[i];
            cout << sum << endl;
        } else buggies[x - 1] = 0;

    }

    auto stop = high_resolution_clock::now();
    cout << "Tempo de execucao: " << duration_cast<milliseconds>(stop - start).count() << " milliseconds" << endl;


    return 0;
}
