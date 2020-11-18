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
    CSGLIST* csgBuckets[6];
    SNAPLIST* snapBuckets[3];
    CDHLIST* cdhBuckets[6];
    CRLIST* crBuckets[4];
    CPLIST* cpBuckets[8];
    
};

extern Database new_Database(int size);

//insert functions
extern void insert_CSGDatabase(char* courseGiven, int idGiven, char* gradeGiven, Database this);
extern void insert_SNAPDatabase(int idGiven, char* nameGiven, char* addressGiven, char* phoneGiven, Database this);
extern void insert_CDHDatabase(char* courseGiven, char* dayGiven, char* hourGiven, Database this);
extern void insert_CRDatabase(char* courseGiven, char* roomGiven, Database this);
void insert_CPDatabase(char* courseGiven, char* prereqGiven, Database this);

//delete functions
extern void remove_CSGDatabase(int idGiven, char* courseGiven, char* gradeGiven, Database this);
extern void remove_SNAPDatabase(int idGiven, char* nameGiven, char* addressGiven, char* phoneGiven, Database this);
extern void remove_CDHDatabase(char* courseGiven, char* dayGiven, char* hourGiven, Database this);
extern void remove_CRDatabase(char* courseGiven, char* roomGiven, Database this);
extern void remove_CPDatabase(char* courseGiven, char* prereqGiven, Database this);

//lookup functions
extern void lookup_CSGDatabase(int idGiven, Database this);
extern void lookup_SNAPDatabase(int idGiven, Database this);
extern void lookup_CDHDatabase(char* courseGiven, Database this);
extern void lookup_CRDatabase(char* courseGiven, Database this);
extern void lookup_CPDatabase(char* courseGiven, Database this);

//delete everything by given tuple functions
extern void except_CRDatabase(char* courseGiven, Database this);
extern void except_CSGDatabase(int idGiven, Database this);
extern void except_CDHDatabase(char* courseGiven, Database this);
extern void except_CPDatabase(char* courseGiven, Database this);
extern void except_SNAPDatabase(int idGiven, Database this);

//Part 2 methods
extern void gradeOfStudent(char* nameGiven, char* courseGiven, Database this);
extern void whereIsStudent(char* nameGiven, char* timeGiven, char* dayGiven, Database this);

//Part 3
extern void allCR_CDH(CRLIST* cr, CDHLIST* cdh, char* room);
extern void joinCR_CDH(CRLIST* cr, CDHLIST* cdh);
extern void selectionCSGDatabase(char* course, Database this);
extern void projectionCSGDatabase(char* course, Database this);
extern void joinCR_CDHDatabase(Database this);
extern void allCR_CDHDatabase(char* room, Database this);

//Print Database
extern void print_Database(Database this);
#endif /* Database_h */
