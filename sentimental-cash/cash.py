# TODO

from cs50 import get_float


def main():
    dollar = get_dollar()
    cents = int(dollar * 100)
    quarters = calculate_quarters(cents)
    cents -= quarters * 25
    dimes = calculate_dimes(cents)
    cents -= dimes * 10
    nickels = calculate_nickels(cents)
    cents -= nickels * 5
    pennies = calculate_pennies(cents)
    cents -= pennies * 1
    coin = quarters + dimes + nickels + pennies
    print(coin)


def get_dollar():
    while True:
        try:
            cents = get_float("Change owed: ")
            if cents >= 0:
                break
        except:
            print("error")
            exit()
    return cents


def calculate_quarters(cents):
    return cents // 25


def calculate_dimes(cents):
    return cents // 10


def calculate_nickels(cents):
    return cents // 5


def calculate_pennies(cents):
    return cents


main()
