from flask import Flask, Response
import json

#Aja ohjelma ja mene esim http://127.0.0.1:3000/summa/31

app = Flask(__name__)

@app.route('/summa/<luku>')
def summa(luku):
    try:
        luku = float(luku)
        z = True

        if luku <= 1:
            z = False
        else:
            for i in range(2, int(luku**0.5) + 1):
                if luku % i == 0:
                    z = False
                    break

        tilakoodi = 200
        vastaus = {
            "status": tilakoodi,
            "Number": luku,
            "isPrime": "true" if z else "false"
        }

    except ValueError:
        tilakoodi = 400
        vastaus = {
            "status": tilakoodi,
            "teksti": "Virheellinen numero"
        }

    jsonvast = json.dumps(vastaus)
    return Response(response=jsonvast, status=tilakoodi, mimetype="application/json")

@app.errorhandler(404)
def page_not_found(virhekoodi):
    vastaus = {
        "status" : 404,
        "teksti" : "Virheellinen päätepiste"
    }
    jsonvast = json.dumps(vastaus)
    return Response(response=jsonvast, status=404, mimetype="application/json")

if __name__ == '__main__':
    app.run(use_reloader=True, host='127.0.0.1', port=3000)
