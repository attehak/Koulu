import time
y = 1
q = 0
k = 1
s = 1
while y == 1:
    if int(q) == 5:
        print("Pääsy evätty")
        break
    # Tarkastaa onko yritetty (q) vielä 5 kertaa

    x = input("Käyttäjätunnus: ")
    z = input("Salasana: ")
    
    if x == "python":
        k = 2
    elif x != "python":
        print("Käyttäjätunnus väärin!")
    # Testaa onko käyttäjätunnus oikein, jos ei se printtaa viestin. Jos oikein se muuttaa k:n kahdeksi joka tarkastetaan myöhemmin

    if z == "rules":
        s = 2
    elif z != "rules":
        print("Salasana väärin!")
    # Sama tässä. Jos oikein vaihetaan s kahteen

    if (int(k) == 2 and int(s) == 2):
        print("Tervetuloa!")
        y = 2
    # Nyt testataan jos k ja s on oikein (2) vai väärin (1)

    else:
        k = 1
        s = 1
        q = int(q) + 1
        time.sleep(0.8)
        # k ja s vaihdetaan takaisin 1 jottei käyttäjä pääse vahingossa sisään ja lisätään q + 1 