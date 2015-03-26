//
//  main.cpp
//  PAT(1002)
//
//  Created by Aquaird on 3/26/15.
//  Copyright (c) 2015 Aquaird. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    
    int k1 = 0;
    int k2 = 0;
    int i;
    
    double p1[12];
    int e1[12];
    double p2[12];
    int e2[12];
    
    double p3[30];
    int e3[30];
    
    int next_p1, tail_p1;
    int next_p2, tail_p2;
    int next_p3;
    
    
    //init & input
    std::cin>>k1;
    tail_p1 = k1;
    for (i=0; i<k1; i++) {
        std::cin>>e1[i];
        std::cin>>p1[i];
    }
    
    std::cin>>k2;
    tail_p2 = k2;
    for (i=0; i<k2; i++) {
        std::cin>>e2[i];
        std::cin>>p2[i];
    }
    
    //calculate
    next_p1 = 0;
    next_p2 = 0;
    next_p3 = 0;
    
    while (next_p1<tail_p2 && next_p2<tail_p2) {
        
        if(e1[next_p1] > e2[next_p2]){
            p3[next_p3] = p1[next_p1];
            e3[next_p3] = e1[next_p1];
            next_p1++;
            if (p3[next_p3] != 0) {
                next_p3++;
            }
        }
        else if(e1[next_p1] < e2[next_p2]){
            p3[next_p3] = p2[next_p2];
            e3[next_p3] = e2[next_p2];
            next_p2++;
            if (p3[next_p3] != 0) {
                next_p3++;
            }
        }
        else{
            
            p3[next_p3] = p2[next_p2] + p1[next_p1];
            e3[next_p3] = e2[next_p2];
            next_p1++;
            next_p2++;
            if (p3[next_p3] != 0) {
                next_p3++;
            }
        }
    }

    while(next_p1 < tail_p1){
        p3[next_p3] = p1[next_p1];
        e3[next_p3] = e1[next_p1];
        if (p3[next_p3] != 0) {
            next_p3++;
        }
        next_p1++;
    }
    
    
    while(next_p2 < tail_p2){
        p3[next_p3] = p2[next_p2];
        e3[next_p3] = e2[next_p2];
        if (p3[next_p3] != 0) {
            next_p3++;
        }
        next_p2++;
    }
    
    std::cout<<next_p3;
    for(i=0;i<next_p3;i++){
        printf(" %d %.1lf",e3[i],p3[i]);
    }
    
    return 0;
}
