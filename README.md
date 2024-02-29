# Welcome to My Mouse
***

## Task
Given a maze, you must find the starting point, the end point, and the shortest path between
the two while also returning the distance of the shortest path. 
The maze is represented by a file passed as the argument.
    
    - The first line of the file contains
        • The HEIGHT x WIDTH
        • The "full" character
        • The "empty" character
        • The "path" character
        • The "entry" character
        • Lastly, the "exit" character
            => (example) 10x10* o12
You're program must find the shortest path through the "empty" (in this case " ") sections of the maze and highlight
this path by marking it with the "path" character (in this case "o").        

## Description
First we read the maze from a file and into a 2d array.
We then traverse the maze to find the entry and exit coordinates.
We create a queue and traverse the maze starting from the entry point, each time checking for empty coordinates that may lead to our exit coordinate.
When we traverse on a coordinate, we check if it is valid (meaning it is in bounds of the maze), and if it too has a next coordinate that is valid.
If so, we add it to the queue, then move to the next empty coordinate. 
We repeat this process until we reach the exit, or until we are unable to move any further, in which case the program ends since no path was found.

## Installation
To compile the program, input "make" into terminal.

$> make

## Usage
Given a correctly formatted maze, the program will mark the shortest path from the starting point to the exit point as well as print the distance of that path (If there is one).
If there is no path to the exit, "No path found!" will be printed out.
If the map is not formatted correctly, "MAP ERROR" will be printed out.

To generate a maze, you can create your own, or utilize the maze_generator.rb file in the maze folder.
    - To utilize this folder, input into terminal: 
        • (example) - "ruby maze_generator.rb 100 100 "a* o12" > [file_to_print_maze]"
Additionally, you can validate the output by utilizing the my_mouse_checker.rb file in the maze folder.
    - This can be performed by inputting into the terminal:
        • (example) - "./my_mouse [file_with_maze] | ruby maze/my_mouse_checker.rb"
```
./my_mouse [file_with_maze]
```

### The Core Team

Selcuk Aksoy and Paul Mwaura
<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
