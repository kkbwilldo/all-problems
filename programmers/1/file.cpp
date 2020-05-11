#include <string>
#include <vector>
#include <tuple>

using namespace std;

tuple<int, int> keys[13];
string solution(vector<int> numbers, string hand){
	string answer = "";
    for(int i=1;i<=12;i++){
        int r=(i-1)/3;
        int c=(i-1)%3;
		keys[i]=make_tuple(r,c); 
	}
	tuple<int, int> Left = make_tuple(3,0); 
	tuple<int, int> Right = make_tuple(3,2);

    for(int i=0;i<numbers.size();i++){
        int pick=numbers[i];
        if(pick==1||pick==4||pick==7) {
			answer+="L";
			Left=keys[pick];
		}
        else if(pick==3||pick==6||pick==9) {
			answer+="R";
			Right=keys[pick];
		}
        else {
			tuple<int,int> inMiddle;
            if(pick==0) inMiddle=keys[11];
			else inMiddle=keys[pick];
			int LR=get<0>(Left);
			int LC=get<1>(Left);
			int RR=get<0>(Right);
			int RC=get<1>(Right);
			int MR=get<0>(inMiddle);
			int MC=get<1>(inMiddle);
            int fromLeft=abs(LR-MR)+abs(LC-MC);
            int fromRight=abs(RR-MR)+abs(RC-MC);
            if(fromLeft==fromRight){
            	if(hand=="left") {
					answer+="L";
					Left=inMiddle;
				}
				else if(hand=="right"){
					answer+="R";
					Right=inMiddle;
				}
			}
            else if(fromLeft<fromRight) {
				answer+="L";
				Left=inMiddle;
			}
			else if(fromLeft>fromRight) {
				answer+="R";
				Right=inMiddle;
			}
		}
	}
    return answer;
}
