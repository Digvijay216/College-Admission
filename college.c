
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cutoffs.h"

#define TEXT_SIZE 120
#define FILE_NAME "confirmed_admissions.txt"

typedef struct {
    char name[TEXT_SIZE];
    char applicationID[TEXT_SIZE];
    char exam[50];
    char category[30];
    double percentile;
    char branch[TEXT_SIZE];
    int admissionYear;
    double cutoff;
} Student;

void clearInputLine(void);
void readLine(const char *prompt, char *buffer, int size);
int readInt(const char *prompt, int minValue, int maxValue);
double readPercentile(const char *prompt);
int equalsIgnoreCase(const char *a, const char *b);
void saveAdmission(const Student *student);
void viewAdmissions(void);
void checkEligibility(void);

void clearInputLine(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void readLine(const char *prompt, char *buffer, int size)
{
    size_t len;

    printf("%s", prompt);

    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }

    len = strlen(buffer);

    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    } else {
        clearInputLine();
    }

    len = strlen(buffer);

    if (len > 0 && buffer[len - 1] == '\r') {
        buffer[len - 1] = '\0';
    }
}

int readInt(const char *prompt, int minValue, int maxValue)
{
    char line[80];
    char *end;
    long value;

    for (;;) {
        readLine(prompt, line, sizeof(line));
        value = strtol(line, &end, 10);

        while (*end != '\0' &&
               isspace((unsigned char)*end)) {
            end++;
        }

        if (line[0] != '\0' &&
            *end == '\0' &&
            value >= minValue &&
            value <= maxValue) {
            return (int)value;
        }

        printf("Enter a number between %d and %d.\n",
               minValue, maxValue);
    }
}

double readPercentile(const char *prompt)
{
    char line[80];
    char *end;
    double value;

    for (;;) {
        readLine(prompt, line, sizeof(line));
        value = strtod(line, &end);

        while (*end != '\0' &&
               isspace((unsigned char)*end)) {
            end++;
        }

        if (line[0] != '\0' &&
            *end == '\0' &&
            value >= 0.0 &&
            value <= 100.0) {
            return value;
        }

        printf("Enter a valid percentile between 0 and 100.\n");
    }
}

int equalsIgnoreCase(const char *a, const char *b)
{
    while (*a != '\0' && *b != '\0') {
        if (tolower((unsigned char)*a) !=
            tolower((unsigned char)*b)) {
            return 0;
        }

        a++;
        b++;
    }

    return *a == '\0' && *b == '\0';
}

void saveAdmission(const Student *student)
{
    FILE *fp;

    fp = fopen(FILE_NAME, "a");

    if (fp == NULL) {
        printf("\nERROR: Cannot open %s for writing.\n",
               FILE_NAME);
        printf("Check folder permissions.\n");
        return;
    }

    fprintf(fp, "========================================\n");
    fprintf(fp, "WCE SANGLI ADMISSION RECORD\n");
    fprintf(fp, "Name: %s\n", student->name);
    fprintf(fp, "Application ID: %s\n",
            student->applicationID);
    fprintf(fp, "College: Walchand College of Engineering, Sangli\n");
    fprintf(fp, "Branch: %s\n", student->branch);
    fprintf(fp, "Exam: %s\n", student->exam);
    fprintf(fp, "Category: %s\n", student->category);
    fprintf(fp, "Percentile: %.4f\n", student->percentile);
    fprintf(fp, "Admission Year: %d\n",
            student->admissionYear);
    fprintf(fp, "Sample Cutoff: %.4f\n", student->cutoff);
    fprintf(fp, "Seat Status: CONFIRMED (SIMULATION)\n");
    fprintf(fp, "========================================\n\n");

    if (fclose(fp) == 0) {
        printf("\nRecord saved successfully in %s\n",
               FILE_NAME);
    } else {
        printf("\nError while closing the file.\n");
    }
}

void viewAdmissions(void)
{
    FILE *fp;
    char line[300];
    int found;

    fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("\nNo saved admission records found.\n");
        printf("Confirm an admission first to create the file.\n");
        return;
    }

    printf("\n========== SAVED ADMISSION RECORDS ==========\n");

    found = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        found = 1;
    }

    if (!found) {
        printf("The file is empty.\n");
    }

    fclose(fp);

    printf("=============================================\n");
}

