'''
python3 file.py < input.txt
'''
import sys

testcase=int(input())
for test in range(testcase):
	a,b=map(int,sys.stdin.readline().split())
	print(a+b)
	
