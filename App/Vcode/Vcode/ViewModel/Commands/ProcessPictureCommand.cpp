#include<ViewModel/Commands/ProcessPictureCommand.h>
#include<ViewModel/ViewModel.h>
ProcessPictureCommand::ProcessPictureCommand(ViewModel* p) :pvm(p){}
void ProcessPictureCommand::exec() {
	shared_ptr<GrayTypeParam> sp = static_pointer_cast<GrayTypeParam, Param>(params);
	pvm->processPicture(sp->getType());
}
void ProcessPictureCommand::setParams(const shared_ptr<Param>& p) {
	params = p;
}