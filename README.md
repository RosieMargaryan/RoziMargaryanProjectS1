# Heart Rate Monitoring System


## Description

The Heart Rate Monitoring System is a C-based project that allows users to monitor their heart rate and receive feedback and insights based on physiological data. The project is divided into two main parts:

1. Data Generation: The first part of the project generates random physiological data (e.g., heart rate, blood pressure, body temperature) at specified intervals and saves it to a file.

2. Data Analysis and Feedback: The second part analyzes the physiological data, provides feedback based on the analysis, and allows users to interactively request suggestions, trend analysis, and health insights based on their heart rate.

## Features

- Random generation of physiological data for a specified duration.
- Analysis of physiological data to detect abnormalities.
- User interaction for suggestions, trend analysis, and health insights.
- Modular code structure with functions for easy maintenance and extension.

## How to Use

1. Data Generation (Part 1):

   - Compile and run the firstpart.c file.
   - Enter the interval (in minutes) for generating random physiological data.
   - The data will be saved to a file named physiological_data.txt.

2. Data Analysis and Feedback (Part 2):

   - Compile and run the secondpart.c file.
   - The program will analyze the physiological data and generate a feedback report in feedback_report.txt.
   - You can interactively choose options to receive suggestions, trend analysis, and health insights based on your heart rate.

## Requirements

- C compiler (e.g., GCC)
- POSIX-compliant operating system (for sleep function)

## File Structure

- firstpart.c: Contains the code for generating random physiological data.
- secondpart.c: Contains the code for analyzing the data and providing feedback.
- physiological_data.txt: Stores the generated physiological data.
- feedback_report.txt: Stores the feedback and analysis results.

## Contributors

- Rozi Margaryan
