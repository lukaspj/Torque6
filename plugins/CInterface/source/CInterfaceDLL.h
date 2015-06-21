
#ifndef _PLUGINS_SHARED_H
#include <plugins/plugins_shared.h>
#endif

#ifndef _SIM_OBJECT_H_
#include <sim/simObject.h>
#endif

extern "C"
{
   PLUGIN_FUNC void create(Plugins::PluginLink _link);
   PLUGIN_FUNC void destroy();

   SimObject* SimFindObject(int id);
   SimObjectPtr<SimObject>* SimFindObjectWrapper(int id);
}