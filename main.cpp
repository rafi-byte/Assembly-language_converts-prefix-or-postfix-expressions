#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// Function to generate assembly code based on the number of address types (1, 2, or 3 address instructions)
void generateAssembly(string postfix, int addressType) {
    stack<string> operandStack;
    vector<string> registers = {"X", "Y", "Z"}; // Dynamic register names
    int regIndex = 0; // Index to cycle through registers

    for (char ch : postfix) {
        if (isalpha(ch)) { // If operand, push it onto the stack
            operandStack.push(string(1, ch));
        } else { // If operator, pop operands from the stack
            string operand1 = operandStack.top(); operandStack.pop();
            string operand2 = operandStack.top(); operandStack.pop();
            string reg = registers[regIndex]; // Choose the register dynamically based on the index

            // Switch case to generate assembly based on the operator
            switch (ch) {
                case '+':
                    if (addressType == 1)
                        cout << "\tLOAD " << operand2 << "\n\tADD " << operand1 << "\n\tSTORE " << reg << endl;
                    else if (addressType == 2)
                        cout << "\tADD " << operand2 << ", " << operand1 << endl;
                    else if (addressType == 3)
                        cout << "\tADD " << reg << ", " << operand2 << ", " << operand1 << endl;
                    break;
                case '-':
                    if (addressType == 1)
                        cout << "\tLOAD " << operand2 << "\n\tSUB " << operand1 << "\n\tSTORE " << reg << endl;
                    else if (addressType == 2)
                        cout << "\tSUB " << operand2 << ", " << operand1 << endl;
                    else if (addressType == 3)
                        cout << "\tSUB " << reg << ", " << operand2 << ", " << operand1 << endl;
                    break;
                case '*':
                    if (addressType == 1)
                        cout << "\tLOAD " << operand2 << "\n\tMUL " << operand1 << "\n\tSTORE " << reg << endl;
                    else if (addressType == 2)
                        cout << "\tMUL " << operand2 << ", " << operand1 << endl;
                    else if (addressType == 3)
                        cout << "\tMUL " << reg << ", " << operand2 << ", " << operand1 << endl;
                    break;
                case '/':
                    if (addressType == 1)
                        cout << "\tLOAD " << operand2 << "\n\tDIV " << operand1 << "\n\tSTORE " << reg << endl;
                    else if (addressType == 2)
                        cout << "\tDIV " << operand2 << ", " << operand1 << endl;
                    else if (addressType == 3)
                        cout << "\tDIV " << reg << ", " << operand2 << ", " << operand1 << endl;
                    break;
            }

            // Push the result into the stack and increment the register index
            operandStack.push(reg);
            regIndex = (regIndex + 1) % registers.size(); // Cycle through the registers
        }
    }
}

// Driver function to run the program
int main() {
    string expression;
    
    // User input for postfix expression
    cout << "Enter postfix expression: ";
    cin >> expression;

    // Generating one-address assembly code
    cout << "\nGenerating one-address assembly code:\n";
    generateAssembly(expression, 1);

    // Generating two-address assembly code
    cout << "\nGenerating two-address assembly code:\n";
    generateAssembly(expression, 2);

    // Generating three-address assembly code
    cout << "\nGenerating three-address assembly code:\n";
    generateAssembly(expression, 3);

    return 0;
}
