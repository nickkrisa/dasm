#include "OpTabB.h"
#include <string>
#include <map>
#include <iostream>
using namespace std;

const struct OpTab::instr OpTab::insTab[]= {
    {"18", {"ADD", "3/4"}},
	{"58", {"ADDF", "3/4"}},
	{"90", {"ADDR", "2"}},
	{"40", {"AND", "3/4"}},
	{"B4", {"CLEAR", "2"}},
	{"28", {"COMP", "3/4"}},
	{"88", {"COMPF", "3/4"}},
	{"A0", {"COMPR", "2"}},
	{"24", {"DIV", "3/4"}},
	{"64", {"DIVF", "3/4"}},
	{"9C", {"DIVR", "2"}},
	{"C4", {"FIX", "1"}},
	{"C0", {"FLOAT", "1"}},
	{"F4", {"HIO", "1"}},
	{"3C", {"J", "3/4"}},
	{"30", {"JEQ", "3/4"}},
	{"34", {"JGT", "3/4"}},
	{"38", {"JLT", "3/4"}},
	{"48", {"JSUB", "3/4"}},
	{"00", {"LDA", "3/4"}},
	{"68", {"LDB", "3/4"}},
	{"50", {"LDCH", "3/4"}},
	{"70", {"LDF", "3/4"}},
	{"08", {"LDL", "3/4"}},
	{"6C", {"LDS", "3/4"}},
	{"74", {"LDT", "3/4"}},
	{"04", {"LDX", "3/4"}},
	{"D0", {"LPS", "3/4"}},
	{"20", {"MUL", "3/4"}},
	{"60", {"MULF", "3/4"}},
	{"98", {"MULR", "2"}},
	{"C8", {"NORM", "1"}},
	{"44", {"OR", "3/4"}},
	{"D8", {"RD", "3/4"}},
	{"AC", {"RMO", "2"}},
	{"4C", {"RSUB", "3/4"}},
	{"A4", {"SHIFTL", "2"}},
	{"A8", {"SHIFTR", "2"}},
	{"F0", {"SIO", "1"}},
	{"EC", {"SSK", "3/4"}},
	{"0C", {"STA", "3/4"}},
	{"78", {"STB", "3/4"}},
	{"54", {"STCH", "3/4"}},
	{"80", {"STF", "3/4"}},
	{"D4", {"STI", "3/4"}},
	{"14", {"STL", "3/4"}},
	{"7C", {"STS", "3/4"}},
	{"E8", {"STSW", "3/4"}},
	{"84", {"STT", "3/4"}},
	{"10", {"STX", "3/4"}},
	{"1C", {"SUB", "3/4"}},
	{"5C", {"SUBF", "3/4"}},
	{"94", {"SUBR", "2"}},
	{"B0", {"SVC", "2"}},
	{"E0", {"TD", "3/4"}},
	{"F8", {"TIO", "1"}},
	{"2C", {"TIX", "3/4"}},
	{"B8", {"TIXR", "2"}},
	{"DC", {"WD", "3/4"}}
};

OpTab::OpTab(){
	for (int i = 0; i < sizeof(insTab)/sizeof(instr); i++)
		mapTab[insTab[i].opcode] = insTab[i].data;
	
}


/*getInstr 
* takes in an opcode as a string and returns
* a pair (std::pair) of strings for the 
* mnemonic and the format
*/
pair<string, string> OpTab::getInstr(string op){
	pair<string, string> dataPair;
	instr i;
	i.data = mapTab[op];
	
	dataPair = std::make_pair(i.data.mnemonic, i.data.format);

	return dataPair;	
}

/*
int main(){
	OpTab optableInstance;
	
	string  opcodeExample = "B8";
	
	pair<string, string> opData;
	
	opData = optableInstance.getInstr(opcodeExample);
	cout << opData.first << endl;
	cout << opData.second << endl;

	
	return 0;
}
*/