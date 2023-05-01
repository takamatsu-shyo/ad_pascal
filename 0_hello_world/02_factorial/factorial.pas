program Factorial;

var
    num: integer;

function IterativeFactorial(n: integer): int64;
var
    i: integer;
    result: int64;
begin
    result := 1;
    for i := 1 to n do
        result := result * i;
    IterativeFactorial := result;
end;

function RecursiveFactorial(n: integer): int64;
begin
    if n <= 1 then
        RecursiveFactorial := 1
    else
        RecursiveFactorial := n * RecursiveFactorial(n - 1);
end;

begin
    write('Enter a positive integer: ');
    readln(num);

    if num < 0 then
    begin
        writeln('Error: Invalid input. Please enter a positive integer.');
        exit;
    end;

    writeln('Iterative factorial: ', IterativeFactorial(num));
    writeln('Recursive factorial: ', RecursiveFactorial(num));
end.
