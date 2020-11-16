//
//  CDHLIST.h
//  CSC173Project4
//
//  Created by sli19 on 11/16/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#ifndef CDHLIST_h
#define CDHLIST_h

#include <stdio.h>
typedef struct CDHLIST CDHLIST;

extern CDHLIST* new_CDHLIST(void);
extern void add_CDHLIST(CDHLIST* this,char* courseGiven, char* dayGiven, int hourGiven);
extern void removeElement_CDHLIST(CDHLIST* this,char* courseGiven, char* dayGiven, int hourGiven);
extern void print_CDHLIST(CDHLIST* this);
#endif /* CDHLIST_h */
