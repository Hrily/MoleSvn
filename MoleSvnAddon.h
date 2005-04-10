///////////////////////////////////////////////////////////////////////////////
// Application : MoleSVN
// Package     : 
// File        : MoleSvnAddon.h
// Description : defines the MoleSvnAddon class, the skeleton of the addon
// Author      : cedric.bresson@artcoder.com
///////////////////////////////////////////////////////////////////////////////
#ifndef __MoleSvnAddon_h__
#define __MoleSvnAddon_h__

#include <KernelKit.h>
#include <StorageKit.h> 
#include <list>
#include "Config.h"
#include "Utils/MoleSvnResources.h"

class MoleSvnAddon
{
private:
	// -- Life-cycle ----------------------------------------------------------
	MoleSvnAddon();
	MoleSvnAddon(const MoleSvnAddon& addon);
		// Description : private constructor, to avoid bad call
	
public:
	static MoleSvnAddon* GetInstance();
		// Description : singleton accessor
		
	~MoleSvnAddon(); 	
		// Description : Destructor
		
	// -- Services ------------------------------------------------------------
	void SetParameters(const entry_ref& rCurrentDirectory, const std::list<entry_ref>& lstEntry);
		// Description : Constructor
		// Arguments   : rCurrentDirectory - the current directory
		//               lstEntry - The list of entry_ref that the user has selected
		// Remarks     : The parameters are those from the process_ref function
		
	void ShowMenu(BPoint point);
		// Description : show the menu
		// Remarks     : the content of the menu depends of the files selected by the user
		
	// -- Accessors -----------------------------------------------------------
	MoleSvnResources* GetResources();
		// Description : returns a pointer to the addon resources
	
private:

	// -- Misc ----------------------------------------------------------------
	image_id FindAddonImage();
		// Description : returns the current image_id of the addon
		// Remarks     : usefull to get the addon filename and retrieve ressource into this file 

	std::string GetAddonFilename();
		// Description : returns the addon filename
		// Remarks     : we must have this function to open ressource in the addon file, and the
		//               user can change the addon name (like for shortcut)
		
	entry_ref m_CurrentDirectory;
		// Description : entry_ref from where the user launchs the addon
		// Init        : By cons
		
	list<entry_ref> m_lstEntry;
		// Description : entry_ref list that the user has selected
		// Init        : By cons
	
	MoleSvnResources* m_pResources;
		// Description : pointer t the addon resource
		// Init        : By cons
		
	TRACE_CLASS (CC_APPLICATION);
};

#endif //__MoleSvnAddon_h__
