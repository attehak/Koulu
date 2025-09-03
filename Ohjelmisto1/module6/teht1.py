import random
x = int(0)
tulos = int(0)

def heitto():
    x = random.randint(1, 6)
    return x

while tulos != 6:
    tulos = heitto()
    print(tulos)