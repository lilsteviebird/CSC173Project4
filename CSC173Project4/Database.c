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
    for(int i = 0; i < 6; i++){
        this->csgBuckets[i] = new_CSGLIST();
        this->cdhBuckets[i] = new_CDHLIST();
    }
    for(int i = 0; i < 3; i++){
        this->snapBuckets[i] = new_SNAPLIST();
    }
    for(int i = 0; i < 4; i++){
        this->crBuckets[i] = new_CRLIST();
    }
    for(int i = 0; i < 8; i++){
        this->cpBuckets[i] = new_CPLIST();
    }
    return this;
}

static int hashId_Method(Database this, int idGiven, int mod){
    int index = idGiven % mod;
    return index;
}

static int hashCourse_Method(Database this, char* courseGiven, int mod){
    int index = 1;
    for(int i = 0; i < strlen(courseGiven); i++){
        index = index + (int) courseGiven[i];
    }
    index = index % this->size;
    return index;
}
//insert methods
void insert_CSGDatabase(char* courseGiven, int idGiven, char* gradeGiven, Database this){
    int index = hashId_Method(this, idGiven, 6);
    add_CSGLIST(this->csgBuckets[index], courseGiven, idGiven, gradeGiven);
}
void insert_SNAPDatabase(int idGiven, char* nameGiven, char* addressGiven, char* phoneGiven, Database this){
    int index = hashId_Method(this, idGiven, 3);
    add_SNAPLIST(this->snapBuckets[index], idGiven, nameGiven, addressGiven, phoneGiven);
}
void insert_CDHDatabase(char* courseGiven, char* dayGiven, char* hourGiven, Database this){
    int index = hashCourse_Method(this, courseGiven, 6);
    add_CDHLIST(this->cdhBuckets[index], courseGiven, dayGiven, hourGiven);
}
void insert_CRDatabase(char* courseGiven, char* roomGiven, Database this){
    int index = hashCourse_Method(this, courseGiven, 4);
    add_CRLIST(this->crBuckets[index], courseGiven, roomGiven);
}
void insert_CPDatabase(char* courseGiven, char* prereqGiven, Database this){
    int index = hashCourse_Method(this, courseGiven, 8);
    add_CPLIST(this->cpBuckets[index], courseGiven, prereqGiven);
}

//remove specific tuble methods
void remove_CSGDatabase(int idGiven, char* courseGiven, char* gradeGiven, Database this){
    int index = hashId_Method(this, idGiven, 6);
    removeElement_CSGLIST(this->csgBuckets[index], courseGiven, idGiven, gradeGiven);
}
void remove_SNAPDatabase(int idGiven, char* nameGiven, char* addressGiven, char* phoneGiven, Database this){
    int index = hashId_Method(this, idGiven, 3);
    removeElement_SNAPLIST(this->snapBuckets[index], idGiven, nameGiven, addressGiven, phoneGiven);
}
void remove_CDHDatabase(char* courseGiven, char* dayGiven, char* hourGiven, Database this){
    int index = hashCourse_Method(this, courseGiven, 6);
    removeElement_CDHLIST(this->cdhBuckets[index], courseGiven, dayGiven, hourGiven);
}
void remove_CRDatabase(char* courseGiven, char* roomGiven, Database this){
    int index = hashCourse_Method(this, courseGiven, 4);
    removeElement_CRLIST(this->crBuckets[index], courseGiven, roomGiven);
}
void remove_CPDatabase(char* courseGiven, char* prereqGiven, Database this){
    int index = hashCourse_Method(this, courseGiven, 8);
    removeElement_CPLIST(this->cpBuckets[index], courseGiven, prereqGiven);
}
//remove all courses or the ids that the tuple "starts with"

//lookup functions

void lookup_CSGDatabase(int idGiven, Database this){
    int index = hashId_Method(this, idGiven, 6);
    print_CSGLIST(lookup_CSGLIST(this->csgBuckets[index], idGiven));
}

void lookup_SNAPDatabase(int idGiven, Database this){
    int index = hashId_Method(this, idGiven, 3);
    print_SNAPLIST(lookup_SNAPLIST(this->snapBuckets[index], idGiven));
}

void lookup_CDHDatabase(char* courseGiven, Database this){
    int index = hashCourse_Method(this, courseGiven, 6);
    print_CDHLIST(lookup_CDHLIST(this->cdhBuckets[index], courseGiven));
}

void lookup_CRDatabase(char* courseGiven, Database this){
    int index = hashCourse_Method(this, courseGiven, 4);
    print_CRLIST(lookup_CRLIST(this->crBuckets[index], courseGiven));
}

void lookup_CPDatabase(char* courseGiven, Database this){
    int index = hashCourse_Method(this, courseGiven, 8);
    print_CPLIST(lookup_CPLIST(this->cpBuckets[index], courseGiven));
}

void print_Database(Database this){
    printf("Printing CSG database...\n");
    for(int i = 0; i< 6; i++){
        print_CSGLIST(this->csgBuckets[i]);
    }
    printf("\nPrinting CDH database...\n");
    for(int i = 0; i< 6; i++){
        print_CDHLIST(this->cdhBuckets[i]);
    }
    printf("\nPrinting CP database...\n");
    for(int i = 0; i< 8; i++){
        print_CPLIST(this->cpBuckets[i]);
    }
    printf("\nPrinting CR database...\n");
    for(int i = 0; i< 4; i++){
        print_CRLIST(this->crBuckets[i]);
    }
    printf("\nPrinting SNAP database...\n");
    for(int i = 0; i< 3; i++){
        print_SNAPLIST(this->snapBuckets[i]);
    }
}





