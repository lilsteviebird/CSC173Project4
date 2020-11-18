//
//  CRLIST.c
//  CSC173Project4
//
//  Created by sli19 on 11/16/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#include "CRLIST.h"
#include <stdlib.h>
#include <string.h>

typedef struct CR{
    char* Course;
    char* Room;
    struct CR *next;
} CR;

struct CRLIST {
    struct CR* head;
};

static CR* new_CR(char* courseGiven, char* roomGiven){
    CR* this = (CR*)malloc(sizeof(CR));
    if(this == NULL){
        return NULL;
    }
    this->next = NULL;
    this->Course = courseGiven;
    this->Room = roomGiven;
    
    return this;
};

CRLIST* new_CRLIST(){
    CRLIST *this = (CRLIST*)malloc(sizeof(struct CRLIST));
    this->head = NULL;
    return this;
}

void add_CRLIST(CRLIST* this,char* courseGiven, char* roomGiven){
    CR* data = new_CR(courseGiven, roomGiven);
    if(this->head == NULL){
        this->head = data;
    }else{
        CR* temp = this->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = data;
    }
}

void removeElement_CRLIST(CRLIST* this,char* courseGiven, char* roomGiven){
    CR* temp = this->head;
    CR* data = new_CR(courseGiven, roomGiven);
    if(this->head->Course == data->Course && this->head->Room == data->Room){
        this->head = temp->next;
    }
    else{
        while(temp->next->Course != data->Course && temp->next->Room != temp->next->Room){
            temp = temp->next;
        }
        CR* newNext = temp->next->next;
        temp->next = newNext;
    }

}

CRLIST* except_CRLIST(CRLIST* this, char* courseGiven){
    CR* temp = this->head;
    CRLIST* returnMe = new_CRLIST();
    
    while(temp != NULL){
        if(temp->Course != courseGiven){
            add_CRLIST(returnMe, temp->Course, temp->Room);
        }
        temp = temp->next;
    }
    return returnMe;
}

CRLIST* lookup_CRLIST(CRLIST* this, char* courseGiven){
    CR* temp = this->head;
    CRLIST* returnMe = new_CRLIST();
    
    while(temp != NULL){
        if(temp->Course == courseGiven){
            add_CRLIST(returnMe, temp->Course, temp->Room);
        }
        temp = temp->next;
    }
    return returnMe;
}

static void print_CR(CR* this){
    printf("\nThe course name is: %s", this->Course);
    printf("\nThe room of this course is: %s\n", this->Room);
}

void print_CRLIST(CRLIST* this){
    if(this->head != NULL){
        CR* temp = this->head;
        while(temp->next != NULL){
            print_CR(temp);
            temp = temp->next;
        }
        print_CR(temp);
    }
}
