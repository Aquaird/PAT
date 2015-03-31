//
//  main.cpp
//  PAT(1004)
//
//  Created by Aquaird on 3/31/15.
//  Copyright (c) 2015 Aquaird. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    int *pro;
    int *n_child;
    int *level;
    int *result;
    
    int n_Node;
    int n_NLeaf;
    
    int i,j,k;
    std::cin>>n_Node;
    std::cin>>n_NLeaf;
    
    int parent;
    int child;
    int max;
    
    pro = (int *)malloc(sizeof(int)*n_Node);
    n_child = (int *)malloc(sizeof(int)*n_Node);
    level = (int *)malloc(sizeof(int)*n_Node);
    
    
    memset(pro, -1, sizeof(int)*n_Node);
    memset(n_child, 0, sizeof(int)*n_Node);
    memset(level, -1, sizeof(int)*n_Node);
    
    for (i=0; i<n_NLeaf; i++) {
        std::cin>>parent;
        std::cin>>n_child[parent-1];
        
        for (j=0; j<n_child[parent-1]; j++) {
            std::cin>>child;
            pro[child-1] = parent-1;
        }
    }
    
    level[0] = 0;
    for (i=0, max=0; i<n_Node; i++) {
        j = i;
        k = 0;
        while (level[j]!=0) {
            j = pro[j];
            k++;
        }
        
        level[i] = k;
        if(level[i] >= max){
            max = level[i];
        }
    }
    
    result = (int *)malloc(sizeof(int)*(max+1));
    memset(result, 0, sizeof(int)*(max+1));
    
    for (i=0; i<n_Node; i++) {
        if(n_child[i] == 0){
            result[level[i]] ++;
        }
    }
    
    for (i=0; i<=max; i++) {
        if (i==max) {
            std::cout<<result[i];
        }
        else{
            std::cout<<result[i]<<' ';
        }
    }
    
    return 0;
}
