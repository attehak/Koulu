x = input("Sukupuoli? (mies/nainen): ")
y = int(input("Hemoglobiiniarvosi (g/l): "))
if x=="mies":
    if y<134:
        print("Alhainen")
    elif (y>=134 and y<=195):
        print("Normaali")
    elif y>195:
        print("Korkea")
elif x=="nainen":
    if y<117:
        print("Alhainen")
    elif (y>=117 and y<=175):
        print("Normaali")
    elif y>175:
        print("Korkea")