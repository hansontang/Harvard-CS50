# TODO
from cs50 import get_string


def main():
    text = get_string("Text:")
    grade = get_grade(text)
    if grade < 0:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def get_grade(text):
    letter = 0
    word = 0
    sentence = 0
    number = 0
    check = 0
    n = len(text)
    new_text = text.split(" ")
    word = len(new_text)
    for s in text:
        if s.isalpha():
            letter += 1
        elif s == "." or s == "!" or s == "?":
            sentence += 1
    L = letter / word * 100
    S = sentence / word * 100
    grade = round(0.0588 * L - 0.296 * S - 15.8)
    return grade


main()
