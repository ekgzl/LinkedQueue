#include <iostream>
#include "Queue.h"
#include "Stack.h"
using namespace std;


/*Write a program that reads a line of text, changes each uppercase letter to lowercase,
and places each letter both in a queue and onto a stack. The program should then verify
whether the line of text is a palindrome (a set of letters or numbers that is the same whether
read forward or backward)*/

bool isAlphanumeric(char c)
{
    return (c == ' ') || (c >= 'a' && c <='z') || (c>= 'A' && c<= 'Z') || (c>= '1' && c<='9');
}

char toLower(char c)
{
            if(c>= 'A' && c<='Z')
            {
                return c - ('A' - 'a');
            }
            return c;
}

string process(string str)
{
    string newStr;
    for(char c: str)
    {
        if(isAlphanumeric(c))
        newStr += tolower(c);
    }
    return newStr;
}

bool isPalindrome(string str)
{
    Queue<char> q;
    Stack<char> s;
    for(char c : str)
    {
        q.insert(c);
        s.push(c);
    }

    while(!q.isEmpty())
    {
        if(q.deleteQ() != s.pop())
            return false;
    }
    return true;
}


int main() {
    cout << "Enter the text line:";
    string input;
    getline(cin,input);
    input = process(input);
    cout << "\n New String: " << input << endl;
    cout << "Is palindrome: " << (isPalindrome(input) ? "Yes" : "No");



}
