# CS170-Project-1
### Zachary Hill and Khuaja Shams

The following is a guideline of what is expected when implementing the code and the different scenarios to expect for different inputs:

First, run the output frame of mainTree.cpp in the open terminal by typing $output mainTree.cpp.

(1)
You should see a message that asks for the type of puzzle you would like to answer. There are only two options to select, type '1' for default puzzle or '2' to create your own puzzle. This puzzle will be set as the initial puzzle. Note: the variable to continue playing is set to 'Y' by default, will discuss this later in the instructions. 

After you type '1' or '2' and press ENTER the next task will be different but if you did not input '1' or '2' you will see a message that says "That is not a valid choice! Please re-enter your choice: " and you will have to type a new input agaian and again UNTIL you type '1' or '2', there can be spacing before or after but nothing else.

If you typed '1' you should see the following display:



If you typed '2' you should see the following display:



Also, type three numbers ranging from 0-8, make sure to space each. Once the first row is filled press ENTER to go to the next row and type three more numbers, continue this until you have three rows each containing three numbers creating a 3x3 array puzzle. Note: the index containing '0' will represent the blank square. If you type anything symbols other than 0-8, more or less than three numbers per row, and/or use the same number in more than one row you should see the message "Invalid Puzzle! Please enter your puzzle again below!" then you will again see the same message for inputting the numbers as shown above.



