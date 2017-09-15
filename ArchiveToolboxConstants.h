/*
 * Your License should go here
 */
#ifndef _archivetoolboxconstants_h_
#define _archivetoolboxconstants_h_

#include <QtCore/QString>

/**
* @brief This namespace is used to define some Constants for the plugin itself.
*/
namespace ArchiveToolboxConstants
{
  const QString ArchiveToolboxPluginFile("ArchiveToolboxPlugin");
  const QString ArchiveToolboxPluginDisplayName("ArchiveToolboxPlugin");
  const QString ArchiveToolboxBaseName("ArchiveToolboxPlugin");

  namespace FilterGroups
  {
  	const QString ArchiveToolboxFilters("ArchiveToolbox");
  }
}

/**
* @brief Use this namespace to define any custom GUI widgets that collect FilterParameters
* for a filter. Do NOT define general reusable widgets here.
*/
namespace FilterParameterWidgetType
{
/* const QString SomeCustomWidget("SomeCustomWidget"); */
}
#endif
