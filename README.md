# interpStr
Convenient str interpolation function for C++

It takes a string with special formatting symbols and generate a sequence of strings.

### Examples:

"/this/is/a/string[1-3].png" will give you a list of strings: "/this/is/a/string1.png", "/this/is/a/string2.png", "/this/is/a/string3.png"



###Format rules:

[1-3] -> 1,2,3

[01-03] -> 01, 02, 03

[01-03, 04, 05, 06-08] -> 01, 02, 03, 04, 05, 06, 07, 08
