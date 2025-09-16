import mysql.connector


yhteys = mysql.connector.connect(
    host="127.0.0.1",
    port=3306,
    database="flight_game",
    user="atte",
    password="atte",
    autocommit=True
)


def hae_lentokentta(icao):
    sql = f"SELECT * FROM airport WHERE ident = '{icao}'"
    kursori = yhteys.cursor()
    kursori.execute(sql)

    tulos = kursori.fetchone()
    print(tulos[3], tulos[10])

hae_lentokentta(str(input("Anna ICAO koodi: ")))
