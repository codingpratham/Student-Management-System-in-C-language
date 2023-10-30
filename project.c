#include <stdio.h>
#include <string.h>

struct student {
    char first[20];
    char last[20];
    int roll;
    float cgpa;
    int id[4];
};

struct student students[50];
int count = 0;

void add_student() {
    if (count < 50) {
        struct student newstudent;
        printf("Enter the first name of the student: ");
        scanf("%s", newstudent.first);
        printf("Enter the last name of the student: ");
        scanf("%s", newstudent.last);
        printf("Enter the Roll number of the student: ");
        scanf("%d", &newstudent.roll);
        printf("Enter the CGPA of the student: ");
        scanf("%f", &newstudent.cgpa);
        
        students[count] = newstudent;
        count++;
        
        printf("Student added successfully.\n\n\n");
    }
    else {
        printf("Maximum number of students reached.\n");
    }
}

void find_Roll() {
    int roll;
    printf("Enter the Roll Number of the student: ");
    scanf("%d", &roll);
    int i;
    for (i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            printf("Student Details:\n");
            printf("First Name: %s\n", students[i].first);
            printf("Last Name: %s\n", students[i].last);
            printf("Roll Number: %d\n", students[i].roll);
            printf("CGPA: %.2f\n", students[i].cgpa);

            printf("\n\n\n\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void find() {
    printf("Total students: %d\n\n\n\n", count);
}

void saveDataToFile() {
    FILE *file;
    file = fopen("Data.txt", "r");
    
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }
int i;
    for (i = 0; i < count; i++) {
        fprintf(file, "%s %s %d %.2f\n", students[i].first, students[i].last, students[i].roll, students[i].cgpa);
    }
    
    fclose(file);
    printf("Data saved to Data.txt successfully.\n\n\n");
}

void loadDataFromFile() {
    FILE *file;
    file = fopen("Data.txt", "r");
    
    if (file == NULL) {
        printf("No data found in Data.txt.\n");
        return;
    }

    count = 0; // Reset the student count

    while (fscanf(file, "%s %s %d %f", students[count].first, students[count].last, &students[count].roll, &students[count].cgpa) != EOF) {
        count++;
    }
    
    fclose(file);
    printf("Data loaded from Data.txt successfully.\n\n\n");
}

int main() {
    int choice;

    // Load data from the file when the program starts
    loadDataFromFile();

    while (1) {
        printf("Student Management System\n");
        printf("1. Add Student\n");
        printf("2. Find Student by Roll Number\n");
        printf("3. Total Students\n");
        printf("4. Save Data to File\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                find_Roll();
                break;
            case 3:
                find();
                break;
            case 4:
                saveDataToFile();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

