# Eight Queens Problem

## Description
This program, written in C, is a solver to the famous 8 Queens problem. The problem entails placing 8 Queens on an 8x8 chess board in such a manor that no two Queens can attack each other. Running the program produces 92 solutions to the problem, however these 92 solutions are simply reflections and rotations of the real number of solutions, which is only 12!

## Getting Started

1. Download project
2. Run `gcc -o queens queens.c`
3. run `./queens`

### Prerequisites

The gcc compiler
Check if you have it with `gcc --version`

Here is my result of running `gcc --version`
gcc (GCC) 5.3.1 20151207 (Red Hat 5.3.1-2)
...

## Optional Switches

1. -n
  - Numbers lines that have solutions on them. Use this rather then piping to cat -n (that breaks -t switch)
2. -p
  - Pretty output. This prints solutions in a visually recognizable format similar to a chess board
3. -t
  - Displays the total time taken in calculating the solutions and printing them to the console

## Authors

* **Jameel Kelley** - [Github](https://github.com/JamKelley22) | [Website] (http://www.public.iastate.edu/~jkelley/)

## Acknowledgments

* [README Template](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
* [Semantic Versioning](http://semver.org/spec/v2.0.0.html)
* [Multiple Command Line Args](https://stackoverflow.com/questions/28014668/multiple-command-line-arguments-in-c)
