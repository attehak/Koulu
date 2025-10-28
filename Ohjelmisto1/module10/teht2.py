import time

class Hissi:
    def __init__(self, ylin, alin):
        self.ylin = ylin
        self.alin = alin
        self.nykyinen = alin

    def kerros_ylös(self):
        time.sleep(1)
        if self.nykyinen < self.ylin:
            self.nykyinen += 1
            print(f"Hissi on nyt kerroksessa {self.nykyinen}")
        else:
            print("Hissi on jo ylimmässä kerroksessa.")

    def kerros_alas(self):
        time.sleep(1)
        if self.nykyinen > self.alin:
            self.nykyinen -= 1
            print(f"Hissi on nyt kerroksessa {self.nykyinen}")
        else:
            print("Hissi on jo alimmassa kerroksessa")

    def siirry_kerrokseen(self, kohde):
        print(f"Hissi liikkuu kerrokseen {kohde}")
        while self.nykyinen < kohde:
            self.kerros_ylös()
        while self.nykyinen > kohde:
            self.kerros_alas()

class Talo:
    def __init__(self, ylin, alin, hissie_määrä):
        self.hissit = [Hissi(ylin, alin) for _ in range(hissie_määrä)]

    def aja_hissiä(self, hissi_numero, kohdee):
        if 0 <= hissi_numero < len(self.hissit):
            print(f"\nHissi numero {hissi_numero + 1} liikkuu:")
            self.hissit[hissi_numero].siirry_kerrokseen(kohdee)
        else:
            print("Virhe")



if __name__ == "__main__":
    talo = Talo(10, 1, 4)
    talo.aja_hissiä(0, 5)
    talo.aja_hissiä(1, 3)
    talo.aja_hissiä(2, 11)
    talo.aja_hissiä(0, 1)
