//
//  CSGLIST.c
//  CSC173Project4
//
//  Created by sli19 on 11/15/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#include "CSGLIST.h"
#include <stdlib.h>
#include <string.h>


typedef struct CSG{
    char* Course;
    int StudentId;
    char* Grade;
    struct CSG *next;
} CSG;

struct CSGLIST {
    struct CSG* head;
};

static CSG* new_CSG(char* courseGiven, int idGiven, char* gradeGiven ){
    CSG* this = (CSG*)malloc(sizeof(CSG));
    if(this == NULL){
        return NULL;
    }
    this->next = NULL;
    this->StudentId = idGiven;
    this->Course = courseGiven;
    this->Grade = gradeGiven;

    
    return this;
};

CSGLIST* new_CSGLIST(){
    CSGLIST *this = (CSGLIST*)malloc(sizeof(struct CSGLIST));
    this->head = NULL;
    return this;
}

void add_CSGLIST(CSGLIST* this, char* courseGiven, int idGiven, char* gradeGiven ){
    CSG* data = new_CSG(courseGiven, idGiven, gradeGiven);
    if(this->head == NULL){
        this->head = data;
    }else{
        CSG* temp = this->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = data;
    }
}

void removeElement_CSGLIST(CSGLIST* this, char* courseGiven, int idGiven, char* gradeGiven ){
    CSG* temp = this->head;
    CSG* data = new_CSG(courseGiven, idGiven, gradeGiven);
    if(this->head->StudentId == data->StudentId && this->head->Course == data->Course && this->head->Grade == data->Grade){
        this->head = temp->next;
    }
    else{
        while(temp->next->StudentId != data->StudentId && temp->next->Course != data->Course && temp->next->Grade != data->Grade){
            temp = temp->next;
        }
        CSG* newNext = temp->next->next;
        temp->next = newNext;
    }

}

CSGLIST* except_CSGLIST(CSGLIST* this, int idGiven){
    CSG* temp = this->head;
    CSGLIST* returnMe = new_CSGLIST();
    
    while(temp != NULL){
        if(temp->StudentId != idGiven){
            add_CSGLIST(returnMe, temp->Course, temp->StudentId, temp->Grade);
        }
        temp = temp->next;
    }
    return returnMe;
}

CSGLIST* lookup_CSGLIST(CSGLIST* this, int idGiven){
    CSG* temp = this->head;
    CSGLIST* returnMe = new_CSGLIST();
    
    while(temp != NULL){
        if(temp->StudentId == idGiven){
            add_CSGLIST(returnMe, temp->Course, temp->StudentId, temp->Grade);
        }
        temp = temp->next;
    }
    return returnMe;
}


static void print_CSG(CSG* this){
    printf("\nThe student ID is: %d", this->StudentId);
    printf("\nThe student course is: %s", this->Course);
    printf("\nThe student grade is: %s\n", this->Grade);
}

void print_CSGLIST(CSGLIST* this){
    if(this->head != NULL){
        CSG* temp = this->head;
        while(temp->next != NULL){
            print_CSG(temp);
            temp = temp->next;
        }
        print_CSG(temp);
    }
}

static void printCSG(CSG* this){
    printf("ID: %d", this->StudentId);
    printf("\tCourse: %s", this->Course);
    printf("\tGrade: %s\n", this->Grade);
}

static void printCSG_SID(CSG* this){
    printf("ID: %d", this->StudentId);
    printf("\n");
}


void selectionCSG(CSGLIST* this, char* course){
    CSG* temp = this->head;
    while(temp != NULL){
        if(strcmp(temp->Course,course)){
            printCSG(temp);
        }
        temp = temp->next;
    }
}

void projectionCSG(CSGLIST* this, char* course){
    CSG* temp = this->head;
    while(temp != NULL){
        if(strcmp(temp->Course,course)){
            printCSG_SID(temp);
        }
        temp = temp->next;
    }
}


