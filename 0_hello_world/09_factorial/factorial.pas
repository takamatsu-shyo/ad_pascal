program Factorial;

var
    n: integer;

function IterativeFactorial(n: integer): int64;
var
    i: integer;
    result: int64;
begin
    result := 1;
    for i := 2 to n do
        result := result * i;
    IterativeFactorial := result;
end;

function RecursiveFactorial(n: integer): int64;
begin
    if n = 0 then
        RecursiveFactorial := 1
    else
        RecursiveFactorial := n * RecursiveFactorial(n - 1);
end;

begin
    write('Enter a non-negative integer: ');
    readln(n);

    if n < 0 then
    begin
        write('Error: Invalid input');
        exit;
    end;

    writeln('Factorial using Iterative: ', IterativeFactorial(n));
    writeln('Factorial using Recursive: ', RecursiveFactorial(n));
end.
