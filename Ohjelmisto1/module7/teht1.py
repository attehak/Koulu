x = (
    ("talvi", (11, 12, 1)),
    ("kevät", (2, 3, 4)),
    ("kesä", (5, 6, 7)),
    ("syksy", (8, 9, 10))
)
z = int(input("anna kuukausi (1-12): "))

for y, a in x:
    if z in a:
        print(f"{z} on {y}.")
        break
