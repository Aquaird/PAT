//
//  main.cpp
//  PAT(1003)
//
//  Created by Aquaird on 3/26/15.
//  Copyright (c) 2015 Aquaird. All rights reserved.
//

#include <iostream>
#include <stdlib.h>


struct road{
    int *from;
    int to;
    int cost = 0;
    struct road *next = NULL;
};

struct city{
    struct road* isStart = NULL;
    struct road* isTail = NULL;
    
    int value = 0;
    bool isCount = false;
};

struct city  *cities;
road *roads;

int main(int argc, const char * argv[]) {

    int n_C;
    int n_R;
    int now;
    int save;
    
    int i;
    
    int MaxValue;
    int MinCost;
    int temp_from;
    
    //init & input
    std::cin>>n_C>>n_R>>now>>save;
    

    return 0;
}
