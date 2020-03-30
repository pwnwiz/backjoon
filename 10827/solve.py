'''
https://www.acmicpc.net/problem/10827
Written in python langs
2020. 03. 30.
Wizley
'''
a,b = map(str, input().split())
digit = len(a.split('.')[1]) * int(b)

aa = a.replace('.', '')
multiply = str(int(aa) ** int(b))

if a.split('.')[0] == '0':
	multiply = '0'*(digit+1-len(multiply)) + multiply

print(multiply[:len(multiply)-digit]+'.'+multiply[len(multiply)-digit:])
