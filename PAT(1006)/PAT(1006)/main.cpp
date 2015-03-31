//
//  main.cpp
//  PAT(1006)
//
//  Created by Aquaird on 3/31/15.
//  Copyright (c) 2015 Aquaird. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct time{
    int h;
    int m;
    int s;
    
    bool compare(struct time *time1, struct time *time2);
};

bool time::compare(struct time *time1, struct time *time2){
    bool less;
    
    if (time1->h != time2->h) {
        less = (time1->h<time2->h);
    }
    else if (time1->m != time2->m){
        less = (time1->m<time2->m);
    }
    else if (time1->s != time2->s){
        less = (time1->s<time2->s);
    }
    
    return less;
}

struct record{
    char id[16];
    struct time time_in;
    struct time time_out;
};

void readTime(struct time* p2time){
    char time[9];
    int i;
    cin>>time;
    
    i=0;
    p2time->h = p2time->m = p2time->s = 0;
    
    p2time->h += atoi(&time[i]);
    i = 3;
    p2time->m += atoi(&time[i]);
    i = 6;
    p2time->s += atoi(&time[i]);
    
}

int main(int argc, const char * argv[]) {
    
    struct record *records;
    
    int n;
    int i;
    int early,late;
    
    cin>>n;
    records = (struct record*)malloc(sizeof(struct record)*n);
    early = 0;
    late = 0;
    
    for (i=0; i<n; i++) {
        cin>>records[i].id;
        readTime(&records[i].time_in);
        readTime(&records[i].time_out);
        if (records[i].time_in.compare(&records[i].time_in, &records[early].time_in)) {
            early = i;
        }
        if (records[i].time_in.compare(&records[late].time_out,&records[i].time_out)) {
            late = i;
        }
    }
    
    cout<<records[early].id<<' '<<records[late].id;
    
    
    return 0;
}
