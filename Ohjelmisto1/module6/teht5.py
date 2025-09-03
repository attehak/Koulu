lista = []

def karsia(lista):
    for i in lista:
        if i % 2 != 0:
            lista.remove(i)
    return lista

while True:
    x = input("Anna luku: ")
    if x == "":
        break
    lista.append(int(x))

print(lista)
tulos = karsia(lista)
print(lista)