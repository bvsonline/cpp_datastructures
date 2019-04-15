//
//  swapbyPtrs.cpp
//  cpp_datastructures
//
//  Created by venkata bethamcharla on 4/14/19.
//  Copyright © 2019 VENKATA. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SwapDataImplementation();
void SwapData (void *vp1, void *vp2, int size);

struct Stock {
    char name[50];
    float price;
};

void SwapDataImplementation()
{
    
    int x = 2, y = 3;
    SwapData(&x, &y, sizeof(int));
    printf("x = %d, y = %d \n", x, y);
    
    float a = 2.0, b = 3.0;
    SwapData(&a, &b, sizeof(int));
    printf("a = %f, b = %f \n", a, b);
    
    double e = 222222222222.0, f = 333333333333.0;
    SwapData(&e, &f, sizeof(double));
    printf("e = %lf, f = %lf \n", e, f);
    
    Stock Uber;
    Uber.price = 50.00;
    strcpy(Uber.name, "UBER");
    
    Stock Lyft;
    Lyft.price = 62;
    strcpy(Lyft.name, "LYFT");
    SwapData(&Uber, &Lyft, sizeof(Stock));
    printf("UBER = %s, %f, LYFT = %s, %f \n", Uber.name,Uber.price,Lyft.name, Lyft.price);
    
    
}
void SwapData (void *vp1, void *vp2, int size)
{
    char temp[size];
    
    memcpy(temp, vp1, size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, temp, size);
    
}
