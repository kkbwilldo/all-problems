#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int maxLen,blockSize,follow,frontBlock;

int solution(string road, int n) {
	queue <int> blockSizes;
	for(int i=0;i<road.size();i++){
		if(road[i] == '1'){
			blockSize++;
			follow++;
		}
		else{
			if (blockSizes.size()<n) blockSizes.push(blockSize);
			else{
				frontBlock= blockSizes.front();
				blockSizes.pop();
				blockSizes.push(blockSize);
				follow -= frontBlock+1;
			}
			follow++;
			blockSize = 0;
		}
		maxLen = max(follow, maxLen);
	}
	return maxLen;
}
