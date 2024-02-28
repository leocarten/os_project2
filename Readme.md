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
Child with PID of 93525 calculated over the x-values of 0.250000 to 0.000000 derived an area of: 0.223144
The current area is: 0.223144
Child with PID of 93526 calculated over the x-values of 0.500000 to 0.250000 derived an area of: 0.182322
The current area is: 0.405466
Child with PID of 93527 calculated over the x-values of 0.750000 to 0.500000 derived an area of: 0.154151
The current area is: 0.559617
Child with PID of 93528 calculated over the x-values of 1.000000 to 0.750000 derived an area of: 0.133531
The current area is: 0.693148
Child with PID of 93529 calculated over the x-values of 1.250000 to 1.000000 derived an area of: 0.117783
The current area is: 0.810931
Child with PID of 93530 calculated over the x-values of 1.500000 to 1.250000 derived an area of: 0.105361
The current area is: 0.916292
Child with PID of 93531 calculated over the x-values of 1.750000 to 1.500000 derived an area of: 0.095310
The current area is: 1.011602
Child with PID of 93532 calculated over the x-values of 2.000000 to 1.750000 derived an area of: 0.087011
The current area is: 1.098613
All of the children are done running!
The total area is: 1.098613.
```

#### Below is when the number of proccesses, `N`, equals 2, and the number of trapezoids assigned to each proccess, `n`, equals 2:
```
[lmc1076@srvlp-dpt-cs01 proj2]$ cc integral.c
[lmc1076@srvlp-dpt-cs01 proj2]$ ./a.out
Child with PID of 93865 calculated over the x-values of 1.000000 to 0.000000 derived an area of: 0.708333
The current area is: 0.708333.
Child with PID of 93866 calculated over the x-values of 2.000000 to 1.000000 derived an area of: 0.408333
The current area is: 1.116667.
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
[lmc1076@srvlp-dpt-cs01 proj2]$ cc integral.c
[lmc1076@srvlp-dpt-cs01 proj2]$ ./a.out
Child with PID of 93965 calculated over the x-values of 0.625000 to 0.000000 derived an area of: 0.081390
The current area is: 0.081390.
Child with PID of 93966 calculated over the x-values of 1.250000 to 0.625000 derived an area of: 0.569671
The current area is: 0.651062.
Child with PID of 93967 calculated over the x-values of 1.875000 to 1.250000 derived an area of: 1.546234
The current area is: 2.197296.
Child with PID of 93968 calculated over the x-values of 2.500000 to 1.875000 derived an area of: 3.011078
The current area is: 5.208374.
Child with PID of 93969 calculated over the x-values of 3.125000 to 2.500000 derived an area of: 4.964203
The current area is: 10.172577.
Child with PID of 93970 calculated over the x-values of 3.750000 to 3.125000 derived an area of: 7.405610
The current area is: 17.578186.
Child with PID of 93971 calculated over the x-values of 4.375000 to 3.750000 derived an area of: 10.335296
The current area is: 27.913483.
Child with PID of 93972 calculated over the x-values of 5.000000 to 4.375000 derived an area of: 13.753263
The current area is: 41.666748.
All of the children are done running!
The total area is: 41.666748.
```
