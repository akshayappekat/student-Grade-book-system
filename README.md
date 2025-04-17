# Gradebook System in C

This C program is a simple gradebook system for managing students, courses, and their grades. Below is a breakdown of the functionality and structure of the code:

## 1. **Structures**:
   - **Student**: Holds information about a student, specifically their name and ID.
   - **Course**: Stores details about a course, including the name and course code.
   - **Grade**: Holds information about a student's grades for a specific course, including the grades for assignments and exams. It also keeps track of the number of grades entered.

## 2. **Global Variables**:
   - Arrays are used to store data for students, courses, and grades, with a maximum capacity defined by constants (`MAX_STUDENTS`, `MAX_COURSES`, `MAX_GRADES`).
   - Integer variables track the number of students, courses, and grades entered into the system.

## 3. **Functions**:
   - **add_student()**: Adds a new student to the system by accepting their name and ID.
   - **add_course()**: Adds a new course by taking the course name and code.
   - **add_grades()**: Adds grades for a student in a course. It ensures that the student and course exist in the system before entering grades. The grades consist of assignments and exams.
   - **display_students()**: Displays all the students currently in the system, showing their names and IDs.
   - **display_courses()**: Displays all the courses in the system with their names and course codes.
   - **display_grades()**: Displays all grades entered, showing the student ID, course code, and individual grades for assignments and exams.
   - **calculate_gpa()**: Calculates the Grade Point Average (GPA) for a student based on their grades. It assumes that each course has 3 credit hours, and the GPA is calculated using weighted averages of the assignment and exam grades.

## 4. **Main Function**:
   - The main function provides a menu-driven interface where the user can perform different operations like adding students, adding courses, adding grades, displaying information, and calculating GPA.
   - The user can enter their choice, and the program will execute the corresponding function.
   - The program runs in a loop, allowing multiple actions until the user chooses to exit.

## 5. **Flow of the Program**:
   - The program starts by displaying a menu with options:
     - Add a student
     - Add a course
     - Add grades for a student in a course
     - Display all students
     - Display all courses
     - Display all grades
     - Calculate the GPA for a student
     - Exit the program
   - Depending on the user's choice, the program calls the respective function to handle that operation.
   - The user can continue interacting with the program until they choose to exit (option 8).

## 6. **Key Features**:
   - **Student and Course Management**: The system allows the addition of students and courses, providing a foundation for managing the gradebook.
   - **Grade Management**: The grades for each student in a specific course can be entered and displayed. This includes both assignment and exam grades.
   - **GPA Calculation**: The program can calculate a student's GPA based on the grades entered, assuming each course has equal credit hours.
   - **Menu-based Interface**: The program operates in a user-friendly, menu-driven manner, making it interactive.

## 7. **Example Scenario**:
   1. A user adds a student named "John Doe" with an ID of `101`.
   2. The user adds a course, such as "Mathematics" with the code `MATH101`.
   3. The user then enters grades for John in the "Mathematics" course. For example, 2 assignment grades and 2 exam grades are entered.
   4. The program allows the user to display all students, all courses, and all grades.
   5. Finally, the user can calculate the GPA for a student, which is based on the entered grades.

This simple gradebook system is useful for managing a small set of students, courses, and grades and could be extended with additional features such as saving data to a file or handling more complex GPA calculations.
