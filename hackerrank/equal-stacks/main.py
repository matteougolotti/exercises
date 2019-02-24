import unittest

def possible_heights(h):
    height = sum(h)
    heights = [height]
    for block in h:
        height = height - block
        heights.append(height)

    return heights

# h1, h2, h3 : Array<Int>
# return: Int
def equalStacks(h1, h2, h3):
    
    possible_heights_1 = possible_heights(h1)
    possible_heights_2 = possible_heights(h2)
    possible_heights_3 = possible_heights(h3)

    possible_heights_1_set = dict()
    for h in possible_heights_1:
      possible_heights_1_set[h] = True
    
    possible_heights_1_2_set = dict()
    for h in possible_heights_2:
        if h in possible_heights_1_set:
          possible_heights_1_2_set[h] = True

    for h in possible_heights_3:
      if h in possible_heights_1_2_set:
        return h
    
    return 0
    

class TestSuite(unittest.TestCase):
    
    def testCase1(self):
      self.assertEqual(5, equalStacks([3, 2, 1, 1, 1], [4, 3, 2], [1, 1, 4, 1]))

if __name__ == "__main__":
    unittest.main()