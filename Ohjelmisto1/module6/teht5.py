lista = []

def karsia(lista):
    listaa = []
    for i in lista:
        if i % 2 == 0:
            listaa.append(i)
    return listaa

while True:
    x = input("Anna luku: ")
    if x == "":
        break
    lista.append(int(x))

print(lista)
tulos = karsia(lista)
print(tulos)