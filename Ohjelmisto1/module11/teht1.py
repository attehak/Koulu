class Julkaisu:
    kirja_määrä = 0
    def __init__(self, kirjan_nimi):
        Julkaisu.kirja_määrä = Julkaisu.kirja_määrä + 1
        self.kirja_numero = Julkaisu.kirja_määrä
        self.kirjan_nimi = kirjan_nimi

    def tulosta_tiedot(self):
        print(f"{self.kirja_numero}: {self.kirjan_nimi}")

class Kirja(Julkaisu):
    def __init__(self, kirjan_nimi, kirjoittaja, sivumäärä):
        super().__init__(kirjan_nimi)
        self.kirjoittaja = kirjoittaja
        self.sivumäärä = sivumäärä

    def tulosta_tiedot(self):
        super().tulosta_tiedot()
        print(f"Kirjoittaja: {self.kirjoittaja}\nsivumäärä: {self.sivumäärä}")

class Lehti(Julkaisu):
    def __init__(self, kirjan_nimi, päätoimittaja):
        super().__init__(kirjan_nimi)
        self.päätoimittaja = päätoimittaja
    
    def tulosta_tiedot(self):
        super().tulosta_tiedot()
        print(f"Päätoimittaja: {self.päätoimittaja}")

julkaisut = []
julkaisut.append(Lehti("Aku Ankka", "Aki Hyyppä"))
julkaisut.append(Kirja("Hytti n:o 6", "Rosa Liksom", "200"))

for j in julkaisut:
    print(j.tulosta_tiedot())
