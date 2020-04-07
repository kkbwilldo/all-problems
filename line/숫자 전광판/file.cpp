#include <iostream>
#define endl '\n'
#define align _align
using namespace std;

int n,cols[105],align,maxRow;
char numbers[105][15];
string alignString;

void input(){
	cin>>n>>alignString;
	if(alignString[0]=='T') align=0;
	else if(alignString[0]=='M') align=1;
	else align=2;

	int max=-1;
	for(int i=0;i<n;i++){
		cin>>cols[i]>>numbers[i];
		if(max<cols[i]) max=cols[i];
	}
	maxRow=2*max-1;
}

int numberPad[10][5]=
{
	{0,3,3,3,0}, // 0
	{1,1,1,1,1}, // 1
	{0,1,0,2,0}, // 2
	{0,1,0,1,0}, // 3
	{3,3,0,1,1},
	{0,2,0,1,0},
	{2,2,0,3,0},
	{0,1,1,1,1},
	{0,3,0,3,0},
	{0,3,0,1,1},
};

void printShape(int type,int col){
	for(int i=0;i<col;i++){
		if(i==0){
			if(type==1||type==4) cout<<".";
			else cout<<"#";
		}
		else if(i==col-1){
			if(type==2||type==4) cout<<".";
			else cout<<"#";
		}
		else{
			if(type!=0) cout<<".";
			else cout<<"#";
		}
	}
}

int getAreaType(int row,int curRow){
	int gap=maxRow-row,margin;
	
	if(align==0) margin=0;
	else if(align==1) margin=gap/2;
	else margin=gap;
	
	int top=0+margin;
	int middle=row/2+margin;
	int bottom=row-1+margin;
	
	if(curRow==top) return 0;
	else if(top<curRow&&curRow<middle) return 1;
	else if(curRow==middle) return 2;
	else if(middle<curRow&&curRow<bottom) return 3;
	else if(curRow==bottom) return 4;
	else return -1;
}

void printNumber(int number,int row,int col,int curRow){
	int areaType=getAreaType(row,curRow);
	int shapeType=areaType<0?4:numberPad[number][areaType];
	printShape(shapeType,col);
}

void print(){
	for(int row=0;row<maxRow;row++){
		for(int i=0;i<n;i++){
			for(int numberIdx=0;numbers[i][numberIdx]!='\0';numberIdx++){
				int r=cols[i]*2-1;
				int c=cols[i];
				printNumber(numbers[i][numberIdx]-'0',r,c,row);
				cout<<" ";
			}
		}
		cout<<endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	freopen("input.txt","r",stdin);
	input();
	print();
	
	return 0;
}
