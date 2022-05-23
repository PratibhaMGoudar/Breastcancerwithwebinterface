
// tumor1.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"	
#include "aib3runtime.h"

// Ctumor1App:
// See tumor1.cpp for the implementation of this class


class Ctumor2App : public CWinApp
{
public:
	Ctumor2App();

	// Overrides
public:
	virtual BOOL InitInstance();

	// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Ctumor2App theApp;