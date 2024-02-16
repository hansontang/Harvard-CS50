import csv
import sys


def main():
    # TODO: Check for command-line usage
    n = len(sys.argv)
    if n == 1 or n == 2:
        text = get_string("Usage:")
        question = text.spilit(" ")
        csvfile = "databases/" + question[-2]
        txtfile = "sequences/" + question[-1]

    elif n == 3:
        csvfile = sys.argv[-2]
        txtfile = sys.argv[-1]

    else:
        print("check your input")
        exit()

    # TODO: Read database file into a variable
    data = []
    with open(csvfile, "r") as file:
        reader = csv.reader(file)
        for row in reader:
            data.append(row)

    title = data[0][1:]
    # print("title",title)

    # TODO: Read DNA sequence file into a variable

    DNA = []
    with open(txtfile, "r") as file:
        line = file.readline()
        DNA.append(line)
    # print("DNA:",DNA)

    # TODO: Find longest match of each STR in DNA sequence

    count_list = []
    for i in range(len(title)):
        # print("title",title[i])
        longest = longest_match(DNA[0], title[i])
        # print("match",longest)
        count_list.append(longest)

    # TODO: Check database for matching profiles
    flag = 0
    for i in range(1, len(data)):
        number = data[i][1:]
        # print(data[i][0])
        mid = 0
        for j in range(len(count_list)):
            # print(j)
            # print(number[j])
            # print(count_list[j])
            if int(number[j]) == int(count_list[j]):
                mid += 1
            # print(mid)
        if mid == len(count_list):
            # print("mid",mid)
            print(data[i][0])
            flag = 1

        # print("-----")
    if flag == 0:
        print("no match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
