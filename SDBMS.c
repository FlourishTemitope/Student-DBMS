// Written by PETER TOPE BLESSING a COMPUTER SCIENCE student of Federal University Oye-Ekiti (FUOYE), Ekiti State
// in partial fulfillment of C Project (not final year project) under the supervisor of Mr. Awoyemi (Fuoye, CSC Lecturer)
// FOR ANY IMPROVEMENT, IDEA OR QUESTION CONTACT ME ON:
// Whatsapp - 07014312797
// Call - 08169782644
// Twitter - Flourish_Temitope (@flourish091)
// Facebook - Flourish Temitope
// Linkedin - Flourish Temitope

// ONLY USE FOR EDUCATIONAL PURPOSES


//A simple C program to collect and store details of students into a CSV File


#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100  //PROGRAM CAN ONLY STORE MAXIMUM OF 100 STUDENTS. CHANGE NUMBER TO YOUR WILL.
//STRUCTURE TAG
struct Student {
    char name[50];
    char matric_no[13]; //change to char
    int level;
    char Faculty[30];
    char Dept[25];
    char Gender[7];
    char phone_no[12];
    
};
//using a structure
struct Student students[MAX_STUDENTS];
int num_students = 0;

//Adding Student to the  database
void add_student(){
    if (num_students >= MAX_STUDENTS){
        printf("Maximum number of students reached.\n");
        return;
    }
    printf("You are adding new student to the Database\n");
struct Student stud;
getchar(); // To get rid of new line
printf("\nEnter Student name: ");
fgets(stud.name,50,stdin);
stud.name[strlen(stud.name)-1] = '\0'; //TO PREVENT fgets() from ignoring following charaters
printf("\nEnter student matric number: ");
scanf("%s", stud.matric_no);
printf("\nEnter Student Level: ");
scanf("%d", &stud.level);
getchar();
printf("\nEnter Student Faculty: ");
fgets(stud.Faculty,30,stdin);
stud.Faculty[strlen(stud.Faculty)-1] = '\0';
printf("\nEnter Student Department: ");
fgets(stud.Dept,30,stdin);
stud.Dept[strlen(stud.Dept)-1] = '\0';
printf("\nEnter student Gender: ");
scanf("%s", stud.Gender);
printf("\nEnter student phone No: ");
scanf("%s", stud.phone_no);


students[num_students++] = stud;
printf("\nStudent added succesfully.\n");


}

//Displaying student in Database
void display_students(){
    if (num_students == 0){
        printf("No Students Added yet\n");
        return;
    }
    printf("STUDENTS IN THE DATABASE ARE LISTED BELOW\n");
    printf("NAME\t\tMATRIC NO.\tLEVEL\tFACULTY\t\tDEPT\t\t GENDER\t PHONE NO");
    for (int i = 0; i < num_students; i++){
        struct Student stud = students[i];
        printf("\n%s\t\t%s\t%d\t%s\t\t%s\t\t%s\t%s", stud.name, stud.matric_no, stud.level,stud.Faculty, stud.Dept,stud.Gender,stud.phone_no);
        
    }
}
//Seaching student using matric no as PRIMARY KEY
void search_student(){ 
    if (num_students == 0){
        printf("No students added yet.\n");
        return;
    }

char matric_no[13];
printf("Enter matric number to search: ");
scanf("\n%s",matric_no );


for (int i = 0; i < num_students; i++)
{
    struct Student stud = students[i];
    int compare = strcasecmp(stud.matric_no,matric_no);
    if(compare == 0)
    {printf("Details of student searched for is listed below\n");
    printf("\nStudent Name: %s\nMatric_No: %s\nLevel: %d\nFaculty: %s\nDepartment: %s\nGender: %s\nPhone No: %s", stud.name, stud.matric_no, stud.level,stud.Faculty, stud.Dept,stud.Gender,stud.phone_no);
    return;
    }
    
}
printf("\nStudent not found.\n");
}

//Deleting student using matric nymber as PRIMARY KEY
void delete_student(){
    if (num_students == 0){
        printf("No students added yet. \n");
        return;
    }

    char matric_no[13]; //using matric no as PRIMARY KEY
    printf("Enter matric number to delete: ");
    scanf("%s", matric_no);

    for (int i = 0; i< num_students; i++){
        struct Student stud = students[i];
        int comp = strcasecmp(stud.matric_no,matric_no);
        if(comp == 0)
        {
            for (int j = i; j< num_students - 1; j++){
            students[j] = students[j+i];
            }
            num_students--;
            printf("\nStudent deleted successfully.\n");
            return;
        }
        
    }
    printf("Student not found.\n");
}
//CREATING A COMMA SEPERATED VALUE FILE AS DATABASE TO STORE STUDENT DATAS
void createfile(){

FILE *fp;
    for (int i = 0; i < num_students; i++){
        struct Student stud = students[i]; 
        fp = fopen("Student-DBMS.csv", "w");
       fprintf(fp,"FULLNAME,\t\t\t\t\tMATRIC NO,\t\tLEVEL,\t\tFACULTY,\t\t\tDEPARTMENT,\t\t\tGENDER,\t\tPHONE NO,\n\n%s,\t\t%s,\t\t%d,\t\t%s,\t\t%s,\t\t%s,\t\t%s", stud.name, stud.matric_no, stud.level,stud.Faculty, stud.Dept,stud.Gender,stud.phone_no);

       fclose(fp);

    }
return;
}

//MAIN  METHOD STARTS HERE
int main(){
 
    int choice;
       
    do{

        for (int i = 0; i < num_students; i++){
        struct Student stud = students[i]; 
 
    FILE *fp;
    fp = fopen("Student-DBMS.csv", "a");
    if (fp != NULL && choice == 1){
        fprintf(fp,"\n%s,\t\t%s,\t\t%d,\t\t%s,\t\t%s,\t\t%s,\t\t%s", stud.name, stud.matric_no, stud.level,stud.Faculty, stud.Dept,stud.Gender,stud.phone_no);
        fclose(fp);
       }}
        
        printf("\n\nStudent Management System\n");
        printf("OPERATIONS AVAILABLE ARE \n\n");
        printf("\t1. Add Student\n");
        printf("\t2. Display Students\n");
        printf("\t3. Search Student\n");
        printf("\t4. Delete Student\n");
        printf("\t5. Exit\n");
        printf("Enter either 1, 2, 3, 4, or 5 based on the operation you want to perform.\n");
        printf("Enter Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_student();
            createfile();
        break;
        case 2:
            display_students();
            break; 
        case 3:
            search_student();
            break;
        case 4:
            delete_student();            
            break;
        case 5:
            printf("Existing program.\n");
            printf("\n************************************************************************\n");
            printf("Program Existed.\n");
            break;
        default:
            printf("Invalid Choice Entered. Please Enter number between 1 to 5\n");
            break;
    
        }
    } while (choice != 5);
    return 0;

        }//Main Method ends here
    
