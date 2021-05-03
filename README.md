# CS170-Project-1
### Zachary Hill and Khuaja Shams

The following is a guideline of what is expected when implementing the code and the different scenarios to expect for different inputs:

The end/goal puzzle will be given, {{1,2,3}, {4,5,6}, {7,8,0}}, so all we need to decide is the initial puzzle and the search algorithm to implement.

First, run the output frame of mainTree.cpp in the open terminal by typing ./runproject.

(1)

You should see a message that asks for the type of puzzle you would like to answer. There are only two options to select, type '1' for default puzzle or '2' to create your own puzzle. This puzzle will be set as the initial puzzle.

After you type '1' or '2' and press ENTER the next task will be different but if you did not input '1' or '2' you will automatically have to create your own puzzle, there can be spacing before or after but nothing else.

![Intro](/readme_pdfs/Intro.pdf)

If you typed '1' you should see the following display:

![Default](/readme_pdfs/Complexity.pdf)

If you typed '2' you should see the following display:

![Create (Start)](/readme_pdfs/Create_Puzzle_1.pdf)

![Create (End)](/readme_pdfs/Create_Puzzle_2.pdf)

Also, type three numbers ranging from 0-8, make sure to space each. Once the first row is filled press ENTER to go to the next row and type three more numbers, continue this until you have three rows each containing three numbers creating a 3x3 array puzzle. Note: the index containing '0' will represent the blank square. If you type anything symbols other than 0-8, more or less than three numbers per row, and/or use the same number in more than one row the code will still compile but will not stop until it is terminated.


(2)

Now that we have the initial puzzle and the goal puzzle the next step to the select the algorithm from the list shown below:

![Algorithm Choice](/readme_pdfs/Algorithm.pdf)

Enter '1' for Uniform Cost Search, '2' for A* Search with Misplaced Tiles, or '3' for A* Search Using Euclidean Distance then press Enter. Again the program will run forever, until it is terminated, if anything else is typed.

(3)

After selecting the algorithm, an entire list of nodes from the Tree will be displayed by using Breadth-First Search. The process and end of the simulation should look somewhat like below:

![Tree Creation](/readme_pdfs/Edge Path.pdf)

(Note: the total cost is shown after each node and increments if is part of the optimal solution)

![Solution](/readme_pdfs/End_Tree.pdf)

There will be a message that states whether the algoithm has succeeded. You should also see the maximum number of nodes in the queue as well as the total number of nodes expanded for the selected initial puzzle and algorithm.

(4)

Important Note: after the solution is provided and we reached the end of the process, you will be asked again whether you want to solve a default puzzle or create your own. Then the same steps above will occur once more and will continue until the program is terminated.

Have fun with solving as many 8 puzzles as you like in the given C++ program! (But only puzzle that are 3x3, 8 tiles to slide, no more no less.)

