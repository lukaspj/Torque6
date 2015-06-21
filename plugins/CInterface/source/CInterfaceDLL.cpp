#include "CInterfaceDLL.h"

#include "sim/simObject.h"

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