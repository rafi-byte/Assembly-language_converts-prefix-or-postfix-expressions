Here are some input/output examples to help illustrate how the refactored code works:

 Example 1: Simple Postfix Expression `AB+`
 Input:
```
Enter postfix expression: AB+
```

 Output:

```
Generating one-address assembly code:
    LOAD A
    ADD B
    STORE X

Generating two-address assembly code:
    ADD A, B

Generating three-address assembly code:
    ADD X, A, B
```

 Explanation:
- One-address: First operand `A` is loaded, `B` is added, and the result is stored in register `X`.
- Two-address: Direct addition of `A` and `B` is performed.
- Three-address: The result of `A + B` is stored in `X` using a three-address instruction.

---

 Example 2: Postfix Expression with Multiplication `ABC*+`
 Input:
```
Enter postfix expression: ABC*+
```

 Output:

```
Generating one-address assembly code:
    LOAD B
    MUL C
    STORE X
    LOAD A
    ADD X
    STORE Y

Generating two-address assembly code:
    MUL B, C
    ADD A, X

Generating three-address assembly code:
    MUL X, B, C
    ADD Y, A, X
```

 Explanation:
- One-address: `B` is loaded, multiplied by `C`, and stored in register `X`. Then, `A` is added to `X`, and the result is stored in register `Y`.
- Two-address: First, `B * C` is stored in a temporary register `X`, and `A` is added to `X`.
- Three-address: The result of `B * C` is stored in `X`, and then `A + X` is stored in `Y`.

---

 Example 3: Postfix Expression with Division and Subtraction `AB/CD-`
 Input:
```
Enter postfix expression: AB/CD-
```

 Output:

```
Generating one-address assembly code:
    LOAD B
    DIV C
    STORE X
    LOAD A
    SUB X
    STORE Y

Generating two-address assembly code:
    DIV B, C
    SUB A, X

Generating three-address assembly code:
    DIV X, B, C
    SUB Y, A, X
```

 Explanation:
- One-address: `B` is divided by `C` and the result is stored in `X`. Then `A` is subtracted from `X`, and the result is stored in `Y`.
- Two-address: Division of `B / C` is stored in `X`, and `A - X` is performed.
- Three-address: The division `B / C` is stored in `X`, and `A - X` is stored in `Y`.

---

Example 4: Postfix Expression with Mixed Operators `AB*C/D+`
Input:
```
Enter postfix expression: AB*C/D+
```

Output:

```
Generating one-address assembly code:
    LOAD A
    MUL B
    STORE X
    LOAD C
    DIV D
    STORE Y
    LOAD X
    ADD Y
    STORE Z

Generating two-address assembly code:
    MUL A, B
    DIV C, D
    ADD X, Y

Generating three-address assembly code:
    MUL X, A, B
    DIV Y, C, D
    ADD Z, X, Y
```

Explanation:
- One-address: First, `A * B` is computed and stored in `X`. Then, `C / D` is computed and stored in `Y`. Finally, `X + Y` is computed and stored in `Z`.
- Two-address: The multiplications and divisions are performed directly in `X` and `Y`, then the addition of `X + Y` is done.
- Three-address: Operations are stored directly into registers, keeping the result in `Z` after all operations.

---

These examples demonstrate how the program handles postfix expressions and generates assembly code with one, two, and three address instructions dynamically.
