# BrainfuckTextGenerator
C++ program that reads text from an input file and generates code in the Brainfuck programming language that, when executed, prints the text to the console

## How It Works
* The program reads each character from the input file.
* For each character, it generates Brainfuck instructions to reach the corresponding ASCII value, efficiently using loops and increments.
* It outputs a Brainfuck program that, when executed, prints the original input text.

## Example
Text:  
```
Hello world!
```

Output:  
```
++++++++++  
[  
  >+++++++  
  >++++++++++  
  >++++++++++  
  >++++++++++  
  >+++++++++++  
  >+++  
  >+++++++++++  
  >+++++++++++  
  >+++++++++++  
  >++++++++++  
  >++++++++++  
  >+++  
  <<<<<<<<<<<<-  
]  
>++.  
>+.  
>++++++++.  
>++++++++.  
>+.  
>++.  
>+++++++++.  
>+.  
>++++.  
>++++++++.  
>.  
>+++.  
```
