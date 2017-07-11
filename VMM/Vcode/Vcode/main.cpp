#include<ViewModel/ViewModel.h>
#include<Model/Model.h>

int main(int argc, char *argv[])
{
	
	shared_ptr<Model> pm(new Model);
	shared_ptr<ViewModel> pvm(new ViewModel());
	pvm->setModel(pm);
	
}

