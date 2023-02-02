/*
EXCEPTIONS FUNCTIONS STACK UNWINDING

- Try blocks catch exceptions not only from statements within the try block, 
  but also from functions that are called within the try block

First
    - When an exception is thrown, the program first looks to see if the 
      exception can be handled immediately inside the current function

Then
    - it progressively goes through the stack searching for a catch.
      This requires unwinding the stack (removing the current function 
      from the call stack)

    - When the current function is removed from the call stack, all local
      variables are destroyed as usual, but no value is returned.
*/

