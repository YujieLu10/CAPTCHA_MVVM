#include<ViewModel\Commands\recognizeCommand.h>
#include<ViewModel\ViewModel.h>

recognizeCommand::recognizeCommand(ViewModel* p) : pvm(p) {}

void recognizeCommand::exec() {
	//shared_ptr<StringParam> sp = static_pointer_cast<StringParam, Param>(params);
	//pvm->loadPicture(sp->getPath());
}
void recognizeCommand::setParams(const shared_ptr<Param>& p) {
	params = p;
}