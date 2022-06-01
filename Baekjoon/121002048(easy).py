import sys
input = sys.stdin.readline

def sliceRow(row):
    newList = [i for i in row if i]
    for i in range(1, len(newList)):
        if newList[i - 1] == newList[i]:
            newList[i - 1] += newList[i]
            newList[i] = 0
    newList = [i for i in newList if i]
    return newList + [0] * (n - len(newList))


def rotateBoard(board):
    rotatedBoard = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            rotatedBoard[j][n - 1 - i] = board[i][j]
    return rotatedBoard

def dfs(board, n):
    ret = max([max(row) for row in board])
    if n == 0:
        return ret
    for _ in range(4):
        slicedBoard = [sliceRow(row) for row in board]
        if slicedBoard != board:
            ret = max(ret, dfs(slicedBoard, n - 1))
        board = rotateBoard(board)
    return ret


n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
print(dfs(board, n))