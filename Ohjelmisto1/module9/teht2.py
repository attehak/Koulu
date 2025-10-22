class Auto:
    def __init__(self, rekkari, max_speed, speed, matka):
        self.rekkari = rekkari
        self.max_speed = max_speed
        self.speed = speed
        self.matka = matka

    def muuta_nopeutta(self, uusi_nopeus):
        if uusi_nopeus > self.max_speed:
            uusi_nopeus = self.max_speed
            print("Liian nopea!")
        elif uusi_nopeus < 0:
            uusi_nopeus = 0
            print("Ei voi olla alle 0!")

        kiihtyvyys = uusi_nopeus - float(self.speed)
        self.speed = uusi_nopeus
        return kiihtyvyys


auto1 = Auto("ABC-123", 142, 0, 0)

print(f"Auton {auto1.rekkari} huippunopeus on {auto1.max_speed}km/h. Nykyinen nopeus on {auto1.speed}km/h. Ja kuljettu matka on {auto1.matka}km.")
auto1.speed = input("Anna auton nopeus:\n>")
while True:
    syote = input("Anna uusi nopeus:\n>")
    if syote == "":
        break
    uusi_nopeus = float(syote)
    kiihtyvyys = auto1.muuta_nopeutta(uusi_nopeus)
    print(f"Kiihtyvyys on {kiihtyvyys} km/h.")
    print(f"Auton nopeus on nyt {auto1.speed} km/h.\n")
