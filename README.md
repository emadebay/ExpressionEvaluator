Just "stack" it next to me
The goal of this project is to create a calculator application
That is easily extensible
Meaning, new commands type can be easily be added

This repository contains C++ libraries for implementing an array, queue, and stack, along with an expression evaluator that utilizes the command pattern, abstract factory, and facade design patterns.

Libraries
Array Class
The Array class provides a dynamic array implementation, allowing for efficient storage and manipulation of elements. It includes methods for adding, removing, accessing elements, and resizing the array as needed.

Queue Class
The Queue class implements a queue data structure using a linked list. It supports enqueueing and dequeueing elements, as well as checking the front element without removing it.

Stack Class
The Stack class is built upon the Array class and provides a stack data structure implementation. It includes methods for pushing and popping elements onto and from the stack, as well as checking the top element without removing it.

Expression Evaluator
The expression evaluator is designed to evaluate postfix expressions efficiently using the command pattern, abstract factory, and facade design patterns.

Postfix Evaluation
The expression evaluator takes a postfix expression as input and evaluates it to produce the result. It uses a stack to perform the evaluation, pushing operands onto the stack and applying operators as they are encountered.

Command Pattern
The command pattern is used to encapsulate each operation in the evaluation process as a command object. This allows for flexible and extensible evaluation logic, as new commands can be easily added or modified without changing the evaluator itself.

Abstract Factory
The abstract factory pattern is employed to create command objects based on parsing the infix expression and converting it to postfix notation. The factory encapsulates the logic for parsing the expression and generating the appropriate commands for evaluation.

Facade Pattern
The facade pattern provides a simplified interface to a complex system. In the context of the expression evaluator, the facade hides the implementation details of the evaluation process and provides a single, easy-to-use interface for clients to interact with.

usage
Clone to machine
type make or make clean to remove the .o files
enter - "./assignment3"
Then enter mathematical expressions
example 2 + 2, 24 / 12

Check for memory leaks using `valgrind ./assignment3`

make sure there are spaces in between them
