// 17% faster pixel setting for text ...
// helper for display_text_len_clip
asm volatile (
	"jmp *JumpDC(,%2,4)\n\t"
	"ud2\n\t"
	".p2align 4\n"
"JumpDC:\n\t"
	".long .DCende\n\t"
	".long L9901\n\t"
	".long L9902\n\t"
	".long L9903\n\t"
	".long L9904\n\t"
	".long L9905\n\t"
	".long L9906\n\t"
	".long L9907\n\t"
	".long L9908\n\t"
	".long L9909\n\t"
	".long L990a\n\t"
	".long L990b\n\t"
	".long L990c\n\t"
	".long L990d\n\t"
	".long L990e\n\t"
	".long L990f\n\t"
	".long L9910\n\t"
	".long L9911\n\t"
	".long L9912\n\t"
	".long L9913\n\t"
	".long L9914\n\t"
	".long L9915\n\t"
	".long L9916\n\t"
	".long L9917\n\t"
	".long L9918\n\t"
	".long L9919\n\t"
	".long L991a\n\t"
	".long L991b\n\t"
	".long L991c\n\t"
	".long L991d\n\t"
	".long L991e\n\t"
	".long L991f\n\t"
	".long L9920\n\t"
	".long L9921\n\t"
	".long L9922\n\t"
	".long L9923\n\t"
	".long L9924\n\t"
	".long L9925\n\t"
	".long L9926\n\t"
	".long L9927\n\t"
	".long L9928\n\t"
	".long L9929\n\t"
	".long L992a\n\t"
	".long L992b\n\t"
	".long L992c\n\t"
	".long L992d\n\t"
	".long L992e\n\t"
	".long L992f\n\t"
	".long L9930\n\t"
	".long L9931\n\t"
	".long L9932\n\t"
	".long L9933\n\t"
	".long L9934\n\t"
	".long L9935\n\t"
	".long L9936\n\t"
	".long L9937\n\t"
	".long L9938\n\t"
	".long L9939\n\t"
	".long L993a\n\t"
	".long L993b\n\t"
	".long L993c\n\t"
	".long L993d\n\t"
	".long L993e\n\t"
	".long L993f\n\t"
	".long L9940\n\t"
	".long L9941\n\t"
	".long L9942\n\t"
	".long L9943\n\t"
	".long L9944\n\t"
	".long L9945\n\t"
	".long L9946\n\t"
	".long L9947\n\t"
	".long L9948\n\t"
	".long L9949\n\t"
	".long L994a\n\t"
	".long L994b\n\t"
	".long L994c\n\t"
	".long L994d\n\t"
	".long L994e\n\t"
	".long L994f\n\t"
	".long L9950\n\t"
	".long L9951\n\t"
	".long L9952\n\t"
	".long L9953\n\t"
	".long L9954\n\t"
	".long L9955\n\t"
	".long L9956\n\t"
	".long L9957\n\t"
	".long L9958\n\t"
	".long L9959\n\t"
	".long L995a\n\t"
	".long L995b\n\t"
	".long L995c\n\t"
	".long L995d\n\t"
	".long L995e\n\t"
	".long L995f\n\t"
	".long L9960\n\t"
	".long L9961\n\t"
	".long L9962\n\t"
	".long L9963\n\t"
	".long L9964\n\t"
	".long L9965\n\t"
	".long L9966\n\t"
	".long L9967\n\t"
	".long L9968\n\t"
	".long L9969\n\t"
	".long L996a\n\t"
	".long L996b\n\t"
	".long L996c\n\t"
	".long L996d\n\t"
	".long L996e\n\t"
	".long L996f\n\t"
	".long L9970\n\t"
	".long L9971\n\t"
	".long L9972\n\t"
	".long L9973\n\t"
	".long L9974\n\t"
	".long L9975\n\t"
	".long L9976\n\t"
	".long L9977\n\t"
	".long L9978\n\t"
	".long L9979\n\t"
	".long L997a\n\t"
	".long L997b\n\t"
	".long L997c\n\t"
	".long L997d\n\t"
	".long L997e\n\t"
	".long L997f\n\t"
	".long L9980\n\t"
	".long L9981\n\t"
	".long L9982\n\t"
	".long L9983\n\t"
	".long L9984\n\t"
	".long L9985\n\t"
	".long L9986\n\t"
	".long L9987\n\t"
	".long L9988\n\t"
	".long L9989\n\t"
	".long L998a\n\t"
	".long L998b\n\t"
	".long L998c\n\t"
	".long L998d\n\t"
	".long L998e\n\t"
	".long L998f\n\t"
	".long L9990\n\t"
	".long L9991\n\t"
	".long L9992\n\t"
	".long L9993\n\t"
	".long L9994\n\t"
	".long L9995\n\t"
	".long L9996\n\t"
	".long L9997\n\t"
	".long L9998\n\t"
	".long L9999\n\t"
	".long L999a\n\t"
	".long L999b\n\t"
	".long L999c\n\t"
	".long L999d\n\t"
	".long L999e\n\t"
	".long L999f\n\t"
	".long L99a0\n\t"
	".long L99a1\n\t"
	".long L99a2\n\t"
	".long L99a3\n\t"
	".long L99a4\n\t"
	".long L99a5\n\t"
	".long L99a6\n\t"
	".long L99a7\n\t"
	".long L99a8\n\t"
	".long L99a9\n\t"
	".long L99aa\n\t"
	".long L99ab\n\t"
	".long L99ac\n\t"
	".long L99ad\n\t"
	".long L99ae\n\t"
	".long L99af\n\t"
	".long L99b0\n\t"
	".long L99b1\n\t"
	".long L99b2\n\t"
	".long L99b3\n\t"
	".long L99b4\n\t"
	".long L99b5\n\t"
	".long L99b6\n\t"
	".long L99b7\n\t"
	".long L99b8\n\t"
	".long L99b9\n\t"
	".long L99ba\n\t"
	".long L99bb\n\t"
	".long L99bc\n\t"
	".long L99bd\n\t"
	".long L99be\n\t"
	".long L99bf\n\t"
	".long L99c0\n\t"
	".long L99c1\n\t"
	".long L99c2\n\t"
	".long L99c3\n\t"
	".long L99c4\n\t"
	".long L99c5\n\t"
	".long L99c6\n\t"
	".long L99c7\n\t"
	".long L99c8\n\t"
	".long L99c9\n\t"
	".long L99ca\n\t"
	".long L99cb\n\t"
	".long L99cc\n\t"
	".long L99cd\n\t"
	".long L99ce\n\t"
	".long L99cf\n\t"
	".long L99d0\n\t"
	".long L99d1\n\t"
	".long L99d2\n\t"
	".long L99d3\n\t"
	".long L99d4\n\t"
	".long L99d5\n\t"
	".long L99d6\n\t"
	".long L99d7\n\t"
	".long L99d8\n\t"
	".long L99d9\n\t"
	".long L99da\n\t"
	".long L99db\n\t"
	".long L99dc\n\t"
	".long L99dd\n\t"
	".long L99de\n\t"
	".long L99df\n\t"
	".long L99e0\n\t"
	".long L99e1\n\t"
	".long L99e2\n\t"
	".long L99e3\n\t"
	".long L99e4\n\t"
	".long L99e5\n\t"
	".long L99e6\n\t"
	".long L99e7\n\t"
	".long L99e8\n\t"
	".long L99e9\n\t"
	".long L99ea\n\t"
	".long L99eb\n\t"
	".long L99ec\n\t"
	".long L99ed\n\t"
	".long L99ee\n\t"
	".long L99ef\n\t"
	".long L99f0\n\t"
	".long L99f1\n\t"
	".long L99f2\n\t"
	".long L99f3\n\t"
	".long L99f4\n\t"
	".long L99f5\n\t"
	".long L99f6\n\t"
	".long L99f7\n\t"
	".long L99f8\n\t"
	".long L99f9\n\t"
	".long L99fa\n\t"
	".long L99fb\n\t"
	".long L99fc\n\t"
	".long L99fd\n\t"
	".long L99fe\n\t"
	".long L99ff\n\t"
"L9901:\n\t"
	"addl $14, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9902:\n\t"
	"addl $12, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9903:\n\t"
	"addl $12, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9904:\n\t"
	"addl $10, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9905:\n\t"
	"addl $10, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9906:\n\t"
	"addl $10, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9907:\n\t"
	"addl $10, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9908:\n\t"
	"addl $8, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9909:\n\t"
	"addl $8, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L990a:\n\t"
	"addl $8, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L990b:\n\t"
	"addl $8, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L990c:\n\t"
	"addl $8, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L990d:\n\t"
	"addl $8, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L990e:\n\t"
	"addl $8, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L990f:\n\t"
	"addl $8, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9910:\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9911:\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9912:\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9913:\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9914:\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9915:\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9916:\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9917:\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9918:\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9919:\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L991a:\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L991b:\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L991c:\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L991d:\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L991e:\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L991f:\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9920:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9921:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $8, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9922:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9923:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9924:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9925:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9926:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9927:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9928:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9929:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L992a:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L992b:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L992c:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L992d:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L992e:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L992f:\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9930:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9931:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9932:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9933:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9934:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9935:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9936:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9937:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9938:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9939:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L993a:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L993b:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L993c:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L993d:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L993e:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L993f:\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9940:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9941:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $10, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9942:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $8, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9943:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $8, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9944:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9945:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9946:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9947:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9948:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9949:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L994a:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L994b:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L994c:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L994d:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L994e:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L994f:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9950:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9951:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9952:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9953:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9954:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9955:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9956:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9957:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9958:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9959:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L995a:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L995b:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L995c:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L995d:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L995e:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L995f:\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9960:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9961:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $8, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9962:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9963:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9964:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9965:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9966:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9967:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9968:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9969:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L996a:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L996b:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L996c:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L996d:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L996e:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L996f:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9970:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9971:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9972:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9973:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9974:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9975:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9976:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9977:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9978:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9979:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L997a:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L997b:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L997c:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L997d:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L997e:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L997f:\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9980:\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9981:\n\t"
	"stosw\n\t"
	"addl $12, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9982:\n\t"
	"stosw\n\t"
	"addl $10, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9983:\n\t"
	"stosw\n\t"
	"addl $10, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9984:\n\t"
	"stosw\n\t"
	"addl $8, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9985:\n\t"
	"stosw\n\t"
	"addl $8, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9986:\n\t"
	"stosw\n\t"
	"addl $8, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9987:\n\t"
	"stosw\n\t"
	"addl $8, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9988:\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9989:\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L998a:\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L998b:\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L998c:\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L998d:\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L998e:\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L998f:\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9990:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9991:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9992:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9993:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9994:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9995:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9996:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9997:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L9998:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L9999:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L999a:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L999b:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L999c:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L999d:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L999e:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L999f:\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99a0:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99a1:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $8, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99a2:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99a3:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99a4:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99a5:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99a6:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99a7:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99a8:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99a9:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99aa:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99ab:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99ac:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99ad:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99ae:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99af:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99b0:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99b1:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99b2:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99b3:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99b4:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99b5:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99b6:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99b7:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99b8:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99b9:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99ba:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99bb:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99bc:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99bd:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99be:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99bf:\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99c0:\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99c1:\n\t"
	"stosl\n\t"
	"addl $10, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99c2:\n\t"
	"stosl\n\t"
	"addl $8, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99c3:\n\t"
	"stosl\n\t"
	"addl $8, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99c4:\n\t"
	"stosl\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99c5:\n\t"
	"stosl\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99c6:\n\t"
	"stosl\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99c7:\n\t"
	"stosl\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99c8:\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99c9:\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99ca:\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99cb:\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99cc:\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99cd:\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99ce:\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99cf:\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99d0:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99d1:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99d2:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99d3:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99d4:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99d5:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99d6:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99d7:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99d8:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99d9:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99da:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99db:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99dc:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99dd:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99de:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99df:\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99e0:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99e1:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $8, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99e2:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99e3:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $6, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99e4:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99e5:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99e6:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99e7:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99e8:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99e9:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99ea:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99eb:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99ec:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99ed:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99ee:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99ef:\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99f0:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99f1:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $6, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99f2:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99f3:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $4, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99f4:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99f5:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99f6:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99f7:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99f8:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99f9:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $4, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99fa:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99fb:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"addl $2, %0\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99fc:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"jmp .DCende\n"
"L99fd:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"addl $2, %0\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99fe:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosw\n\t"
	"jmp .DCende\n"
"L99ff:\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosl\n\t"
	"stosl\n\t"
".DCende:\n\t"
	: "+D" (dst)
	: "a" (color2), "r" (dat)
	: "cc", "memory"
);
