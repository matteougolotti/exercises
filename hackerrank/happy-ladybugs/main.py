import unittest

def __allLadybugsAreHappy(b):
    for i in range(0, len(b)):
        # First ladybug
        if i == 0 and b[i] != b[i+1]:
          return False

        # Last ladybug
        if i == (len(b) - 1) and b[i] != b[i - 1]:
            return False

        if i > 0 and i < (len(b) - 1) and b[i] != b[i - 1] and b[i] != b[i + 1]:
            return False
    return True

def __atLeastOneEmptySpace(b):
    for c in b:
        if c == '_':
            return True
    return False

def __noColorOccursOnce(b):
    occurrences = dict()
    for color in b:
        if color >= 'A' and color <= 'Z':
            if color in occurrences:
                occurrences[color] = occurrences[color] + 1
            else:
                occurrences[color] = 1
    for color in occurrences:
        if occurrences[color] == 1:
            return False
    return True

def happyLadybugs(b):
    if len(b) == 0:
        return 'YES'
    if len(b) == 1:
        if b[0] == '_':
            return 'YES'
        else:
            return 'NO'

    if __allLadybugsAreHappy(b):
        return 'YES'
    
    if __atLeastOneEmptySpace(b) and __noColorOccursOnce(b):
        return 'YES'

    # Else
    return 'NO'

class TestSuit(unittest.TestCase):

    def testCase(self):
        self.assertEqual("YES", happyLadybugs("AABBCC"))
        self.assertEqual("YES", happyLadybugs("AABBC_C"))

if __name__ == "__main__":
    unittest.main()