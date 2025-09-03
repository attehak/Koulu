import random
x = int(0)
tulos = int(0)

def heitto(koko):
    x = random.randint(1, koko)
    return x

koko = int(input("Anna nopan koko: "))

while tulos != koko:
    tulos = heitto(koko)
    print(tulos)