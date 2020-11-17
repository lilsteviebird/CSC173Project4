//
//  CDHLIST.c
//  CSC173Project4
//
//  Created by sli19 on 11/16/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#include "CDHLIST.h"
#include <stdlib.h>
#include <string.h>

typedef struct CDH{
    char* Course;
    char* Day;
    int Hour;
    struct CDH *next;
} CDH;

struct CDHLIST {
    struct CDH* head;
};

static CDH* new_CDH(char* courseGiven, char* dayGiven, int hourGiven ){
    CDH* this = (CDH*)malloc(sizeof(CDH));
    if(this == NULL){
        return NULL;
    }
    this->next = NULL;
    this->Hour = hourGiven;
    this->Course = courseGiven;
    this->Day = dayGiven;
    
    return this;
};

CDHLIST* new_CDHLIST(){
    CDHLIST *this = (CDHLIST*)malloc(sizeof(struct CDHLIST));
    this->head = NULL;
    return this;
}

void add_CDHLIST(CDHLIST* this,char* courseGiven, char* dayGiven, int hourGiven){
    CDH* data = new_CDH(courseGiven, dayGiven, hourGiven);
    if(this->head == NULL){
        this->head = data;
    }else{
        CDH* temp = this->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = data;
    }
}

void removeElement_CDHLIST(CDHLIST* this,char* courseGiven, char* dayGiven, int hourGiven){
    CDH* temp = this->head;
    CDH* data = new_CDH(courseGiven, dayGiven, hourGiven);
    if(this->head->Course == data->Course){
        this->head = temp->next;
    }
    else{
        while(temp->next->Course != data->Course){
            temp = temp->next;
        }
        CDH* newNext = temp->next->next;
        temp->next = newNext;
    }

}

static void print_CDH(CDH* this){
    printf("\nThe course name is: %s", this->Course);
    printf("\nThe day of this course is: %s", this->Day);
    printf("\nThe hours of this course is: %d\n", this->Hour);
}

void print_CDHLIST(CDHLIST* this){
    if(this->head != NULL){
        CDH* temp = this->head;
        while(temp->next != NULL){
            print_CDH(temp);
            temp = temp->next;
        }
        print_CDH(temp);
    }
}
