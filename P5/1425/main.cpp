#include <iostream>
using namespace std;

const int N = 1e6, M = 1e6;
int q[N], temp[N];
int n, m;

void merge_sort(int p[], int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(p, l, mid), merge_sort(p, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] < q[j]) temp[k++] = q[i++];
        else temp[k++] = q[j++];
    while (i <= mid) temp[k++] = q[i++];
    while (j <= r) temp[k++] = q[j++];

    for (int i = l, j = 0; i <= r; ++i, ++j) q[i] = temp[j];

}

void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;
    int x = q[(l + r) / 2], i = l - 1, j = r + 1;
    while (i < j)
    {
        do i++; while (q[i] < x);
        do j--; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j + 1, r);
}

int main()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; ++i) scanf("%d", &q[i]);

        // for (int i = 0; i < n; ++i) printf("%d ", q[i]);
        quick_sort(q, 0, n - 1);

        for (int i = n - 1; i >= n - m; --i) printf("%d ", q[i]);
        cout << endl;
    }
    return 0;
}