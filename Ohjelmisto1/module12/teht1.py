import requests

pyyntö = "https://api.chucknorris.io/jokes/random"
vastaus = requests.get(pyyntö).json()

print(vastaus["value"])
