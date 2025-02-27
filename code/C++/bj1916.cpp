//1916 최소비용 구하기 - C++17
//메모리 : 7276KB / 시간 : 32ms
//2024년 2월 1일 21:17:17

#include <queue>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<long, int> li; // pair<long, int>가 너무 기니 li로 이름을 바꾸어 진행

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long check[1001]; // 각 도시별 방문 확인 및 최저 가중치 확인 용도 배열
  fill(check, check+1001, -1e9); // check 배열을 전부 -1e9(어떤 경우에도 넘을 수 없는 값)로 저장
  vector<li> vt[1001]; // 벡터 배열, 인덱스 = 도시 번호 / 삽입된 정보 = {버스 , 가중치}
  priority_queue<li> pq; // li(long, int)자료형을 가진 우선순위 큐 선언
  int n, m, a, b, c, i, start, end;
  cin >> n >> m; // 도시 개수, 버스 개수 입력
  for(i=0;i<m;i++) {
      cin >> a >> b >> c; // 출발 도시, 도착 도시, 가중치
      vt[a].push_back({b, c}); // {도착도시, 가중치} 정보를 출발도시 번호를 인덱스로 가지고 있는 벡터에 삽입
  }
  cin >> start >> end; // 진짜 원하는 경로 입력
  check[start] = 0; // 첫번째 도시를 방문했다 저장하기 
  pq.push({0, start}); // 첫번째 도시를 가중치를 0으로 두어 삽입하기
  while(!pq.empty()) { // 우선순위 큐가 빌때까지 반복
    long tweight = pq.top().first; // 가지고 있는 정보 중 가장 낮은 가중치
    int tnode = pq.top().second; // 가중치가 제일 낮은 노드
    pq.pop(); // 저장했으니 pop 해버리기
    if(check[tnode] < tweight) continue; // 노드에 들어있는 가중치가 현재 가중치보다 높으면 continue
    if(tnode == end) { // end노드에 도달했다면 출력하고 끝내기!! 
        cout << tweight*-1;
        break;
    }
    for(i=0;i<vt[tnode].size();i++) {
      if(check[vt[tnode][i].first] < tweight-vt[tnode][i].second) { // 다음 노드로 가는 가중치가 현재 가중치보다 낮다면
        pq.push({tweight-vt[tnode][i].second, vt[tnode][i].first}); // 다음 노드로 가는 가중치와 다음 노드 번호 삽입 
        check[vt[tnode][i].first] = tweight-vt[tnode][i].second; // 최솟값이 변경되었으니 해당 노드의 최소값 수정
      }
    }
  }
  return 0;
}