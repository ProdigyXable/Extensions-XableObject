        ��  ��                  �      �� ��     0 	        �4   V S _ V E R S I O N _ I N F O     ���                                           S t r i n g F i l e I n f o   �   0 4 0 9 0 4 e 4   4 
  C o m p a n y N a m e     C l i c k t e a m   @   F i l e D e s c r i p t i o n     E d i f   O b j e c t   *   F i l e V e r s i o n     2 . 0 0     0   I n t e r n a l N a m e   E d i f E x t   Z   L e g a l C o p y r i g h t   C o p y r i g h t   �   2 0 1 2   C l i c k t e a m     @   O r i g i n a l F i l e n a m e   E d i f E x t . m f x   :   P r o d u c t V e r s i o n   1 ,   0 ,   0 ,   1     2 	  S p e c i a l B u i l d   0 0 0 0 0 0 0 1     D    V a r F i l e I n f o     $    T r a n s l a t i o n     	�       ��
 ���     0 	        %Y�  (   E D I F   ��f       0 	        {
    "About": {
        "Name": "Xable Object",
        "Author": "Samuel Benton",
        "Copyright": "Copyright � 2014 - 2015 Xable Enterprises",
        "Comment": "An extension with various functions/abilities.",
        "URL": "http://www.xable.us/xable-object.html",
        "Help": "http://www.xable.us/xable-object.html",
        "Identifier": "PXMN"
    },
    "ActionMenu": 
	[
		[0, "Action Comment"],
		"Separator",
		["Object Storage",
			[1, "Store internal object via Object Picker"],
			[6, "Store internal object via Fixed Value"],
			"Separator",
			[5, "Forget Stored Object"],
		],
		["Object Manipulation",
			[4, "Change Stored Object's Angle"],
			[2, "Change Stored Object's X Position"],
			[3, "Change Stored Object's Y Position"],
		],
		"Separator"
	],

    "ConditionMenu": 
	[
		["Comments",
			[0, "Conditional Comment (Always True)"],
			[1, "Conditional Comment (Always False)"],
		],

		["Numerical Conditions",
			[2, "Check status of numerical bit"],
			[5, "Check if number is prime"],
		],

		["Object Conditions",
			[3, "Bad Object Detected"],
			"Separator",
			[4, "Is Object Bad?"],
		],

		["Cartesian Coordinate Conditions",
			[6, "Is Any Input Invalid?"],
		],
	],

    "ExpressionMenu": 
	[
		["Numerical Expressions",
			[0, "X mod Y"],
			[1, "Convert x into base y"],
			"Separator",
			[2, "Find Nth prime number"],
			"Separator",
			[4, "Find sign of number"],
			"Separator",
			[11, "Calculate Factorial"],
			[12, "Calculate Fibonacci Number"],
		],

		["Boolean Flags",
			[6, "Turn numerical bit On"],
			[7, "Turn numerical bit Off"],
			"Separator",
			[8, "Toggle numerical bit"],
		],

		"Separator",

		["Comments",
			[3, "Expression Comment"],
		],

		["Coordinate System Transformations",
			[16, "Get Cartesian Coordinate System X"],
			[17, "Get Cartesian Coordinate System Y"],
			"Separator",
			[14, "Get Polar Coordinate System Radius"],
			[15, "Get Polar Coordinate System Angle"],
		],

		["Objects",
			[5, "Retrieve Stored Object's Angle"],
			"Separator",
			[9, "Retrieve Stored Object's X Position"],
			[10, "Retrieve Stored Object's Y Position"],
			"Separator",
			[13, "Retrieve Stored Object's Fixed Value"],
		],		
    ],
    "Actions": 
	[
		{"Title": "%0",
			"Parameters":
			[
				["Text", "Custom Message"],
			],
		},
		{"Title": "Store %0 to internal object",
			"Parameters":
			[
				["Object", "Store internal object"],
			],
		},
		{"Title": "Change stored object by %0 pixels horizontally",
			"Parameters":
			[
				["Integer", "Change in X-Position"],
			],
		},	
		{"Title": "Change stored object by %0 pixels vertically",
			"Parameters":
			[
				["Integer", "Change in Y-Position"],
			],
		},	
		{"Title": "Rotate stored object by %0 degrees",
			"Parameters":
			[
				["Integer", "Change in angle"],
			],
		},
		{"Title": "Forget stored object",
		},
		{"Title": "Store object whose fixed value is %0",
			"Parameters":
			[
				["Integer", "Object's Fixed Value"],
			],
		},
	],

    "Conditions": 
	[
		{"Title": "%0 [True]",
		     "Parameters":
			[
				["Text","Custom Message"],
		    ],		
			"Triggered": false
		},
		{"Title": "%0 [False]",
		     "Parameters":
			[
				["Text","Custom Message"],
		    ],		
			"Triggered": false
		},
		{"Title": "%o Check bit %1 of %0",
			"Parameters":
			[
				["Integer", "Number"],
				["Integer", "Bit Index"],
			],
			"Triggered": false
		},
		{"Title": "%o Bad Object has been detected",
			"Triggered": true
		},
		{"Title": "%o Is stored object a bad object?",
			"Triggered": false
		},
		{"Title": "%o Is %0 a prime number?",
			"Parameters":
			[
				["Integer", "Number"],
			],
			"Triggered": false
		},
		{"Title": "%o Was an invalid input received?",
			"Triggered": true
		},
	],



    "Expressions": [
        {"Title": "Mod(",
         "Returns": "Integer",
         "Parameters": 
			[
                ["Integer","Dividend"],
                ["Integer","Divisor"],
            ]
        },
		
		{"Title": "Base$(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Integer","First number"],
                ["Integer","Second number"],
            ]
        },
		
		{"Title": "Prime(",
         "Returns": "Integer",
         "Parameters": 
			[
                ["Integer","Initial Number"],
                ["Integer","Nth following Prime Number"],
            ]
        },
		
		{"Title": "Comment$(",
         "Returns": "Text",
         "Parameters": 
			[
                ["Text","Comment message"],
            ]
        },
		
		{"Title": "Sign(",
         "Returns": "Integer",
         "Parameters": 
			[
                ["Integer","Number"],
            ]
        },
        
		{"Title": "ObjectAngle(",
         "Returns": "Float",
        },
		{"Title": "FlagOn(",
         "Returns": "Integer",
         "Parameters": 
			[
                ["Integer","Bitmask or Integer"],
				["Integer","Flag Index"],
            ]
        },
		
		{"Title": "FlagOff(",
         "Returns": "Integer",
         "Parameters": 
			[
                ["Integer","Bitmask or Integer"],
				["Integer","Flag Index"],
            ]
        },
		
		{"Title": "FlagSwap(",
         "Returns": "Integer",
         "Parameters": 
			[
                ["Integer","Bitmask or Integer"],
				["Integer","Flag Index"],
            ]
        },
		
		{"Title": "ObjectX(",
         "Returns": "Integer",
        },
		
		{"Title": "ObjectY(",
         "Returns": "Integer",
        },
		
		{"Title": "Factorial(",
         "Returns": "Integer",
		 "Parameters":
		 [
			["Integer","Positive Integer"],
		 ]
        },
		
		{"Title": "FiboNumber(",
         "Returns": "Integer",
		 "Parameters":
		 [
			["Integer","Fibonacci Index"],
		 ]
        },
		
		{"Title": "ObjectFixedValue(",
         "Returns": "Integer",
        },

		{"Title": "PolarRadius(",
         "Returns": "Float",
		 "Parameters":
		 [
			["Float","Cartesian X Coordinate"],
			["Float","Cartesian Y Coordinate"],
		 ]
        },

		{"Title": "PolarAngle(",
         "Returns": "Float",
		 "Parameters":
		 [
			["Float","Cartesian X Coordinate"],
			["Float","Cartesian Y Coordinate"],
		 ]
        },

		{"Title": "CartesianX(",
         "Returns": "Float",
		 "Parameters":
		 [
			["Float","Polar Radius Coordinate"],
			["Float","Polar Angle Coordinate"],
		 ]
        },

		{"Title": "CartesianY(",
         "Returns": "Float",
		 "Parameters":
		 [
			["Float","Polar Radius Coordinate"],
			["Float","Polar Angle Coordinate"],
		 ]
        },
    ]
}   &       �� ��     0	           M F 2                               