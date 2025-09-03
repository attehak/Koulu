gallon = int(0)
def laskuri(gallon):
    litra = gallon * 3.785
    return litra
gallon = int(input("Anna gallonat: "))
tulos = laskuri(gallon)
print(str(tulos) + " Litraa")