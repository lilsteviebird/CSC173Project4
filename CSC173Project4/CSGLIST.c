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
    char Course[6];
    int StudentId;
    char Grade[2];
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
    strcpy(this->Course, courseGiven);
    strcpy(this->Grade, gradeGiven);
    
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
    if(this->head->StudentId == data->StudentId){
        this->head = temp->next;
    }
    else{
        while(temp->next->StudentId != data->StudentId){
            temp = temp->next;
        }
        CSG* newNext = temp->next->next;
        temp->next = newNext;
    }

}

static void print_CSG(CSG* this){
    printf("The student ID is: %d", this->StudentId);
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

