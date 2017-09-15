/*
 * Your License or Copyright can go here
 */

#include "ArchiveToolboxFilter.h"

#include "SIMPLib/Common/Constants.h"



#include "ArchiveToolbox/ArchiveToolboxConstants.h"
#include "ArchiveToolbox/ArchiveToolboxVersion.h"

// Include the MOC generated file for this class
#include "moc_ArchiveToolboxFilter.cpp"

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
ArchiveToolboxFilter::ArchiveToolboxFilter() :
  AbstractFilter()
{
  initialize();
  setupFilterParameters();
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
ArchiveToolboxFilter::~ArchiveToolboxFilter()
{
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void ArchiveToolboxFilter::initialize()
{
  setErrorCondition(0);
  setWarningCondition(0);
  setCancel(false);
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void ArchiveToolboxFilter::setupFilterParameters()
{
  FilterParameterVector parameters;

  setFilterParameters(parameters);
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void ArchiveToolboxFilter::dataCheck()
{
  setErrorCondition(0);
  setWarningCondition(0);
  
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void ArchiveToolboxFilter::preflight()
{
  // These are the REQUIRED lines of CODE to make sure the filter behaves correctly
  setInPreflight(true); // Set the fact that we are preflighting.
  emit preflightAboutToExecute(); // Emit this signal so that other widgets can do one file update
  emit updateFilterParameters(this); // Emit this signal to have the widgets push their values down to the filter
  dataCheck(); // Run our DataCheck to make sure everthing is setup correctly
  emit preflightExecuted(); // We are done preflighting this filter
  setInPreflight(false); // Inform the system this filter is NOT in preflight mode anymore.
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void ArchiveToolboxFilter::execute()
{
  initialize();
  dataCheck();
  if(getErrorCondition() < 0) { return; }

  if (getCancel() == true) { return; }

  if (getWarningCondition() < 0)
  {
    QString ss = QObject::tr("Some warning message");
    setWarningCondition(-88888888);
    notifyWarningMessage(getHumanLabel(), ss, getWarningCondition());
  }

  if (getErrorCondition() < 0)
  {
    QString ss = QObject::tr("Some error message");
    setErrorCondition(-99999999);
    notifyErrorMessage(getHumanLabel(), ss, getErrorCondition());
    return;
  }

  notifyStatusMessage(getHumanLabel(), "Complete");
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
AbstractFilter::Pointer ArchiveToolboxFilter::newFilterInstance(bool copyFilterParameters)
{
  ArchiveToolboxFilter::Pointer filter = ArchiveToolboxFilter::New();
  if(true == copyFilterParameters)
  {
    copyFilterParameterInstanceVariables(filter.get());
  }
  return filter;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
const QString ArchiveToolboxFilter::getCompiledLibraryName()
{ return ArchiveToolboxConstants::ArchiveToolboxBaseName; }

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
const QString ArchiveToolboxFilter::getBrandingString()
{
  return "ArchiveToolbox";
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
const QString ArchiveToolboxFilter::getFilterVersion()
{
  QString version;
  QTextStream vStream(&version);
  vStream <<  ArchiveToolbox::Version::Major() << "." << ArchiveToolbox::Version::Minor() << "." << ArchiveToolbox::Version::Patch();
  return version;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
const QString ArchiveToolboxFilter::getGroupName()
{ return SIMPL::FilterGroups::Unsupported; }

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
const QString ArchiveToolboxFilter::getSubGroupName()
{ return "ArchiveToolbox"; }

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
const QString ArchiveToolboxFilter::getHumanLabel()
{ return "ArchiveToolboxFilter"; }

