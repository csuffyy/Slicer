/*=auto=========================================================================

  Portions (c) Copyright 2005 Brigham and Women's Hospital (BWH) All Rights Reserved.

  See Doc/copyright/copyright.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Program:   3D Slicer
  Module:    $RCSfile: vtkGradientAnisotropicDiffusionFilterGUI.h,v $
  Date:      $Date: 2006/03/19 17:12:29 $
  Version:   $Revision: 1.3 $

=========================================================================auto=*/
#ifndef __vtkCommandLineModuleGUI_h
#define __vtkCommandLineModuleGUI_h

#include "vtkSlicerBaseGUIWin32Header.h"
#include "vtkSlicerModuleGUI.h"

#include "vtkMRMLScene.h"
#include "vtkCommandLineModuleLogic.h"

#include "ModuleDescription.h"


class vtkSlicerNodeSelectorWidget;
//BTX
class ModuleWidgetMap;
//ETX

class VTK_COMMANDLINEMODULE_EXPORT vtkCommandLineModuleGUI : public vtkSlicerModuleGUI
{
public:
  static vtkCommandLineModuleGUI *New();
  vtkTypeMacro(vtkCommandLineModuleGUI,vtkSlicerModuleGUI);
  void PrintSelf(ostream& os, vtkIndent indent);

   // Description: Get/Set MRML node
  vtkGetObjectMacro (Logic, vtkCommandLineModuleLogic);
  vtkSetObjectMacro (Logic, vtkCommandLineModuleLogic);
  
  // Description: Get/Set MRML node
  vtkGetObjectMacro (CommandLineModuleNode, vtkMRMLCommandLineModuleNode);
  vtkSetObjectMacro (CommandLineModuleNode, vtkMRMLCommandLineModuleNode);

  // Description:
  // Create widgets
  virtual void BuildGUI ( );

  // Description:
  // Add obsereves to GUI widgets
  virtual void AddGUIObservers ( );
  
  // Description:
  // Remove obsereves to GUI widgets
  virtual void RemoveGUIObservers ( );

  // Description:
  // Remove obsereves to MRML node
  virtual void RemoveMRMLNodeObservers ( );

  // Description:
  // Remove obsereves to Logic
  virtual void RemoveLogicObservers ( );
  
  // Description:
  // Pprocess events generated by Logic
  virtual void ProcessLogicEvents ( vtkObject *caller, unsigned long event,
                                  void *callData ){};

  // Description:
  // Pprocess events generated by GUI widgets
  virtual void ProcessGUIEvents ( vtkObject *caller, unsigned long event,
                                  void *callData );

  // Description:
  // Pprocess events generated by MRML
  virtual void ProcessMRMLEvents ( vtkObject *caller, unsigned long event, 
                                  void *callData);
  // Description:
  // Describe behavior at module startup and exit.
  virtual void Enter ( ){};
  virtual void Exit ( ){};

  // Description:
  // Get/Set the ModuleDescription object
  const ModuleDescription& GetModuleDescription() const
    { return ModuleDescriptionObject; }
  void SetModuleDescription(const ModuleDescription& description);
//   vtkGetMacro(ModuleDescription, ModuleDescription);
//   vtkSetMacro(ModuleDescription, ModuleDescription);
  
  
private:
  vtkCommandLineModuleGUI();
  ~vtkCommandLineModuleGUI();
  vtkCommandLineModuleGUI(const vtkCommandLineModuleGUI&);
  void operator=(const vtkCommandLineModuleGUI&);

  // Description:
  // Updates GUI widgets based on parameters values in MRML node
  void UpdateGUI();

  // Description:
  // Updates parameters values in MRML node based on GUI widgets 
  void UpdateMRML();
  
  ModuleDescription ModuleDescriptionObject;  // Should this go in the mrml node?

  ModuleWidgetMap *InternalWidgetMap;

  
  vtkSlicerNodeSelectorWidget* CommandLineModuleNodeSelector;
  
  vtkCommandLineModuleLogic *Logic;
  vtkMRMLCommandLineModuleNode* CommandLineModuleNode;

};

#endif

