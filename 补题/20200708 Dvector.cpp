using pll = pair<ll, ll>;
using vint = vector<ll>;

vector<pll> midware[MAXN];
ll ans[MAXN][2];

void process(const vector<pll> &p, int tp) 
{

    for (int i = 0; i <= 20005; ++i) {
        midware[i].clear();
    }

    for (auto &pi:p) {
        midware[pi.first].emplace_back(pi.second, int(&pi - &p.front()));
    }

    for (int i = 0; i <= 20005; ++i) {
        if (midware[i].size() < 2) continue;
        auto &a = midware[i];
        sort(a.begin(), a.end());

        ll sum = 0;
        for (auto ai:a) {
            sum += abs(ai.first - a.front().first);
        }

        ll pid = a.front().second;
        ll len = a.size();
        ans[pid][tp] = sum;

        for (ll j = 1; j < len; ++j) {
            pid = a[j].second;
            sum += abs(a[j].first - a[j - 1].first)
                   * (j - (len - j));
            ans[pid][tp] = sum;
        }
    }
}

void solve(int kaseId = -1) 
{
    int n;
    cin >> n;
    vector<pll> p(n);

    for (auto &pi:p) {
        cin >> pi.first >> pi.second;
        pi.first += 10000ll;
        pi.second += 10000ll;
    }

    process(p, 0);
    for (auto &pi:p) swap(pi.first, pi.second);
    process(p, 1);

    ll result = 0;

    for (int i = 0; i < n; ++i) {
        result = (result + ans[i][0] * ans[i][1] % MOD) % MOD;
    }

    cout << result << endl;
}
