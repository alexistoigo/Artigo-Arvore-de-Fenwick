#pragma GCC optimize("Ofast,02")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define ll long long
#define MAX int32_t(1e5+10)
//const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;
using namespace std::chrono;

int n, bit[MAX];

ll sum(int pos) {
    ll soma = 0;
    while (pos > 0) {
        soma += bit[pos];
        pos -= (pos & -pos);
    }
    return soma;
}

void update(int i, int val) {
    while (i <= n) {
        bit[i] += val;
        i += (i & -i);
    }
}

int main() {

    IO

    auto start = high_resolution_clock::now();

    cin >> n;
    int x;
    char op;
    vector<int> vet(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> vet[i], update(i, vet[i]);

    while (cin >> op >> x) {
        if (op == '?') cout << (sum(x) - long(vet[x])) << "\n";
        else update(x, -vet[x]);
    }

    auto stop = high_resolution_clock::now();
    cout << "Tempo de execucao: " << duration_cast<microseconds>(stop - start).count() << " microseconds" << endl;


    return 0;
}
