#include <stdio.h>
#include <stdlib.h>
#include <string.h>


	
typedef struct Subject{
	char *name;
	int mark;
}Subject;

typedef struct Student{
		char *name;
		int grud;
		int age;
		char *section ; 
		Subject subject[4];
	}Student;
	
int studentCounter = 0;
Student *students;
	
Student creatNewStudent( char *name,int grud, int age, char *section); 
void case1();
void printStudentInfo(Student st);
void addSubjects(Student *st);
void addNewStudent(Student st);
int findStudent(const char *name);
void editStudentGrades(int studentNo, int subjectNo, int grade);
void case2();
void case3();





int main(int argc, char *argv[])
{
	
	while(1){
		printf("=============================================\n\n");
		printf("1. Add new student\n");
		printf("2 . find for student\n");
		printf("3 . edit information  student\n");
		
		printf("chose number from up\n");
		int x;
		scanf("%d", &x);

		   switch(x){
	   		case 1:
	   		    case1();
	   		    break;
	   		case 2:
	   		    case2();
	   		    break;
	   		case 3:
	   		    case3();
	   		    break;
	        default:
	            printf("the number not fount");
	   		}
		}
	
	return 0;
}




Student creatNewStudent(char *name, int grud,int age, char *section){
	Student st;
	st.name = name;
	st.grud = grud;
	st.age = age;
	st.section = section;

	addSubjects(&st);
	
    return st;
}
void printStudentInfo(Student st){
	printf("\n--------------\n\n student info :\n\n--------------\n -student name : %s\n,-student grud : %d\n,-student age : %d\n,-student section : %s\n", st.name, st.grud,st.age,st.section);
	printf("******************************************\n");
	for(int i = 0 ; i < 4 ; i++){
		printf("--subject name :   %s || subject mark : %d\n",st.subject[i].name, st.subject[i].mark );
	}
	
}
void addSubjects(Student *st){
	Subject arabic, english, math, turkish; 
	
	arabic.name = "arabic";
	arabic.mark= 0 ;
	
	english.name = "english";
	arabic.mark= 0 ;
	
	math.name = "math";
	arabic.mark= 0 ;
	
	turkish.name = "turkish";
	arabic.mark= 0 ;
	
	st->subject[0] = arabic;
	st->subject[1] = english;
	st->subject[2] = math;
	st->subject[3] = turkish;
}
void addNewStudent(Student st){
	studentCounter++;
	students = realloc(students, sizeof(Student) * studentCounter);
	students[studentCounter-1] = st;
}
int findStudent(const char *name){
	for(int i = 0 ; i < studentCounter ; i++){
		if(strcmp(name ,students[i].name) == 0){
			printf("the studen %s is found\n", name);
			printStudentInfo(students[i]);
			return i;
		}
	}
	printf("the student is not found");
	return -1;
}
void case1(){
	printf("\n---------------------------\n\n");
	
		printf("enter the student name\n");
		char *student_name = (char *)malloc(60);
		scanf("%s", student_name);
		
		printf("enter the student grud\n");
		int student_grud;
		scanf("%d", &student_grud);
		
		printf("enter the student age\n");
		int student_age;
		scanf("%d", &student_age);
		
		printf("enter the student section\n");
		char *student_section = (char *)malloc(60);
		scanf("%s", student_section);
		
		
		Student st = creatNewStudent(student_name, student_grud, student_age, student_section);
		printStudentInfo(st);
		addNewStudent(st);
}
void case2(){
		printf("enter the student name\n");
		char *student_name = (char *)malloc(60);
		scanf("%s", student_name);
		findStudent(student_name);
		
}

void editStudentGrades(int studentNo, int subjectNo, int grade)
{
    students[studentNo].subject[subjectNo].mark = grade;
}
void case3()
{
    printf("###################################\n");
    printf("enter student name \n");
    char *studentName = (char *)malloc(60);
    scanf("%s", studentName);
    
    int stNo = findStudent(studentName);
    if(stNo == -1)
    {
        return;
    }
    
    int choice;
    do
    {
        printf("\n enter any chose from numbers\n");
        printf("enter -1 to exit from program\n");
        printf("1. edit arabic mark\n");
        printf("2. edit english mark\n");
        printf("3. edit math mark\n");
        printf("4. edit turkish mark\n");
        scanf("%d", &choice);
        
        if(choice >= 1 && choice <= 4)
        {
            int newGrade;
            printf("enter newGrade... ");
            scanf("%d", &newGrade);
            editStudentGrades(stNo, choice-1, newGrade);
            
        }
        else if(choice == -1)
            return;
        else 
            printf("enter -1 to exit from program (-1)");
        
    }while(choice != -1);
    
}
