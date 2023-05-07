program BubbleSort;

var
    arr: array of integer;
    n: integer;

procedure ReadArray(n: integer; var a: array of integer);
var
    i: integer;
begin
    for i := 0 to n - 1 do
    begin
        write('Enter element ', i + 1, ': ');
        readln(a[i]);
    end;
end;

procedure PrintArray(n: integer; const a: array of integer);
var
    i: integer;
begin
    for i := 0 to n - 1 do
        write(a[i], ' ');
    writeln;
end;

procedure BubbleSort(n: integer; var a: array of integer);
var
    i, j, temp: integer;
begin
    for i := 0 to n - 2 do
        for j := 0 to n - i - 2 do
           if a[j] > a[j + 1] then
           begin
               temp := a[j];
               a[j] := a[j + 1];
               a[j + 1] := temp;
           end;
end;

begin
    write('Enter the num of elements: ');
    readln(n);

    SetLength(arr, n);

    writeln('Enter the eleemnts:');
    ReadArray(n, arr);

    writeln('Array before sorting:');
    PrintArray(n, arr);

    BubbleSort(n, arr);

    writeln('Array after Bubble Sort:');
    PrintArray(n, arr);
end.
