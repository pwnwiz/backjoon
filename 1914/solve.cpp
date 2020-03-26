'''
https://www.acmicpc.net/problem/1914
Written in python langs
2020. 03. 26.
Wizley
'''

def hanoi(n, f, p, t):
	if n == 1:
		print(str(f) + ' ' + str(t))
	else:
		hanoi(n-1, f, t, p)
		print(str(f) + ' ' + str(t))
		hanoi(n-1, p, f, t)

n = int(input())

if n <= 20:
	print(2**n-1)
	hanoi(n, 1, 2, 3)

else:
	print(2**n-1)	

