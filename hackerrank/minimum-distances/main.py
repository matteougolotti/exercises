import unittest

def minimumDistances(a):
    last_indexes = dict()
    distances = dict()

    for i in range(len(a)):
        if a[i] in last_indexes:
            if a[i] in distances:
                distances[a[i]] = min(distances[a[i]], i - last_indexes[a[i]])
            else:
                distances[a[i]] = i - last_indexes[a[i]]
        else:
            last_indexes[a[i]] = i

    distance_values = [ value for key, value in distances.items() ]

    if len(distance_values) > 0:
        return min(distance_values)
    else:
        return -1


class TestSuite(unittest.TestCase):

    def testCase(self):
        self.assertEqual(3, minimumDistances([7, 1, 3, 4, 1, 7]))

if __name__ == "__main__":
    unittest.main()