import math

class Solutions:
    # Day 1: Score of a String - Q3110(Easy)
    '''
        You are given a string s. 
        The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.
        Return the score of s.

        Example 1:
        Input: s = "hello"
        Output: 13
        Explanation:
        The ASCII values of the characters in s are: 'h' = 104, 'e' = 101, 'l' = 108, 'o' = 111.
        So, the score of s would be |104 - 101| + |101 - 108| + |108 - 108| + |108 - 111| = 3 + 7 + 0 + 3 = 13.

        Example 2:
        Input: s = "zaz"
        Output: 50
        Explanation:
        The ASCII values of the characters in s are: 'z' = 122, 'a' = 97.
        So, the score of s would be |122 - 97| + |97 - 122| = 25 + 25 = 50.


        Constraints:
        2 <= s.length <= 100
        s consists only of lowercase English letters.
    '''
    

class JuneDailyProblems(Solutions):
    def __init__(self):
        print("Welcome to June Daily Leetcode Problems")
        print("This is Yasaswin Palukuri, with solutions to the Daily Problems of June 2024")
        print("So, without any further ado, let's get started")
        self.menuDriven()


    def menuDriven(self):
        while(True):
            print("Enter the day of the problem you want the answer for or 88 to Exit:")
            print("1. Day 1: Score of a String")
            print("88. Exit")
            day = int(input("Enter your choice: "))
            if day == 1:
                self.scoreOfString()
            elif day == 88:
                print("Thank you for using the June Daily Leetcode Problems")
            else:
                print("Invalid Choice. Please try again.")


    def test(self):
        # Test for Day 1
        print("Day 1: Score of a String")
        print("Test 1: ", self.solutions.scoreOfString("hello"))
        print("Test 2: ", self.solutions.scoreOfString("zaz"))


def main():
    juneDailyProblems = JuneDailyProblems()
