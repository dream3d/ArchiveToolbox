/*
 * Your License or Copyright can go here
 */

#include "ArchiveToolboxPlugin.h"

#include <QtCore/QFile>
#include <QtCore/QFileInfo>

#include "SIMPLib/Common/FilterManager.h"
#include "SIMPLib/Common/IFilterFactory.hpp"
#include "SIMPLib/Common/FilterFactory.hpp"

#include "ArchiveToolbox/ArchiveToolboxConstants.h"

// Include the MOC generated file for this class
#include "moc_ArchiveToolboxPlugin.cpp"

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
ArchiveToolboxPlugin::ArchiveToolboxPlugin() :
m_Version("0.1.0"),                            // Initialize ArchiveToolbox's Version Number Here
m_CompatibilityVersion("0.1.0"), // Initialize ArchiveToolbox's Compatibility Version Number Here
m_Vendor("Vendor Name"),                                // Initialize ArchiveToolbox's Vendor Name Here
m_URL("URL"),                                           // Initialize Company URL Here
m_Location("Location"),                                 // Initialize ArchiveToolbox library Location Here
m_Description("Description"),                           // Initialize ArchiveToolbox's Description Here
m_Copyright("Copyright"),                               // Initialize ArchiveToolbox's Copyright Here
m_Filters(QList<QString>()),                        // Initialize ArchiveToolbox's List of Dependencies Here
m_DidLoad(false)
{

}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
ArchiveToolboxPlugin::~ArchiveToolboxPlugin()
{
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString ArchiveToolboxPlugin::getPluginName()
{
  return (ArchiveToolboxConstants::ArchiveToolboxPluginDisplayName);
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString ArchiveToolboxPlugin::getVersion()
{
  return m_Version;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString ArchiveToolboxPlugin::getCompatibilityVersion()
{
  return m_CompatibilityVersion;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString ArchiveToolboxPlugin::getVendor()
{
  return m_Vendor;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString ArchiveToolboxPlugin::getURL()
{
  return m_URL;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString ArchiveToolboxPlugin::getLocation()
{
  return m_Location;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString ArchiveToolboxPlugin::getDescription()
{
  /* PLEASE UPDATE YOUR PLUGIN'S DESCRIPTION FILE.
  It is located at ArchiveToolbox/Resources/ArchiveToolbox/ArchiveToolboxDescription.txt */

  QFile licenseFile(":/ArchiveToolbox/ArchiveToolboxDescription.txt");
  QFileInfo licenseFileInfo(licenseFile);
  QString text = "<<--Description was not read-->>";

  if ( licenseFileInfo.exists() )
  {
    if ( licenseFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
      QTextStream in(&licenseFile);
      text = in.readAll();
    }
  }
  return text;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString ArchiveToolboxPlugin::getCopyright()
{
  return m_Copyright;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QString ArchiveToolboxPlugin::getLicense()
{
  /* PLEASE UPDATE YOUR PLUGIN'S LICENSE FILE.
  It is located at ArchiveToolbox/Resources/ArchiveToolbox/ArchiveToolboxLicense.txt */

  QFile licenseFile(":/ArchiveToolbox/ArchiveToolboxLicense.txt");
  QFileInfo licenseFileInfo(licenseFile);
  QString text = "<<--License was not read-->>";

  if ( licenseFileInfo.exists() )
  {
    if ( licenseFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
      QTextStream in(&licenseFile);
      text = in.readAll();
    }
  }
  return text;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
QMap<QString, QString> ArchiveToolboxPlugin::getThirdPartyLicenses()
{
  QMap<QString, QString> licenseMap;
  QList<QString> fileStrList;
  fileStrList.push_back(":/ThirdParty/HDF5.txt");
  fileStrList.push_back(":/ThirdParty/Boost.txt");
  fileStrList.push_back(":/ThirdParty/Qt.txt");
  fileStrList.push_back(":/ThirdParty/Qwt.txt");

  for (QList<QString>::iterator iter = fileStrList.begin(); iter != fileStrList.end(); iter++)
  {
    QFile file(*iter);
    QFileInfo licenseFileInfo(file);

    if ( licenseFileInfo.exists() )
    {
      if ( file.open(QIODevice::ReadOnly | QIODevice::Text) )
      {
        QTextStream in(&file);
        licenseMap.insert(licenseFileInfo.baseName(), in.readAll());
      }
    }
  }

  return licenseMap;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
bool ArchiveToolboxPlugin::getDidLoad()
{
  return m_DidLoad;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void ArchiveToolboxPlugin::setDidLoad(bool didLoad)
{
  m_DidLoad = didLoad;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void ArchiveToolboxPlugin::setLocation(QString filePath)
{
  m_Location = filePath;
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void ArchiveToolboxPlugin::writeSettings(QSettings& prefs)
{
}

// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void ArchiveToolboxPlugin::readSettings(QSettings& prefs)
{
}

#include "ArchiveToolboxFilters/RegisterKnownFilters.cpp"

#include "FilterParameterWidgets/RegisterKnownFilterParameterWidgets.cpp"

