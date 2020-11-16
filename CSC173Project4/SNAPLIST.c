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
    char Name[20];
    char Address[50];
    char Phone[11];
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
    strcpy(this->Name, nameGiven);
    strcpy(this->Address, addressGiven);
    strcpy(this->Phone, phoneGiven);
    
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
    if(this->head->StudentId == data->StudentId){
        this->head = temp->next;
    }
    else{
        while(temp->next->StudentId != data->StudentId){
            temp = temp->next;
        }
        SNAP* newNext = temp->next->next;
        temp->next = newNext;
    }

}

static void print_SNAP(SNAP* this){
    printf("The student ID is: %d", this->StudentId);
    printf("\nThe student name is: %s", this->Name);
    printf("\nThe student address is: %s", this->Address);
    printf("\nThe student phone number is: %s", this->Phone);
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
