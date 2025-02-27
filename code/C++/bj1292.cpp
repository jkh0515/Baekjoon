//1292 쉽게 푸는 문제 - C++17
//메모리 : 2020KB / 시간 : 0ms
//2024년 7월 18일 01:09:19

#include <iostream>

using namespace std;
int main(){
	int i, j, arr[1001], n, m, ans=0, k=1;
	for(i=1;i<=1000;i++){
		for(j=1;j<=i;j++){
			arr[k]=i;
			if(k>1000) break;
			k++;
		}
	}
	cin>>n>>m;
	for(int i=n; i<=m; i++)
		ans+=arr[i];
	cout<<ans;
    return 0;
}