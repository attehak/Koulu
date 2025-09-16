import mysql.connector

yhteys = mysql.connector.connect(
    host="127.0.0.1",
    port=3306,
    database="flight_game",
    user="atte",
    password="atte",
    autocommit=True
)

def hae_maa(maa):
    sql = f"SELECT type, COUNT(*) FROM airport WHERE iso_country = '{maa}' GROUP BY type"
    kursori = yhteys.cursor()
    kursori.execute(sql)

    tulos = kursori.fetchall()
    for rivi in tulos:
        print(f"{rivi[0]}: {rivi[1]}")

hae_maa(input("Anna maakoodi (muodossa FI, US, EN...): "))
