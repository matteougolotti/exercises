import re

from typing import List, Tuple

def solve(sudoku : List[List[int]]) -> bool:
  flag = 0
  
  for y in range(9):
    for x in range(9):
      if sudoku[y][x] == 0:
        flag = 1
        possible_values = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]

        # Remove values in row
        for k in range(9):
          possible_values[sudoku[y][k]] = 0
          possible_values[sudoku[k][x]] = 0
        x_3 = x - x % 3
        y_3 = y - y % 3
        for x_i in range(3):
          for y_i in range(3):
            possible_values[sudoku[y_3 + y_i][x_3 + x_i]] = 0

        for n in range(1, len(possible_values)):
          if possible_values[n] == 1:
            sudoku[y][x] = n
            if solve(sudoku):
              return True
            else:
              sudoku[y][x] = 0
        return False
  
  if flag == 0:
    return True

def build_sudoku(numbers : List[int]) -> List[List[int]]:
  sudoku = [ [] for i in range(9) ]

  i = 0
  for y in range(9):
    for x in range(9):
      sudoku[y].append(int(numbers[i]))
      i += 1

  return sudoku

def sudoku_str(sudoku : List[List[int]]) -> str:
  result = ""
  for y in range(len(sudoku)):
    for x in range(len(sudoku[y])):
      result += " " + str(sudoku[y][x])

  return result[1:]

if __name__ == "__main__":
  n = int(input())
  
  for i in range(n):
    line = input() # "3 0 6 5 0 8 4 0 0 5 2 0 0 0 0 0 0 0 0 8 7 0 0 0 0 3 1 0 0 3 0 1 0 0 8 0 9 0 0 8 6 3 0 0 5 0 5 0 0 9 0 6 0 0 1 3 0 0 0 0 2 5 0 0 0 0 0 0 0 0 7 4 0 0 5 2 0 6 3 0 0"
    line = re.sub(' +', ' ', line)
    numbers = line.split(' ')

    sudoku = build_sudoku(numbers)

    ok = solve(sudoku)

    result = sudoku_str(sudoku)
    print(result)
