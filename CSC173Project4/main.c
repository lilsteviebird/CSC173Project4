//
//  main.c
//  CSC173Project4
//
//  Created by sli19 on 11/15/20.
//  Copyright © 2020 sli19. All rights reserved.
//

#include <stdio.h>

#include "CSGLIST.h"
#include <string.h>
#include "Database.h"
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    Database testData = new_Database(5);
    //inserting CSG data
    insert_CSGDatabase("CS101", 12345, "A", testData);
    insert_CSGDatabase("CS101", 67890, "B", testData);
    insert_CSGDatabase( "EE200", 12345, "C", testData);
    insert_CSGDatabase( "EE200", 22222, "B+", testData);
    insert_CSGDatabase( "CS101", 33333, "A-", testData);
    insert_CSGDatabase( "PH100", 67890, "C+", testData);
    //inserting SNAP data
    insert_SNAPDatabase(12345, "C.Brown", "12 Apple St.", "555-1234", testData);
    insert_SNAPDatabase(67890, "L.Brown", "34 Pear Ave.", "555-5678", testData);
    insert_SNAPDatabase(22222, "P.Patty", "56 Grape Blvd.", "555-9999", testData);
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
    
    gradeOfStudent("C.Brown", "CS101", testData);
    whereIsStudent("C.Brown", "9AM", "M", testData);
    char* name;
    char* course;
    printf("\nPlease enter a Name: ");
    scanf("%s", &name);
    printf("%s", &name);
    printf("\nPlease enter a Course: ");
    scanf("%s", &course);
    printf("%s", &course);
    
    gradeOfStudent(name, course, testData);


//    while(running){
//        int selection = 0;
//        printf("\nHello welcome to the Database tester please select an option you'd like to do");
//        printf("\n1. What grade did StudentName get in CourseName?");
//        printf("\n2. Where is StudentName at Time on Day?");
//
//        printf("\nEnter a number: ");
//        scanf("%d", &selection);
//
//        if(selection == 1){
//            char course[64];
//            char name[64];
//            printf("\nPlease enter a Name: ");
//            scanf("%s", name);
//            printf("\nPlease enter a Course: ");
//            scanf("%s\n", course);
//            gradeOfStudent(name, course, testData);
//        }
//        if(selection == 2){
//            char day[64];
//            char hour[64];
//            char name[64];
//            printf("\nPlease enter a Name: ");
//            scanf("%s", name);
//            printf("\nPlease enter an Hour: ");
//            scanf("%s", hour);
//            printf("\nPlease enter a Day: ");
//            scanf("%s", day);
//            whereIsStudent(name, hour, day, testData);
//        }
//
//
//
//    }
    
  
    
    return 0;
}
