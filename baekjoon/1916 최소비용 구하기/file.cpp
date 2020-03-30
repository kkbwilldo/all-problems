#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1010;

int numCities,numBuses;
int depart,arrive,cost;
int Start,End;

vector <int> cities[MAX];
vector <int> costs[MAX];

int table[MAX];
bool check[MAX];

int main(){
    freopen("input.txt","r",stdin);
    cin>>numCities>>numBuses;
    for(int i=0;i<numBuses;i++){
        cin>>depart>>arrive>>cost;
        cities[depart].push_back(arrive);
        costs[depart].push_back(arrive);
     }
    cin>>Start>>End;
    for(int i=1;i<=numCities;i++) table[i]=987987987;
    table[Start]=0;
    for(int i=1;i<=numCities;i++){
        int minVal=987987987,minIdx=-1;
        for(int j=1;j<=numCities;j++){
            if(!check[j]&&minVal>table[j]){
                minVal=table[j];
                minIdx=j;
            }
        }
        check[minIdx]=true;
        for(int j=0;j<cities[minIdx].size();j++){
            int node2=cities[minIdx][j];
            int cost2=costs[minIdx][j];
            if(table[node2]>table[minIdx]+cost2){
                table[node2]=table[minIdx]+cost2;
            }
        }
    }
    cout<<table[End]<<endl;
    return 0;
}