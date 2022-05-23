#define TMRUNTIME_API extern "C" __declspec(dllexport)
typedef struct tagSYSFEEDBACK
{
	int iResponseCode;
	bool bMsgAvailable;
	TCHAR szMsg[256];
}SYSFEEDBACK, *PSYSFEEDBACK;

typedef struct tagSYSTEMINPUT
{
	int id;
	int iType;
	double dValue;
	TCHAR szName[100];
	double* pdValue;
}SYSTEMINPUT, *PSYSTEMINPUT;

typedef struct tagSYSTEMOUTPUT
{
	int id;
	int iType;
	double dValue;
	TCHAR szName[100];
	double* pdValue;
	int iCountValues;
}SYSTEMOUTPUT, *PSYSTEMOUTPUT;

#define INPUTTYPE_INT 0
#define INPUTTYPE_DOUBLE 1
#define INPUTTYPE_ARRAY 2
#define INPUTTYPE_STRING 3

#define OUTPUTTYPE_INT 0
#define OUTPUTTYPE_DOUBLE 1
#define OUTPUTTYPE_ARRAY 2
#define OUTPUTTYPE_STRING 3

#define ARRAYTYPE_DOUBLE 10
#define ARRAYTYPE_INT 12

#define TMLOADERROR_SUCCESS 1
#define TMLOADERROR_NOTENOUGHMEMORY 2
#define TMLOADERROR_PERMISSIONDENIED 4
#define TMLOADERROR_FILENOTFOUND 8
#define TMLOADERROR_FILEREAD 32
#define TMLOADERROR_UNKNOWN 64

#define THEERRORCODE_SUCCESS 0
#define THEERRORCODE_NOSYSTEMLOADED -1
#define THEERRORCODE_SYSTEMITEM_NOTFOUND -2

TMRUNTIME_API double tmAISystem_GetVersion(void);
TMRUNTIME_API int tmAISystem_Load(const char* szFileName, int idAISystem , PSYSFEEDBACK pFeedback);
TMRUNTIME_API int tmAISystem_Unload(int idAISytem);
TMRUNTIME_API int tmAISystem_Execute(int idAISystem);
TMRUNTIME_API int tmAISystem_SetValue(int idAISytem, int idInput, double dValue);
TMRUNTIME_API int tmAISystem_SetArrayValues(int idAISystem, int idInput, double* pdValues, int iCountValues);
TMRUNTIME_API int tmAISystem_GetCountSystemInputs(int idAISystem);
TMRUNTIME_API int tmAISystem_GetCountSystemOutputs(int idAISystem);
TMRUNTIME_API int tmAISystem_GetSystemInputInfo( int idAISystem, int idInput, PSYSTEMINPUT pInputOUT);
TMRUNTIME_API int tmAISystem_GetSystemInputValue( int idAISystem, int idInput, double* pdValue);
TMRUNTIME_API int tmAISystem_GetSystemOutputInfo( int idAISystem, int idOutput, PSYSTEMOUTPUT pOutputOUT);
TMRUNTIME_API int tmAISystem_GetSystemOutputValue( int idAISystem, int idOutput, double* pdValue);
TMRUNTIME_API int tmAISystem_GetAllSystemInputs(int idAISystem, PSYSTEMINPUT pInputsOUT);
TMRUNTIME_API int tmAISystem_GetAllSystemOutputs(int idAISystem, PSYSTEMOUTPUT pOutputsOUT);


