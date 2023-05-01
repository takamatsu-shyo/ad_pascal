program ArithmeticCalculator;

var
    num1, num2, result: real;
    _operator: char;

begin
    writeln('Enter two numbers and an operator (+, -, *, /):');

    write('Number 1: ');
    readln(num1);

    write('Number 2: ');
    readln(num2);

    write('Operator: ');
    readln(_operator);


    case _operator of
        '+': result := num1 + num2;
        '-': result := num1 - num2;
        '*': result := num1 * num2;
        '/': 
            if num2 <> 0 then
                result := num1 / num2
            else
            begin
                writeln('Error: Division by zero.');
                exit;
            end;
    else
        begin
            writeln('Error: Invalid operator.');
            exit;
        end;
    end;

    writeln('Result: ', result:0:2);
end.
