x = set()
z = input("Anna nimi: ")
x.add(z)
print("Uusi nimi")

while True:
    z = input("Anna nimi: ")
    if z == "":
        break

    if z in x:
        print("Aiemmin syötetty nimi")

    else:
        print("Uusi nimi")
        x.add(z)

for i in x:
    print(i)
