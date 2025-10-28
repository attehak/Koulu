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

if __name__ == "__main__":
    h = Hissi(10, 1)
    h.siirry_kerrokseen(5)
    time.sleep(3)
    h.siirry_kerrokseen(1)
