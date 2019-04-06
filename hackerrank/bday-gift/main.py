import os
import sys

def solve(balls : [int]) -> float:
  expected_value = 0.0
  for p in balls:
    expected_value += p / 2

  return expected_value

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    balls_count = int(input())

    balls = []

    for _ in range(balls_count):
        balls_item = int(input())
        balls.append(balls_item)

    result = solve(balls)

    fptr.write(str(result) + '\n')

    fptr.close()
