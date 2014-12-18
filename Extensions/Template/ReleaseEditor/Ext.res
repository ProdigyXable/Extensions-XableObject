        ��  ��                  �      �� ��     0 	        �4   V S _ V E R S I O N _ I N F O     ���                                           S t r i n g F i l e I n f o   �   0 4 0 9 0 4 e 4   4 
  C o m p a n y N a m e     C l i c k t e a m   @   F i l e D e s c r i p t i o n     E d i f   O b j e c t   *   F i l e V e r s i o n     2 . 0 0     0   I n t e r n a l N a m e   E d i f E x t   Z   L e g a l C o p y r i g h t   C o p y r i g h t   �   2 0 1 2   C l i c k t e a m     @   O r i g i n a l F i l e n a m e   E d i f E x t . m f x   :   P r o d u c t V e r s i o n   1 ,   0 ,   0 ,   1     2 	  S p e c i a l B u i l d   0 0 0 0 0 0 0 1     D    V a r F i l e I n f o     $    T r a n s l a t i o n     	�       ��
 ���     0 	        %Y�  (   E D I F   ��e       0 	        �PNG

   IHDR           ���   tRNS      n��  �IDATx���;N1���̢P �%�A9G�"�Ѣ� q�G��3�����)�+
gv���I<�({��a{2EYa /W��_>�*��OXҎ(>*,��� "��^;�ԱQgy�,��N���^c������H�98:����eHa�����Z"r���Ώ��k"z����{fV_Ew �%W�m�f!�HKQ@�яal~�+���():ֶD���������}���T��q�z���~8#�5(F{r�`6_�jw �rr����3�2�8�"�2c:y�>�m�}>2F]8�lTQ�urZ~h��*���H��N���+�	�>*�������"�òo!� Qۻ?�vrZb��U��A�1�G'S<�C��� Ug{@�j������{����h    IEND�B`�   �  (   E D I F   ��f       0 	        {
    "About": {
        "Name": "Xable Object",
        "Author": "Samuel Benton",
        "Copyright": "Copyright � 2014 Xable Enterprises",
        "Comment": "An extension with various functions/abilities.",
        "URL": "http://www.xable.us/xable-object.html",
        "Help": "http://www.xable.us/xable-object.html",
        "Identifier": "PXMN"
    },
    "ActionMenu": 
	[
		[0, "Custom Action Comment"],
		
		["Objects",
			[1, "Set internal object"],
			[2, "Change X Position"],
			[3, "Change Y Position"],
			[4, "Change Angle"],

			"Separator",

			[5, "Remove Current Object"],
		],
		
		"Separator",
	],

    "ConditionMenu": 
	[
		["Comments",
			[0, "Custom Conditional Comment (Always True)"],
			[1, "Custom Conditional Comment (Always False)"],
		],

		["Numerical Conditions",
			[2, "Check bit of number"],
			[5, "Check if number is prime"],
		],

		["Object Conditions",
			[3, "Bad Object Detected"],
			[4, "Is Object Bad?"],
		],
	],

    "ExpressionMenu": 
	[
		["Numerical Expressions",
			[0, "X mod Y"],
			[1, "Convert x into base y"],
			[2, "Find Nth prime number"],
			[4, "Find sign of number"],
			[11, "Calculate Factorial"],
			[12, "Calculate Fibonacci Number"],
		],

		["Boolean Flags",
			[6, "Turn bit within number On"],
			[7, "Turn bit within number Off"],
			[8, "Toggle bit within number"],
		],

		"Separator",

		["Comments",
			[3, "Expression Comment"],
		],

		["Objects",
			[5, "Object Angle"],
			[9, "Object X Position"],
			[10, "Object Y Position"],
		],

		"Separator",
		
    ],
    "Actions": 
	[
		{"Title": "%0",
			"Parameters":
			[
				["Text", "Custom Message"],
			],
		},
		{"Title": "Set %0 to internal object",
			"Parameters":
			[
				["Object", "Set internal object"],
			],
		},
		{"Title": "Change current object by %0 pixels horizontally",
			"Parameters":
			[
				["Integer", "Change in X-Position"],
			],
		},	
		{"Title": "Change current object by %0 pixels vertically",
			"Parameters":
			[
				["Integer", "Change in Y-Position"],
			],
		},	
		{"Title": "Rotate current object by %0 degrees",
			"Parameters":
			[
				["Float", "Change in angle"],
			],
		},
		{"Title": "Forget current object",
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
		{"Title": "%o Is current object a bad object?",
			"Triggered": false
		},
		{"Title": "%o Is %0 a prime number?",
			"Parameters":
			[
				["Integer", "Number"],
			],
			"Triggered": false
		},
	],



    "Expressions": [
        {"Title": "Modx(",
         "Returns": "Integer",
         "Parameters": 
			[
                ["Integer","First number"],
                ["Integer","Second number"],
            ]
        },
		{"Title": "Base(",
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
		{"Title": "Comment(",
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
                ["Integer","Flag/Int"],
				["Integer","Flag Index"],
            ]
        },
		{"Title": "FlagOff(",
         "Returns": "Integer",
         "Parameters": 
			[
                ["Integer","Flag/Int"],
				["Integer","Flag Index"],
            ]
        },
		{"Title": "FlagSwap(",
         "Returns": "Integer",
         "Parameters": 
			[
                ["Integer","Flag/Int"],
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
    ]
}   &       �� ��     0	           M F 2                               