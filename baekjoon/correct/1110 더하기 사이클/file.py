import sys
sys.stdin = open('input.txt','r')

num=int(input())
temp=num
answer=0

while 1 :
	ten=temp//10
	one=temp%10
	Sum=ten+one
	Next=one*10+Sum%10
	answer+=1
	temp=Next
	if temp==num:
		break
		
print(answer)
	
		

