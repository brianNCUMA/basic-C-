/*
Assignment:A8-2
Name:Ĭ�f��
Student Number:107201522
Course:2020-CE1001
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string.h>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
string Manacher(string s) {
    // Insert '#'
    string t = "$#";
    for (int i = 0; i < s.size(); ++i) {
        t += s[i];
        t += "#";
    }
    // Process t
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i) {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]]) ++p[i];
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i]) {
            resLen = p[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter - resLen) / 2, resLen - 1);
}

int main() {
    while (true){
    string s1;
    std::cin >> s1;
    string str=Manacher(s1);
    if (str.length() != 1)
        {cout <<"Palindrome:"<< Manacher(s1) << "\n";
        cout <<"Length:"<<str.length()<<"\n";}
    else if (s1=="-1"){break;}
    else {cout << "Palindrome not existed!"<<endl;}
    }
}
