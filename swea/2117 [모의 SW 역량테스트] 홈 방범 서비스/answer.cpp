#include<iostream>
#include<cstring>
#include<queue>
 
#define endl "\n"
#define MAX 20
using namespace std;
 
int N, M, Answer;
int MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
int Bigger(int A, int B) { if (A > B) return A; return B; }
 
void Initialize()
{
    Answer = 0;
    memset(MAP, 0, sizeof(MAP));
    memset(Visit, false, sizeof(Visit));
}
 
void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
 
int Company_Benefit(int k)
{
    return (k * k) + (k - 1)*(k - 1);
}
 
void BFS(int a, int b)
{
    int House_Cnt = 0;
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    Visit[a][b] = true;
 
    if (MAP[a][b] == 1) House_Cnt++;
    int Service = 1;
 
    while (Q.empty() == 0)
    {
        if (Service > N + 1) break;
        if (House_Cnt * M - Company_Benefit(Service) >= 0) Answer = Bigger(Answer, House_Cnt);
        int S = Q.size();
 
        for (int Qs = 0; Qs < S; Qs++)
        {
            int x = Q.front().first;
            int y = Q.front().second;
            Q.pop();
 
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
 
                if (nx >= 0 && ny >= 0 && nx < N && ny < N)
                {
                    if (Visit[nx][ny] == false)
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(nx, ny));
                        if (MAP[nx][ny] == 1) House_Cnt++;
                    }
                }
            }
        }
        Service++;
    }
}
 
void Solution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            memset(Visit, false, sizeof(Visit));
            BFS(i, j);
        }
    }
}
 
void Solve()
{
    int Tc; cin >> Tc;
    for (int T = 1; T <= Tc; T++)
    {
        Initialize();
        Input();
        Solution();
 
        cout << "#" << T << " " << Answer << endl;
    }
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}

