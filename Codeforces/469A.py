a = int(input())
p = [*map(int, input().split())][1:]
q = [*map(int, input().split())][1:]
if set(range(1, a+1)) == (set(p) | set(q)):
    print("I become the guy.")
else:
    print("Oh, my keyboard!")