void checkEligibility(void)
{
    Student student;
    int examChoice;
    int categoryChoice;
    int eligibleIndex[CUTOFF_COUNT];
    int eligibleCount;
    int selected;
    int seatChoice;
    int finalChoice;
    int i;
    int index;

    memset(&student, 0, sizeof(student));
    eligibleCount = 0;

    printf("\n========== STUDENT DETAILS ==========\n");

    readLine("Enter student name: ",
             student.name, sizeof(student.name));

    if (student.name[0] == '\0') {
        printf("Name cannot be empty.\n");
        return;
    }

    readLine("Enter application ID: ",
             student.applicationID,
             sizeof(student.applicationID));

    if (student.applicationID[0] == '\0') {
        printf("Application ID cannot be empty.\n");
        return;
    }

    printf("\nSelect entrance exam:\n");
    printf("1. MHT-CET\n");
    printf("2. JEE Main (No categoryChoice)\n");

    examChoice = readInt("Enter choice: ", 1, 2);

    if (examChoice == 1) {
        strcpy(student.exam, "MHT-CET");
    } else {
        strcpy(student.exam, "JEE Main(No categoryChoice)");
    }

    printf("\nSelect category:\n");
    printf("1. OPEN\n");
    printf("2. OBC\n");
    printf("3. SC\n");
    printf("4. ST\n");
    printf("5. EWS\n");

    categoryChoice = readInt("Enter choice: ", 1, 5);

    if (categoryChoice == 1) {
        strcpy(student.category, "OPEN");
    } else if (categoryChoice == 2) {
        strcpy(student.category, "OBC");
    } else if (categoryChoice == 3) {
        strcpy(student.category, "SC");
    } else if (categoryChoice == 4) {
        strcpy(student.category, "ST");
    } else {
        strcpy(student.category, "EWS");
    }

    student.percentile =
        readPercentile("Enter percentile (0-100): ");

    student.admissionYear =
        readInt("Enter admission year: ", 2020, 2100);

    for (i = 0; i < CUTOFF_COUNT; i++) {
        if (equalsIgnoreCase(cutoffs[i].exam,
                             student.exam) &&
            equalsIgnoreCase(cutoffs[i].category,
                             student.category) &&
            student.percentile >= cutoffs[i].cutoff) {

            eligibleIndex[eligibleCount] = i;
            eligibleCount++;
        }
    }

    printf("\n========== ELIGIBILITY RESULT ==========\n");

    if (eligibleCount == 0) {
        printf("No eligible branch found in the sample data.\n");
        printf("This is not an official admission decision.\n");
        return;
    }

    printf("Eligible branches based on cutoff data:\n");

    for (i = 0; i < eligibleCount; i++) {
        index = eligibleIndex[i];

        printf("%d. %s | Cutoff: %.4f\n",
               i + 1,
               cutoffs[index].branch,
               cutoffs[index].cutoff);
    }

    selected = readInt(
        "Select preferred branch number: ",
        1, eligibleCount);

    index = eligibleIndex[selected - 1];

    strcpy(student.branch, cutoffs[index].branch);
    student.cutoff = cutoffs[index].cutoff;

    printf("\nSelected branch: %s\n", student.branch);
    printf("1. Freeze seat\n");
    printf("2. Leave seat\n");

    seatChoice = readInt("Enter choice: ", 1, 2);

    if (seatChoice == 2) {
        printf("Seat left. No record saved.\n");
        return;
    }

    printf("\n========== FINAL CONFIRMATION ==========\n");
    printf("Name: %s\n", student.name);
    printf("Application ID: %s\n",
           student.applicationID);
    printf("Branch: %s\n", student.branch);
    printf("Exam: %s\n", student.exam);
    printf("Category: %s\n", student.category);
    printf("Percentile: %.4f\n", student.percentile);
    printf("Admission Year: %d\n",
           student.admissionYear);

    printf("\n1. Confirm and save\n");
    printf("2. Cancel\n");

    finalChoice = readInt("Enter choice: ", 1, 2);

    if (finalChoice == 1) {
        saveAdmission(&student);
    } else {
        printf("Cancelled. No record saved.\n");
    }
}

int main(void)
{
    int choice;

    for (;;) {
        printf("\n========================================\n");
        printf(" WCE SANGLI ADMISSION SYSTEM\n");
        printf("========================================\n");
        printf("1. Check eligibility and select branch\n");
        printf("2. View saved admission records\n");
        printf("3. Exit\n");

        choice = readInt("Enter choice: ", 1, 3);

        if (choice == 1) {
            checkEligibility();
        } else if (choice == 2) {
            viewAdmissions();
        } else {
            printf("Thank you for using the program.\n");
            break;
        }
    }

    return 0;
}
