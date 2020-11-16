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

typedef struct Database* Database;

struct Database{
    int size;
    int count;
    CSGLIST* buckets[5];
};

extern Database new_Database(int size);
extern void insert_CSGDatabase(char* courseGiven, int idGiven, char* gradeGiven, Database this);
extern void print_Database(Database this);
#endif /* Database_h */
