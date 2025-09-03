lista = []
x = 0

def laskuri(lista):
    summa = sum(lista)
    return summa

while True:
    x = input("Anna luku: ")
    if x == "":
        break
    lista.append(int(x))

tulos = laskuri(lista)
print(tulos)