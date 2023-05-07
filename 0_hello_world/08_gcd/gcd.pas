program GCD;

var
    a, b: integer;

function EuclideanGCD(a, b: integer): integer;
var
    temp: integer;
begin
    while b <> 0 do
    begin
        temp := b;
        b := a mod b;
        a := temp;
    end;
    EuclideanGCD := a;
end;

function RecursiveGCD(a, b: integer): integer;
begin
    if b = 0 then
        RecursiveGCD := a
    else
        RecursiveGCD := RecursiveGCD(b, a mod b);
end;

begin
    write('Enter two positive integers: ');
    readln(a, b);

    writeln('GCD Euclidean: ', EuclideanGCD(a, b));
    writeln('GCD Recursive: ', RecursiveGCD(a, b));
end.
