import random
x = int(input("anna luku: "))
z = int(0)
y = int(0)

for i in range(x):
    z = int(random.randint(1, 6))
    y = y + z
print(y)