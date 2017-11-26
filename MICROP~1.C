#include <iostream>
#include <string>

using namespace std;

// This is the main stack that contains all the data
int mainStack[100];

// This is the A register in the CPU
int accumulator;

// The Opcode Functions
int write(int address, int mainStack[]){
	int userInput = 0;
	cin >> userInput;
	mainStack[address] = userInput;
	return 0;
}

int read(int address, int mainStack[]){
	return mainStack[address];
	//return 0;
}

int load(int address, int mainStack[]){
	accumulator = mainStack[address];
	return 0;
}

int store(int address, int mainStack[]){
	mainStack[address] = accumulator;
	return 0;
}

int add(int address, int mainStack[]){
	accumulator += mainStack[address];
	return 0;
}

int subtract(int address, int mainStack[]){
	int value = accumulator - mainStack[address];
	accumulator = value;
	return 0;
}

int divide(int address, int mainStack[]){
	int value = accumulator / mainStack[address];
	accumulator = value;
	return 0;
}

int multiply(int address, int mainStack[]){

	int value = accumulator * mainStack[address];
	accumulator = value;
	return 0;
}

// The Prompt to take input
int prompt() {
	int currentInstruction;
	int opcode ;
	int operand ;
	int val=0;
	int currentLine = 0;
	int op;
	while (true) {
		// 99 is the command to quit.
		cin >> opcode;
		if(opcode==99)
            break;
		cin >> operand;
        currentInstruction= opcode*100+operand;
		mainStack[currentLine] = currentInstruction;
		currentLine++;
	switch ( opcode ) {
		case 10:
		write(operand, mainStack);
			break;
		case 11:{
		val=read(operand, mainStack);
		op=operand;
			break;}
		case 20:
		load(operand, mainStack);
		break;

		case 21:
		store(operand, mainStack);
		break;

		case 30:
		add(operand, mainStack);
		break;

		case 31:
		subtract(operand, mainStack);
		break;

		case 32:
		divide(operand, mainStack);
		break;

		case 33:
		multiply(operand, mainStack);
		break;

		case 99: // END
		break;

		default:

		cout << "\n Please enter a valid Opcode \n";
		return 1;
		break;
	}
   }// End Of while
    cout<<"\n\t Executing the program .";
    for(long i=0;i<=100000000;i++) // Time delay Loop
    {
        if(i%20000000==0)
            cout<<".";
    }

    cout<<"\n\t Output Stored in "<<op<<": "<<val<<endl;
	return 0;
}


//Main Method
int main() {
	cout 		<< "-->  Welcome to Paradox Microprocessors \n"
				<< "-->  Please enter you program below \n"
				<< "-->  Enter an instruction or instruction plus data \n"
				<< "-->  the Memory size is of 100 bits. \n"
				<< "-->  10:WD   11:RD   20:LDA  21:STA  00-99:Available Memory\n"
				<< "-->  30:ADD  31:SUB  32:DIV  33:MUL  99:HLT\n";
	prompt();
	return 0;
}
