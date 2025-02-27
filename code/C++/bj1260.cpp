//1260 DFS와 BFS - C++17
//메모리 : 2392KB / 시간 : 8ms
//2024년 5월 11일 00:30:00

#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
 
vector<int> vec[10002];
vector<int> result_bfs;
vector<int> result_dfs;
bool visit[1002];
 
void bfs(int temp){
    queue<int> q;
    q.push(temp);
    visit[temp] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        result_bfs.push_back(x);
 
        for (int i = 0; i < vec[x].size(); i++){
            if(!visit[vec[x][i]]){ //방문하지 않은 곳만 탐색
                q.push(vec[x][i]); 
                visit[vec[x][i]] = true;
            }
        }
    }
}
 
void dfs(int x){
    visit[x] = true;
    result_dfs.push_back(x);
 
    for (int i = 0; i < vec[x].size(); i++){
        if(!visit[vec[x][i]]){ //방문하지 않은 곳만 탐색
            dfs(vec[x][i]);
        }
    }
}
 
int main(){
    int n, m, v, a, b;
    cin >> n >> m >> v;
 
    for (int i = 1; i <= m;i++){
        cin >> a >> b;
        vec[a].push_back(b); //양방향 간선처리
        vec[b].push_back(a); //양방향 간선처리
    }
    for (int i = 1; i <= n;i++){
        sort(vec[i].begin(), vec[i].end()); // 낮은 숫자부터 탐색.
    }
    bfs(v);
    memset(visit, false, sizeof(visit));
    dfs(v);
    for (int i = 0; i < result_dfs.size() ;i++){
        cout << result_dfs[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < result_bfs.size() ;i++){
        cout << result_bfs[i] << " ";
    }
    
    return 0;
}