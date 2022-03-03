## C Programming Final Project

### 1. String Reduction

John has a string, s consisting of n lowercase English alphabetic letters. In one operation, he can delete any pair of adjacent letters with same value. For example, string “aabcc” would become either “aab” or “bcc” after operation. John wants to reduce s as much as possible. To do this, he will repeat the above operation as many times as it can be performed. Help John out by finding and printing s non-reducible form!

Note: If the final string is empty, print “Empty String”.
Input Format
The first line contains a single integer denoting the length of s.
The second line contains string s.
Constraints
•
1 ≤ |s| ≤ 100
•
s only contains lowercase English alphabetic letters (i.e., a to z).
Output Format
If the final string is empty, print “Empty String”; otherwise, print the final non-reducible string.
Test Case - 1
Input
9
aaabccddd
Output
abd
Explanation
John can perform the following sequence of operations to get the final string:
aaabccddd → abccddd
abccddd → abddd
abddd → abd
Thus, we print abd.
Test Case - 2
Input
4
baab
Output
Empty String
Explanation
John can perform the following sequence of operations to get the final string:
baab → bb
bb → Empty String
Thus, we print Empty String.

### 2. Finding number of grandchildren for given input string

Given a file containing strings separated by space, where the first string is “child” and second string is “Father”. 
Write a program which finds number of grandchildren for any given string.
Example:
file.txt
luke shaw
wayne rooney
rooney ronaldo
shaw rooney
mike wayne
Input : ronaldo
Output:2

### 3. Reverse bits order for given integer number.

Write a program that reverses the order of the bits in an unsigned int value. The program should input the value from the user and call function reverseBits to print the bits in reverse order. Print the value in bits both before and after the bits are reversed to confirm that the bits are reversed properly.
Input: 8
Output: Before:1000 After:0001

