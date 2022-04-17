//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class MyThread2 : public TThread
{
private:
    class MyThread *myThreadPtr;
protected:
	void __fastcall Execute();
public:
	__fastcall MyThread2(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
