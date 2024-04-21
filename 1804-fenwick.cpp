#include <bits/stdc++.h>

#define IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
#define FIN freopen("entrada.txt", "r", stdin);
#define FOUT freopen("saida.sol", "w", stdout);
#define ull unsigned long long
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define MAX int(1e5+6)

const int INF = 0x3f3f3f3f;
using namespace std;

int n, bit[MAX];

int sum(int pos) {
    int soma = 0;
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

    cin >> n;
    int x;
    char op;
    vector<int> vet(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> vet[i], update(i, vet[i]);

    while (cin >> op >> x) {
        if (op == '?') cout << sum(x) - vet[x] << "\n";
        else update(x, -vet[x]);
    }

    return 0;
}
