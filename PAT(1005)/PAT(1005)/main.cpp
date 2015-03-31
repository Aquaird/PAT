//
//  main.cpp
//  PAT(1005)
//
//  Created by Aquaird on 3/31/15.
//  Copyright (c) 2015 Aquaird. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

string words[10] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int main(int argc, const char * argv[]) {
    
    string input;
    int sum,i,temp_1,temp_10,temp_100;
    sum = 0;
    
    cin>>input;
    
    
    for (i=0; i<input.size(); i++) {
        
        sum = sum + (int)(input.c_str()[i]-'0');
        
    }
    
    if (sum<10) {
        cout<<words[sum];
    }
    else if(sum<100){
        temp_1 = sum%10;
        sum/=10;
        temp_10 = sum%10;
        cout<<words[temp_10]<<' ';
        cout<<words[temp_1];
    }
    else{
        temp_1 = sum%10;
        sum/=10;
        temp_10 = sum%10;
        sum/=10;
        temp_100 = sum%10;
        cout<<words[temp_100]<<' ';
        cout<<words[temp_10]<<' ';
        cout<<words[temp_1];

    }
    
    return 0;
}
