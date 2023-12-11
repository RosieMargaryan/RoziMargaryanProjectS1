#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void analyzeAndProvideFeedback(const char *inputFilename, const char *outputFilename);
void showSuggestions(int heartRate);
void analyzeTrends(int heartRate);
void displayHealthInsights(int heartRate);

int main() {
    int choice;
    int heartRate;

    // Step 1: Analyze physiological data and generate feedback report
    analyzeAndProvideFeedback("physiological_data.txt", "feedback_report.txt");

    // Step 2: Display menu options and wait for user input
    printf("Menu:\n");
    printf("1. Show suggestions based on heart rate\n");
    printf("2. Analyze trends in heart rate\n");
    printf("3. Display health insights based on heart rate\n");
    printf("4. Exit\n");

    // Step 3: Handle user choices in a loop until the user chooses to exit (option 4)
    do {
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your current heart rate: ");
                scanf("%d", &heartRate);
                // Step 4: Show suggestions based on user's heart rate
                showSuggestions(heartRate);
                break;
            case 2:
                printf("Analyzing trends in heart rate...\n");
                printf("Enter your current heart rate: ");
                scanf("%d", &heartRate);
                // Step 5: Analyze trends in heart rate
                analyzeTrends(heartRate);
                break;
            case 3:
                printf("Displaying health insights based on heart rate...\n");
                printf("Enter your current heart rate: ");
                scanf("%d", &heartRate);
                // Step 6: Display health insights based on user's heart rate
                displayHealthInsights(heartRate);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to analyze physiological data and generate a feedback report
void analyzeAndProvideFeedback(const char *inputFilename, const char *outputFilename) {
    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");
    char line[256];
    double bloodVolumeVariation, bodyTemp, bloodOxygenSaturation, pulseTransitTime;
    int systolicBP, diastolicBP, heartRate;

    // Check if files were opened successfully
    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Step 7: Read each line of the input file and analyze physiological data
    while (fgets(line, sizeof(line), inputFile)) {
        // Check for different types of physiological data in each line
        if (strstr(line, "Blood Volume Variation:")) {
            sscanf(line, "Blood Volume Variation: %lf", &bloodVolumeVariation);
            // Step 8: Assuming a range for blood volume variation (example range, needs to be adjusted)
            if (bloodVolumeVariation < 0.5 || bloodVolumeVariation > 1.5) {
                fprintf(outputFile, "Abnormal Blood Volume Variation Detected: %.2lf\n", bloodVolumeVariation);
            }
        }
        if (strstr(line, "Body Temperature:")) {
            sscanf(line, "Body Temperature: %lf", &bodyTemp);
            // Step 9: Check for abnormal body temperature and provide feedback
            if (bodyTemp < 36.0 || bodyTemp > 37.5) {
                fprintf(outputFile, "Abnormal Body Temperature Detected: %.2lf°C\n", bodyTemp);
            }
        }
        if (strstr(line, "Blood Oxygen Saturation:")) {
            sscanf(line, "Blood Oxygen Saturation: %lf", &bloodOxygenSaturation);
            // Step 10: Check for low blood oxygen saturation and provide feedback
            if (bloodOxygenSaturation < 95.0) {
                fprintf(outputFile, "Low Blood Oxygen Saturation Detected: %.2lf%%\n", bloodOxygenSaturation);
            }
        }
        if (strstr(line, "Blood Pressure:")) {
            sscanf(line, "Blood Pressure: %d/%d", &systolicBP, &diastolicBP);
            // Step 11: Check for abnormal blood pressure and provide feedback
            if (systolicBP < 90 || systolicBP > 140 || diastolicBP < 60 || diastolicBP > 90) {
                fprintf(outputFile, "Abnormal Blood Pressure Detected: %d/%d mmHg\n", systolicBP, diastolicBP);
            }
        }
        if (strstr(line, "Pulse Transit Time:")) {
            sscanf(line, "Pulse Transit Time: %lf", &pulseTransitTime);
            // Step 12: Assuming a range for pulse transit time (example range, needs to be adjusted)
            if (pulseTransitTime < 0.1 || pulseTransitTime > 0.2) {
                fprintf(outputFile, "Abnormal Pulse Transit Time Detected: %.2lf seconds\n", pulseTransitTime);
            }
        }
        if (strstr(line, "Heartbeats Per Minute:")) {
            sscanf(line, "Heartbeats Per Minute: %d", &heartRate);
            // Step 13: Check for abnormal heart rate and provide feedback
            if (heartRate < 60 || heartRate > 100) {
                fprintf(outputFile, "Abnormal Heart Rate Detected: %d BPM\n", heartRate);
            }
        }
    }

    // Step 14: Close the input and output files
    if (fclose(inputFile) != 0 || fclose(outputFile) != 0) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }
}

// Function to show suggestions based on heart rate
void showSuggestions(int heartRate) {
    // Placeholder function for suggestions based on heart rate
    printf("Suggestions for heart rate %d BPM:\n", heartRate);
    printf("1. Consider deep breathing exercises to reduce stress.\n");
    printf("2. Ensure sufficient sleep for overall well-being.\n");
    // Add more personalized suggestions based on heart rate
    printf("\n");
}

// Function to analyze trends in heart rate
void analyzeTrends(int heartRate) {
    // Placeholder function for trend analysis
    printf("Analyzing trends for heart rate %d BPM:\n", heartRate);

    // Step 15: Provide feedback based on trends in heart rate
    if (heartRate > 80) {
        printf("Trend: Elevated heart rate observed. Monitor for potential stress.\n");
    } else if (heartRate < 60) {
        printf("Trend: Lower than normal heart rate observed. Consider consulting a healthcare professional.\n");
    } else {
        printf("Trend: Heart rate within normal range.\n");
    }

    printf("\n");
}

// Function to display health insights based on heart rate
void displayHealthInsights(int heartRate) {
    // Placeholder function for health insights
    printf("Displaying health insights for heart rate %d BPM:\n", heartRate);

    // Step 16: Provide health insights based on heart rate
    if (heartRate > 100) {
        printf("Insight: Elevated heart rate. Consider activities to reduce stress.\n");
    } else if (heartRate < 60) {
        printf("Insight: Lower than normal heart rate. Consult a healthcare professional if persistent.\n");
    } else {
        printf("Insight: Heart rate within normal range.\n");
    }

    printf("\n");
}