
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

	LPRDATA HandlerObject;


	/*  Add any data you want to store in your extension to this class
        (eg. what you'd normally store in rdPtr)

        Unlike rdPtr, you can store real C++ objects with constructors
        and destructors, without having to call them manually or store
        a pointer.
    */

    // int MyVariable;




    /*  Add your actions, conditions and expressions as real class member
        functions here. The arguments (and return type for expressions) must
        match EXACTLY what you defined in the JSON.

        Remember to link the actions, conditions and expressions to their
        numeric IDs in the class constructor (Extension.cpp)
    */

    // Expressions
        unsigned int Modulus(int x, int y);
		TCHAR * BaseConversionString(int number, int base);
		long FindPrime(int number,  int nth_number);

		byte Sign(double number);
		int EventNum();
		float ObjectAngle();
		int ObjectX();
		int ObjectY();

		int IntBitFlagOn(int number, int bit_index);
		int IntBitFlagOff(int number, int bit_index);
		int IntBitFlagToggle(int number, int bit_index);

	// Actions
		void ActionComment(TCHAR * message);

		void SetObject(LPRDATA ffobject);
		void IncrementX(int deltaX);
		void IncrementY(int deltaY);
		void ChangeAngle(float deltaAngle);
		void ObjectChanged();

		void ExpressionComment(TCHAR * message);
		void ClearObject();

	// Conditions 

		bool TrueCondition(TCHAR * message);
		bool FalseCondition(TCHAR * message);
		bool FlagStatus(int number, int flag_index);
		bool BadObject();
		bool BadObjectTest();

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