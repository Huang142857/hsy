#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
   
    FITNESS_DATA fitnessData[100];
    int recordCount = 0;

   
    FILE *file;
    file = fopen("FitnessData_2023.csv", "r");

    
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL) {
        
        size_t len = strlen(line);
        if (len > 0 && line[len-1] == '\n') {
            line[len-1] = '\0';
        }

       
        char date[11], time[6], stepsStr[10];
        tokeniseRecord(line, ",", date, time, stepsStr);

        int steps = atoi(stepsStr);

        
        strcpy(fitnessData[recordCount].date, date);
        strcpy(fitnessData[recordCount].time, time);
        fitnessData[recordCount].steps = steps;

       
        recordCount++;
    }

    
    fclose(file);

    for (int i = 0; i < 3; i++) {
        printf("%s/%s/%d\n", fitnessData[i].date, fitnessData[i].time, fitnessData[i].steps);
    }

    return 0;
}
