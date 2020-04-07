#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	node* head,Bhead;
	int val;
	bool isStart,isEnd,isBlue;
	node():head(NULL),Bhead(NULL),val(-1),isStart(false),isEnd(false),isBlue(false){}
	node(int _val,string type,node* _head,node* _Bhead=NULL):val(_val),head(_head),Bhead(_Bhead){
		isStart=isEnd=isBlue=false;
		if(type=="start") isStart=true;
		else if(type=="end") isEnd=true;
		else if(type=="blue") isBlue=true;		
	}
};

struct unit{
	int curPos,toGo,earned;
	unit():curPos(-1),toGo(-1),earned(-1){}
	unit(int _curPos,int _toGo,int _earned):curPos(_curPos),toGo(_toGo),earned(_earned){}
};

node nodes[33];
nodes[0]=node(0,"start",nodes[1]);
nodes[1]=node(2,"",nodes[2]);
nodes[2]=node(4,"",nodes[3]);
nodes[3]=node(6,"",nodes[4]);
nodes[4]=node(8,"",nodes[5]);
nodes[5]=node(10,"blue",nodes[6],nodes[22]);
nodes[6]=node(12,"",nodes[7]);
nodes[7]=node(14,"",nodes[8]);
nodes[8]=node(16,"",nodes[9]);
nodes[9]=node(18,"",nodes[10]);
nodes[10]=node(20,"blue",nodes[11],nodes[26]);
nodes[11]=node(22,"",nodes[12]);
nodes[12]=node(24,"",nodes[13]);
nodes[13]=node(26,"",nodes[14]);
nodes[14]=node(28,"",nodes[15]);
nodes[15]=node(30,"blue",nodes[16],nodes[28]);
nodes[16]=node(32,"",nodes[17]);
nodes[17]=node(34,"",nodes[18]);
nodes[18]=node(36,"",nodes[19]);
nodes[19]=node(38,"",nodes[20]);
nodes[20]=node(40,"",nodes[21]);
nodes[21]=node(0,"end",NULL);
nodes[22]=node(13,"",nodes[23]);
nodes[23]=node(16,"",nodes[24]);
nodes[24]=node(19,"",nodes[25]);
nodes[25]=node(25,"",nodes[31]);
nodes[26]=node(22,"",nodes[27]);
nodes[27]=node(24,"",nodes[25]);
nodes[28]=node(28,"",nodes[29]);
nodes[29]=node(27,"",nodes[30]);
nodes[30]=node(26,"",nodes[25]);
nodes[31]=node(30,"",nodes[32]);
nodes[32]=node(35,"",nodes[20]);

void Copy(unit* temp,unit* origin){
	temp.curPos=origin.curPos;
	temp.toGo=origin.toGo;
	temp.earned=origin.earned;
}

bool WeCanGo(unit* pick,int diceRoll){

}
















