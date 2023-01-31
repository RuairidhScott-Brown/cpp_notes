/*
STRINGS

std::string is used for standard ascii and utf-8 strings. 
std::wstring is used for wide-character/unicode (utf-16) strings.

Creation and destruction
(constructor)   Create or copy a string
(destructor)	Destroy a string

Size and capacity
capacity()  Returns the number of characters that can be held without reallocation
empty()     Returns a boolean indicating whether the string is empty
length()    Returns the number of characters in string
size()      Returns the number of characters in string
max_size()  Returns the maximum string size that can be allocated
reserve()	Expand or shrink the capacity of the string

Element access
[], at()	Accesses the character at a particular index

Modification
=, assign() Assigns a new value to the string
+=          Concatenates characters to end of the string
append()    Concatenates characters to end of the string
push_back() Concatenates characters to end of the string
insert()    Inserts characters at an arbitrary index in string
clear()     Delete all characters in the string
erase()     Erase characters at an arbitrary index in string
replace()   Replace characters at an arbitrary index with other characters
resize()    Expand or shrink the string (truncates or adds characters at end of string)
swap()	    Swaps the value of two strings

Input and Output
>>          Reads values from the input stream into the string
getline()   Reads values from the input stream into the string
<<          Writes string value to the output stream
c_str()     Returns the contents of the string as a NULL-terminated C-style string
copy()      Copies contents (not NULL-terminated) to a character array
data()	    Same as c_str(). The non-const overload allows writing to the returned string.

String comparison
==, !=      Compares whether two strings are equal/unequal (returns bool)
<, <=, > >= Compares whether two strings are less than / greater than each other (returns bool)
compare()	Compares whether two strings are equal/unequal (returns -1, 0, or 1)

Substrings and concatenation
+           Concatenates two strings
substr()	Returns a substring

Searching
find()      Find index of first character/substring
find_first_of()     Find index of first character from a set of characters
find_first_not_of() Find index of first character not from a set of characters
find_last_of()      Find index of last character from a set of characters
find_last_not_of()  Find index of last character not from a set of characters
rfind()	            Find index of last character/substring

Iterator and allocator support
begin(), end()      Forward-direction iterator support for beginning/end of string
get_allocator()     Returns the allocator
rbegin(), rend()    Reverse-direction iterator support for beginning/end of string	

*/
#include <string>