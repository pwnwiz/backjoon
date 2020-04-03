'''
https://www.acmicpc.net/problem/1437
Written in python langs
2020. 04. 03.
Wizley
'''
a = int(input())

if a <= 2:
    print(a)
    exit(0)

count = a // 3
remain = a % 3

if remain == 2:
	result = (3 ** count) * 2

elif remain == 1:
	result = ((3 ** count) // 3) * 4

else:
	result = 3 ** count

	
print(result % 10007)

