// This is the main DLL file.

#pragma warning( disable : 4251)
#include "../../stdafx.h"

#include "../Headers/MarshalHelper.h"
#include "../Headers/ActionMapWrapper.h"
#include "../Headers/CollectionsWrapper.h"

using namespace System::Runtime::InteropServices;

IJWLayer::ActionMap::ActionMap()
   : SimObject(new EngineActionMap) { }

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets object pointer. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <returns>  null if it fails, else the object pointer. </returns>
///-------------------------------------------------------------------------------------------------

EngineActionMap* IJWLayer::ActionMap::GetObjectPtr()
{
   return static_cast<EngineActionMap*>(mObject);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Binds a key to a command. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">     The device. </param>
/// <param name="action">     The action. </param>
/// <param name="command">    The command. </param>
/// <param name="modifiers">  The modifiers. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::bind(String^ device, String^ action, String^ command, ...array<String^> ^modifiers)
{
   if (!IsAlive())
      return;
   const char* _device = (char*)Marshal::StringToHGlobalAnsi(device).ToPointer();
   const char* _action = (char*)Marshal::StringToHGlobalAnsi(action).ToPointer();
   const char* _command = (char*)Marshal::StringToHGlobalAnsi(command).ToPointer();

   pin_ptr<const char*> array_pin = &MarshalHelper::MarshalStringArrayToChar(modifiers, 3)[0];
   array_pin[0] = _device;
   array_pin[1] = _action;
   array_pin[2] = _command;
   GetObjectPtr()->processBind(modifiers->Length + 3, array_pin);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Bind a key to a method on an object. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">     The device. </param>
/// <param name="action">     The action. </param>
/// <param name="command">    The command. </param>
/// <param name="object">     [in,out] If non-null, the object. </param>
/// <param name="modifiers">  The modifiers. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::_bindObj(String^ device, String^ action, String^ command, EngineSimObject* object, ...array<String^> ^modifiers)
{
   if (!IsAlive())
      return;
   const char* _device = (char*)Marshal::StringToHGlobalAnsi(device).ToPointer();
   const char* _action = (char*)Marshal::StringToHGlobalAnsi(action).ToPointer();
   const char* _command = (char*)Marshal::StringToHGlobalAnsi(command).ToPointer();

   pin_ptr<const char*> array_pin = &MarshalHelper::MarshalStringArrayToChar(modifiers, 3)[0];
   array_pin[0] = _device;
   array_pin[1] = _action;
   array_pin[2] = _command;
   GetObjectPtr()->processBind(modifiers->Length + 3, array_pin, object);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Bind a key to a method on an object. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">     The device. </param>
/// <param name="action">     The action. </param>
/// <param name="command">    The command. </param>
/// <param name="object">     The object. </param>
/// <param name="modifiers">  The modifiers. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::bindObj(String^ device, String^ action, String^ command, SimObject ^object, ...array<String^> ^modifiers)
{
   if (!IsAlive())
      return;
   _bindObj(device, action, command, object->GetObjectPtr(), modifiers);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Bind a key to a method on an object. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">     The device. </param>
/// <param name="action">     The action. </param>
/// <param name="command">    The command. </param>
/// <param name="objID">      Identifier for the object. </param>
/// <param name="modifiers">  The modifiers. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::bindObj(String^ device, String^ action, String^ command, int objID, ...array<String^> ^modifiers)
{
   if (!IsAlive())
      return;
   EngineSimObject* obj = Sim::findObject(objID);
   _bindObj(device, action, command, obj, modifiers);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Bind a key to a command. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">     The device. </param>
/// <param name="action">     The action. </param>
/// <param name="makeCmd">    The make command. </param>
/// <param name="breakCmd">   The break command. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::bindCmd(String^ device, String^ action, String^ makeCmd, String^ breakCmd)
{
   if (!IsAlive())
      return;
   const char* _device = (char*)Marshal::StringToHGlobalAnsi(device).ToPointer();
   const char* _action = (char*)Marshal::StringToHGlobalAnsi(action).ToPointer();
   const char* _makeCmd = (char*)Marshal::StringToHGlobalAnsi(makeCmd).ToPointer();
   const char* _breakCmd = (char*)Marshal::StringToHGlobalAnsi(breakCmd).ToPointer();
   GetObjectPtr()->processBindCmd(_device, _action, _makeCmd, _breakCmd);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Unbinds a key. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">  The device. </param>
/// <param name="action">  The action. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::unbind(String^ device, String^ action)
{
   if (!IsAlive())
      return;
   const char* _device = (char*)Marshal::StringToHGlobalAnsi(device).ToPointer();
   const char* _action = (char*)Marshal::StringToHGlobalAnsi(action).ToPointer();
   GetObjectPtr()->processUnbind(_device, _action);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Unbind object from key. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">  The device. </param>
/// <param name="action">  The action. </param>
/// <param name="object">  [in,out] If non-null, the object. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::_unbindObj(String^ device, String^ action, EngineSimObject* object)
{
   if (!IsAlive())
      return;
   const char* _device = (char*)Marshal::StringToHGlobalAnsi(device).ToPointer();
   const char* _action = (char*)Marshal::StringToHGlobalAnsi(action).ToPointer();
   GetObjectPtr()->processUnbind(_device, _action, object);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Unbind object from key. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">     The device. </param>
/// <param name="action">     The action. </param>
/// <param name="objectID">   Identifier for the object. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::unbindObj(String^ device, String^ action, int objectID)
{
   if (!IsAlive())
      return;
   EngineSimObject* obj = Sim::findObject(objectID);
   _unbindObj(device, action, obj);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Unbind object from key. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">  The device. </param>
/// <param name="action">  The action. </param>
/// <param name="object">  The object. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::unbindObj(String^ device, String^ action, SimObject^ object)
{
   if (!IsAlive())
      return;
   _unbindObj(device, action, object->GetObjectPtr());
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Saves the ActionMap to a given file. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="fileName">   Filename of the file. </param>
/// <param name="append">     true to append. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::save(String^ fileName, bool append)
{
   if (!IsAlive())
      return;
   const char* _fileName = (char*)Marshal::StringToHGlobalAnsi(fileName).ToPointer();
   char buffer[1024];

   if (fileName)
   {
      if (Con::expandPath(buffer, sizeof(buffer), _fileName))
         _fileName = buffer;
   }

   GetObjectPtr()->dumpActionMap(_fileName, append);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Saves the ActionMap to a given file. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="fileName">   The file name to save. </param>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::save(String^ fileName)
{
   if (!IsAlive())
      return;
   save(fileName, false);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Saves this object to a file. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::save()
{
   if (!IsAlive())
      return;
   save(nullptr, false);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Pushes this ActionMap onto the ActionMap stack. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::push()
{
   if (!IsAlive())
      return;
   EngineSimSet* actionMapSet = Sim::getActiveActionMapSet();
   actionMapSet->pushObject(GetObjectPtr());
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Removes this ActionMap from the ActionMap stack. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///-------------------------------------------------------------------------------------------------

void IJWLayer::ActionMap::pop()
{
   if (!IsAlive())
      return;
   EngineSimSet* actionMapSet = Sim::getActiveActionMapSet();
   actionMapSet->removeObject(GetObjectPtr());
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the key that this command is bound to. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="command"> The command to search for. </param>
///
/// <returns>
///   Returns a string containing the binding as a field (TAB separated string), or nullptr if it
///   fails.
/// </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::ActionMap::getBinding(String^ command)
{
   if (!IsAlive())
      return nullptr;
   const char* _command = (char*)Marshal::StringToHGlobalAnsi(command).ToPointer();
   return gcnew String(GetObjectPtr()->getBinding(_command));
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Get the command that's bound to the given device and action. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">  The device. </param>
/// <param name="action">  The action. </param>
///
/// <returns>  nullptr if it fails, else the command. </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::ActionMap::getCommand(String^ device, String^ action)
{
   if (!IsAlive())
      return nullptr;
   const char* _device = (char*)Marshal::StringToHGlobalAnsi(device).ToPointer();
   const char* _action = (char*)Marshal::StringToHGlobalAnsi(action).ToPointer();
   return gcnew String(GetObjectPtr()->getCommand(_device, _action));
}

///-------------------------------------------------------------------------------------------------
/// <summary>
///   Use the isInverted method to determine if a specific device + action pair is inverted. This
///   only applies to scrolling devices. < / summary>
/// </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">  The device. </param>
/// <param name="action">  The action. </param>
///
/// <returns>  true if inverted, false if not. </returns>
///-------------------------------------------------------------------------------------------------

bool IJWLayer::ActionMap::isInverted(String^ device, String^ action)
{
   if (!IsAlive())
      return false;
   const char* _device = (char*)Marshal::StringToHGlobalAnsi(device).ToPointer();
   const char* _action = (char*)Marshal::StringToHGlobalAnsi(action).ToPointer();
   return GetObjectPtr()->isInverted(_device, _action);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets the scale associated with the device and action. </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">  The device. </param>
/// <param name="action">  The action. </param>
///
/// <returns>  The scale. </returns>
///-------------------------------------------------------------------------------------------------

float IJWLayer::ActionMap::getScale(String^ device, String^ action)
{
   if (!IsAlive())
      return -1;
   const char* _device = (char*)Marshal::StringToHGlobalAnsi(device).ToPointer();
   const char* _action = (char*)Marshal::StringToHGlobalAnsi(action).ToPointer();
   return GetObjectPtr()->getScale(_device, _action);
}

///-------------------------------------------------------------------------------------------------
/// <summary>  Gets dead zone . </summary>
///
/// <remarks>  Lukas, 24-03-2015. </remarks>
///
/// <param name="device">  The device. </param>
/// <param name="action">  The action. </param>
///
/// <returns>
///   nullptr if it fails, else dead-zone specification, or \0 0\ meaning that there is no dead-
///   zone.
/// </returns>
///-------------------------------------------------------------------------------------------------

String^ IJWLayer::ActionMap::getDeadZone(String^ device, String^ action)
{
   if (!IsAlive())
      return nullptr;
   const char* _device = (char*)Marshal::StringToHGlobalAnsi(device).ToPointer();
   const char* _action = (char*)Marshal::StringToHGlobalAnsi(action).ToPointer();
   return gcnew String(GetObjectPtr()->getDeadZone(_device, _action));
}