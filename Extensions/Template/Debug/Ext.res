        ��  ��                  �      �� ��     0 	        �4   V S _ V E R S I O N _ I N F O     ���                   !                       S t r i n g F i l e I n f o   �   0 4 0 9 0 4 e 4   4 
  C o m p a n y N a m e     C l i c k t e a m   @   F i l e D e s c r i p t i o n     E d i f   O b j e c t   *   F i l e V e r s i o n     2 . 0 0     0   I n t e r n a l N a m e   E d i f E x t   Z   L e g a l C o p y r i g h t   C o p y r i g h t   �   2 0 1 2   C l i c k t e a m     @   O r i g i n a l F i l e n a m e   E d i f E x t . m f x   :   P r o d u c t V e r s i o n   1 ,   0 ,   0 ,   1     2 	  S p e c i a l B u i l d   0 0 0 0 0 0 0 1     D    V a r F i l e I n f o     $    T r a n s l a t i o n     	�       ��
 ���     0 	        %Y�  (   E D I F   ��e       0 	        �PNG

   IHDR           ���   tRNS      n��  �IDATx���;N1���̢P �%�A9G�"�Ѣ� q�G��3�����)�+
gv���I<�({��a{2EYa /W��_>�*��OXҎ(>*,��� "��^;�ԱQgy�,��N���^c������H�98:����eHa�����Z"r���Ώ��k"z����{fV_Ew �%W�m�f!�HKQ@�яal~�+���():ֶD���������}���T��q�z���~8#�5(F{r�`6_�jw �rr����3�2�8�"�2c:y�>�m�}>2F]8�lTQ�urZ~h��*���H��N���+�	�>*�������"�òo!� Qۻ?�vrZb��U��A�1�G'S<�C��� Ug{@�j������{����h    IEND�B`�     (   E D I F   ��f       0 	        {
    "About": {
        "Name": "Xable Object",
        "Author": "Samuel Benton",
        "Copyright": "Copyright (C) 2013 Xable Enterprises",
        "Comment": "An extension with various functions/abilities.",
        "URL": "http://www.xable.us/xable_object.html",
        "Help": "http://www.xable.us/xable_object.html",
        "Identifier": "PXMN"
    },
    "ActionMenu": 
	[
		"Separator",
		
		[0, "Set Object"],
		
		"Separator",
	],

    "ConditionMenu": 
	[
		"Separator",

		[0, "Custom Comment Text (Always True)"],
		[1, "Custom Comment Text (Always False)"],
		
		"Separator",
	],
    "ExpressionMenu": [

		"Separator",
	
		["Numerical Expressions",

			[0,"X mod Y"],
		
			[1, "Convert x into base y"],

			[2, "Find Nth Prime Number"],

		],

		"Separator",

		[-1, "Xable Enterprises", true],

		"Separator",

    ],
    "Actions": 
	[
		{"Title": "Set object to %0"}		
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
        
    ]
}   &       �� ��     0	           M F 2                               