with open('matrix.txt') as file:
    array2d = [[int(digit) for digit in line.split()] for line in file]

print array2d