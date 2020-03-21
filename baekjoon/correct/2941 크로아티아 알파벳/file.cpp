/*
6개의 알파벳(c,d,l,n,s,z)에 대하여 처리를 다르게 했다.
6개의 알파벳이 아니면 cnt를 증가시키고 방문처리 시킨다.
6개의 알파벳이면 다음 인덱스가 존재하는지 확인한 후 크로아티아 알파벳인지 확인한다.
*/
#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

const int MAX=110;

int size,cnt;
string modified;
bool visited[110];

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	
	cin>>modified;
	size=modified.size();
	for(int i=0;i<size;i++){
		if(visited[i]) continue;
		if(modified[i]!='c'&&modified[i]!='d'&&modified[i]!='l'&&\
		modified[i]!='n'&&modified[i]!='s'&&modified[i]!='z'){
			cnt++;
			visited[i]=true;
		}
		else{
			if(modified[i]=='c'){
				visited[i]=true;
				cnt++;
				if(i+1>=size) continue;
				if(modified[i+1]=='='||modified[i+1]=='-') visited[i+1]=true;
			}
			else if(modified[i]=='l'||modified[i]=='n'){
				visited[i]=true;
				cnt++;
				if(i+1>=size) continue;
				if(modified[i+1]=='j') visited[i+1]=true;
			}
			else if(modified[i]=='s'||modified[i]=='z'){
				visited[i]=true;
				cnt++;
				if(i+1>=size) continue;
				if(modified[i+1]=='=') visited[i+1]=true;
			}
			else if(modified[i]=='d'){
				visited[i]=true;
				cnt++;
				if(i+1>=size) continue;
				if(modified[i+1]=='-') visited[i+1]=true;
				else if(modified[i+1]=='z'){
					if(i+2>=size) continue;
					if(modified[i+2]=='='){
						visited[i+1]=visited[i+2]=true;
					}
				}
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
