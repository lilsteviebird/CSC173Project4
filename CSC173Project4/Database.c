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


Database new_Database(int size){
    Database this = (Database)malloc(sizeof(struct Database));
    if(this == NULL){
        return NULL;
    }
    this->size = size;
    for(int i = 0; i < size; i++){
        this->buckets[i] = new_CSGLIST();
    }
    this->count = 0;
    return this;
}

static int hashId_Method(Database this, int idGiven){
    int index = idGiven % this->size;
    return index;
}

void insert_CSGDatabase(char* courseGiven, int idGiven, char* gradeGiven, Database this){
    int index = hashId_Method(this, idGiven);
    add_CSGLIST(this->buckets[index], courseGiven, idGiven, gradeGiven);
}

void print_Database(Database this){
    for(int i = 0; i< this->size; i++){
        print_CSGLIST(this->buckets[i]);
    }
}





