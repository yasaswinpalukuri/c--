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


    # Day 7: Replace Words - Q648(Medium)
    '''
        In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word successor. 
        For example, when the root "an" is followed by the successor word "other", we can form a new word "another".

        Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it. 
        If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

        Return the sentence after the replacement.

        Example 1:
        Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
        Output: "the cat was rat by the bat"
        
        Example 2:
        Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
        Output: "a a b c"
        
        Example 3:
        Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
        Output: "a a a a a a a a bbb baba a"
        
        Example 4:
        Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
        Output: "the cat was rat by the bat"
        
        Example 5:
        Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
        Output: "it is ab that this solution is ac"
        

        Constraints:
        1 <= dictionary.length <= 1000
        1 <= dictionary[i].length <= 100
        dictionary[i] consists of only lower-case letters.
        1 <= sentence.length <= 10^6
        sentence consists of only lower-case letters and spaces.
        The number of words in sentence is in the range [1, 1000]
        The length of each word in sentence is in the range [1, 1000]
        Each two consecutive words in sentence will be separated by exactly one space.
        sentence does not have leading or trailing spaces.
    '''
    def replaceWords(self, dictionary: list, sentence: str) -> str:
        dictionary = set(dictionary)
        result = []
        for word in sentence.split():
            prefix = ''
            for i in range(len(word)):
                prefix = word[:i]
                if prefix in dictionary:
                    break
            result.append(prefix)
        return ' '.join(result)



    # Day 8: Continuous Subarray Sum - Q523(Medium)
    '''
        Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

        A good subarray is a subarray where:

        its length is at least two, and
        the sum of the elements of the subarray is a multiple of k.
        Note that:

        A subarray is a contiguous part of the array.
        An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.
        

        Example 1:

        Input: nums = [23,2,4,6,7], k = 6
        Output: true
        Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
        Example 2:

        Input: nums = [23,2,6,4,7], k = 6
        Output: true
        Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
        42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
        Example 3:

        Input: nums = [23,2,6,4,7], k = 13
        Output: false
        

        Constraints:

        1 <= nums.length <= 10^5
        0 <= nums[i] <= 10^9
        0 <= sum(nums[i]) <= 23^1 - 1
        1 <= k <= 23^1 - 1
    '''
    def checkSubarraySum(self, nums: list, k: int) -> bool:
        prefixSum = 0
        prefixSumIndex = {0: -1}
        for i in range(len(nums)):
            prefixSum += nums[i]
            if k != 0:
                prefixSum %= k
            if prefixSum in prefixSumIndex:
                if i - prefixSumIndex[prefixSum] > 1:
                    return True
            else:
                prefixSumIndex[prefixSum] = i
        return False
    

    # Day 9: Subarray Sums Divisible by K - Q974(Medium)
    '''
        Given an integer array nums and an integer k,
        return the number of non-empty subarrays that have a sum divisible by k.
        A subarray is a contiguous part of an array.

        Example 1:
        Input: nums = [4,5,0,-2,-3,1], k = 5
        Output: 7
        Explanation: There are 7 subarrays with a sum divisible by k = 5:
        [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
        
        
        Example 2:
        Input: nums = [5], k = 9
        Output: 0
        
        Constraints:
        1 <= nums.length <= 3 * 104
        -104 <= nums[i] <= 104
        2 <= k <= 104
    '''
    def subarraysDivByK(self, nums: list, k: int) -> int:
        prefixSum = 0
        prefixSumIndex = {0:1}
        count = 0
        for i in range(len(nums)):
            prefixSum += nums[i]
            prefixSum %= k
            if prefixSum in prefixSumIndex:
                count += prefixSumIndex[prefixSum]
            if prefixSum in prefixSumIndex:
                prefixSumIndex[prefixSum] += 1
            else:
                prefixSumIndex[prefixSum] = 1
        return count

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
            print("Day 7: Replace Words")
            print("Day 8: Continuous Subarray Sum")
            print("Day 9: Subarray Sums Divisible by K")
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
                W = int(input("Enter the value of groupsize: "))
                print("We can rearrange the given hand of cards into groups of size",W,": ", self.isNStraightHand(hand, W))

            elif day == 7:
                dictionary = list(input("Enter the list of words: ").split())
                sentence = input("Enter the sentence: ")
                print("The sentence after the replacement is: ", self.replaceWords(dictionary, sentence))
            elif day == 8:
                nums = list(map(int, input("Enter the list of integers: ").split()))
                k = int(input("Enter the value of k: "))
                print("The given list of integers has a good subarray: ", self.checkSubarraySum(nums, k))
            
            elif day == 9:
                nums = list(map(int, input("Enter the list of integers: ").split()))
                k = int(input("Enter the value of k: "))
                print("The number of non-empty subarrays that have a sum divisible by k is: ", self.subarraysDivByK(nums, k))

            elif day == 88:
                print("Thank you for using the June Daily Leetcode Problems:)")
                break

            else:
                print("Invalid Choice. Please try again.")


def main():
    juneDailyProblems = JuneDailyProblems()

if __name__ == "__main__":
    main()