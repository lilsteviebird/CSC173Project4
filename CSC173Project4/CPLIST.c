//
//  CPLIST.c
//  CSC173Project4
//
//  Created by sli19 on 11/16/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#include "CPLIST.h"
#include <stdlib.h>
#include <string.h>

typedef struct CP{
    char* Course;
    char* Prereq;
    struct CP *next;
} CP;

struct CPLIST {
    struct CP* head;
};

static CP* new_CP(char* courseGiven, char* preReqGiven ){
    CP* this = (CP*)malloc(sizeof(CP));
    if(this == NULL){
        return NULL;
    }
    this->next = NULL;
    this->Course = courseGiven;
    this->Prereq = preReqGiven;
    
    return this;
};

CPLIST* new_CPLIST(){
    CPLIST *this = (CPLIST*)malloc(sizeof(struct CPLIST));
    this->head = NULL;
    return this;
}

void add_CPLIST(CPLIST* this,char* courseGiven, char* preReqGiven){
    CP* data = new_CP(courseGiven, preReqGiven);
    if(this->head == NULL){
        this->head = data;
    }else{
        CP* temp = this->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = data;
    }
}

void removeElement_CPLIST(CPLIST* this, char* courseGiven, char* preReqGiven){
    CP* temp = this->head;
    CP* data = new_CP(courseGiven, preReqGiven);
    if(this->head->Course == data->Course && this->head->Prereq == data->Prereq){
        this->head = temp->next;
    }
    else{
        while(temp->next->Course != data->Course && temp->next->Prereq != data->Prereq){
            temp = temp->next;
        }
        CP* newNext = temp->next->next;
        temp->next = newNext;
    }

}

CPLIST* lookup_CPLIST(CPLIST* this, char* courseGiven){
    CP* temp = this->head;
    CPLIST* returnMe = new_CPLIST();
    
    while(temp != NULL){
        if(temp->Course == courseGiven){
            add_CPLIST(returnMe, temp->Course, temp->Prereq);
        }
        temp = temp->next;
    }
    return returnMe;
}


static void print_CP(CP* this){
    printf("\nThe course name is: %s", this->Course);
    printf("\nThe pre req is: %s\n", this->Prereq);
}

void print_CPLIST(CPLIST* this){
    if(this->head != NULL){
        CP* temp = this->head;
        while(temp->next != NULL){
            print_CP(temp);
            temp = temp->next;
        }
        print_CP(temp);
    }
}
