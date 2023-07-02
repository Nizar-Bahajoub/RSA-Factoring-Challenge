#!/usr/bin/python3

import sys

def factorize(num):
    for factor in range(2, num//2 + 1):
        if num % factor == 0:
            return factor, num // factor
    return None

def main(file_path):
    with open(file_path, 'r') as file:
        for line in file:
            num = int(line.strip())
            factors = factorize(num)
            if factors:
                print(f"{num} = {factors[0]} * {factors[1]}")
            else:
                print(f"{num} is a prime number.")

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)

    file_path = sys.argv[1]
    main(file_path)
