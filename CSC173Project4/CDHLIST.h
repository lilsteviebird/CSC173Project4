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
extern void add_CDHLIST(CDHLIST* this,char* courseGiven, char* dayGiven, char* hourGiven);
extern void removeElement_CDHLIST(CDHLIST* this,char* courseGiven, char* dayGiven, char* hourGiven);
extern void print_CDHLIST(CDHLIST* this);

extern CDHLIST* lookup_CDHLIST(CDHLIST* this, char* courseGiven);
extern CDHLIST* except_CDHLIST(CDHLIST* this, char* courseGiven);
#endif /* CDHLIST_h */
