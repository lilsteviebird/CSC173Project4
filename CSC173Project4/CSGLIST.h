//
//  CSGLIST.h
//  CSC173Project4
//
//  Created by sli19 on 11/15/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#ifndef CSGLIST_h
#define CSGLIST_h

#include <stdio.h>

typedef struct CSGLIST CSGLIST;

extern CSGLIST* new_CSGLIST(void);
extern void add_CSGLIST(CSGLIST* this, char* courseGiven, int idGiven, char* gradeGiven );
extern void removeElement_CSGLIST(CSGLIST* this, char* courseGiven, int idGiven, char* gradeGiven );
extern void print_CSGLIST(CSGLIST* this);

extern CSGLIST* lookup_CSGLIST(CSGLIST* this, int idGiven);
extern CSGLIST* except_CSGLIST(CSGLIST* this, int idGiven);

#endif /* CSGLIST_h */
