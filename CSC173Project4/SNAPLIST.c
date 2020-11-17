//
//  SNAPLIST.c
//  CSC173Project4
//
//  Created by sli19 on 11/16/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#include "SNAPLIST.h"
#include <stdlib.h>
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

static SNAP* new_SNAP(int idGiven, char* nameGiven, char* addressGiven, char* phoneGiven ){
    SNAP* this = (SNAP*)malloc(sizeof(SNAP));
    if(this == NULL){
        return NULL;
    }
    this->next = NULL;
    this->StudentId = idGiven;
    this->Name = nameGiven;
    this->Address = addressGiven;
    this->Phone = phoneGiven;

    
    return this;
};

SNAPLIST* new_SNAPLIST(){
    SNAPLIST *this = (SNAPLIST*)malloc(sizeof(struct SNAPLIST));
    this->head = NULL;
    return this;
}

void add_SNAPLIST(SNAPLIST* this,int idGiven, char* nameGiven, char* addressGiven, char* phoneGiven ){
    SNAP* data = new_SNAP(idGiven, nameGiven, addressGiven, phoneGiven);
    if(this->head == NULL){
        this->head = data;
    }else{
        SNAP* temp = this->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = data;
    }
}

void removeElement_SNAPLIST(SNAPLIST* this, int idGiven, char* nameGiven, char* addressGiven, char* phoneGiven){
    SNAP* temp = this->head;
    SNAP* data = new_SNAP(idGiven, nameGiven, addressGiven, phoneGiven);
    if(this->head->StudentId == data->StudentId && this->head->Name != data->Name && this->head->Address != data->Address && this->head->Phone != data->Phone){
        this->head = temp->next;
    }
    else{
        while(temp->next->StudentId != data->StudentId && temp->next->Name != data->Name && temp->next->Address != data->Address && temp->next->Phone != data->Phone){
            temp = temp->next;
        }
        SNAP* newNext = temp->next->next;
        temp->next = newNext;
    }

}

SNAPLIST* lookup_SNAPLIST(SNAPLIST* this, int idGiven){
    SNAP* temp = this->head;
    SNAPLIST* returnMe = new_SNAPLIST();
    
    while(temp != NULL){
        if(temp->StudentId == idGiven){
            add_SNAPLIST(returnMe, temp->StudentId, temp->Name, temp->Address, temp->Phone);
        }
        temp = temp->next;
    }
    return returnMe;
}

static void print_SNAP(SNAP* this){
    printf("\nThe student ID is: %d", this->StudentId);
    printf("\nThe student name is: %s", this->Name);
    printf("\nThe student address is: %s", this->Address);
    printf("\nThe student phone number is: %s\n", this->Phone);
}

void print_SNAPLIST(SNAPLIST* this){
    if(this->head != NULL){
        SNAP* temp = this->head;
        while(temp->next != NULL){
            print_SNAP(temp);
            temp = temp->next;
        }
        print_SNAP(temp);
    }
}
