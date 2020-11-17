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


    Database testData = new_Database(5);
    //inserting CSG data
    insert_CSGDatabase("CSC101", 12345, "A", testData);
    insert_CSGDatabase("CSC101", 67890, "B", testData);
    insert_CSGDatabase( "EE200", 12345, "C", testData);
    insert_CSGDatabase( "EE200", 22222, "B+", testData);
    insert_CSGDatabase( "CS101", 33333, "A-", testData);
    insert_CSGDatabase( "PH100", 67890, "C+", testData);
    //inserting SNAP data
    insert_SNAPDatabase(12345, "C. Brown", "12 Apple St.", "555-1234", testData);
    insert_SNAPDatabase(67890, "L. Brown", "34 Pear Ave.", "555-5678", testData);
    insert_SNAPDatabase(22222, "P. Patty", "56 Grape Blvd.", "555-9999", testData);
    //inserting CP data
    insert_CPDatabase("CS101", "CS100", testData);
    insert_CPDatabase("EE200", "EE005", testData);
    insert_CPDatabase("EE200", "CS100", testData);
    insert_CPDatabase("CS120", "CS101", testData);
    insert_CPDatabase("CS121", "CS120", testData);
    insert_CPDatabase("CS205", "CS101", testData);
    insert_CPDatabase("CS206", "CS121", testData);
    insert_CPDatabase("CS206", "CS205", testData);
    
    //inserting CR data
    insert_CRDatabase("CS101", "Turing Aud.", testData);
    insert_CRDatabase("EE200", "25 Ohm Hall", testData);
    insert_CRDatabase("PH100", "Newton Lab.", testData);
//    //inserting CDH data
    insert_CDHDatabase("CS101", "M", "9AM", testData);
    insert_CDHDatabase("CS101", "W", "9AM", testData);
    insert_CDHDatabase("CS101", "F", "9AM", testData);
    insert_CDHDatabase("EE200", "Tu", "10AM", testData);
    insert_CDHDatabase("EE200", "W", "1PM", testData);
    insert_CDHDatabase("EE200", "Th", "10AM", testData);
    
    print_Database(testData);
    printf("\nNow we remove one of something from every list\n");
    remove_CRDatabase("EE200", "25 Ohm Hall", testData);
    remove_CSGDatabase(67890, "PH100", "C+", testData);
    remove_SNAPDatabase(22222, "C. Brown","12 Apple St.", "555-1234", testData);
    remove_CPDatabase("CS205", "CS101", testData);
    remove_CDHDatabase("EE200", "W", "1PM", testData);
    
    print_Database(testData);

    return 0;
}
