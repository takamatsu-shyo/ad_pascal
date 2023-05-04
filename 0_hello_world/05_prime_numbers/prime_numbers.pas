program PrimeNumbers;

var
    n, i: integer;

function IsPrime(num: integer): boolean;
var
    i, limit: integer;
begin
    if num <= 1 then
    begin
        isPrime := False;
        exit;
    end;

    if num = 2 then
    begin
        isPrime := True;
        exit;
    end;

    limit := trunc(sqrt(num));
    for i := 2 to limit do
    begin
        if num mod i = 0 then
        begin
            IsPrime := False;
            exit;
        end;
    end;

    IsPrime := True;
end;

begin
    write('Enter a positive integer: ');
    readln(n);
    
    writeln('Prime numbers between 1 and ', n, ':');
    for i := 1 to n do
    begin
        if IsPrime(i) then
            write(i, ' ');
    end;
    writeln;
end.
