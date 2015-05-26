class Extension
{
public:

    LPRDATA rdPtr;
    LPRH    rhPtr;

    Edif::Runtime Runtime;

    static const int MinimumBuild = 251;
    static const int Version = 1;

    static const int OEFLAGS = 0;
    static const int OEPREFS = 0;
    
    static const int WindowProcPriority = 100;

    Extension(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr);
    ~Extension();

	// Custom variable for this object.
	LPRDATA HandlerObject;

	// Returns true if the stored object is still valid. It is not valid if the stored object equals its default value (rdPtr)
	// or if its relating object is about to be destroyed
	boolean IsObjectStillValid()
	{
		return (((LPRO)StoredObject)->roHo.hoFlags & HOF_DESTROYED) == false && StoredObject != rdPtr;
	}

	// Returns true if the MMFusion build is 280 or less (meaning is the product lower than Clickteam Fusion). 
	// Helps with diffculties within the rcAngle variable.
	boolean IsProductMMF2()
	{
		return (SDK->mV->mvGetVersion != NULL && (SDK->mV->mvGetVersion() & MMFBUILD_MASK) < 280);
	}

    // Expressions
        unsigned int Modulus(int x, int y);
		TCHAR * BaseConversionString(int number, int base);
		long FindPrime(int number,  int nth_number);

		byte Sign(double number);
		int EventNum();
		int ObjectAngle();
		int ObjectX();
		int ObjectY();
		int ObjectFixedValue();

		int IntBitFlagOn(int number, int bit_index);
		int IntBitFlagOff(int number, int bit_index);
		int IntBitFlagToggle(int number, int bit_index);
		int Factorial(int number);
		int FiboNumber(int number);


	// Actions
		void ActionComment(TCHAR * message);

		void SetObject(LPRDATA object);
		void SetObjectFixedValue(int fixedvalue);
		void IncrementX(int deltaX);
		void IncrementY(int deltaY);
		void ChangeAngle(int deltaAngle);
		void ObjectChanged();

		void ExpressionComment(TCHAR * message);
		void ClearObject();

	// Conditions 
		bool TrueCondition(TCHAR * message);
		bool FalseCondition(TCHAR * message);
		bool FlagStatus(int number, int flag_index);
		bool BadObject();
		bool BadObjectTest();
		bool PrimeTest(int number);

	// void SetObject(LPRO object);



    /* These are called if there's no function linked to an ID */

    void Action(int ID, LPRDATA rdPtr, long param1, long param2);
    long Condition(int ID, LPRDATA rdPtr, long param1, long param2);
    long Expression(int ID, LPRDATA rdPtr, long param);




    /*  These replace the functions like HandleRunObject that used to be
        implemented in Runtime.cpp. They work exactly the same, but they're
        inside the extension class.
    */

    short Handle();
    short Display();

    short Pause();
    short Continue();

    bool Save(HANDLE File);
    bool Load(HANDLE File);

};