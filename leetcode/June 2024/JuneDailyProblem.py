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
    def scoreOfString(self, s: str) -> int:
        score = 0
        for i in range(1, len(s)):
            score += abs(ord(s[i]) - ord(s[i-1]))
        return score

    # Day 2: Reverse String - Q344(Easy)
    '''
        Write a function that reverses a string. The input string is given as an array of characters s.

        Example 1:
        Input: s = ["h","e","l","l","o"]
        Output: ["o","l","l","e","h"]

        Example 2:
        Input: s = ["H","a","n","n","a","h"]
        Output: ["h","a","n","n","a","H"]

        Constraints:
        1 <= s.length <= 10^5
        s[i] is a printable ascii character.
    '''
    def reverseString(self, s: list):

class JuneDailyProblems(Solutions):
    def __init__(self):
        print("Welcome to June Daily Leetcode Problems")
        print("This is Yasaswin Palukuri, with solutions to the Daily Problems of June 2024")
        print("So, without any further ado, let's get started")
        self.menuDriven()


    def menuDriven(self):
        while(True):
            print("Enter the day of the problem you want the answer for or 88 to Exit:")
            print("Day 1: Score of a String")
            print("Day 2: Reverse String")
            print("88. Exit")
            day = int(input("Enter your choice: "))
            if day == 1:
                word = input("Enter the string: ")
                print("The score of the string is: ", self.scoreOfString(word))
            
            elif day == 2:
                word = list(input("Enter the string: "))
                self.reverseString(word)
                print("The reversed string is: ", word)

            elif day == 88:
                print("Thank you for using the June Daily Leetcode Problems:)")
                break

            else:
                print("Invalid Choice. Please try again.")


def main():
    juneDailyProblems = JuneDailyProblems()

if __name__ == "__main__":
    main()