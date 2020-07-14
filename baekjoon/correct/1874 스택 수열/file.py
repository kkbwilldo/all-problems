import sys
sys.stdin = open('input.txt', 'r')

stack=[]
answer=[]
push_num=1
flag=True

num=int(input())

for i in range(num):
	element=int(input())
	while push_num <= element:
		stack.append(push_num)
		answer.append('+')
		push_num+=1
	if stack[-1] == element:
		stack.pop()
		answer.append('-')
	else:
		flag=False
		
if flag:
	for op in answer:
		print(op)
else:
	print("NO")


