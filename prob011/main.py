with open('matrix.txt') as file:
    array2d = [[int(digit) for digit in line.split()] for line in file]

print array2d

def checkFromOrigin(x, y):
    return max(checkN(x, y), checkNE(x, y), checkE(x, y), checkSE(x, y), checkS(x, y), checkSW(x, y), checkW(x, y), checkNW(x, y))

def checkN(x, y):

    if y-3 < 0:
        return 0
    else:
        return array2d[x][y] * array2d[x][y-1] * array2d[x][y-2] * array2d[x][y-3]

def checkNE(x, y):

    if y-3 < 0 or x+3 >= len(array2d):
        return 0
    else:
        return array2d[x][y] * array2d[x + 1][y-1] * array2d[x + 2][y-2] * array2d[x + 3][y-3]

def checkE(x, y):

    if x+3 >= len(array2d):
        return 0
    else:
        return array2d[x][y] * array2d[x+1][y] * array2d[x+2][y] * array2d[x+3][y]


def checkSE(x, y):
    if x+3 >= len(array2d) or y+3 >= len(array2d):
        return 0
    else:
        return array2d[x][y] * array2d[x+1][y+1] * array2d[x+2][y+2] * array2d[x+3][y+3]

def checkS(x, y):
    if y+3 >= len(array2d):
        return 0
    else:
        return array2d[x][y] * array2d[x][y+1] * array2d[x][y+2] * array2d[x][y+3]
def checkSW(x, y):
    if x-3 < 0 or y+3 >= len(array2d):
        return 0
    else:
        return array2d[x][y] * array2d[x-1][y+1] * array2d[x-2][y+2] * array2d[x-3][y+3]
def checkW(x, y):
    if x-3 < 0:
        return 0
    else:
        return array2d[x][y] * array2d[x-1][y] * array2d[x-2][y] * array2d[x-3][y]
def checkNW(x, y):
    if y-3 < 0 or x-3 < 0:
        return 0
    else:
        return array2d[x][y] * array2d[x-1][y-1] * array2d[x-2][y-2] * array2d[x-3][y-3]


m = 0

for x in range(0, len(array2d)):
    for y in range(0, len(array2d)):

        maxFromOrigin = checkFromOrigin(x, y)
        if maxFromOrigin > m:
            m = maxFromOrigin

print m
