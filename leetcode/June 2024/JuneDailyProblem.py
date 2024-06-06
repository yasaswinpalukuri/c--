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
        l, r = 0, len(s) - 1
        while l < r:
            s[l], s[r] = s[r], s[l]
            l += 1
            r -= 1
    
    # Day 3: Append Characters to String to Make Subsequence - Q2468(Medium)
    '''
        You are given two strings s and t consisting of only lowercase English letters.

        Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.
        A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

        Example 1:
        Input: s = "coaching", t = "coding"
        Output: 4
        Explanation: Append the characters "ding" to the end of s so that s = "coachingding".
        Now, t is a subsequence of s ("coachingding").
        It can be shown that appending any 3 characters to the end of s will never make t a subsequence.
        
        Example 2:
        Input: s = "abcde", t = "a"
        Output: 0
        Explanation: t is already a subsequence of s ("abcde").
        
        Example 3:
        Input: s = "z", t = "abcde"
        Output: 5
        Explanation: Append the characters "abcde" to the end of s so that s = "zabcde".
        Now, t is a subsequence of s ("zabcde").
        It can be shown that appending any 4 characters to the end of s will never make t a subsequence.
        

        Constraints:
        1 <= s.length, t.length <= 10^5
        s and t consist only of lowercase English letters.
    '''
    def appendChracters(self, s: str, t: str) -> int:
        i, j = 0, 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                j += 1
            i += 1
        return len(t) - j
    
    # Day 4: Longest Palindrome - Q409(Easy)
    '''
        Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

        Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

        Example 1:
        Input: s = "abccccdd"
        Output: 7
        Explanation:
        One longest palindrome that can be built is "dccaccd", whose length is 7.

        Example 2:
        Input: s = "a"
        Output: 1

        Example 3:
        Input: s = "bb"
        Output: 2

        Constraints:
        1 <= s.length <= 2000
        s consists of lowercase and/or uppercase English letters only.
    '''
    def longestPalindrome(self, s: str) -> int:
        freq = {}
        for char in s:
            if char in freq:
                freq[char] += 1
            else:
                freq[char] = 1
        
        length = 0
        for key in freq:
            length += freq[key] // 2 * 2
            if length % 2 == 0 and freq[key] % 2 == 1:
                length += 1
        return length

    # Day 5: Find Common Characters - Q1002(Easy)
    '''
        Given an array words of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates). 
        For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

        You may return the answer in any order.

        Example 1:
        Input: words = ["bella","label","roller"]
        Output: ["e","l","l"]
        
        Example 2:
        Input: words = ["cool","lock","cook"]
        Output: ["c","o"]
        

        Constraints:
        1 <= words.length <= 100
        1 <= words[i].length <= 100
        words[i] consists of lowercase English letters.
    '''
    def commonChars(self, words: list) -> list:
        freq = [float('inf')] * 26
        for word in words:
            temp = [0] * 26
            for char in word:
                temp[ord(char) - ord('a')] += 1
            for i in range(26):
                freq[i] = min(freq[i], temp[i])
        
        result = []
        for i in range(26):
            result.extend([chr(i + ord('a'))] * freq[i])
        return result
    

    # Day 6: Hand of Straights - Q846(Medium)
    '''
        Alice has a hand of cards, given as an array of integers.

        Now she wants to rearrange the cards into groups so that each group is size W, and consists of W consecutive cards.

        Return true if and only if she can.

        Example 1:
        Input: hand = [1,2,3,6,2,3,4,7,8], W = 3
        Output: true
        Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8].

        Example 2:
        Input: hand = [1,2,3,4,5], W = 4
        Output: false
        Explanation: Alice's hand can't be rearranged into groups of 4.

        Constraints:
        1 <= hand.length <= 10000
        0 <= hand[i] <= 10^9
        1 <= W <= hand.length
    '''
    def isNStraightHand(self, hand: list, W: int) -> bool:
        freq = {}
        for card in hand:
            if card in freq:
                freq[card] += 1
            else:
                freq[card] = 1
        
        for card in sorted(freq):
            if freq[card] > 0:
                for i in range(W - 1, -1, -1):
                    if card + i not in freq:
                        return False
                    freq[card + i] -= freq[card]
                    if freq[card + i] < 0:
                        return False
        return True

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
            print("Day 3: Append Characters to String to Make Subsequence")
            print("Day 4: Longest Palindrome")
            print("Day 5: Find Common Characters")
            print("Day 6: Hand of Straights")
            print("88. Exit")
            day = int(input("Enter your choice: "))
            if day == 1:
                word = input("Enter the string: ")
                print("The score of the string is: ", self.scoreOfString(word))
            
            elif day == 2:
                word = list(input("Enter the string: "))
                self.reverseString(word)
                print("The reversed string is: ", word)

            elif day == 3:
                s = input("Enter the first string: ")
                t = input("Enter the second string: ")
                print("The minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s is: ", self.appendChracters(s, t))

            elif day == 4:
                word = input("Enter the string: ")
                print("The length of the longest palindrome that can be built with the given string is: ", self.longestPalindrome(word))

            elif day == 5:
                words = list(input("Enter the list of words: ").split())
                print("The list of all characters that show up in all strings within the list is: ", self.commonChars(words))

            elif day == 6:
                hand = list(map(int, input("Enter the list of integers: ").split()))
                W = int(input("Enter the value of W: "))
                print("We can rearrange the given hand of cards into groups of size",W,": ", self.isNStraraightHand(hand, W))

            elif day == 88:
                print("Thank you for using the June Daily Leetcode Problems:)")
                break

            else:
                print("Invalid Choice. Please try again.")


def main():
    juneDailyProblems = JuneDailyProblems()

if __name__ == "__main__":
    main()