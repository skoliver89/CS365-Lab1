# CS365-Lab1
C Hello World and Fork() in Linux

HelloWorld <br />
Experience the world of c-programming as the early computer scientists did before GUI's and integrated development systems such as Visual Studio.<br />
Use Google to find a sample HelloWorld program. The hardcore people use the vi pronounced vee eye. Here is an URL: <br />
http://www.cs.colostate.edu/helpdocs/vi.html<br />
gcc is the compiler that you use to compile your c code. Here is an URL: <br />
http://ce.uml.edu/compile.htm. <br />
You should be able to find more compete instructions on the web. Make this one a very, very simple one!!!<br />

fork() system calls – this is the key of this lab!<br />
Create a program that uses the fork() and getpid () system calls. There is a simple example in our text and a lot of them on the web. Find a simple one, get it to work, and then play with it so it does something cool!<br />
The following URL http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html <br />
can be very useful. Read and gain a good understanding before coding. Get the first example to work. Make the MAX_COUNT to be 20. Change the MAX_COUNT back to 200 or even higher for the second example.<br />

Do something with this fork thing<br />
Let’s assume that there are two actions you would like to take. In that case, you can give one to the parent process and give the other to the child process. How to tell the difference between the parent and china process? This is the first thing you have to figure out. <br />
Now the two actions, one action to find the largest element and the other actions could be to find the smallest element. So create an array of 1000 and populate it with random integers before the fork call. Do two actions, with the parent finding the largest element and the child processing finding the smallest element, and then each prints the result out. Even better, do that before the fork so you know the result is correct or not. Event better, do these recursively with one or two functions. <br />
Here is the part you need two copies of the same array. Replace every element of the parent with the largest element and print out the total; replace every element of the child process with the smallest element and print out the total. Yes, I know you can calculate the total, but here we are asking you to do the actual replacing to prove a point. <br />
