#include "CInterfaceDLL.h"

using namespace Plugins;
PluginLink Plugins::Link;

// Called when the plugin is loaded.
void create(PluginLink _link)
{
   Link = _link;
}

void destroy()
{
}

SimObject* SimFindObject(int id)
{
   return Sim::findObject(id);
}

SimObjectPtr<SimObject>* SimFindObjectWrapper(int id)
{
   return new SimObjectPtr<SimObject>(Sim::findObject(id));
}