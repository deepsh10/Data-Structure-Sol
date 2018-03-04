/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   encodingForStupidPeople.cpp
 * Author: shaw
 *
 * Created on March 4, 2018, 8:48 AM
 */

#include <cstdlib>
#include "iostream"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char encodeString[500] = "\0";
    int now=0;
    int count=0;
    char prev;
    cout << "Enter encoding string :";
    cin >> encodeString ;
  
    while(encodeString[now])
    {
        if(prev==encodeString[now] || now == 0)
        {
            count++;
        }
        else
        {
            printf("%c%d",encodeString[now-1],count);
            count=1;
        }
        prev = encodeString[now];
        now++;
    }
    printf("%c%d",encodeString[now-1],count);
    
    return 0;
}

