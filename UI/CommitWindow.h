///////////////////////////////////////////////////////////////////////////////
// Application : MoleSVN
// Package     : UI
// File        : CommitWindow.h
// Description : defines window which will display Commit parameters, like
//               URL repository, revision
// Author      : cedric.bresson@artcoder.com
///////////////////////////////////////////////////////////////////////////////
#ifndef __CommitWindow_h__
#define __CommitWindow_h__

#include "../Config.h"
#include "../Svn/SvnCommands.h"
#include "../Svn/SvnEntry.h"


#define BCLV_COMMIT 1

#include "../3rd/BCLV/ColumnTypes.h"

class CommitWindow : public BWindow
{
public:
	// -- Life-cycle ----------------------------------------------------------
	CommitWindow(Commit* pCmd);
		// Description : constructor
	
	virtual ~CommitWindow();
		// Description : destructor
		
	// -- Hooks ---------------------------------------------------------------
	virtual void MessageReceived(BMessage *message);

	// -- Misc ----------------------------------------------------------------
	int32 LoadEntries();
		// Description : create a new thread and load svn entries recursively 

private:
	void CreateView();
		// Description : build UI
		
	void AddItem(const SvnEntry* pEntry);
		// Description : add a new item to the CLV
		
	Commit* 	  		m_pCmd;
	BColumnListView*  	m_pFilesToCommitView;

	BTextView* 	  		m_pTextView;
	BTextControl* 		m_pLogin;
	BTextControl* 		m_pPassword;
	
	TRACE_CLASS (CC_APPLICATION);
};


#endif //__CommitWindow_h__

