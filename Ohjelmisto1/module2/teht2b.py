import time
import math
x = float(input('Anna ympyrän säde: '))
print("Odota hetki kun lasken..")
print("...")
time.sleep(1)
print("..")
time.sleep(0.7)
print(".")
time.sleep(0.5)
z = math.pi * x ** 2
print("Selvä tässä on ympyrän pinta-ala: " + str(z))
