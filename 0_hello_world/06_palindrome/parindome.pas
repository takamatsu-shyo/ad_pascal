program PalindromeChecker;

var
    inputStr : string;

function ReverseString(s: string): string;
var
    i, len: integer;
begin
    len := Length(s);
    SetLength(ReverseString, len);

    for i := 1 to len do
        ReverseString[len - i + 1] := s[i];
end;

function IsPalindrome(s: string): boolean;
begin
    IsPalindrome := s = ReverseString(s);
end;

begin
    write('Enger a string: ');
    readln(inputStr);

    if IsPalindrome(inputStr) then
        writeln('It is a palindrome')
    else
        writeln('Not a palindrome');
end.
