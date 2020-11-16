//
//  main.c
//  CSC173Project4
//
//  Created by sli19 on 11/15/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#include <stdio.h>

#include "CSGLIST.h"

#include "Database.h"

int main(int argc, const char * argv[]) {
    // insert code here...

    CSGLIST* testMe = new_CSGLIST();
    
    add_CSGLIST(testMe, "CSC173", 5, "90");
    add_CSGLIST(testMe, "CSC171", 2, "78");

    Database testData = new_Database(5);
    insert_CSGDatabase("CSC173", 5, "90", testData);
    insert_CSGDatabase("CSC171", 5, "88", testData);
    insert_CSGDatabase( "CSC171", 2, "78", testData);
    print_Database(testData);
    return 0;
}
