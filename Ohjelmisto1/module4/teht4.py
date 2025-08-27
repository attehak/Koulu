import random
import time
x = int(random.randint(1, 10))
y = 1
print("Tervetuloa arvauspeliin!")
time.sleep(1)
while y == 1:
    z = int(input("Arvaa numero 1 ja 10 väliltä: "))
    
    if z == x:
        print("Onnittelut voitit pelin!")
        y = 2

    elif z > x:
        print("Liian suuri arvaus")
    
    elif z < x:
        print("Liian pieni arvaus")