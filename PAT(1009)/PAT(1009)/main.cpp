//
//  main.cpp
//  PAT(1009)
//
//  Created by Aquaird on 4/1/15.
//  Copyright (c) 2015 Aquaird. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

struct term{
    float coff;
    long ex;
};

int cmp(const void *t1, const void *t2){
    
    struct term *T1;
    struct term *T2;
    
    T1 = (struct term*)t1;
    T2 = (struct term*)t2;
    
    if (T1->ex < T2->ex) {
        return 1;
    }
    if (T1->ex == T2->ex) {
        return 0;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    struct term *p1;
    struct term *p2;
    struct term *r;
    int k1,k2;
    

    
    int i,j,k;
    int kr,rp;
    

    cin>>k1;
    p1 = (struct term *)malloc(sizeof(struct term)*k1);
    for (i=0; i<k1; i++) {
        cin>>p1[i].ex;
        cin>>p1[i].coff;
    }
    
    cin>>k2;
    p2 = (struct term *)malloc(sizeof(struct term)*k2);
    for (i=0; i<k2; i++) {
        cin>>p2[i].ex;
        cin>>p2[i].coff;
    }
    
    r = (struct term *)malloc(sizeof(struct term)*k1*k2);
    
    k=0;
    for (i=0; i<k1; i++) {
        for (j=0; j<k2; j++) {
            r[k].ex = p1[i].ex + p2[j].ex;
            r[k].coff = p1[i].coff * p2[j].coff;
            k++;
        }
    }
    
    qsort(r, k1*k2, sizeof(struct term), cmp);
    
    
    kr=0;
    rp=0;
    i=0,j=0;
    while (i<k1*k2) {
        while (r[i].ex == r[j].ex && i!=0) {
            r[j].coff += r[i].coff;
            r[i].coff = 0;
            i++;
            rp++;
        }
        if (r[j].coff == 0) {
            rp++;
        }
        j = i;
        i++;
    }
    
    cout<<k1*k2-rp;
    for (i=0; i<k1*k2; i++) {
        if (r[i].coff != 0) {
            printf(" %ld %.1f",r[i].ex,r[i].coff);
        }
    }
    return 0;
}
