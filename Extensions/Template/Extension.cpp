
#include "Common.h"


///
/// EXTENSION CONSTRUCTOR/DESTRUCTOR
///

Extension::Extension(LPRDATA _rdPtr, LPEDATA edPtr, fpcob cobPtr)
    : rdPtr(_rdPtr), rhPtr(_rdPtr->rHo.hoAdRunHeader), Runtime(_rdPtr)
{
    /*
        Link all your action/condition/expression functions to their IDs to match the
        IDs in the JSON here
    */

	ClearObject();

	LinkExpression(0, Modulus);
	LinkExpression(1, BaseConversionString);
	LinkExpression(2, FindPrime);
	LinkExpression(3, ExpressionComment);
	LinkExpression(4, Sign);
	LinkExpression(5, ObjectAngle);
	LinkExpression(6, IntBitFlagOn);
	LinkExpression(7, IntBitFlagOff);
	LinkExpression(8, IntBitFlagToggle);
	LinkExpression(9, ObjectX);
	LinkExpression(10, ObjectY);
	LinkExpression(11, Factorial);
	LinkExpression(12, FiboNumber);
	LinkExpression(13, ObjectFixedValue);

	LinkAction(0, ActionComment);
	LinkAction(1, SetObject);
	LinkAction(2, ChangeX);
	LinkAction(3, ChangeY);
	LinkAction(4, ChangeAngle);
	LinkAction(5, ClearObject);
	LinkAction(6, SetObjectFixedValue);

	LinkCondition(0, TrueCondition);
	LinkCondition(1, FalseCondition);
	LinkCondition(2, FlagStatus);
	LinkCondition(3, BadObject);
	LinkCondition(4, BadObjectTest);
	LinkCondition(5, PrimeTest);

    /*
        This is where you'd do anything you'd do in CreateRunObject in the original SDK

        It's the only place you'll get access to edPtr at runtime, so you should transfer
        anything from edPtr to the extension class here.
   
    */


    
}

Extension::~Extension()
{
    /*
        This is where you'd do anything you'd do in DestroyRunObject in the original SDK.
        (except calling destructors and other such atrocities, because that's automatic in Edif)
    */



}


short Extension::Handle()
{
	if( !IsObjectStillValid() )
	{
		ClearObject();
	}

    /*
       If your extension will draw to the MMF window you should first 
       check if anything about its display has changed :

           if (rdPtr->roc.rcChanged)
              return REFLAG_DISPLAY;
           else
              return 0;

       You will also need to make sure you change this flag yourself 
       to 1 whenever you want to redraw your object
     
       If your extension won't draw to the window, but it still needs 
       to do something every MMF loop use :

            return 0;

       If you don't need to do something every loop, use :

            return REFLAG_ONESHOT;

       This doesn't mean this function can never run again. If you want MMF
       to handle your object again (causing this code to run) use this function:

            Runtime.Rehandle();

       At the end of the loop this code will run

    */

	return 0;
}


short Extension::Display()
{
    /*
       If you return REFLAG_DISPLAY in Handle() this routine will run.
    */

    return 0;
}

short Extension::Pause()
{
    return 0;
}

short Extension::Continue()
{
    return 0;
}

bool Extension::Save(HANDLE File)
{
	bool OK = false;

    #ifndef VITALIZE

	    // Save the object's data here

	    OK = true;

    #endif

	return OK;
}

bool Extension::Load(HANDLE File)
{
	bool OK = false;

    #ifndef VITALIZE

	    // Load the object's data here

	    OK = true;

    #endif

	return OK;
}


// These are called if there's no function linked to an ID

void Extension::Action(int ID, LPRDATA rdPtr, long param1, long param2)
{

}

long Extension::Condition(int ID, LPRDATA rdPtr, long param1, long param2)
{
    return false;
}

long Extension::Expression(int ID, LPRDATA rdPtr, long param)
{
    return 0;
}

