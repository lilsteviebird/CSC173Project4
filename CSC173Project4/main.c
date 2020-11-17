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
    
    bool running = true;
    while(running){
        int selection = 0;
        printf("Hello welcome to the Database tester please select an option you'd like to do");
        printf("\n1. Print Database");
        printf("\n2. Delete a specific Course, Student and Grade");
        printf("\n3. Delete a specific Student, Name, Address and Phone Number");
        printf("\n4. Delete a specific Course and Pre-Req");
        printf("\n5. Delete a specific Course, and Room");
        printf("\n6. Delete a specific Course, Day and Hour");
        printf("\n7. Lookup a Student's Course and Grade");
        printf("\n8. Lookup a Student's Name, Address, and Phone Number");
        printf("\n9. Lookup a Course and its Pre-Req");
        printf("\n10. Lookup a Course and its Room");
        printf("\n11. Lookup a Course and its Day and Hours");
        
        printf("\nEnter a number: ");
        scanf("%d", &selection);
        if(selection == 1){
            print_Database(testData);
        }
        if(selection == 2){
            char* course = NULL;
            int id;
            char* grade = NULL;
            printf("\nPlease enter a Course: ");
            scanf("%[^\n]%*c", course);
//            printf("\nPlease enter an ID: ");
//            scanf("%d", &id);
//            printf("\nPlease enter a Grade: ");
//            scanf("%[^\n]%*c", &course);
            remove_CSGDatabase(id, course, grade, testData);
        }
        if(selection == 3){
            print_Database(testData);
        }
        if(selection == 4){
            print_Database(testData);
        }
        if(selection == 5){
            print_Database(testData);
        }
        if(selection == 6){
            print_Database(testData);
        }
        if(selection == 7){
            print_Database(testData);
        }
        if(selection == 8){
            print_Database(testData);
        }
        if(selection == 9){
            print_Database(testData);
        }
        if(selection == 10){
            print_Database(testData);
        }
        if(selection == 11){
            print_Database(testData);
        }




    }
    
  
    
    return 0;
}
