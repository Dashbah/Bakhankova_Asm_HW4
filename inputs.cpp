//
// Created by Dashbah on 15.12.2022.
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <random>
#include <iostream>
//
// Created by Dashbah on 09.11.2022.
//


extern double left, right;

bool consoleInput() {
    printf("a, b, left, right: \n");
//    scanf("%lf", &a);
//    scanf("%lf", &b);
    scanf("%lf", &left);
    scanf("%lf", &right);
    if (left >= right) {
        return false;
    }
    return true;
}

bool fileInput() {
    FILE *input;
    char fileName[50];
    printf("Enter input file name: ");
    scanf("%s", fileName);
    if (access(fileName, F_OK) == 0) {
        input = fopen(fileName, "r");
        fscanf(input, "%lf", &left);
        fscanf(input, "%lf", &right);
        printf("Your parameters: \n");
        printf("left: ");
        printf("%lf", left);
        printf(" right: ");
        printf("%lf", right);
        printf("\n");
        return true;
    }
    return false;
}

void randomGeneration() {
    time_t t;
    srand((unsigned) time(&t));
    //    std::random_device rd;
    //    std::default_random_engine eng(rd());
    //    std::uniform_real_distribution<double> distr(-10, 10);
    //    std::cout << distr(left);

    left = rand() % 20 - 10;
    right = left + rand() % 20;

    printf("Your parameters: \n");
    printf("left: ");
    printf("%lf", left);
    printf(" right: ");
    printf("%lf", right);
    printf("\n");
}
