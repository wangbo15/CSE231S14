
//
//  StaticAnalysisPass.cpp
//  
//
//  Created by Jules Testard on 22/05/2014.
//
//

/*
 * Note : use the errs() instead of std::cout in this file to output to the console (if your name is not mike and you don't have a fancy debugger that
 * took hours to install :).
 */
#include "PointerAnalysis.h"
/*
 * For basic static analysis, flow is just "assigned to top", which just means the basic string from the Flow general class will be top.
 * This method is expected to do much more when overloaded.
 */
Flow* PointerAnalysis::executeFlowFunction(Flow *in, Instruction* inst){
	//errs() << "Instruction Opcode : " << inst->getOpcode() << ", get name : " << inst->getOpcodeName() << "\n";
	PointerAnalysisFlow * output;
	switch(inst->getOpcode()) {
	case 28 : //store instruction
		output = executeStoreInst(in,inst);
		break;
	default:
		output = new PointerAnalysisFlow(PointerAnalysisFlow::TOP);
		break;
	}
	//errs() << "Instruction : " << *inst << ", Flow value : " << output->jsonString() << "\n";
	return output;
}


PointerAnalysisFlow* PointerAnalysis::executeStoreInst(Flow* in, Instruction* instruction) {
	PointerAnalysisFlow* f = new PointerAnalysisFlow();
//	StoreInst* store = dyn_cast<StoreInst>(instruction);
//	f->copy(in);
//	errs() << "Operand : " << store->getPointerOperand() << "\n";
	return f;
}

PointerAnalysis::PointerAnalysis(Function &F) : StaticAnalysis() {
	this->top = new PointerAnalysisFlow(PointerAnalysisFlow::TOP);//Should be changed by subclasses of Flow to an instance of the subclass
	this->bottom = new PointerAnalysisFlow(PointerAnalysisFlow::BOTTOM);//Should be changed by subclasses of Flow to an instance of the subclass
	this->functionName = F.getName();
	buildCFG(F);
}
