program FibonacciSequence;

var
    n: integer;

function IterativeFibonacci(n: integer): int64;
var
    i: integer;
    a, b, temp: int64;
begin
    if n <= 1 then
        IterativeFibonacci := n
    else
    begin
        a := 0;
        b := 1;
        for i := 2 to n do
        begin
            temp := a + b;
            a := b;
            b := temp;
        end;
        IterativeFibonacci := b;
    end;
end;

(*TODO semi collon ?*)

function RecursiveFibonacci(n: integer): int64;
begin
    if n <= 1 then
        RecursiveFibonacci := n
    else
        RecursiveFibonacci := RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
end;

(*TODO function / procedure ?*)

procedure PrintFibonacciSequence(n: integer);
var
    i: integer;
begin
    writeln('Iterative Fibonacci sequence');
    for i := 0 to n - 1 do
        write(IterativeFibonacci(i), ' ');
    writeln();

    writeln('Recursive Fibonacci sequence');
    for i := 0 to n - 1 do
        write(RecursiveFibonacci(i), ' ');
    writeln();
end;

begin
    write('Enter a positive integer: ');
    readln(n);

    if n < 1 then
    begin
        writeln('Error: Invalid input. Please enter a positive integer.');
        exit;
    end;

    PrintFibonacciSequence(n);
end.
