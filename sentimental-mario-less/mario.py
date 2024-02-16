# TODO
from cs50 import get_int

while True:
    try:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break
    except:
        print("Error!")
        exit()

for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i)
