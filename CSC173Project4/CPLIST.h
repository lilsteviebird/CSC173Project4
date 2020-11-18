//
//  CPLIST.h
//  CSC173Project4
//
//  Created by sli19 on 11/16/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#ifndef CPLIST_h
#define CPLIST_h

#include <stdio.h>
typedef struct CPLIST CPLIST;

extern CPLIST* new_CPLIST(void);
extern void add_CPLIST(CPLIST* this,char* courseGiven, char* preReqGiven);
extern void removeElement_CPLIST(CPLIST* this, char* courseGiven, char* preReqGiven);
extern void print_CPLIST(CPLIST* this);

extern CPLIST* lookup_CPLIST(CPLIST* this, char* courseGiven);
extern CPLIST* except_CPLIST(CPLIST* this, char* courseGiven);
#endif /* CPLIST_h */
