program SumOdDigits;

var
    n, sum, digit: integer;

begin
    write('Enger a non-negative integer: ');
    readln(n);

    if n < 0 then
    begin
        writeln('Error: Invalid input');
        exit;
    end;

    sum := 0;
    while n > 0 do
    begin
        digit := n mod 10;
        sum := sum + digit;
        n := n div 10;
    end;

    writeln('Sum of digits: ', sum);
end.
