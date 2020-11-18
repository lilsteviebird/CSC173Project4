//
//  CRLIST.h
//  CSC173Project4
//
//  Created by sli19 on 11/16/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#ifndef CRLIST_h
#define CRLIST_h

#include <stdio.h>
typedef struct CRLIST CRLIST;

extern CRLIST* new_CRLIST(void);
extern void add_CRLIST(CRLIST* this,char* courseGiven, char* roomGiven);
extern void removeElement_CRLIST(CRLIST* this,char* courseGiven, char* roomGiven);
extern void print_CRLIST(CRLIST* this);
extern CRLIST* lookup_CRLIST(CRLIST* this, char* courseGiven);
extern CRLIST* except_CRLIST(CRLIST* this, char* courseGiven);
#endif /* CRLIST_h */
