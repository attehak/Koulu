x = int(input("Anna luku: "))
z = True
if x <= 1:
    z = False

else:
    for i in range(2, int(x**0.5) + 1):
        if x % i == 0:
            z = False
            break

if z == True:
    print("On")
else:
    print("Ei oo")