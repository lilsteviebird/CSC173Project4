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

typedef struct SNAP{
    int StudentId;
    char* Name;
    char* Address;
    char* Phone;
    struct SNAP *next;
} SNAP;

struct SNAPLIST {
    struct SNAP* head;
};

typedef struct CSG{
    char* Course;
    int StudentId;
    char* Grade;
    struct CSG *next;
} CSG;

struct CSGLIST {
    struct CSG* head;
};

typedef struct CDH{
    char* Course;
    char* Day;
    char* Hour;
    struct CDH *next;
} CDH;

struct CDHLIST {
    struct CDH* head;
};

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
void except_CSGDatabase(int idGiven, Database this){
    int index = hashId_Method(this, idGiven, 6);
    CSGLIST* withMe = except_CSGLIST(this->csgBuckets[index], idGiven);
    this->csgBuckets[index] = withMe;
}

void except_CDHDatabase(char* courseGiven, Database this){
    int index = hashCourse_Method(this, courseGiven, 6);
    CDHLIST* withMe = except_CDHLIST(this->cdhBuckets[index], courseGiven);
    this->cdhBuckets[index] = withMe;
}

void except_CPDatabase(char* courseGiven, Database this){
    int index = hashCourse_Method(this, courseGiven, 8);
    CPLIST* withMe = except_CPLIST(this->cpBuckets[index], courseGiven);
    this->cpBuckets[index] = withMe;
}

void except_CRDatabase(char* courseGiven, Database this){
    int index = hashCourse_Method(this, courseGiven, 4);
    CRLIST* withMe = except_CRLIST(this->crBuckets[index], courseGiven);
    this->crBuckets[index] = withMe;
}

void except_SNAPDatabase(int idGiven, Database this){
    int index = hashId_Method(this, idGiven, 3);
    SNAPLIST* withMe = except_SNAPLIST(this->snapBuckets[index], idGiven);
    this->snapBuckets[index] = withMe;
}

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

//Part 2 functions

void gradeOfStudent(char* nameGiven, char* courseGiven, Database this){
    //will throw access error if student not found
    int goodId = 10000;
    
    for(int i = 0; i< sizeof(this->snapBuckets)/sizeof(SNAPLIST*); i++){
        SNAPLIST* tryMe= this->snapBuckets[i];
        SNAP* temp = tryMe->head;
        while(temp != NULL){
            if(temp->Name == nameGiven){
                printf("got here");
                goodId = temp->StudentId;
            }
            temp = temp->next;
        }
    }
    for(int i = 0; i < sizeof(this->csgBuckets)/sizeof(CSGLIST*); i++){
        CSGLIST* tryMe = this->csgBuckets[i];
        CSG* temp = tryMe->head;
        while(temp != NULL){
            if(temp->Course == courseGiven && temp->StudentId == goodId){
                printf("\nThe student ID is: %d", temp->StudentId);
                printf("\nThe student course is: %s", temp->Course);
                printf("\nThe student grade is: %s\n", temp->Grade);
            }
            temp = temp->next;
        }
    
    }
    
}

void whereIsStudent(char* nameGiven, char* timeGiven, char* dayGiven, Database this){
    //will throw access error if id not found
    int goodId = 10000;
    
    char* goodCourse;
    
    for(int i = 0; i< sizeof(this->snapBuckets)/sizeof(SNAPLIST*); i++){
        SNAPLIST* tryMe= this->snapBuckets[i];
        SNAP* temp = tryMe->head;
        while(temp != NULL){
            if(temp->Name == nameGiven){
                goodId = temp->StudentId;
            }
            temp = temp->next;
        }
    }
    for(int i = 0; i < sizeof(this->csgBuckets)/sizeof(CSGLIST*); i++){
        CSGLIST* tryMe = this->csgBuckets[i];
        CSG* temp = tryMe->head;
        while(temp != NULL){
            if(temp->StudentId == goodId){
                goodCourse = temp->Course;
                for(int j = 0; j < sizeof(this->cdhBuckets)/sizeof(CDHLIST*); j++){
                    CDHLIST* tryThis = lookup_CDHLIST(this->cdhBuckets[j], goodCourse);
                    CDH* temp2 = tryThis->head;
                    while(temp2 != NULL){
                        if(temp2->Hour == timeGiven && temp2->Day == dayGiven){
                            printf("\nThe course name is: %s", temp2->Course);
                            printf("\nThe day of this course is: %s", temp2->Day);
                            printf("\nThe hours of this course is: %s\n", temp2->Hour);
                        }
                        temp2 = temp2->next;
                    }
                }
            }
            temp = temp->next;
        }
    
    }
    
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





