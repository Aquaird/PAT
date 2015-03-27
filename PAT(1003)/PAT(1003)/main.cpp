//
//  main.cpp
//  PAT(1003)
//
//  Created by Aquaird on 3/26/15.
//  Copyright (c) 2015 Aquaird. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#define INF 2147483647

struct road{
    int to_city;
    int cost = 0;
    struct road *next = NULL;
};

struct city{
    struct road* isStart = NULL;
    struct road* isTail = isStart;
    
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
    
    int *dist;
    int *value;
    int *count;
    
    int temp_from;
    int temp_to;
    int temp_cost;
    struct road *temp_road;
    
    //init & input
    std::cin>>n_C>>n_R>>now>>save;
    
    cities = (struct city*)malloc(sizeof(struct city)*n_C);
    dist = (int*)malloc(sizeof(int)*n_C);
    for(i=0;i<n_C;i++){
        dist[i] = INF;
    }
    
    value = (int*)malloc(sizeof(int)*n_C);
    count = (int*)malloc(sizeof(int)*n_C);
    
    for (i=0; i<n_C; i++) {
        std::cin>>cities[i].value;
    }
    
    for (i=0; i<n_R; i++) {
        std::cin>>temp_from;
        std::cin>>temp_to;
        std::cin>>temp_cost;
        
        temp_road = (road*)malloc(sizeof(struct road));
        temp_road->cost = temp_cost;
        temp_road->to_city = temp_to;
        if (cities[temp_from].isTail == NULL) {
            cities[temp_from].isStart = temp_road;
            cities[temp_from].isTail = cities[temp_from].isStart;
        }
        else{
            cities[temp_from].isTail->next = temp_road;
            cities[temp_from].isTail = temp_road;
        }
        
        temp_road = (road*)malloc(sizeof(struct road));
        temp_road->cost = temp_cost;
        temp_road->to_city = temp_from;
        if (cities[temp_to].isTail == NULL) {
            cities[temp_to].isStart = temp_road;
            cities[temp_to].isTail = cities[temp_to].isStart;
        }
        else{
            cities[temp_to].isTail->next = temp_road;
            cities[temp_to].isTail = temp_road;
        }
    }
    
    
    for (temp_road = cities[now].isStart; temp_road!=NULL; temp_road=temp_road->next) {
        if(temp_road->cost>0 && temp_road->to_city!=now){
            dist[temp_road->to_city] = temp_road->cost;
            value[temp_road->to_city] = cities[temp_road->to_city].value + cities[now].value;
            count[temp_road->to_city] = 1;
        }
    }
    
    cities[now].isCount = true;
    
    for (i=1; i<n_C; i++) {
        int min = INF;
        int j;
        int u = 0;
        
        for (j=0; j<n_C; j++) {
            if (!cities[j].isCount && dist[j]<min) {
                min = dist[j];
                u = j;
            }
        }
        
        cities[u].isCount = true;
        
        for (temp_road = cities[u].isStart; temp_road!=NULL; temp_road=temp_road->next) {
            if (cities[temp_road->to_city].isCount == false && temp_road->cost>0) {
                
                if (min+temp_road->cost < dist[temp_road->to_city]) {
                    dist[temp_road->to_city] = min + temp_road->cost;
                    value[temp_road->to_city] = value[u] + cities[temp_road->to_city].value;
                    count[temp_road->to_city] = count[u];
                }
                else if(min+temp_road->cost == dist[temp_road->to_city]){
                    if(value[temp_road->to_city] <= value[u] + cities[temp_road->to_city].value){
                        value[temp_road->to_city] = value[u] + cities[temp_road->to_city].value;
                    }
                    count[temp_road->to_city]+=count[u];
                }
            }
        
        
        }
    
    }
    
    std::cout<<count[save]<<' '<<value[save];

    return 0;
}
