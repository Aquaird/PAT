//
//  main.cpp
//  PAT(1001)
//
//  Created by Aquaird on 3/26/15.
//  Copyright (c) 2015 Aquaird. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    long int a;
    long int b;
    long int result;
    long int output[3];
    int i=0;
    bool positive;
    
    cin>>a;
    cin>>b;
    
    result = a+b;
    positive = (result>=0);
    result = (result>=0)?result:-result;

    
    if(result == 0){
        cout<<0;
    }else{
    
    while (result>0) {
        output[i] = result%1000;
        result/=1000;
        i++;
    }
    

    i=i-1;
    output[i] *= (positive)?1:-1;
    
    cout<<output[i];
    i--;
    for(;i>=0;i--){
        cout<<',';
        if(output[i]<10){
            cout<<"00";
        }
        else if(output[i]<100){
            cout<<'0';
        }
        cout<<output[i];
        
    }
    
    }
    return 0;
}
