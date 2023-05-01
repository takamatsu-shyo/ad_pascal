program HelloUser;

var
    userName: string;

begin
    write('Please enter your name: ');
    readln(userName);
    writeln('Hello, ', userName, '!');
end.
