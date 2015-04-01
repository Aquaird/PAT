//
//  main.cpp
//  PAT(1008)
//
//  Created by Aquaird on 4/1/15.
//  Copyright (c) 2015 Aquaird. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int i;
    int p,q;
    int n;
    
    long int sum;
    
    cin>>n;
    
    for (i=0,sum=0; i<n; i++) {
        cin>>q;
        if(0 == i){
            sum += q*6;
        }
        else{
            sum += (abs(q-p)*(5) + (q-p));
        }
        
        p=q;
        sum+=5;
    }
    cout<<sum;
}
