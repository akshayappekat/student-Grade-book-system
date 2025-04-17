#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 100
#define MAX_GRADES 10

struct Student {
    char name[50];
    int id;
};

struct Course {
    char name[50];
    char code[10];
};

struct Grade {
    int student_id;
    char course_code[10];
    int assignment_grades[MAX_GRADES];
    int exam_grades[MAX_GRADES];
    int num_grades;
};

struct Student students[MAX_STUDENTS];
struct Course courses[MAX_COURSES];
struct Grade grades[MAX_GRADES];

int num_students = 0;
int num_courses = 0;
int num_grades = 0;

void add_student() {
    if (num_students >= MAX_STUDENTS) {
        printf("Error: Maximum number of students reached.\n");
        return;
    }

    printf("Enter student name: ");
    fgets(students[num_students].name, sizeof(students[num_students].name), stdin);
    students[num_students].name[strcspn(students[num_students].name, "\n")] = '\0';
    printf("Enter student ID: ");
    scanf("%d", &students[num_students].id);
    getchar();
    num_students++;
}

void add_course() {
    if (num_courses >= MAX_COURSES) {
        printf("Error: Maximum number of courses reached.\n");
        return;
    }

    printf("Enter course name: ");
    fgets(courses[num_courses].name, sizeof(courses[num_courses].name), stdin);
    courses[num_courses].name[strcspn(courses[num_courses].name, "\n")] = '\0';
    printf("Enter course code: ");
    fgets(courses[num_courses].code, sizeof(courses[num_courses].code), stdin);
    courses[num_courses].code[strcspn(courses[num_courses].code, "\n")] = '\0';
    num_courses++;
}

void add_grades() {
    if (num_grades >= MAX_GRADES) {
        printf("Error: Maximum number of grades reached.\n");
        return;
    }

    int student_id, num;
    char course_code[10];

    printf("Enter student ID: ");
    scanf("%d", &student_id);
    getchar();

    bool student_found = false;
    for (int i = 0; i < num_students; i++) {
        if (students[i].id == student_id) {
            student_found = true;
            break;
        }
    }

    if (!student_found) {
        printf("Error: Student with ID %d not found.\n", student_id);
        return;
    }

    printf("Enter course code: ");
    fgets(course_code, sizeof(course_code), stdin);
    course_code[strcspn(course_code, "\n")] = '\0';

    bool course_found = false;
    for (int i = 0; i < num_courses; i++) {
        if (strcmp(courses[i].code, course_code) == 0) {
            course_found = true;
            break;
        }
    }

    if (!course_found) {
        printf("Error: Course with code %s not found.\n", course_code);
        return;
    }

    printf("Enter number of grades: ");
    scanf("%d", &num);
    getchar();

    for (int i = 0; i < num; i++) {
        printf("Enter assignment grade %d: ", i + 1);
        scanf("%d", &grades[num_grades].assignment_grades[i]);
        printf("Enter exam grade %d: ", i + 1);
        scanf("%d", &grades[num_grades].exam_grades[i]);
    }

    grades[num_grades].student_id = student_id;
    strcpy(grades[num_grades].course_code, course_code);
    grades[num_grades].num_grades = num;
    num_grades++;
}

void display_students() {
    printf("\nStudents:\n");
    for (int i = 0; i < num_students; i++) {
        printf("%s (ID: %d)\n", students[i].name, students[i].id);
    }
}

void display_courses() {
    printf("\nCourses:\n");
    for (int i = 0; i < num_courses; i++) {
        printf("%s (%s)\n", courses[i].name, courses[i].code);
    }
}

void display_grades() {
    printf("\nGrades:\n");
    for (int i = 0; i < num_grades; i++) {
        printf("Student ID: %d, Course Code: %s\n", grades[i].student_id, grades[i].course_code);
        printf("Grades:");
        for (int j = 0; j < grades[i].num_grades; j++) {
            printf(" Assignment %d: %d, Exam %d: %d,", j + 1, grades[i].assignment_grades[j], j + 1, grades[i].exam_grades[j]);
        }
        printf("\n");
    }
}

float calculate_gpa(int student_id) {
    float total_credit_hours = 0;
    float total_grade_points = 0;

    for (int i = 0; i < num_grades; i++) {
        if (grades[i].student_id == student_id) {
            for (int j = 0; j < grades[i].num_grades; j++) {
                float credit_hours = 3;
                total_credit_hours += credit_hours;

                float assignment_gpa = grades[i].assignment_grades[j] / 10.0;
                float exam_gpa = grades[i].exam_grades[j] / 10.0;

                float weighted_grade_points = (assignment_gpa * 0.4 + exam_gpa * 0.6) * credit_hours;
                total_grade_points += weighted_grade_points;
            }
        }
    }

    if (total_credit_hours == 0) {
        return 0;
    } else {
        return total_grade_points / total_credit_hours;
    }
}

int main() {
    int choice;
    do {
        printf("\nStudent Gradebook\n");
        printf("1. Add student\n");
        printf("2. Add course\n");
        printf("3. Add grades\n");
        printf("4. Display students\n");
        printf("5. Display courses\n");
        printf("6. Display grades\n");
        printf("7. Calculate GPA\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                add_student();
                break;
            case 2:
                add_course();
                break;
            case 3:
                add_grades();
                break;
            case 4:
                display_students();
                break;
            case 5:
                display_courses();
                break;
            case 6:
                display_grades();
                break;
            case 7: {
                int student_id;
                printf("Enter student ID: ");
                scanf("%d", &student_id);
                getchar();
                float gpa = calculate_gpa(student_id);
                printf("GPA for student with ID %d: %.2f\n", student_id, gpa);
                break;
            }
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 8);

    return 0;
}
