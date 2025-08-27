y = 1
min = 999999999
max = 0
while y == 1:
    x = input("Anna luku: ")
    if x == "":
        y = 2
    elif int(x) < int(min):
        min = x
    elif int(x) > int(max):
        max = x
print("Pienin luku: " + str(min))
print("Suurin luku: " + str(max))
