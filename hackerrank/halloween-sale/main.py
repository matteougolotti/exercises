import unittest

def howManyGames(p, d, m, s):
    games = 0
    price = p

    while(s >= price):
        games = games + 1
        s = s - price
        if price > m:
            price = max(m, price - d)
    
    return games

class TestSuit(unittest.TestCase):

    def testCase(self):
        self.assertEqual(7, howManyGames(20, 3, 6, 85))

if __name__ == "__main__":
    unittest.main()