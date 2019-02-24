import unittest

def fairRations(B):
    if sum(B) % 2 != 0:
        return "NO"

    loafs = 0
    for i in range(len(B)):
        if B[i] % 2 != 0:
            B[i] = B[i] + 1
            B[i + 1] = B[i + 1] + 1
            loafs = loafs + 2
    
    return loafs


class TestSuit(unittest.TestCase):

    def testCase(self):
        self.assertEqual(4, fairRations([4, 5, 6, 7]))
        self.assertEqual(4, fairRations([2, 3, 4, 5, 6]))
        self.assertEqual("NO", fairRations([1, 2]))

if __name__ == "__main__":
    unittest.main()