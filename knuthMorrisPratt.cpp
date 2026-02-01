/*
Knuth-Morris-Pratt Algorithm

It is an efficient search algorithm that can be used to find the occurrence of a pattern in a given input.
Time Complexity - O(n + m) where n is the length of the input and m is the length of the pattern.

Example Problem: Find the first occurrence of a pattern (needle) in a string (haystack).

Ideas:
    1. Brute Force - For each index in the haystack as the starting index of the substring, compare the substring of length len(needle) with the needle.
    2. But what if the needle's prefix is also it's suffix? We can use this information to skip some comparisons.
    3. We need to compute the Longest Prefix Suffix of the needle.

    Longest Prefix Suffix
        For each substring of the needle with start index 0, we need to find the length of the longest prefix that is also a suffix of that substring.
        Example: needle = 'aaaa'
                For the substring 'a', the longest prefix suffix is 0
                For the substring 'aa', the longest prefix suffix is 1
                For the substring 'aaa', the longest prefix suffix is 2
                For the substring 'aaaa', the longest prefix suffix is 3

Algorithm:

prev_lps -  a variable that is equal to the length of the longest prefix suffix of a previous substring, 
            It can also be thought of as an index of last character of the substring where the prefix equals the suffix
            Example:
                a -> prev_lps = 0
                aa -> prev_lps = 1
                ab -> prev_lps = 0
                aba -> prev_lps = 1
                abab -> prev_lps = 2
                abs -> prev_lps = 0

    populateLPS(string needle):
        if(len(needle) == 0)
            return 0
        
        lps <- vector of size len(needle) initialized with 0
        prev_lps <- 0 
        index <- 1

        while(index < len(needle)):
            if(needle[index] == needle[prev_lps]):
                lps[index] <- prev_lps + 1 // Why? We need to increment the size of the longest prefix suffix because the current character matches with the last character of previous substring where the prefix equals the suffix
                prev_lps <- prev_lps + 1 //Increment the length of the longest prefix suffix
                index <- index + 1 // Move to the next character
            else:
                if prev_lps == 0: //There was never a prefix of the substring that was also a suffix
                    lps[index] <- 0 //The longest prefix suffix is 0
                    index <- index + 1 //Move to the next character
                else: 
                    prev_lps <- lps[prev_lps - 1] //Move to the previous character where the prefix equals the suffix

        return lps

    kmp(string haystack, string needle):
        if(len(needle) == 0)
            return 0

        lps <- populateLPS(needle)
        needle_index <- 0
        haystack_index <- 0
        
        while(haystack_index < len(haystack)):
            if(haystack[haystack_index] == needle[needle_index]):
                haystack_index <- haystack_index + 1
                needle_index <- needle_index + 1
            else:
                if needle_index == 0:
                    haystack_index <- haystack_index + 1
                else:
                    needle_index <- lps[needle_index - 1]
            
            if needle_index == len(needle):
                return haystack_index - len(needle)

*/