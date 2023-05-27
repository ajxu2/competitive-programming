a = int(input())
for i in range(a):
    if i % 2 == 0:
        print("I hate ", end="")
    else:
        print("I love ", end="")
    if i == a-1:
        print("it")
    else:
        print("that ", end="")
