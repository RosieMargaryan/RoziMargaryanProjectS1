#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function prototypes
void generateRandomPhysiologicalData(int minutes, const char *filename);

int main() {
    int interval;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Ask for the interval before generating events
    printf("Enter the interval for random generation (1 to 20 minutes): ");
    scanf("%d", &interval);

    // Check if the entered interval is within the valid range
    if (interval <= 0 || interval > 20) {
        printf("Please enter a number between 1 and 20.\n");
        return 0;
    } else {
        printf("Physiological data generation started.\n");
    }

    // Call the function to generate random physiological data
    generateRandomPhysiologicalData(interval, "physiological_data.txt");

    return 0;
}

// Function to generate random physiological data and write to a file
void generateRandomPhysiologicalData(int minutes, const char *filename) {
    // Open the file in append mode
    FILE *file = fopen(filename, "a");

    // Check if the file was opened successfully
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Write a header for the random physiological data section
    fprintf(file, "\nRandom Physiological Data:\n");
    fflush(stdout);

    // Loop to generate data for the specified number of minutes
    for (int i = 0; i < minutes; ++i) {
        // Get the current time
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        // Write the time and various physiological data to the file
        fprintf(file, "Time: [%02d:%02d:%02d]\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
        fprintf(file, "Blood Volume Variation: %lf\n", (double)rand() / RAND_MAX);
        fprintf(file, "Body Temperature: %lf\n", 36.0 + ((double)rand() / RAND_MAX) * 2.0);
        fprintf(file, "Blood Oxygen Saturation: %lf\n", (double)rand() / RAND_MAX);
        fprintf(file, "Blood Pressure: %d/%d\n", 90 + rand() % 30, 60 + rand() % 20);
        fprintf(file, "Pulse Transit Time: %lf\n", (double)rand() / RAND_MAX);
        fprintf(file, "Heartbeats Per Minute: %d\n", 60 + rand() % 40);

        // Add a newline for better readability
        fprintf(file, "\n");
        fflush(file);

        // Wait for 60 seconds before generating the next set of data
        sleep(60);
    }

    // Close the file
    if (fclose(file) != 0) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }
}