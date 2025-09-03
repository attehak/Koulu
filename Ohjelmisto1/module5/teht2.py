z = []
x = int(input("Anna luku: "))
while x != "":
    z.append(int(x))
    x = (input("Anna luku tai paina enter: "))

z.sort(reverse=True)
print(z[:5])