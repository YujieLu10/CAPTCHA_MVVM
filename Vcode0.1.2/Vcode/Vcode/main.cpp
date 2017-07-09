#include"ViewModel.h"
#include"Model.h"
int main(int argc, char *argv[])
{
	
	Model m;
	ViewModel vm(&m);
	
	m.addObserver(&vm);

	system("pause");
}
