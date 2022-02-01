# -MULTI-LINE-CALCULATOR
In this homework you are going to write a (C / C++) program that will interpret mathematical calculations 
from an input file with “.inp” extension. The input file can include keywords, alphanumeric variables, 
symbols, and operators. Each line is taken as an expression. The result of the calculation will be written 
to an output file with “.out” extension. The program search all the “.inp” files in the same folder with the 
executable. And create the separate “.out” files for each input. You have different challenge steps to 
interpret the inputs. Solve as much challenge as you can. Do not start form the last one. I strongly advise 
to solve them one by one. Each time creating a different project should be a good practice. Do not copy 
past your previous solution but use the knowledge from it to solve next challenge. The examples are just 
informal. Your interpreter must calculate different operation combinations. 

Keywords: OUT , IN , IF , THEN , ELSE , LOOP , TIMES
OUT    Write out the given variable input in the console and output file.  -> OUT A
IN     Gets input to a variable from console. (We do not use in challenges.) -> IN B
IF     Starts an IF clause. It will followed by THEN and ELSE in one line. -> A = IF B<C THEN B ELSE C
THEN
ELSE
LOOP   Create a loop that will do the operation between LOOP and TIMES keyword n times. n is given as a constant after TIMES keyword. -> LOOP A = B+A TIMES 5


Operations: * , / , + , - , < , > , ==, <= , >= , !, != , =
*   Multiplication    5 * 2 => 10
/   Division          5 / 2 => 2 , 5.0 / 2 => 2.5
+   Addition          5 + 2 => 7
-   Subtraction,      5 – 2 => 3
<   Smaller           5 < 2 => false
>   Grater            5 > 2 => true
==  Equality          5 == 2 => false , 2==2 => true
<=  Smaller or Equal  5 <= 2 => true , 2<=2 => true
>=  Grater or Equal   5 >=2 => true , 2>= 2 => true
!   Not               !5 => false, !0 => true
!=  Not Equal         5 != 2 => true , 2 != 2 => false
=   Assignment        A = 5

Symbols: ( , )
Variable Names: Start with an alphabetic character and can continue with alphanumeric characters. Ex: 
A, B, C, D, E, A1, B2C, C3, D44, …

Challange1: Integer Constants one-character variable names
A = 5
B= 10
C= A+B
OUT C
Output file must store: 15

Challange2: Double Constants one-character variable names
A = 5.3
B = 10.2
C = A+B
OUT C
Output file must store: 15.5

Challange3: Integer Division
A = 5
B = 9
C = B / A
OUT C
Output file must store: 1

Challenge4: Double Division
A = 5.0
B = 9
C= B / A
OUT C
Output file must store: 1.8

Challange5: Operator Precedence
A = 6
B = 2
C = A + B
D = B * A + B * C
OUT D
Output file must store: 28

Challange6: Operator Precedence with Parentheses
A = 1
B = 2
C = A + B
D = (A + B ) * C + B
OUT D
Output file must store: 11

Challange7: using IF THEN ELSE statement
A1 = 1
B1 = 2
A2 = IF A1 > B1 THEN A1 ELSE B1
OUT A2
Output file must store: 2

Challange8: Combine IF clause with operations
A = 1
B = 2
C = IF ( A + B ) <= 3 THEN A ELSE B
OUT C
Output file must store: 1

Challange9: Loop Statement
A = 2
B = 3
LOOP C = C + A * B TIMES 5
OUT C
Output file must store: 30

Challange10: Create your custom input files and try your multi line calculate perferctness

Program Main Screen: No output will be shown on the screen unless the input file includes an IN 
command. Your program must start and end without any unnecessary input and output commands. Just 
the OUT commands from the input file should result a console and file output. 
