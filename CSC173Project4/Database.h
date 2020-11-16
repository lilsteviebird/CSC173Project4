//
//  Database.h
//  CSC173Project4
//
//  Created by sli19 on 11/15/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#ifndef Database_h
#define Database_h

#include <stdio.h>

#include "CSGLIST.h"
#include "CPLIST.h"
#include "SNAPLIST.h"
#include "CDHLIST.h"
#include "CRLIST.h"

typedef struct Database* Database;

struct Database{
    int size;
    int count;
    CSGLIST* csgBuckets[5];
    SNAPLIST* snapBuckets[5];
    CDHLIST* cdhBuckets[5];
    CRLIST* crBuckets[5];
    CPLIST* cpBuckets[5];
    
};

extern Database new_Database(int size);
extern void insert_CSGDatabase(char* courseGiven, int idGiven, char* gradeGiven, Database this);
extern void insert_SNAPDatabase(int idGiven, char* nameGiven, char* addressGiven, char* phoneGiven, Database this);
extern void insert_CDHDatabase(char* courseGiven, char* dayGiven, int hourGiven, Database this);
extern void insert_CRDatabase(char* courseGiven, char* roomGiven, Database this);
void insert_CPDatabase(char* courseGiven, char* prereqGiven, Database this);
extern void print_Database(Database this);
#endif /* Database_h */
