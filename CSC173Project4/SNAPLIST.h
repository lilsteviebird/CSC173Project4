//
//  SNAPLIST.h
//  CSC173Project4
//
//  Created by sli19 on 11/16/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#ifndef SNAPLIST_h
#define SNAPLIST_h

#include <stdio.h>

typedef struct SNAPLIST SNAPLIST;

extern SNAPLIST* new_SNAPLIST(void);
extern void add_SNAPLIST(SNAPLIST* this,int idGiven, char* nameGiven, char* addressGiven, char* phoneGiven);
extern void removeElement_SNAPLIST(SNAPLIST* this, int idGiven, char* nameGiven, char* addressGiven, char* phoneGiven);
extern void print_SNAPLIST(SNAPLIST* this);

extern SNAPLIST* lookup_SNAPLIST(SNAPLIST* this, int idGiven);
extern SNAPLIST* except_SNAPLIST(SNAPLIST* this, int idGiven);
#endif /* SNAPLIST_h */
