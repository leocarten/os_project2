#include <stdio.h>
#include <stdlib.h>

// GLOBAL VARIABLES
int N = 8;
int n = 64;
float total_area = 0;
float upperbound = 2;
// float upperbound = 5;
float lowerbound = 0;

// function declaration
float myFunction(float input);

// function to calculate area from some x value to another x value
float calculateArea(float functionUpperbound, float functionLowerbound){
    float h = (functionUpperbound - functionLowerbound) / (float)n;
    float sum = 0;
    int i;
    for(i = 0; i < n; i++){
        // calculate the area of the trapezoid and update the sum
        sum += (h/2)*(myFunction(functionLowerbound + i * h) + myFunction(functionLowerbound + (i+1) * h));
    }
    return sum;
}

// the function we want to find the area underneath
float myFunction(float input){
    float y = (1/(input + 1));
    // float y = (input*input);
    return y;
}

int main() {
    // // the below function calls work !!
    // float area = calculateArea(0.25, 0.0);
    // printf("Area: %f\n",area);


    // pipes for the child and parent to communicate through. index 1 is write, index 0 is read.
    int parentToChildPipe[N][2];
    int childToParentPipe[N][2];

    // create parentToChildPipe - this is the pipe that will supply the children with their data
    int i;
    for (i = 1; i <= N; i++) {
        if (pipe(parentToChildPipe[i]) == -1) {
            exit(1);
        }
    }

    // create childToParentPipe - this is the pipe the children will use to write back to the parent
    int q;
    for (q = 1; q <= N; q++) {
        if (pipe(childToParentPipe[q]) == -1) {
            exit(1);
        }
    }

    // Processes
    int j;
    for (j = 1; j <= N; j++) {
        pid_t pid = fork();
        if (pid == -1) {
            // issue with fork call
            exit(1);
        } 
        else if (pid == 0) {
            // CHILD PROCESS(S)

            // Close write end
            close(parentToChildPipe[j][1]); 

            float value;

            // read integer value from parent
            if (read(parentToChildPipe[j][0], &value, sizeof(int)) == -1) {
                exit(1);
            }

            float newVal = value * j; // get the starting x value

            float area = calculateArea(newVal, (float)(newVal - value));

            // We need to do something here with the value we have recieved to calculate area
            printf("Child with PID of %d calculated over the x-values of %f to %f derived an area of: %f\n", getpid(), newVal, (newVal - value), area);

            // Close read end in child
            close(parentToChildPipe[j][0]);

            // Write area value back to parent
            float valueSentToParent = area; 
            // float valueSentToParent = N/(upperbound - lowerbound);
            if (write(childToParentPipe[j][1], &valueSentToParent, sizeof(int)) == -1) {
                exit(1);
            }

            // Close write end
            close(childToParentPipe[j][1]);
            exit(0);
        } 
        else {
            // PARENT

            // close read end
            close(parentToChildPipe[j][0]);

            // write values to the child for it to do stuff with
            float valueSendToChild = (float)(upperbound - lowerbound) / (N);

            if (write(parentToChildPipe[j][1], &valueSendToChild, sizeof(int)) == -1) {
                exit(1);
            }

            // close write end in parent
            close(parentToChildPipe[j][1]);

            // wait for child to complete task of calculating the area
            while (wait(NULL) > 0);

            // The child is done, read the value from child
            float valueRecievedFromChild;
            if (read(childToParentPipe[j][0], &valueRecievedFromChild, sizeof(int)) == -1) {
                exit(1);
            }

            // Update the global variable with the value caluclated by the child
            total_area += valueRecievedFromChild;

            printf("The current area is: %f.\n", total_area);

            // Close read end
            close(childToParentPipe[j][0]);
        }
    }

    printf("All of the children are done running!\n");

    printf("The total area is: %f.\n", total_area);

    return 0;
}
