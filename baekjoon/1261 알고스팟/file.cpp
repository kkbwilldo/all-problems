#include<iostream>
#include<queue>
 
using namespace std;

const int MAX = 110;
 
int row, col;
int map[MAX][MAX];
int cost[MAX][MAX];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
 
void BFS(){
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    cost[0][0] = 0;
 
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
            
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];
                
            if (nr < 0 || nc < 0 || nr >= row || nc >= col) continue;
            
            if (map[nr][nc] == 1){
                if (cost[nr][nr] > cost[r][c] + 1)
                {
                    cost[nr][nc] = cost[r][c] + 1;
                    q.push(make_pair(nr, nc));
                }
            }
            else if (map[nr][nc] == 0)
            {
                if (cost[nr][nc] > cost[r][c])
                {
                    cost[nr][nc] = cost[r][c];
                    q.push(make_pair(nr, nc));
                }
            }
        }
    }
}
 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    
    cin >> col >> row;
    for (int i = 0; i < row; i++)
    {
        char STRING[col];
        cin >> STRING;
        for (int j = 0; j < col; j++)
        {
            map[i][j] = STRING[j] - '0';
            cost[i][j] = 987987987;
        }
    }
    
    BFS();
    cout << cost[row-1][col-1] << endl;
 
    return 0;
}

