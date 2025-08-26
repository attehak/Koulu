x = int(input("Anna vuosi: "))
if x % 400 == 0:
    print(str(x) + " on karkausvuosi!")
elif x % 100 == 0:
    print(str(x) + " ei ole karkausvuosi..")
elif x % 4 == 0:
    print(str(x) + " on karkausvuosi!")
else:
    print(str(x) + " ei ole karkausvuosi..")