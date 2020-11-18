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
    
        Database testData2 = new_Database(5);
        //inserting CSG data
        insert_CSGDatabase("CS101", 12345, "A", testData2);
        insert_CSGDatabase("CS101", 67890, "B", testData2);
        insert_CSGDatabase( "EE200", 12345, "C", testData2);
        insert_CSGDatabase( "EE200", 22222, "B+", testData2);
        insert_CSGDatabase( "CS101", 33333, "A-", testData2);
        insert_CSGDatabase( "PH100", 67890, "C+", testData2);
        //inserting SNAP data
        insert_SNAPDatabase(12345, "C.Brown", "12 Apple St.", "555-1234", testData2);
        insert_SNAPDatabase(67890, "L.Brown", "34 Pear Ave.", "555-5678", testData2);
        insert_SNAPDatabase(22222, "P.Patty", "56 Grape Blvd.", "555-9999", testData2);
        //inserting CP data
        insert_CPDatabase("CS101", "CS100", testData2);
        insert_CPDatabase("EE200", "EE005", testData2);
        insert_CPDatabase("EE200", "CS100", testData2);
        insert_CPDatabase("CS120", "CS101", testData2);
        insert_CPDatabase("CS121", "CS120", testData2);
        insert_CPDatabase("CS205", "CS101", testData2);
        insert_CPDatabase("CS206", "CS121", testData2);
        insert_CPDatabase("CS206", "CS205", testData2);
        
        //inserting CR data
        insert_CRDatabase("CS101", "Turing Aud.", testData2);
        insert_CRDatabase("EE200", "25 Ohm Hall", testData2);
        insert_CRDatabase("PH100", "Newton Lab.", testData2);
    //    //inserting CDH data
        insert_CDHDatabase("CS101", "M", "9AM", testData2);
        insert_CDHDatabase("CS101", "W", "9AM", testData2);
        insert_CDHDatabase("CS101", "F", "9AM", testData2);
        insert_CDHDatabase("EE200", "Tu", "10AM", testData2);
        insert_CDHDatabase("EE200", "W", "1PM", testData2);
        insert_CDHDatabase("EE200", "Th", "10AM", testData2);

    
    
//    gradeOfStudent("C.Brown", "CS101", testData);
//    whereIsStudent("C.Brown", "9AM", "M", testData);
    
    //The code below for some reason rejects user input, I have print statements in the method that
    //demonstrates that the method is indeed getting both name and course correctly but doesn't run
    //What is baffling is that the lines above do work which shows the method works?
    
    /*
    char* name;
    char* course;
    printf("\nPlease enter a Name: ");
    scanf("%s", &name);
    printf("%s", &name);
    printf("\nPlease enter a Course: ");
    scanf("%s", &course);
    printf("%s", &course);


    gradeOfStudent(&name, &course, testData);
    gradeOfStudent(fixName, fixCourse, testData);
     */

    bool running = true;
    
    while(running){
        int selection = 0;
        printf("\nHello welcome to the Database tester please select an option you'd like to do");
        printf("\n1. What grade did C.Brown get in CS101?");
        printf("\n2. What grade did C.Brown get in EE200?");
        printf("\n3. What grade did L.Brown get in PH101?");
        printf("\n4. What grade did P.Patty get in PH101?");
        printf("\n5. Where is C.Brown at 9AM on M?");
        printf("\n6. What grade did P.Patty get in PH101?");
        printf("\n7. What grade did P.Patty get in PH101?");
        printf("\n8. What grade did P.Patty get in PH101?");

        printf("\n9. To test the rest of part 1");

        printf("\nEnter a number: ");
        scanf("%d", &selection);

        if(selection == 1){
            gradeOfStudent("C.Brown", "CS101", testData);
        }
        if(selection == 2){
            gradeOfStudent("C.Brown", "EE200", testData);
        }
        if(selection == 3){
            gradeOfStudent("L.Brown", "PH101", testData);
        }
        if(selection == 4){
            gradeOfStudent("P.Patty", "EE200", testData);
        }
        if(selection == 5){
            whereIsStudent("C.Brown", "9AM", "M", testData);
        }
        if(selection == 6){
            whereIsStudent("C.Brown", "9AM", "W", testData);

        }
        if(selection == 7){
            whereIsStudent("L.Brown", "9AM", "M", testData);

        }
        if(selection == 8){
            whereIsStudent("P.Patty", "1PM", "W", testData);

        }
        if(selection == 9){
            running = false;
        }



    }
    
    printf("\nNow here is the existing Database, which shows the insertion above works\n");
    print_Database(testData);
    printf("\n Lets Remove all of student ID 12345 from the existing CSG\n");
    except_CSGDatabase(12345, testData);
    except_SNAPDatabase(12345, testData);
    printf("\n Now lets print out the new database\n");
    print_Database(testData);
    printf("\n Now lets lookup what days and hours CS101 is going on\n");
    lookup_CDHDatabase("CS101", testData);
    
  
    
    return 0;
}
