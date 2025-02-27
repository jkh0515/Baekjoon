//2751 수 정렬하기 2 - C++17
//메모리 : 80144KB / 시간 : 476ms
//2023년 8월 7일 00:15:01

#include <iostream>
using namespace std;
int arr[10000000];
int ans[10000000];

void merges(int left, int right) {
    int mid = (left + right) / 2;
    int i = left, j = mid+1, k = left;
    while(i <= mid and j <= right) {
        if(arr[i] > arr[j]) {
            ans[k++] = arr[j++];
        }
        else {
            ans[k++] = arr[i++];
        }
    }
    if(i > mid) {
        while(j <= right) {
            ans[k++] = arr[j++];
        }
    }
    else {
        while(i <= mid) {
            ans[k++] = arr[i++];
        }
    }
    for(int a=left;a<=right;a++) {
        arr[a] = ans[a];
    }
}

void partition(int left, int right) {
    int mid;
    if(left < right) {
        mid = (left + right) / 2;
        partition(left, mid);
        partition(mid+1, right);
        merges(left, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    // cin >> n;
    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }
    partition(0,n-1);

    for(int i=0;i<n;i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}