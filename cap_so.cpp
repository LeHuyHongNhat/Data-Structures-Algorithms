#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
int a[MAXN], tmp[MAXN];

int merge(int l, int r) {
    if (l == r) return 0;
    int mid = (l + r) / 2;
    int cnt = merge(l, mid) + merge(mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] > a[j] && a[i] % 2 == 0 && a[j] % 2 == 0) {
            cnt += mid - i + 1;
            j++;
        } else {
            i++;
        }
    }
    i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (i = l, j = 0; i <= r; i++, j++) a[i] = tmp[j];
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int cnt = merge(0, n - 1);
    cout << cnt << endl;

    return 0;
}
