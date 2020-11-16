//
//  Database.c
//  CSC173Project4
//
//  Created by sli19 on 11/15/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#include "Database.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


Database new_Database(int size){
    Database this = (Database)malloc(sizeof(struct Database));
    if(this == NULL){
        return NULL;
    }
    this->size = size;
    for(int i = 0; i < size; i++){
        this->csgBuckets[i] = new_CSGLIST();
        this->cdhBuckets[i] = new_CDHLIST();
        this->cpBuckets[i] = new_CPLIST();
        this->crBuckets[i] = new_CRLIST();
        this->snapBuckets[i] = new_SNAPLIST();
    }
    this->count = 0;
    return this;
}

static int hashId_Method(Database this, int idGiven){
    int index = idGiven % this->size;
    return index;
}

static int hashCourse_Method(Database this, char* courseGiven){
    int index = 0;
    for(int i = 0; i < strlen(courseGiven); i++){
        index = index * (int) courseGiven[i];
    }
    index = index % this->size;
    return index;
}

void insert_CSGDatabase(char* courseGiven, int idGiven, char* gradeGiven, Database this){
    int index = hashId_Method(this, idGiven);
    add_CSGLIST(this->csgBuckets[index], courseGiven, idGiven, gradeGiven);
}
void insert_SNAPDatabase(int idGiven, char* nameGiven, char* addressGiven, char* phoneGiven, Database this){
    int index = hashId_Method(this, idGiven);
    add_SNAPLIST(this->snapBuckets[index], idGiven, nameGiven, addressGiven, phoneGiven);
}
void insert_CDHDatabase(char* courseGiven, char* dayGiven, int hourGiven, Database this){
    int index = hashCourse_Method(this, courseGiven);
    add_CDHLIST(this->cdhBuckets[index], courseGiven, dayGiven, hourGiven);
}
void insert_CRDatabase(char* courseGiven, char* roomGiven, Database this){
    int index = hashCourse_Method(this, courseGiven);
    add_CRLIST(this->crBuckets[index], courseGiven, roomGiven);
}
void insert_CPDatabase(char* courseGiven, char* prereqGiven, Database this){
    int index = hashCourse_Method(this, courseGiven);
    add_CPLIST(this->cpBuckets[index], courseGiven, prereqGiven);
}

void print_Database(Database this){
    printf("Printing CSG database...\n");
    for(int i = 0; i< this->size; i++){
        print_CSGLIST(this->csgBuckets[i]);
    }
    printf("Printing CDH database...\n");
    for(int i = 0; i< this->size; i++){
        print_CDHLIST(this->cdhBuckets[i]);
    }
    printf("Printing CR database...\n");
    for(int i = 0; i< this->size; i++){
        print_CRLIST(this->crBuckets[i]);
    }
    printf("Printing CP database...\n");
    for(int i = 0; i< this->size; i++){
        print_CPLIST(this->cpBuckets[i]);
    }
    printf("Printing SNAP database...\n");
    for(int i = 0; i< this->size; i++){
        print_SNAPLIST(this->snapBuckets[i]);
    }
}





