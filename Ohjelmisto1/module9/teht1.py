class Auto:
    def __init__(self, rekkari, max_speed, speed, matka):
        self.rekkari = rekkari
        self.max_speed = max_speed
        self.speed = speed
        self.matka = matka
        pass

auto1 = Auto("ABC-123", 142, 0, 0)

print(f"Auton {auto1.rekkari} huippunopeus on {auto1.max_speed}km/h. Nykyinen nopeus on {auto1.speed}km/h. Ja kuljettu matka on {auto1.matka}km.")
