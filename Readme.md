# Leo Carten - OS Project 2
### Forks, Children, Parents, and Pipes
#### Code summary
First, I generate all of the pipes using for loops. We are going to need 2 sets of pipes, one set of pipes will be used for the parent to write to the children, and the other set will be for the children to write to the parent.

Second, once I established bi-directional communication between children and parents (meaning that parents could send values to children, children could do something to the values, write back, and parents could read), then I started working on the `calculateArea` function. After I re-taught myself the fundamental theory of Calculus, I was able to write a function that calculates the area under the curve from some x value to another x value.

Third, I called the `calculateArea` function accordingly, strategically calculating the area of certain parts of the function by assigning the work to the children.

Lastly, I wrote the value back to the parent, which kept a running tally of areas returned from the children.

I used a lot of online resources to complete this, the ones that were the most help are listed below:

- [Calculator to check my work](https://www.integral-calculator.com/)

- [Reviewing the fundamental theory of calculus](https://www.youtube.com/watch?v=1p0NHR5w0Lc&t=362s)

- [Researching pipe system calls](https://www.geeksforgeeks.org/pipe-system-call/)


# Example outputs
#### Below is when the number of proccesses, `N`, equals 8, and the number of trapezoids assigned to each proccess, `n`, equals 64:
```
[lmc1076@srvlp-dpt-cs01 proj2]$ cc integral.c
[lmc1076@srvlp-dpt-cs01 proj2]$ ./a.out
Child with PID of 90102 calculated over the x-values of 0.250000 to 0.000000 derived an area of: 0.223144
Child with PID of 90103 calculated over the x-values of 0.500000 to 0.250000 derived an area of: 0.182322
Child with PID of 90104 calculated over the x-values of 0.750000 to 0.500000 derived an area of: 0.154151
Child with PID of 90105 calculated over the x-values of 1.000000 to 0.750000 derived an area of: 0.133531
Child with PID of 90106 calculated over the x-values of 1.250000 to 1.000000 derived an area of: 0.117783
Child with PID of 90107 calculated over the x-values of 1.500000 to 1.250000 derived an area of: 0.105361
Child with PID of 90108 calculated over the x-values of 1.750000 to 1.500000 derived an area of: 0.095310
Child with PID of 90109 calculated over the x-values of 2.000000 to 1.750000 derived an area of: 0.087011
All of the children are done running!
The total area is: 1.098613.
```

#### Below is when the number of proccesses, `N`, equals 2, and the number of trapezoids assigned to each proccess, `n`, equals 2:
```
[lmc1076@srvlp-dpt-cs01 proj2]$ cc integral.c
[lmc1076@srvlp-dpt-cs01 proj2]$ ./a.out
Child with PID of 89239 calculated over the x-values of 1.000000 to 0.000000 derived an area of: 0.708333
Child with PID of 89240 calculated over the x-values of 2.000000 to 1.000000 derived an area of: 0.408333
All of the children are done running!
The total area is: 1.116667.
```

# How do I change the code to different bounds, or have a new function?
To change the bounds, you can change the global variables `upperbound` and `lowerbound`.
To change the function, you can change the `y` value of the function named `myFunction`. 
### Below is an example of my code calculating the area under the function `f(x)=x^2` from 0 to 5:

1) Change the global variables:
```
float upperbound = 5;
float lowerbound = 0;
```

2) Change the function:
```
float myFunction(float input){
    float y = (input*input);
    return y;
}
```

#### The output:
```
Child with PID of 91168 calculated over the x-values of 0.625000 to 0.000000 derived an area of: 0.081390
Child with PID of 91169 calculated over the x-values of 1.250000 to 0.625000 derived an area of: 0.569671
Child with PID of 91170 calculated over the x-values of 1.875000 to 1.250000 derived an area of: 1.546234
Child with PID of 91171 calculated over the x-values of 2.500000 to 1.875000 derived an area of: 3.011078
Child with PID of 91172 calculated over the x-values of 3.125000 to 2.500000 derived an area of: 4.964203
Child with PID of 91173 calculated over the x-values of 3.750000 to 3.125000 derived an area of: 7.405610
Child with PID of 91174 calculated over the x-values of 4.375000 to 3.750000 derived an area of: 10.335296
Child with PID of 91175 calculated over the x-values of 5.000000 to 4.375000 derived an area of: 13.753263
All of the children are done running!
The total area is: 41.666748.
```
