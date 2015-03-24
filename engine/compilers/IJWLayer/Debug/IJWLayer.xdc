<?xml version="1.0"?><doc>
<members>
<member name="D:S8" decl="false" source="e:\github\torque6\engine\source\torqueconfig.h" line="28">
Version number is major * 1000 + minor * 100 + revision * 10.
What's the name of your game? Used in a variety of places.
Human readable version string.
DSO version.
Used to suppress unused compiler warnings.
Profiler macros used when the profiler is disabled.
The following pre-processor definitions should be added to your compiler command-line
if you required their respective functionality:

'TORQUE_DEBUG'
Should be associated with a compiler un-optimized build.  Typically produces more
diagnostic engine output such as warnings/errors to the console.

'TORQUE_RELEASE'
Should be associated with a compiler optimized build.  Typically produces less
diagnostic engine output than the 'TORQUE_DEBUG' build.

'TORQUE_SHIPPING'
Should be associated with a compiler optimized build that you intend to ship.
Typically produces only the output that is useful (and available) for the
end-user to report.

'TORQUE_UNICODE'
When defined, enables unicode support.

'TORQUE_ENABLE_PROFILER'
When defined, Torque will capture performance profiling information that sacrifices
a small performance overhead to gain significant diagnostics information.

'TORQUE_DEBUG_NET'
When defined, Torque will enabled certain features that enabled diagnostics of
its networking sub-system.

'TORQUE_GATHER_METRICS'
When defined, Torque will gather additional performance metrics.

'TORQUE_MULTITHREAD'
When defined, Torque will attempt to make select systems thread-safe.  This does not
make the entire engine thread-safe nor is it a magic bullet that will make the engine
perform operations in parallel and speed-up the engine.
</member>
<member name="T:FileTime" decl="false" source="e:\github\torque6\engine\source\platform\types.win32.h" line="35">
Platform dependent file date-time structure.  The defination of this structure
  * will likely be different for each OS platform.

</member>
<member name="M:endianSwap(System.UInt16!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\platform\types.h" line="98">
Convert the byte ordering on the U16 to and from big/little endian format.
@param in_swap Any U16
@returns swaped U16.

</member>
<member name="M:endianSwap(System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\platform\types.h" line="109">
Convert the byte ordering on the U32 to and from big/little endian format.
@param in_swap Any U32
@returns swaped U32.

</member>
<member name="T:PlatformAssert" decl="true" source="e:\github\torque6\engine\source\platform\types.h" line="136">
Offset macro:
Calculates the location in memory of a given member x of class cls from the
start of the class.  Need several definitions to account for various
flavors of GCC.
</member>
<member name="M:Platform.init" decl="true" source="e:\github\torque6\engine\source\platform\platform.h" line="136">
Application.
</member>
<member name="M:Platform.getUserHomeDirectory" decl="true" source="e:\github\torque6\engine\source\platform\platform.h" line="146">
User.
</member>
<member name="M:Platform.initWindow(Point2I!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\platform\platform.h" line="150">
Window.
</member>
<member name="M:Platform.AlertOK(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\platform\platform.h" line="159">
GUI.
</member>
<member name="M:Platform.enableKeyboardTranslation" decl="true" source="e:\github\torque6\engine\source\platform\platform.h" line="166">
Input.
</member>
<!-- Discarding badly formed XML document comment for member 'M:Platform.getTime'. -->
<member name="M:Platform.getRandom" decl="true" source="e:\github\torque6\engine\source\platform\platform.h" line="179">
Math.
</member>
<member name="M:Platform.debugBreak" decl="true" source="e:\github\torque6\engine\source\platform\platform.h" line="182">
Debug.
</member>
<member name="M:Platform.getCurrentDirectory" decl="true" source="e:\github\torque6\engine\source\platform\platform.h" line="187">
File IO.
</member>
<member name="M:Platform.createUUID" decl="true" source="e:\github\torque6\engine\source\platform\platform.h" line="221">
Misc.
</member>
<member name="T:MutexHandle" decl="false" source="e:\github\torque6\engine\source\platform\threads\mutex.h" line="71">
Helper for simplifying mutex locking code.

This class will automatically unlock a mutex that you've
locked through it, saving you from managing a lot of complex
exit cases. For instance:

@code
MutexHandle handle;
handle.lock(myMutex);

if(error1)
  return; // Auto-unlocked by handle if we leave here - normally would
          // leave the mutex locked, causing much pain later.

handle.unlock();
@endcode
</member>
<member name="T:OverlapTestResult" decl="false" source="e:\github\torque6\engine\source\math\mconstants.h" line="45">
Result of an overlap test.
</member>
<member name="M:isPow2(System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="209">
Determines if the given U32 is some 2^n
@returns true if in_num is a power of two, otherwise false
</member>
<!-- Discarding badly formed XML document comment for member 'M:getMin(System.UInt32,System.UInt32)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMin(System.UInt16,System.UInt16)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMin(System.Byte,System.Byte)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMin(System.Int32,System.Int32)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMin(System.Int16,System.Int16)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMin(System.SByte,System.SByte)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMin(System.Single,System.Single)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMin(System.Double,System.Double)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMax(System.UInt32,System.UInt32)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMax(System.UInt16,System.UInt16)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMax(System.Byte,System.Byte)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMax(System.Int32,System.Int32)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMax(System.Int16,System.Int16)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMax(System.SByte,System.SByte)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMax(System.Single,System.Single)'. -->
<!-- Discarding badly formed XML document comment for member 'M:getMax(System.Double,System.Double)'. -->
<member name="T:Point2I" decl="false" source="e:\github\torque6\engine\source\math\mpoint.h" line="37">
2D integer point

Uses S32 internally.
</member>
<member name="T:Point3I" decl="false" source="e:\github\torque6\engine\source\math\mpoint.h" line="96">
3D integer point

Uses S32 internally.
</member>
<member name="T:Point2F" decl="false" source="e:\github\torque6\engine\source\math\mpoint.h" line="156">
2D floating-point point.
</member>
<member name="M:Point2F.interpolate(Point2F!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,Point2F!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single!System.Runtime.CompilerServices.IsConst)" decl="true" source="e:\github\torque6\engine\source\math\mpoint.h" line="176">
Interpolate from a to b, based on c.

@param   a   Starting point.
@param   b   Ending point.
@param   c   Interpolation factor (0.0 .. 1.0).
</member>
<member name="T:Point2D" decl="false" source="e:\github\torque6\engine\source\math\mpoint.h" line="236">
2D high-precision point.

Uses F64 internally.
</member>
<member name="M:Point2D.interpolate(Point2D!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,Point2D!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Double!System.Runtime.CompilerServices.IsConst)" decl="true" source="e:\github\torque6\engine\source\math\mpoint.h" line="258">
Interpolate from a to b, based on c.

@param   a   Starting point.
@param   b   Ending point.
@param   c   Interpolation factor (0.0 .. 1.0).
</member>
<member name="T:Point4F" decl="false" source="e:\github\torque6\engine\source\math\mpoint.h" line="466">
4D floating-point point.

Uses F32 internally.

Useful for representing quaternions and other 4d beasties.
</member>
<member name="M:Point4F.#ctor(System.Single!System.Runtime.CompilerServices.IsConst,System.Single!System.Runtime.CompilerServices.IsConst,System.Single!System.Runtime.CompilerServices.IsConst,System.Single!System.Runtime.CompilerServices.IsConst)" decl="true" source="e:\github\torque6\engine\source\math\mpoint.h" line="483">
Create point from coordinates.
</member>
<member name="M:Point4F.set(System.Single!System.Runtime.CompilerServices.IsConst,System.Single!System.Runtime.CompilerServices.IsConst,System.Single!System.Runtime.CompilerServices.IsConst,System.Single!System.Runtime.CompilerServices.IsConst)" decl="true" source="e:\github\torque6\engine\source\math\mpoint.h" line="486">
Set point's coordinates.
</member>
<member name="M:Point4F.interpolate(Point4F!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,Point4F!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single!System.Runtime.CompilerServices.IsConst)" decl="true" source="e:\github\torque6\engine\source\math\mpoint.h" line="489">
Interpolate from _pt1 to _pt2, based on _factor.

@param   _pt1    Starting point.
@param   _pt2    Ending point.
@param   _factor Interpolation factor (0.0 .. 1.0).
</member>
<member name="M:mRound(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="623">
Precision Rounding.
</member>
<member name="M:mIsNAN(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="626">
Is NAN?
</member>
<member name="M:mIsZero(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="629">
Tolerate Is Zero?
</member>
<member name="M:mNotZero(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="632">
Tolerate Not Zero?
</member>
<member name="M:mLessThan(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="635">
Tolerate Less-Than?
</member>
<member name="M:mGreaterThan(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="638">
Tolerate Greater-Than?
</member>
<member name="M:mLessThanZero(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="641">
Safe Less Than Zero?
</member>
<member name="M:mGreaterThanZero(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="644">
Safe Greater Than Zero?
</member>
<member name="M:mIsEqual(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="647">
Safe Is Equal?
</member>
<member name="M:mNotEqual(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="650">
Safe Not Equal?
</member>
<member name="M:mIsEqualRange(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="653">
Tolerate Is Equal within Range?
</member>
<member name="M:mIsOne(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="656">
Tolerate Is One?
</member>
<member name="M:mLessThanOrEqual(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="659">
Tolerate Less-Than or Equal?
</member>
<member name="M:mGreaterThanOrEqual(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="662">
Tolerate Greater-Than or Equal?
</member>
<member name="M:mGetMinMax(System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="665">
Get Min/Max.
</member>
<member name="M:mSwap(System.Single*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.Single*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="668">
Swap.
</member>
<member name="M:mSquared(System.Single)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="671">
Returns the input value squared.
</member>
<member name="M:mSquared(System.Double)" decl="false" source="e:\github\torque6\engine\source\math\mmathfn.h" line="677">
@copydoc mSquaredF
</member>
<member name="T:DataChunker" decl="true" source="e:\github\torque6\engine\source\memory\datachunker.h" line="31">
Implements a chunked data allocater.

Calling new/malloc all the time is a time consuming operation. Therefore,
we provide the DataChunker, which allocates memory in blockss of
chunkSize (by default 16k, see ChunkSize, though it can be set in
the constructor), then doles it out as requested, in chunks of up to
chunkSize in size.

It will assert if you try to get more than ChunkSize bytes at a time,
and it deals with the logic of allocating new blocks and giving out
word-aligned chunks.

Note that new/free/realloc WILL NOT WORK on memory gotten from the
DataChunker. This also only grows (you can call freeBlocks to deallocate
and reset things).
</member>
<member name="T:DataChunker.DataBlock" decl="false" source="e:\github\torque6\engine\source\memory\datachunker.h" line="55">
Block of allocated memory.

<b>This has nothing to do with datablocks as used in the rest of Torque.</b>
</member>
<member name="M:DataChunker.alloc(System.Int32)" decl="true" source="e:\github\torque6\engine\source\memory\datachunker.h" line="71">
Return a pointer to a chunk of memory from a pre-allocated block.

This memory goes away when you call freeBlocks.

This memory is word-aligned.
@param   size    Size of chunk to return. This must be less than chunkSize or else
                 an assertion will occur.
</member>
<member name="M:DataChunker.freeBlocks" decl="true" source="e:\github\torque6\engine\source\memory\datachunker.h" line="80">
Free all allocated memory blocks.

This invalidates all pointers returned from alloc().
</member>
<member name="M:DataChunker.#ctor(System.Int32)" decl="true" source="e:\github\torque6\engine\source\memory\datachunker.h" line="85">
Initialize using blocks of a given size.

One new block is allocated at constructor-time.

@param   size    Size in bytes of the space to allocate for each block.
</member>
<member name="T:_StringTable" decl="true" source="e:\github\torque6\engine\source\string\stringtable.h" line="37">
A global table for the hashing and tracking of strings.

Only one _StringTable is ever instantiated in Torque. It is accessible via the
global variable StringTable.

StringTable is used to manage strings in Torque. It performs the following tasks:
     - Ensures that only one pointer is ever used for a given string (through
       insert()).
     - Allows the lookup of a string in the table.

@code
// Adding a string to the StringTable.
StringTableEntry mRoot;
mRoot = StringTable-&gt;insert(root);

// Looking up a string in the StringTable.
StringTableEntry stName = StringTable-&gt;lookupn(name, len);

// Comparing two strings in the StringTable (see below).
if(mRoot == stName) Con::printf("These strings are equal!");
@endcode

<b>But why is this useful, you ask?</b> Because every string that's run through the
StringTable is stored once and only once, every string has one and only one
pointer mapped to it. As a pointer is an integer value (usually an unsigned int),
so we can do several neat things:
     - StringTableEntrys can be compared directly for equality, instead of using
       the time-consuming dStrcmp() or dStricmp() function.
     - For things like object names, we can avoid storing multiple copies of the
       string containing the name. The StringTable ensures that we only ever store
       one copy.
     - When we're doing lookups by name (for instances, of resources), we can determine
       if the object is even registered in the system by looking up its name in the
       StringTable. Then, we can use the pointer as a hash key.

 The scripting engine and the resource manager are the primary users of the
 StringTable.

@note Be aware that the StringTable NEVER DEALLOCATES memory, so be careful when you
      add strings to it. If you carelessly add many strings, you will end up wasting
      space.
</member>
<member name="T:_StringTable.Node" decl="false" source="e:\github\torque6\engine\source\string\stringtable.h" line="82">
@name Implementation details
@{
This is internal to the _StringTable class.
</member>
<member name="M:_StringTable.create" decl="true" source="e:\github\torque6\engine\source\string\stringtable.h" line="105">
@}
Initialize StringTable.

This is called at program start to initialize the StringTable global.
</member>
<member name="M:_StringTable.destroy" decl="true" source="e:\github\torque6\engine\source\string\stringtable.h" line="113">
Destroy the StringTable

This is called at program end to destroy the StringTable global.
</member>
<member name="M:_StringTable.insert(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Boolean)" decl="true" source="e:\github\torque6\engine\source\string\stringtable.h" line="118">
Get a pointer from the string table, adding the string to the table
if it was not already present.

@param  string   String to check in the table (and add).
@param  caseSens Determines whether case matters.
</member>
<member name="M:_StringTable.insertn(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Int32,System.Boolean)" decl="true" source="e:\github\torque6\engine\source\string\stringtable.h" line="125">
Get a pointer from the string table, adding the string to the table
if it was not already present.

@param  string   String to check in the table (and add).
@param  len      Length of the string in bytes.
@param  caseSens Determines whether case matters.
</member>
<member name="M:_StringTable.lookup(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Boolean)" decl="true" source="e:\github\torque6\engine\source\string\stringtable.h" line="133">
Get a pointer from the string table, NOT adding the string to the table
if it was not already present.

@param  string   String to check in the table (but not add).
@param  caseSens Determines whether case matters.
</member>
<member name="M:_StringTable.lookupn(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Int32,System.Boolean)" decl="true" source="e:\github\torque6\engine\source\string\stringtable.h" line="140">
Get a pointer from the string table, NOT adding the string to the table
if it was not already present.

@param  string   String to check in the table (but not add).
@param  len      Length of string in bytes.
@param  caseSens Determines whether case matters.
</member>
<member name="M:_StringTable.resize(System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="true" source="e:\github\torque6\engine\source\string\stringtable.h" line="149">
Resize the StringTable to be able to hold newSize items. This
is called automatically by the StringTable when the table is
full past a certain threshhold.

@param newSize   Number of new items to allocate space for.
</member>
<member name="M:_StringTable.hashString(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\string\stringtable.h" line="156">
Hash a string into a U32.
</member>
<member name="M:_StringTable.hashStringn(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="true" source="e:\github\torque6\engine\source\string\stringtable.h" line="159">
Hash a string of given length into a U32.
</member>
<member name="F:_StringTable.EmptyString" decl="false" source="e:\github\torque6\engine\source\string\stringtable.h" line="162">
Empty string.
</member>
<member name="T:BitSet32" decl="true" source="e:\github\torque6\engine\source\collection\bitset.h" line="30">
A convenience class to manipulate a set of bits.

Notice that bits are accessed directly, ie, by passing
a variable with the relevant bit set or not, instead of
passing the index of the relevant bit.
</member>
<member name="F:BitSet32.mbits" decl="false" source="e:\github\torque6\engine\source\collection\bitset.h" line="39">
Internal representation of bitset.
</member>
<member name="M:BitSet32.set" decl="false" source="e:\github\torque6\engine\source\collection\bitset.h" line="50">
Set all bits to true.
</member>
<member name="M:BitSet32.set(System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\collection\bitset.h" line="53">
Set the specified bit(s) to true.
</member>
<member name="M:BitSet32.set(BitSet32,System.Boolean)" decl="false" source="e:\github\torque6\engine\source\collection\bitset.h" line="56">
Masked-set the bitset; ie, using s as the mask and then setting the masked bits
to b.
</member>
<member name="M:BitSet32.clear" decl="false" source="e:\github\torque6\engine\source\collection\bitset.h" line="60">
Clear all bits.
</member>
<member name="M:BitSet32.clear(System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\collection\bitset.h" line="63">
Clear the specified bit(s).
</member>
<member name="M:BitSet32.toggle(System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\collection\bitset.h" line="66">
Toggle the specified bit(s).
</member>
<member name="M:BitSet32.test(System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\collection\bitset.h" line="69">
Are any of the specified bit(s) set?
</member>
<member name="M:BitSet32.testStrict(System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\collection\bitset.h" line="72">
Are ALL the specified bit(s) set?
</member>
<member name="M:BitSet32.op_Assign(System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\collection\bitset.h" line="75">
@name Operator Overloads
@{
</member>
<member name="F:gWarnUndefinedScriptVariables" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="38">
Indicates that warnings about undefined script variables should be displayed.

@note This is set and controlled by script.
</member>
<member name="T:ConsoleLogEntry" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="48">
Represents an entry in the log.
</member>
<member name="T:ConsoleLogEntry.Level" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="51">
This field indicates the severity of the log entry.

Log entries are filtered and displayed differently based on
their severity. Errors are highlighted red, while normal entries
are displayed as normal text. Often times, the engine will be
configured to hide all log entries except warnings or errors,
or to perform a special notification when it encounters an error.
</member>
<member name="T:ConsoleLogEntry.Type" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="66">
Used to associate a log entry with a module.

Log entries can come from different sources; for instance,
the scripting engine, or the network code. This allows the
logging system to be aware of where different log entries
originated from.
</member>
<member name="F:ConsoleLogEntry.mString" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="82">
Indicates the actual log entry.

This contains a description of the event being logged.
For instance, "unable to access file", or "player connected
successfully", or nearly anything else you might imagine.

Typically, the description should contain a concise, descriptive
string describing whatever is being logged. Whenever possible,
include useful details like the name of the file being accessed,
or the id of the player or GuiControl, so that if a log needs
to be used to locate a bug, it can be done as painlessly as
possible.
</member>
<member name="T:EnumTable" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="97">
Scripting engine representation of an enum.

This data structure is used by the scripting engine
to expose enumerations to the scripting language. It
acts to relate named constants to integer values, just
like an enum in C++.
</member>
<member name="F:EnumTable.size" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="105">
Number of enumerated items in the table.
</member>
<member name="T:EnumTable.Enums" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="108">
This represents a specific item in the enumeration.
</member>
<member name="M:EnumTable.#ctor(System.Int32,EnumTable.Enums*)" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="117">
Constructor.

This sets up the EnumTable with predefined data.

@param sSize  Size of the table.
@param sTable Pointer to table of Enums.

@see gLiquidTypeTable
@see gAlignTable
</member>
<member name="D:StringCallback" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="136">
@defgroup tsScripting TorqueScript Bindings
TorqueScrit bindings
@defgroup console_callbacks Scripting Engine Callbacks
@ingroup tsScripting

The scripting engine makes heavy use of callbacks to represent
function exposed to the scripting language. StringCallback,
IntCallback, FloatCallback, VoidCallback, and BoolCallback all
represent exposed script functions returning different types.

ConsumerCallback is used with the function Con::addConsumer; functions
registered with Con::addConsumer are called whenever something is outputted
to the console. For instance, the TelnetConsole registers itself with the
console so it can echo the console over the network.

@note Callbacks to the scripting language - for instance, onExit(), which is
      a script function called when the engine is shutting down - are handled
      using Con::executef() and kin.
@{

</member>
<member name="D:GetDataFunction" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="165">
@}
@defgroup console_types Scripting Engine Type Functions
@ingroup tsScripting

@see Con::registerType
@{
</member>
<member name="F:DSOVersion" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="189">
This is the version number associated with DSO files.

If you make any changes to the way the scripting language works
(such as DSO format changes, adding/removing op-codes) that would
break compatibility, then you should increment this.

If you make a really major change, increment it to the next multiple
of ten.

12/29/04 - BJG - 33-&gt;34 Removed some opcodes, part of namespace upgrade.
12/30/04 - BJG - 34-&gt;35 Reordered some things, further general shuffling.
11/03/05 - BJG - 35-&gt;36 Integrated new debugger code.
</member>
<member name="T:Con.Constants" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="186">
Various configuration constants.
</member>
<member name="M:Con.init" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="214">
@name Control Functions

The console must be initialized and shutdown appropriately during the
lifetime of the app. These functions are used to manage this behavior.

@note Torque deals with this aspect of console management, so you don't need
      to call these functions in normal usage of the engine.
@{
Initializes the console.

This performs the following steps:
  - Calls Namespace::init() to initialize the scripting namespace hierarchy.
  - Calls ConsoleConstructor::setup() to initialize globally defined console
    methods and functions.
  - Registers some basic global script variables.
  - Calls AbstractClassRep::init() to initialize Torque's class database.
  - Registers some basic global script functions that couldn't usefully
    be defined anywhere else.
</member>
<member name="M:Con.shutdown" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="235">
Shuts down the console.

This performs the following steps:
  - Closes the console log file.
  - Calls Namespace::shutdown() to shut down the scripting namespace hierarchy.
</member>
<member name="M:Con.isActive" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="242">
Is the console active at this time?
</member>
<member name="M:Con.addConsumer(=FUNC:System.Void(ConsoleLogEntry.Level,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*))" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="245">
@}
@name Console Consumers

The console distributes its output through Torque by using
consumers. Every time a new line is printed to the console,
all the ConsumerCallbacks registered using addConsumer are
called, in order.

@note The GuiConsole control, which provides the on-screen
      in-game console, uses a different technique to render
      the console. It calls getLockLog() to lock the Vector
      of on-screen console entries, then it renders them as
      needed. While the Vector is locked, the console will
      not change the Vector. When the GuiConsole control is
      done with the console entries, it calls unlockLog()
      to tell the console that it is again safe to modify
      the Vector.

@see TelnetConsole
@see TelnetDebugger
@see WinConsole
@see MacCarbConsole
@see iPhoneConsole
@see StdConsole
@see ConsoleLogger

@{
</member>
<member name="M:Con.stripColorChars(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="275">
@}
@name Miscellaneous
@{
Remove color marking information from a string.

@note It does this in-place, so be careful! It may
      potentially blast data if you're not careful.
      When in doubt, make a copy of the string first.
</member>
<!-- Discarding badly formed XML document comment for member 'M:Con.expandPath(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte*,System.UInt32,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Boolean!System.Runtime.CompilerServices.IsConst)'. -->
<member name="M:Con.isFunction(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="321">
Returns true if fn is a global scripting function.

This looks in the global namespace. It also checks to see if fn
is in the StringTable; if not, it returns false.
</member>
<member name="M:Con.tabComplete(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte*,System.UInt32,System.UInt32,System.Boolean)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="327">
This is the basis for tab completion in the console.

@note This is an internally used function. You probably don't
      care much about how this works.

This function does some basic parsing to try to ascertain the namespace in which
we are attempting to do tab completion, then bumps control off to the appropriate
tabComplete function, either in SimObject or Namespace.

@param  inputBuffer     Pointer to buffer containing starting data, or last result.
@param  cursorPos       Location of cursor in this buffer. This is used to indicate
                        what part of the string should be kept and what part should
                        be advanced to the next match if any.
@param  maxResultLength Maximum amount of result data to put into inputBuffer. This
                        is capped by MaxCompletionBufferSize.
@param  forwardTab      Should we go forward to next match or backwards to previous
                        match? True indicates forward.
</member>
<member name="M:Con.addVariable(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Int32,System.Void*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="346">
@}
@name Variable Management
@{
Add a console variable that references the value of a variable in C++ code.

If a value is assigned to the console variable the C++ variable is updated,
and vice-versa.

@param name    Global console variable name to create
@param type    The type of the C++ variable; see the ConsoleDynamicTypes enum for a complete list.
@param pointer Pointer to the variable.
@see ConsoleDynamicTypes
</member>
<member name="M:Con.removeVariable(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="363">
Remove a console variable.

@param name   Global console variable name to remove
@return       true if variable existed before removal.
</member>
<member name="M:Con.setLocalVariable(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="369">
Assign a string value to a locally scoped console variable

@note The context of the variable is determined by gEvalState; that is,
      by the currently executing code.

@param name   Local console variable name to set
@param value  String value to assign to name
</member>
<member name="M:Con.getLocalVariable(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="378">
Retrieve the string value to a locally scoped console variable

@note The context of the variable is determined by gEvalState; that is,
      by the currently executing code.

@param name   Local console variable name to get
</member>
<member name="M:Con.setVariable(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="386">
@}
@name Global Variable Accessors
@{
Assign a string value to a global console variable
@param name   Global console variable name to set
@param value  String value to assign to this variable.
</member>
<member name="M:Con.getVariable(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="395">
Retrieve the string value of a global console variable
@param name   Global Console variable name to query
@return       The string value of the variable or "" if the variable does not exist.
</member>
<member name="M:Con.setBoolVariable(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Boolean)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="400">
Same as setVariable(), but for bools.
</member>
<member name="M:Con.getBoolVariable(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Boolean)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="403">
Same as getVariable(), but for bools.

@param  name  Name of the variable.
@param  def   Default value to supply if no matching variable is found.
</member>
<member name="M:Con.setIntVariable(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="409">
Same as setVariable(), but for ints.
</member>
<member name="M:Con.getIntVariable(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="412">
Same as getVariable(), but for ints.

@param  name  Name of the variable.
@param  def   Default value to supply if no matching variable is found.
</member>
<member name="M:Con.setFloatVariable(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Single)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="418">
Same as setVariable(), but for floats.
</member>
<member name="M:Con.getFloatVariable(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Single)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="421">
Same as getVariable(), but for floats.

@param  name  Name of the variable.
@param  def   Default value to supply if no matching variable is found.
</member>
<member name="M:Con.addCommand(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,=FUNC:System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*(SimObject*,System.Int32,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst**),System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Int32,System.Int32)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="427">
@}
@name Global Function Registration
@{
Register a C++ function with the console making it a global function callable from the scripting engine.

@param name      Name of the new function.
@param cb        Pointer to the function implementing the scripting call; a console callback function returning a specific type value.
@param usage     Documentation for this function. @ref console_autodoc
@param minArgs   Minimum number of arguments this function accepts
@param maxArgs   Maximum number of arguments this function accepts
</member>
<member name="M:Con.addCommand(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,=FUNC:System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*(SimObject*,System.Int32,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst**),System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Int32,System.Int32)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="445">
@}
@name Namespace Function Registration
@{
Register a C++ function with the console making it callable
as a method of the given namespace from the scripting engine.

@param nameSpace Name of the namespace to associate the new function with; this is usually the name of a class.
@param name      Name of the new function.
@param cb        Pointer to the function implementing the scripting call; a console callback function returning a specific type value.
@param usage     Documentation for this function. @ref console_autodoc
@param minArgs   Minimum number of arguments this function accepts
@param maxArgs   Maximum number of arguments this function accepts
</member>
<member name="M:Con.markCommandGroup(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="464">
@}
@name Special Purpose Registration

These are special-purpose functions that exist to allow commands to be grouped, so
that when we generate console docs, they can be more meaningfully presented.

@ref console_autodoc "Click here for more information about console docs and grouping."

@{
</member>
<member name="M:Con.addOverload(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="479">
@deprecated
</member>
<member name="M:Con.printf(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,BTEllipsis)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="482">
@}
@name Console Output

These functions process the formatted string and pass it to all the ConsumerCallbacks that are
currently registered. The console log file and the console window callbacks are installed by default.

@see addConsumer()
@see removeConsumer()
@{
@param _format   A stdlib printf style formatted out put string
@param ...       Variables to be written
</member>
<member name="M:Con.warnf(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,BTEllipsis)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="497">
@note The console window colors warning text as LIGHT GRAY.
@param _format   A stdlib printf style formatted out put string
@param ...       Variables to be written
</member>
<member name="M:Con.errorf(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,BTEllipsis)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="502">
@note The console window colors warning text as RED.
@param _format   A stdlib printf style formatted out put string
@param ...       Variables to be written
</member>
<member name="M:Con.warnf(ConsoleLogEntry.Type,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,BTEllipsis)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="507">
@note The console window colors warning text as LIGHT GRAY.
@param type      Allows you to associate the warning message with an internal module.
@param _format   A stdlib printf style formatted out put string
@param ...       Variables to be written
@see Con::warnf()
</member>
<member name="M:Con.errorf(ConsoleLogEntry.Type,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,BTEllipsis)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="514">
@note The console window colors warning text as RED.
@param type      Allows you to associate the warning message with an internal module.
@param _format   A stdlib printf style formatted out put string
@param ...       Variables to be written
@see Con::errorf()
</member>
<member name="M:Con.cls" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="521">
clear the console log
</member>
<member name="M:Con.printSeparator" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="524">
Prints a separator to the console.
</member>
<member name="M:Con.printBlankLine" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="527">
Prints a separator to the console.
</member>
<member name="M:Con.isMainThread" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="530">
@}
Returns true when called from the main thread, false otherwise
</member>
<member name="M:Con.execute(System.Int32,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst**)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="536">
@name Console Execution

These are functions relating to the execution of script code.

@{
Call a script function from C/C++ code.

@param argc      Number of elements in the argv parameter
@param argv      A character string array containing the name of the function
                 to call followed by the arguments to that function.
@code
// Call a Torque script function called mAbs, having one parameter.
char* argv[] = {"abs", "-9"};
char* result = execute(2, argv);
@endcode
</member>
<member name="M:Con.executef(System.Int32,BTEllipsis)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="554">
@see execute(S32 argc, const char* argv[])
</member>
<member name="M:Con.execute(SimObject*,System.Int32,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst**,System.Boolean)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="557">
Call a Torque Script member function of a SimObject from C/C++ code.
@param object    Object on which to execute the method call.
@param argc      Number of elements in the argv parameter (must be &gt;2, see argv)
@param argv      A character string array containing the name of the member function
                 to call followed by an empty parameter (gets filled with object ID)
                 followed by arguments to that function.
@code
// Call the method setMode() on an object, passing it one parameter.

char* argv[] = {"setMode", "", "2"};
char* result = execute(mysimobject, 3, argv);
@endcode
</member>
<member name="M:Con.executef(SimObject*,System.Int32,BTEllipsis)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="573">
@see execute(SimObject *, S32 argc, const char *argv[])
</member>
<member name="M:Con.evaluate(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Boolean,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="576">
Evaluate an arbitrary chunk of code.

@param  string   Buffer containing code to execute.
@param  echo     Should we echo the string to the console?
@param  fileName Indicate what file this code is coming from; used in error reporting and such.
</member>
<member name="M:Con.evaluatef(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,BTEllipsis)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="583">
Evaluate an arbitrary line of script.

This wraps dVsprintf(), so you can substitute parameters into the code being executed.
</member>
<member name="M:Con.getReturnBuffer(System.UInt32)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="588">
@}
@name Console Function Implementation Helpers

The functions Con::getIntArg, Con::getFloatArg and Con::getArgBuffer(size) are used to
allocate on the console stack string variables that will be passed into the next console

getReturnBuffer lets you allocate stack space to return data in.
@{

</member>
<member name="M:Con.lookupNamespace(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="607">
@}
@name Namespaces
@{
</member>
<member name="M:Con.classLinkNamespaces(Namespace*,Namespace*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="616">
@note This should only be called from consoleObject.h
</member>
<member name="M:Con.getLockLog(ConsoleLogEntry**!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.UInt32*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="618">
@}
@name Logging
@{
</member>
<member name="M:Con.setData(System.Int32,System.Void*,System.Int32,System.Int32,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst**,EnumTable*,BitSet32)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="627">
@}
@name Dynamic Type System
@{

</member>
<member name="T:ConsoleConstructor" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="650">
This is the backend for the ConsoleMethod()/ConsoleFunction() macros.

See the group ConsoleConstructor Innards for specifics on how this works.

@see @ref console_autodoc
@nosubgrouping
</member>
<member name="F:ConsoleConstructor.sc" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="659">
@name Entry Type Fields

One of these is set based on the type of entry we want
inserted in the console.

@ref console_autodoc
@{
</member>
<member name="F:ConsoleConstructor.mina" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="674">
 @deprecated Unused.
@}
Minimum/maximum number of arguments for the function.
</member>
<member name="F:ConsoleConstructor.next" decl="false" source="e:\github\torque6\engine\source\console\console.h" line="683">
@name ConsoleConstructer Innards

The ConsoleConstructor class is used as the backend for the ConsoleFunction() and
ConsoleMethod() macros. The way it works takes advantage of several properties of
C++.

The ConsoleFunction()/ConsoleMethod() macros wrap the declaration of a ConsoleConstructor.

@code
     // The definition of a ConsoleFunction using the macro
     ConsoleFunction(ExpandPath, const char*, 2, 2, "(string filePath)")
     {
        argc;
        char* ret = Con::getReturnBuffer( 1024 );
        Con::expandPath(ret, 1024, argv[1]);
        return ret;
     }

     // Resulting code
     static const char* cExpandPath(SimObject *, S32, const char **argv);
     static ConsoleConstructor
           gExpandPathobj(NULL,"ExpandPath", cExpandPath,
           "(string filePath)", 2, 2);
     static const char* cExpandPath(SimObject *, S32 argc, const char **argv)
     {
        argc;
        char* ret = Con::getReturnBuffer( 1024 );
        Con::expandPath(ret, 1024, argv[1]);
        return ret;
     }

     // A similar thing happens when you do a ConsoleMethod.
@endcode

As you can see, several global items are defined when you use the ConsoleFunction method.
The macro constructs the name of these items from the parameters you passed it. Your
implementation of the console function is is placed in a function with a name based on
the actual name of the console funnction. In addition, a ConsoleConstructor is declared.

Because it is defined as a global, the constructor for the ConsoleConstructor is called
before execution of main() is started. The constructor is called once for each global
ConsoleConstructor variable, in the order in which they were defined (this property only holds true
within file scope).

We have ConsoleConstructor create a linked list at constructor time, by storing a static
pointer to the head of the list, and keeping a pointer to the next item in each instance
of ConsoleConstructor. init() is a helper function in this process, automatically filling
in commonly used fields and updating first and next as needed. In this way, a list of
items to add to the console is assemble in memory, ready for use, before we start
execution of the program proper.

In Con::init(), ConsoleConstructor::setup() is called to process this prepared list. Each
item in the list is iterated over, and the appropriate Con namespace functions (usually
Con::addCommand) are invoked to register the ConsoleFunctions and ConsoleMethods in
the appropriate namespaces.

@see Namespace
@see Con
@{
</member>
<member name="M:ConsoleConstructor.#ctor(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,=FUNC:System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*(SimObject*,System.Int32,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst**),System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Int32,System.Int32)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="748">
@}
@name Basic Console Constructors
@{
</member>
<member name="M:ConsoleConstructor.#ctor(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="758">
@}
@name Magic Console Constructors

These perform various pieces of "magic" related to consoleDoc functionality.
@ref console_autodoc
@{
Indicates a group marker. (A doxygen illusion)

@see Con::markCommandGroup
@ref console_autodoc
</member>
<member name="M:ConsoleConstructor.#ctor(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="772">
Indicates a namespace usage string.
</member>
<member name="T:Namespace" decl="true" source="e:\github\torque6\engine\source\console\console.h" line="778">
@name Global Console Definition Macros

@note If TORQUE_DEBUG is defined, then we gather documentation information, and
      do some extra sanity checks.

@see ConsoleConstructor
@ref console_autodoc
@{
@}
</member>
<!-- Discarding badly formed XML document comment for member 'T:AbstractClassRep'. -->
<member name="D:AbstractClassRep.SetDataNotify" decl="false" source="e:\github\torque6\engine\source\console\consoleobject.h" line="190">
This is a function pointer typedef to support get/set callbacks for fields
</member>
<member name="D:AbstractClassRep.WriteDataNotify" decl="false" source="e:\github\torque6\engine\source\console\consoleobject.h" line="194">
This is a function pointer typedef to support optional writing for fields.
</member>
<member name="D:AbstractClassRep.WriteCustomTamlSchema" decl="false" source="e:\github\torque6\engine\source\console\consoleobject.h" line="197">
Allows the writing of a custom TAML schema.
</member>
<member name="F:AbstractClassRep.Field.pFieldDocs" decl="false" source="e:\github\torque6\engine\source\console\consoleobject.h" line="225">

 This is filled when type is StartField or EndField
</member>
<member name="M:AbstractClassRep.isClass(AbstractClassRep*)" decl="false" source="e:\github\torque6\engine\source\console\consoleobject.h" line="277">
Helper class to see if we are a given class, or a subclass thereof.
</member>
<member name="T:ConsoleObject" decl="false" source="e:\github\torque6\engine\source\console\consoleobject.h" line="431">
Interface class to the console.

@section ConsoleObject_basics The Basics

Any object which you want to work with the console system should derive from this,
and access functionality through the static interface.

This class is always used with the DECLARE_CONOBJECT and IMPLEMENT_* macros.

@code
// A very basic example object. It will do nothing!
class TorqueObject : public ConsoleObject {
     // Must provide a Parent typedef so the console system knows what we inherit from.
     typedef ConsoleObject Parent;

     // This does a lot of menial declaration for you.
     DECLARE_CONOBJECT(TorqueObject);

     // This is for us to register our fields in.
     static void initPersistFields();

     // A sample field.
     S8 mSample;
}
@endcode

@code
// And the accordant implementation...
IMPLEMENT_CONOBJECT(TorqueObject);

void TorqueObject::initPersistFields()
{
  // If you want to inherit any fields from the parent (you do), do this:
  Parent::initPersistFields();

  // Pass the field, the type, the offset,                  and a usage string.
  addField("sample", TypeS8, Offset(mSample, TorqueObject), "A test field.");
}
@endcode

That's all you need to do to get a class registered with the console system. At this point,
you can instantiate it via script, tie methods to it using ConsoleMethod, register fields,
and so forth. You can also register any global variables related to the class by creating
a consoleInit() method.

You will need to use different IMPLEMENT_ macros in different cases; for instance, if you
are making a NetObject (for ghosting), a DataBlock, or a NetEvent.

@see AbstractClassRep for gory implementation details.
@nosubgrouping
</member>
<member name="M:ConsoleObject.#ctor" decl="false" source="e:\github\torque6\engine\source\console\consoleobject.h" line="485">
@deprecated This is disallowed.
</member>
<member name="M:ConsoleObject.findField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="489">
Get a reference to a field by name.
</member>
<member name="M:ConsoleObject.getClassRep" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="492">
Gets the ClassRep.
</member>
<member name="M:ConsoleObject.setField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="495">
Set the value of a field.
</member>
<member name="M:ConsoleObject.create(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="500">
@name Object Creation
@{
</member>
<member name="M:ConsoleObject.lookupClassName(System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="504">
@}
Get the classname from a class tag.
</member>
<member name="M:ConsoleObject.addGroup(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="511">
@name Fields
@{
Mark the beginning of a group of fields.

This is used in the consoleDoc system.
@see console_autodoc
</member>
<member name="M:ConsoleObject.endGroup(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="520">
Mark the end of a group of fields.

This is used in the consoleDoc system.
@see console_autodoc
</member>
<member name="M:ConsoleObject.addField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.UInt32!System.Runtime.CompilerServices.IsConst,System.UInt32!System.Runtime.CompilerServices.IsConst,System.UInt32!System.Runtime.CompilerServices.IsConst,EnumTable*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="526">
Register a complex field.

@param  in_pFieldname     Name of the field.
@param  in_fieldType      Type of the field. @see ConsoleDynamicTypes
@param  in_fieldOffset    Offset to  the field from the start of the class; calculated using the Offset() macro.
@param  in_elementCount   Number of elements in this field. Arrays of elements are assumed to be contiguous in memory.
@param  in_table          An EnumTable, if this is an enumerated field.
@param  in_pFieldDocs     Usage string for this field. @see console_autodoc
</member>
<member name="M:ConsoleObject.addField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.UInt32!System.Runtime.CompilerServices.IsConst,System.UInt32!System.Runtime.CompilerServices.IsConst,=FUNC:System.Boolean(System.Void*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*),System.UInt32!System.Runtime.CompilerServices.IsConst,EnumTable*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="541">
Register a complex field with a write notify.

@param  in_pFieldname     Name of the field.
@param  in_fieldType      Type of the field. @see ConsoleDynamicTypes
@param  in_fieldOffset    Offset to  the field from the start of the class; calculated using the Offset() macro.
@param  in_writeDataFn    This method will return whether the field should be written or not.
@param  in_elementCount   Number of elements in this field. Arrays of elements are assumed to be contiguous in memory.
@param  in_table          An EnumTable, if this is an enumerated field.
@param  in_pFieldDocs     Usage string for this field. @see console_autodoc
</member>
<member name="M:ConsoleObject.addField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.UInt32!System.Runtime.CompilerServices.IsConst,System.UInt32!System.Runtime.CompilerServices.IsConst,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="558">
Register a simple field.

@param  in_pFieldname  Name of the field.
@param  in_fieldType   Type of the field. @see ConsoleDynamicTypes
@param  in_fieldOffset Offset to  the field from the start of the class; calculated using the Offset() macro.
@param  in_pFieldDocs  Usage string for this field. @see console_autodoc
</member>
<member name="M:ConsoleObject.addField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.UInt32!System.Runtime.CompilerServices.IsConst,System.UInt32!System.Runtime.CompilerServices.IsConst,=FUNC:System.Boolean(System.Void*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*),System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="570">
Register a simple field with a write notify.

@param  in_pFieldname  Name of the field.
@param  in_fieldType   Type of the field. @see ConsoleDynamicTypes
@param  in_fieldOffset Offset to  the field from the start of the class; calculated using the Offset() macro.
@param  in_writeDataFn    This method will return whether the field should be written or not.
@param  in_pFieldDocs  Usage string for this field. @see console_autodoc
</member>
<member name="M:ConsoleObject.addFieldV(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.UInt32!System.Runtime.CompilerServices.IsConst,System.UInt32!System.Runtime.CompilerServices.IsConst,ConsoleTypeValidator*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="583">
Register a validated field.

A validated field is just like a normal field except that you can't
have it be an array, and that you give it a pointer to a ConsoleTypeValidator
subclass, which is then used to validate any value placed in it. Invalid
values are ignored and an error is printed to the console.

@see addField
@see typeValidators.h
</member>
<member name="M:ConsoleObject.addProtectedField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.UInt32!System.Runtime.CompilerServices.IsConst,System.UInt32!System.Runtime.CompilerServices.IsConst,=FUNC:System.Boolean(System.Void*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*),=FUNC:System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*(System.Void*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*),System.UInt32!System.Runtime.CompilerServices.IsConst,EnumTable*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.C" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="598">
Register a complex protected field.

@param  in_pFieldname     Name of the field.
@param  in_fieldType      Type of the field. @see ConsoleDynamicTypes
@param  in_fieldOffset    Offset to  the field from the start of the class; calculated using the Offset() macro.
@param  in_setDataFn      When this field gets set, it will call the callback provided. @see console_protected
@param  in_getDataFn      When this field is accessed for it's data, it will return the value of this function
@param  in_elementCount   Number of elements in this field. Arrays of elements are assumed to be contiguous in memory.
@param  in_table          An EnumTable, if this is an enumerated field.
@param  in_pFieldDocs     Usage string for this field. @see console_autodoc
</member>
<member name="M:ConsoleObject.addProtectedField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.UInt32!System.Runtime.CompilerServices.IsConst,System.UInt32!System.Runtime.CompilerServices.IsConst,=FUNC:System.Boolean(System.Void*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*),=FUNC:System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*(System.Void*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*),=FUNC:System.Boolean(System.Void*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*),Syste" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="617">
Register a complex protected field.

@param  in_pFieldname     Name of the field.
@param  in_fieldType      Type of the field. @see ConsoleDynamicTypes
@param  in_fieldOffset    Offset to  the field from the start of the class; calculated using the Offset() macro.
@param  in_setDataFn      When this field gets set, it will call the callback provided. @see console_protected
@param  in_getDataFn      When this field is accessed for it's data, it will return the value of this function
@param  in_writeDataFn    This method will return whether the field should be written or not.
@param  in_elementCount   Number of elements in this field. Arrays of elements are assumed to be contiguous in memory.
@param  in_table          An EnumTable, if this is an enumerated field.
@param  in_pFieldDocs     Usage string for this field. @see console_autodoc
</member>
<member name="M:ConsoleObject.addProtectedField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.UInt32!System.Runtime.CompilerServices.IsConst,System.UInt32!System.Runtime.CompilerServices.IsConst,=FUNC:System.Boolean(System.Void*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*),=FUNC:System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*(System.Void*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*),System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="638">
Register a simple protected field.

@param  in_pFieldname  Name of the field.
@param  in_fieldType   Type of the field. @see ConsoleDynamicTypes
@param  in_fieldOffset Offset to  the field from the start of the class; calculated using the Offset() macro.
@param  in_setDataFn   When this field gets set, it will call the callback provided. @see console_protected
@param  in_getDataFn   When this field is accessed for it's data, it will return the value of this function
@param  in_pFieldDocs  Usage string for this field. @see console_autodoc
</member>
<member name="M:ConsoleObject.addProtectedField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.UInt32!System.Runtime.CompilerServices.IsConst,System.UInt32!System.Runtime.CompilerServices.IsConst,=FUNC:System.Boolean(System.Void*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*),=FUNC:System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*(System.Void*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*),=FUNC:System.Boolean(System.Void*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*),Syste" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="653">
Register a simple protected field.

@param  in_pFieldname  Name of the field.
@param  in_fieldType   Type of the field. @see ConsoleDynamicTypes
@param  in_fieldOffset Offset to  the field from the start of the class; calculated using the Offset() macro.
@param  in_setDataFn   When this field gets set, it will call the callback provided. @see console_protected
@param  in_getDataFn   When this field is accessed for it's data, it will return the value of this function
@param  in_writeDataFn    This method will return whether the field should be written or not.
@param  in_pFieldDocs  Usage string for this field. @see console_autodoc
</member>
<member name="M:ConsoleObject.addDepricatedField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="670">
Add a deprecated field.

A deprecated field will always be undefined, even if you assign a value to it. This
is useful when you need to make sure that a field is not being used anymore.
</member>
<member name="M:ConsoleObject.removeField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="676">
Remove a field.

Sometimes, you just have to remove a field!
@returns True on success.
</member>
<member name="M:ConsoleObject.initPersistFields" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="682">
@}
Register dynamic fields in a subclass of ConsoleObject.

@see addField(), addFieldV(), addDepricatedField(), addGroup(), endGroup()
</member>
<member name="M:ConsoleObject.consoleInit" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="689">
Register global constant variables and do other one-time initialization tasks in
a subclass of ConsoleObject.

@deprecated You should use ConsoleMethod and ConsoleFunction, not this, to
            register methods or commands.
@see console
</member>
<member name="M:ConsoleObject.getFieldList" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="697">
@name Field List
@{
Get a list of all the fields. This information cannot be modified.
</member>
<member name="M:ConsoleObject.getModifiableFieldList" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="703">
Get a list of all the fields, set up so we can modify them.

@note This is a bad trick to pull if you aren't very careful,
      since you can blast field data!
</member>
<member name="M:ConsoleObject.getDynamicGroupExpand" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="709">
Get a handle to a boolean telling us if we expanded the dynamic group.

@see GuiInspector::Inspect()
</member>
<member name="M:ConsoleObject.getStaticClassRep" decl="false" source="e:\github\torque6\engine\source\console\consoleobject.h" line="713">
@}
@name ConsoleObject Implementation

These functions are implemented in every subclass of
ConsoleObject by an IMPLEMENT_CONOBJECT or IMPLEMENT_CO_* macro.
@{
Get the abstract class information for this class.
</member>
<member name="M:ConsoleObject.getParentStaticClassRep" decl="false" source="e:\github\torque6\engine\source\console\consoleobject.h" line="724">
Get the abstract class information for this class's superclass.
</member>
<member name="M:ConsoleObject.getClassId(System.UInt32)" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="727">
Get our network-layer class id.

@param  netClassGroup  The net class for which we want our ID.
@see
</member>
<member name="M:ConsoleObject.getClassName" decl="true" source="e:\github\torque6\engine\source\console\consoleobject.h" line="733">
Get our compiler and platform independent class name.

@note This name can be used to instantiate another instance using create()
</member>
<member name="T:ColorI" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="34">
@defgroup stream_overload Primitive Type Stream Operation Overloads
These macros define the read and write functions for all primitive types.
@{
@}
</member>
<member name="T:Stream" decl="false" source="e:\github\torque6\engine\source\io\stream.h" line="67">
Base stream class for streaming data across a specific media
</member>
<member name="T:Stream.Status" decl="false" source="e:\github\torque6\engine\source\io\stream.h" line="71">
Status constantants for the stream
</member>
<member name="M:Stream.getStatus" decl="false" source="e:\github\torque6\engine\source\io\stream.h" line="99">
Gets the status of the stream
</member>
<member name="M:Stream.getStatusString(Stream.Status!System.Runtime.CompilerServices.IsConst)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="101">
Gets a printable string form of the status
</member>
<member name="M:Stream.hasCapability(Stream.Capability!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\io\stream.h" line="109">
Checks to see if this stream has the capability of a given function
</member>
<member name="M:Stream.getPosition" decl="false" source="e:\github\torque6\engine\source\io\stream.h" line="112">
Gets the position in the stream
</member>
<member name="M:Stream.setPosition(System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\io\stream.h" line="114">
Sets the position of the stream.  Returns if the new position is valid or not
</member>
<member name="M:Stream.getStreamSize" decl="false" source="e:\github\torque6\engine\source\io\stream.h" line="116">
Gets the size of the stream
</member>
<member name="M:Stream.readLine(System.Byte*,System.UInt32)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="119">
Reads a line from the stream.
@param buffer buffer to be read into
@param bufferSize max size of the buffer.  Will not read more than the "bufferSize"
</member>
<member name="M:Stream.writeLine(System.Byte*)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="123">
writes a line to the stream
</member>
<member name="M:Stream.readSTString(System.Boolean)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="126">
Reads a string and inserts it into the StringTable
@see StringTable
</member>
<member name="M:Stream.readString(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte*)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="129">
Reads a string of maximum 255 characters long
</member>
<member name="M:Stream.readLongString(System.UInt32,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte*)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="131">
Reads a string that could potentially be more than 255 characters long.
@param maxStringLen Maximum length to read.  If the string is longer than maxStringLen, only maxStringLen bytes will be read.
@param stringBuf buffer where data is read into
</member>
<member name="M:Stream.writeLongString(System.UInt32,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="135">
Writes a string to the stream.  This function is slightly unstable.
Only use this if you have a valid string that is not empty.
writeString is safer.
</member>
<member name="M:Stream.writeString(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Int32)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="142">
Writes a string to the stream.
</member>
<member name="M:Stream.writeFormattedBuffer(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,BTEllipsis)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="145">
Writes a formatted buffer to the stream.
NOTE: A maximum string length of 4K is allowed.
</member>
<member name="M:Stream.writeStringBuffer(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="false" source="e:\github\torque6\engine\source\io\stream.h" line="149">
Writes a NULL terminated string buffer.
</member>
<member name="M:Stream.write(ColorI!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="152">
Write an integral color to the stream.
</member>
<member name="M:Stream.write(ColorF!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="154">
Write a floating point color to the stream.
</member>
<member name="M:Stream.read(ColorI*)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="156">
Read an integral color from the stream.
</member>
<member name="M:Stream.read(ColorF*)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="158">
Read a floating point color from the stream.
</member>
<member name="M:Stream.copyFrom(Stream*)" decl="true" source="e:\github\torque6\engine\source\io\stream.h" line="208">
Copy the contents of another stream into this one
</member>
<member name="M:Stream.writeTabs(System.UInt32)" decl="false" source="e:\github\torque6\engine\source\io\stream.h" line="211">
Write a number of tabs to this stream
</member>
<member name="T:SimFieldDictionary" decl="false" source="e:\github\torque6\engine\source\sim\simfielddictionary.h" line="36">
Dictionary to keep track of dynamic fields on SimObject.
</member>
<member name="F:SimFieldDictionary.mVersion" decl="false" source="e:\github\torque6\engine\source\sim\simfielddictionary.h" line="60">
In order to efficiently detect when a dynamic field has been
added or deleted, we increment this every time we add or
remove a field.
</member>
<member name="T:TamlCallbacks" decl="false" source="e:\github\torque6\engine\source\persistence\taml\tamlcallbacks.h" line="33">
@ingroup tamlGroup
@see tamlGroup
</member>
<member name="M:TamlCallbacks.onTamlPreWrite" decl="false" source="e:\github\torque6\engine\source\persistence\taml\tamlcallbacks.h" line="40">
Called prior to Taml writing the object.
</member>
<member name="M:TamlCallbacks.onTamlPostWrite" decl="false" source="e:\github\torque6\engine\source\persistence\taml\tamlcallbacks.h" line="43">
Called after Taml has finished writing the object.
</member>
<member name="M:TamlCallbacks.onTamlPreRead" decl="false" source="e:\github\torque6\engine\source\persistence\taml\tamlcallbacks.h" line="46">
Called prior to Taml reading the object.
</member>
<member name="M:TamlCallbacks.onTamlPostRead(TamlCustomNodes!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\persistence\taml\tamlcallbacks.h" line="49">
Called after Taml has finished reading the object.
The custom properties is additionally passed here for object who want to process it at the end of reading.
</member>
<member name="M:TamlCallbacks.onTamlAddParent(SimObject*)" decl="false" source="e:\github\torque6\engine\source\persistence\taml\tamlcallbacks.h" line="53">
Called after Taml has finished reading the object and has added the object to any parent.
</member>
<member name="M:TamlCallbacks.onTamlCustomWrite(TamlCustomNodes*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\persistence\taml\tamlcallbacks.h" line="56">
Called during the writing of the object to allow custom properties to be written.
</member>
<member name="M:TamlCallbacks.onTamlCustomRead(TamlCustomNodes!System.Runtime.CompilerServices.IsConst*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="false" source="e:\github\torque6\engine\source\persistence\taml\tamlcallbacks.h" line="59">
Called during the reading of the object to allow custom properties to be read.
</member>
<member name="T:SimObject" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="44">
Base class for objects involved in the simulation.

@section simobject_intro Introduction

SimObject is a base class for most of the classes you'll encounter
working in Torque. It provides fundamental services allowing "smart"
object referencing, creation, destruction, organization, and location.
Along with SimEvent, it gives you a flexible event-scheduling system,
as well as laying the foundation for the in-game editors, GUI system,
and other vital subsystems.

@section simobject_subclassing Subclassing

You will spend a lot of your time in Torque subclassing, or working
with subclasses of, SimObject. SimObject is designed to be easy to
subclass.

You should not need to override anything in a subclass except:
    - The constructor/destructor.
    - processArguments()
    - onAdd()/onRemove()
    - onGroupAdd()/onGroupRemove()
    - onNameChange()
    - onStaticModified()
    - onDeleteNotify()
    - onEditorEnable()/onEditorDisable()
    - inspectPreApply()/inspectPostApply()
    - things from ConsoleObject (see ConsoleObject docs for specifics)

Of course, if you know what you're doing, go nuts! But in most cases, you
shouldn't need to touch things not on that list.

When you subclass, you should define a typedef in the class, called Parent,
that references the class you're inheriting from.

@code
class mySubClass : public SimObject {
    typedef SimObject Parent;
    ...
@endcode

Then, when you override a method, put in:

@code
bool mySubClass::onAdd()
{
    if(!Parent::onAdd())
        return false;

    // ... do other things ...
}
@endcode

Of course, you want to replace onAdd with the appropriate method call.

@section simobject_lifecycle A SimObject's Life Cycle

SimObjects do not live apart. One of the primary benefits of using a
SimObject is that you can uniquely identify it and easily find it (using
its ID). Torque does this by keeping a global hierarchy of SimGroups -
a tree - containing every registered SimObject. You can then query
for a given object using Sim::findObject() (or SimSet::findObject() if
you want to search only a specific set).

@code
       // Three examples of registering an object.

       // Method 1:
       AIClient *aiPlayer = new AIClient();
       aiPlayer-&gt;registerObject();

       // Method 2:
       ActionMap* globalMap = new ActionMap;
       globalMap-&gt;registerObject("GlobalActionMap");

       // Method 3:
       bool reg = mObj-&gt;registerObject(id);
@endcode

Registering a SimObject performs these tasks:
    - Marks the object as not cleared and not removed.
    - Assigns the object a unique SimObjectID if it does not have one already.
    - Adds the object to the global name and ID dictionaries so it can be found
      again.
    - Calls the object's onAdd() method. <b>Note:</b> SimObject::onAdd() performs
      some important initialization steps. See @ref simobject_subclassing "here
      for details" on how to properly subclass SimObject.
    - If onAdd() fails (returns false), it calls unregisterObject().
    - Checks to make sure that the SimObject was properly initialized (and asserts
      if not).

Calling registerObject() and passing an ID or a name will cause the object to be
assigned that name and/or ID before it is registered.

Congratulations, you have now registered your object! What now?

Well, hopefully, the SimObject will have a long, useful life. But eventually,
it must die.

There are a two ways a SimObject can die.
        - First, the game can be shut down. This causes the root SimGroup
          to be unregistered and deleted. When a SimGroup is unregistered,
          it unregisters all of its member SimObjects; this results in everything
          that has been registered with Sim being unregistered, as everything
          registered with Sim is in the root group.
        - Second, you can manually kill it off, either by calling unregisterObject()
          or by calling deleteObject().

When you unregister a SimObject, the following tasks are performed:
    - The object is flagged as removed.
    - Notifications are cleaned up.
    - If the object is in a group, then it removes itself from the group.
    - Delete notifications are sent out.
    - Finally, the object removes itself from the Sim globals, and tells
      Sim to get rid of any pending events for it.

If you call deleteObject(), all of the above tasks are performed, in addition
to some sanity checking to make sure the object was previously added properly,
and isn't in the process of being deleted. After the object is unregistered, it
de-allocates itself.

@section simobject_editor Torque Editors

SimObjects are one of the building blocks for the in-game editors. They
provide a basic interface for the editor to be able to list the fields
of the object, update them safely and reliably, and inform the object
things have changed.

This interface is implemented in the following areas:
    - onNameChange() is called when the object is renamed.
    - onStaticModified() is called whenever a static field is modified.
    - inspectPreApply() is called before the object's fields are updated,
                    when changes are being applied.
    - inspectPostApply() is called after the object's fields are updated.
    - onEditorEnable() is called whenever an editor is enabled (for instance,
                    when you hit F11 to bring up the world editor).
    - onEditorDisable() is called whenever the editor is disabled (for instance,
                    when you hit F11 again to close the world editor).

(Note: you can check the variable gEditingMission to see if the mission editor
is running; if so, you may want to render special indicators. For instance, the
fxFoliageReplicator renders inner and outer radii when the mission editor is
running.)

@section simobject_console The Console

SimObject extends ConsoleObject by allowing you to
to set arbitrary dynamic fields on the object, as well as
statically defined fields. This is done through two methods,
setDataField and getDataField, which deal with the complexities of
allowing access to two different types of object fields.

Static fields take priority over dynamic fields. This is to be
expected, as the role of dynamic fields is to allow data to be
stored in addition to the predefined fields.

The fields in a SimObject are like properties (or fields) in a class.

Some fields may be arrays, which is what the array parameter is for; if it's non-null,
then it is parsed with dAtoI and used as an index into the array. If you access something
as an array which isn't, then you get an empty string.

<b>You don't need to read any further than this.</b> Right now,
set/getDataField are called a total of 6 times through the entire
Torque codebase. Therefore, you probably don't need to be familiar
with the details of accessing them. You may want to look at Con::setData
instead. Most of the time you will probably be accessing fields directly,
or using the scripting language, which in either case means you don't
need to do anything special.

The functions to get/set these fields are very straightforward:

@code
 setDataField(StringTable-&gt;insert("locked", false), NULL, b ? "true" : "false" );
 curObject-&gt;setDataField(curField, curFieldArray, STR.getStringValue());
 setDataField(slotName, array, value);
@endcode

<i>For advanced users:</i> There are two flags which control the behavior
of these functions. The first is ModStaticFields, which controls whether
or not the DataField functions look through the static fields (defined
with addField; see ConsoleObject for details) of the class. The second
is ModDynamicFields, which controls dynamically defined fields. They are
set automatically by the console constructor code.

@nosubgrouping
</member>
<member name="T:SimObject.Notify" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="256">
@name Notification
@{
</member>
<member name="T:SimObject.WriteFlags" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="269">
@}
</member>
<member name="F:SelectedOnly" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="273">
 marked as selected should be outputted. Used in SimSet.
</member>
<member name="F:SimObject.mNotifyList" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="291">
@name Notification
@{
</member>
<member name="F:SimObject.mFieldFilter" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="294">
@}
</member>
<member name="F:SimObject.mNotifyFreeList" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="307">
@name Notification
Helper functions for notification code.
@{
</member>
<member name="F:SimObject.mFieldDictionary" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="315">
@}
</member>
<member name="M:SimObject.onTamlPreWrite" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="321">
Taml callbacks.
</member>
<member name="M:SimObject.getDataField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="379">
@name Accessors
@{
Get the value of a field on the object.

See @ref simobject_console "here" for a detailed discussion of what this
function does.

@param   slotName    Field to access.
@param   array       String containing index into array
                     (if field is an array); if NULL, it is ignored.
</member>
<member name="M:SimObject.setDataField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="392">
Set the value of a field on the object.

See @ref simobject_console "here" for a detailed discussion of what this
function does.

@param   slotName    Field to access.
@param   array       String containing index into array; if NULL, it is ignored.
@param   value       Value to store.
</member>
<member name="M:SimObject.getDataFieldType(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="412">
Get the type of a field on the object.

@param   slotName    Field to access.
@param   array       String containing index into array
                     (if field is an array); if NULL, it is ignored.
</member>
<member name="M:SimObject.getFieldDictionary" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="419">
Get reference to the dictionary containing dynamic fields.

See @ref simobject_console "here" for a detailed discussion of what this
function does.

This dictionary can be iterated over using a SimFieldDictionaryIterator.
</member>
<member name="M:SimObject.clearDynamicFields" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="427">
Clear all dynamic fields.
</member>
<member name="M:SimObject.setCanSaveDynamicFields(System.Boolean)" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="430">
Set whether fields created at runtime should be saved. Default is true.
</member>
<member name="M:SimObject.getCanSaveDynamicFields" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="432">
Get whether fields created at runtime should be saved. Default is true.
</member>
<member name="M:SimObject.setInternalName(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="435">
These functions support internal naming that is not namespace
bound for locating child controls in a generic way.

Set the internal name of this control (Not linked to a namespace)
</member>
<member name="M:SimObject.getInternalName" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="440">
Get the internal of of this control
</member>
<member name="M:SimObject.save(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Boolean)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="443">
Save object as a TorqueScript File.
</member>
<member name="M:SimObject.isMethod(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="446">
Check if a method exists in the objects current namespace.
</member>
<member name="M:SimObject.#ctor(System.Byte!System.Runtime.CompilerServices.IsConst)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="448">
@}
@name Initialization
@{

</member>
<member name="M:SimObject.onAdd" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="459">
@}
@name Events
@{
</member>
<member name="M:SimObject.inspectPreApply" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="469">

 Specifically, this is called by setDataField
 when a static field is modified, see
 @ref simobject_console "the console details".
Called before any property of the object is changed in the world editor.

The calling order here is:
 - inspectPreApply()
 - ...
 - calls to setDataField()
 - ...
 - inspectPostApply()
</member>
<member name="M:SimObject.inspectPostApply" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="484">
Called after any property of the object is changed in the world editor.

@see inspectPreApply
</member>
<member name="M:SimObject.onDeleteNotify(SimObject*)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="489">
Called when a SimObject is deleted.

When you are on the notification list for another object
and it is deleted, this method is called.
</member>
<member name="M:SimObject.onEditorEnable" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="495">
Called when the editor is activated.
</member>
<member name="M:SimObject.onEditorDisable" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="498">
Called when the editor is deactivated.
</member>
<member name="M:SimObject.findObject(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="501">
@}
Find a named sub-object of this object.

This is subclassed in the SimGroup and SimSet classes.

For a single object, it just returns NULL, as normal objects cannot have children.
</member>
<member name="M:SimObject.removeNotify(System.Void*,SimObject.Notify.Type)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="510">
@name Notification
@{
</member>
<member name="M:SimObject.registerReference(SimObject**)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="518">
Register a reference to this object.

You pass a pointer to your reference to this object.

When the object is deleted, it will null your
pointer, ensuring you don't access old memory.

@param obj   Pointer to your reference to the object.
</member>
<member name="M:SimObject.unregisterReference(SimObject**)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="528">
Unregister a reference to this object.

Remove a reference from the list, so that it won't
get nulled inappropriately.

Call this when you're done with your reference to
the object, especially if you're going to free the
memory. Otherwise, you may erroneously get something
overwritten.

@see registerReference
</member>
<member name="M:SimObject.registerObject" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="541">
@}
@name Registration

SimObjects must be registered with the object system.
@{
Register an object with the object system.

This must be called if you want to keep the object around.
In the rare case that you will delete the object immediately, or
don't want to be able to use Sim::findObject to locate it, then
you don't need to register it.

registerObject adds the object to the global ID and name dictionaries,
after first assigning it a new ID number. It calls onAdd(). If onAdd fails,
it unregisters the object and returns false.

If a subclass's onAdd doesn't eventually call SimObject::onAdd(), it will
cause an assertion.
</member>
<member name="M:SimObject.registerObject(System.UInt32)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="564">
Register the object, forcing the id.

@see registerObject()
@param   id  ID to assign to the object.
</member>
<member name="M:SimObject.registerObject(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="570">
Register the object, assigning the name.

@see registerObject()
@param   name  Name to assign to the object.
</member>
<member name="M:SimObject.registerObject(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.UInt32)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="576">
Register the object, assigning a name and ID.

@see registerObject()
@param   name  Name to assign to the object.
@param   id  ID to assign to the object.
</member>
<member name="M:SimObject.unregisterObject" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="583">
Unregister the object from Sim.

This performs several operations:
 - Sets the removed flag.
 - Call onRemove()
 - Clear out notifications.
 - Remove the object from...
     - its group, if any. (via getGroup)
     - Sim::gNameDictionary
     - Sim::gIDDictionary
 - Finally, cancel any pending events for this object (as it can't receive them now).
</member>
<member name="M:SimObject.getId" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="597">

This helper function can be used when you're done with the object
and don't want to be bothered with the details of cleaning it up.
@}
@name Accessors
@{
</member>
<member name="M:SimObject.addToSet(System.UInt32)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="629">
@}
@name Sets

The object must be properly registered before you can add/remove it to/from a set.

All these functions accept either a name or ID to identify the set you wish
to operate on. Then they call addObject or removeObject on the set, which
sets up appropriate notifications.

An object may be in multiple sets at a time.
@{
</member>
<member name="M:SimObject.writeField(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="646">
@}
@name Serialization
@{
Determine whether or not a field should be written.

@param   fieldname The name of the field being written.
@param   value The value of the field.
</member>
<member name="M:SimObject.write(Stream*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.UInt32,System.UInt32)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="657">
Output the TorqueScript to recreate this object.

This calls writeFields internally.
@param   stream  Stream to output to.
@param   tabStop Indentation level for this object.
@param   flags   If SelectedOnly is passed here, then
                 only objects marked as selected (using setSelected)
                 will output themselves.
</member>
<member name="M:SimObject.writeFields(Stream*!System.Runtime.CompilerServices.IsImplicitlyDereferenced,System.UInt32)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="667">
Write the fields of this object in TorqueScript.

@param   stream  Stream for output.
@param   tabStop Indentation level for the fields.
</member>
<member name="M:SimObject.assignFieldsFrom(SimObject*)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="682">
Copy fields from another object onto this one.

Objects must be of same type. Everything from obj
will overwrite what's in this object; extra fields
in this object will remain. This includes dynamic
fields.

@param   obj Object to copy from.
</member>
<member name="M:SimObject.assignDynamicFieldsFrom(SimObject*)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="692">
Copy dynamic fields from another object onto this one.

Everything from obj will overwrite what's in this
object.

@param   obj Object to copy from.
</member>
<member name="M:SimObject.getNamespace" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="700">
@}
Return the object's namespace.
</member>
<member name="M:SimObject.tabComplete(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*,System.Int32,System.Boolean)" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="705">
Get next matching item in namespace.

This wraps a call to Namespace::tabComplete; it gets the
next thing in the namespace, given a starting value
and a base length of the string. See
Namespace::tabComplete for details.
</member>
<member name="M:SimObject.isSelected" decl="false" source="e:\github\torque6\engine\source\sim\simobject.h" line="713">
@name Accessors
@{
</member>
<member name="M:SimObject.dump" decl="true" source="e:\github\torque6\engine\source\sim\simobject.h" line="722">
@}
</member>
<member name="T:SimNameDictionary" decl="false" source="e:\github\torque6\engine\source\sim\simdictionary.h" line="39">
Map of names to SimObjects

Provides fast lookup for name-&gt;object and
for fast removal of an object given object*
</member>
<member name="T:SimIdDictionary" decl="false" source="e:\github\torque6\engine\source\sim\simdictionary.h" line="88">
Map of ID's to SimObjects.

Provides fast lookup for ID-&gt;object and
for fast removal of an object given object*
</member>
<member name="M:Semaphore.#ctor(System.Int32)" decl="true" source="e:\github\torque6\engine\source\platform\threads\semaphore.h" line="38">
Create a semaphore. initialCount defaults to 1.
</member>
<member name="M:Semaphore.Dispose" decl="true" source="e:\github\torque6\engine\source\platform\threads\semaphore.h" line="40">
Delete a semaphore, ignoring it's count.
</member>
<member name="M:Semaphore.acquire(System.Boolean,System.Int32)" decl="true" source="e:\github\torque6\engine\source\platform\threads\semaphore.h" line="43">
Acquire the semaphore, decrementing its count.
if the initial count is less than 1, block until it goes above 1, then acquire.
Returns true if the semaphore was acquired, false if the semaphore could
not be acquired and block was false.
</member>
<member name="M:Semaphore.release" decl="true" source="e:\github\torque6\engine\source\platform\threads\semaphore.h" line="49">
Release the semaphore, incrementing its count.
Never blocks.
</member>
<member name="M:SimObjectList.removeStable(SimObject*)" decl="true" source="e:\github\torque6\engine\source\sim\simobjectlist.h" line="48">
Remove the SimObject* from the list; guaranteed to preserve list order.
</member>
<member name="T:SimEvent" decl="true" source="e:\github\torque6\engine\source\sim\simevent.h" line="37">
Represents a queued event in the sim.

Sim provides an event queue for your convenience, which
can be used to schedule events. A few things which use
this event queue:

    - The scene lighting system. In order to keep the game
      responsive while scene lighting occurs, the lighting
      process is divided into little chunks. In implementation
      terms, there is a subclass of SimEvent called
      SceneLightingProcessEvent. The process method of this
      subclass calls into the lighting code, telling it to
      perform the next chunk of lighting calculations.
    - The schedule() console function uses a subclass of
      SimEvent called SimConsoleEvent to keep track of
      scheduled events.
</member>
<member name="F:SimEvent.destObject" decl="false" source="e:\github\torque6\engine\source\sim\simevent.h" line="61">
 of addition to the list.
</member>
<member name="M:SimEvent.process(SimObject*)" decl="false" source="e:\github\torque6\engine\source\sim\simevent.h" line="66">

A dummy virtual destructor is required
so that subclasses can be deleted properly
Function called when event occurs.

This is where the meat of your event's implementation goes.

See any of the subclasses for ideas of what goes in here.

The event is deleted immediately after processing. If the
object referenced in destObject is deleted, then the event
is not called. The even will be executed unconditionally if
the object referenced is NULL.

@param   object  Object stored in destObject.
</member>
<member name="T:SimConsoleEvent" decl="true" source="e:\github\torque6\engine\source\sim\simconsoleevent.h" line="32">
Implementation of schedule() function.

This allows you to set a console function to be
called at some point in the future.
</member>
<member name="M:SimConsoleEvent.#ctor(System.Int32,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst**,System.Boolean)" decl="true" source="e:\github\torque6\engine\source\sim\simconsoleevent.h" line="45">
Constructor

Pass the arguments of a function call, optionally on an object.

The object for the call to be executed on is specified by setting
onObject and storing a reference to the object in destObject. If
onObject is false, you don't need to store anything into destObject.

The parameters here are passed unmodified to Con::execute() at the
time of the event.

@see Con::execute(S32 argc, const char *argv[])
@see Con::execute(SimObject *object, S32 argc, const char *argv[])
</member>
<member name="T:SimConsoleThreadExecCallback" decl="false" source="e:\github\torque6\engine\source\sim\simconsolethreadexecevent.h" line="32">
Used by Con::threadSafeExecute()
</member>
<member name="T:Stream" decl="true" source="e:\github\torque6\engine\source\algorithm\crc.h" line="26">
Initial value for CRCs
Value XORd with the CRC to post condition it (ones complement)
</member>
<member name="M:BitStream.writeCussedU32(System.UInt32)" decl="false" source="e:\github\torque6\engine\source\io\bitstream.h" line="84">
Use this method to write out values in a concise but ass backwards way...
Good for values you expect to be frequently zero, often small. Worst case
this will bloat values by nearly 20% (5 extra bits!) Best case you'll get
one bit (if it's zero).

This is not so much for efficiency's sake, as to make life painful for
people that want to reverse engineer our network or file formats.
</member>
<member name="M:BitStream.writeRangedS32(System.Int32,System.Int32,System.Int32)" decl="true" source="e:\github\torque6\engine\source\io\bitstream.h" line="132">
Writes a clamped signed integer to the stream using 
an optimal amount of bits for the range.
</member>
<member name="M:BitStream.readRangedS32(System.Int32,System.Int32)" decl="true" source="e:\github\torque6\engine\source\io\bitstream.h" line="136">
Reads a ranged signed integer written with writeRangedS32.
</member>
<member name="M:BitStream.writeRangedF32(System.Single,System.Single,System.Single,System.UInt32)" decl="true" source="e:\github\torque6\engine\source\io\bitstream.h" line="147">
Writes a clamped floating point value to the 
stream with the desired bits of precision.
</member>
<member name="M:BitStream.readRangedF32(System.Single,System.Single,System.UInt32)" decl="true" source="e:\github\torque6\engine\source\io\bitstream.h" line="151">
Reads a ranged floating point value written with writeRangedF32.
</member>
<member name="T:InfiniteBitStream" decl="false" source="e:\github\torque6\engine\source\io\bitstream.h" line="218">
This class acts to provide an "infinitely extending" stream.

Basically, it does what ResizeBitStream does, but it validates
on every write op, so that you never have to worry about overwriting
the buffer.
</member>
<member name="M:InfiniteBitStream.validate(System.UInt32)" decl="true" source="e:\github\torque6\engine\source\io\bitstream.h" line="229">
Ensure we have space for at least upcomingBytes more bytes in the stream.
</member>
<member name="M:InfiniteBitStream.reset" decl="true" source="e:\github\torque6\engine\source\io\bitstream.h" line="232">
Reset the stream to zero length (but don't clean memory).
</member>
<member name="M:InfiniteBitStream.compact" decl="true" source="e:\github\torque6\engine\source\io\bitstream.h" line="235">
Shrink the buffer down to match the actual size of the data.
</member>
<member name="M:InfiniteBitStream.writeToStream(Stream*!System.Runtime.CompilerServices.IsImplicitlyDereferenced)" decl="true" source="e:\github\torque6\engine\source\io\bitstream.h" line="238">
Write us out to a stream... Results in last byte getting padded!
</member>
<member name="T:TamlChildren" decl="false" source="e:\github\torque6\engine\source\persistence\taml\tamlchildren.h" line="36">
@ingroup tamlGroup
@see tamlGroup
</member>
<member name="M:TamlChildren.getTamlChildCount" decl="false" source="e:\github\torque6\engine\source\persistence\taml\tamlchildren.h" line="41">
Called when Taml attempts to compile a list of children.
</member>
<member name="M:TamlChildren.getTamlChild(System.UInt32!System.Runtime.CompilerServices.IsConst)" decl="false" source="e:\github\torque6\engine\source\persistence\taml\tamlchildren.h" line="44">
Called when Taml attempts to compile a list of children.
</member>
<member name="M:TamlChildren.addTamlChild(SimObject*)" decl="false" source="e:\github\torque6\engine\source\persistence\taml\tamlchildren.h" line="47">
Called when Taml attempts to populate an objects children during a read.
</member>
<!-- Discarding badly formed XML document comment for member 'T:SimSet'. -->
<member name="D:SimSet.iterator" decl="false" source="e:\github\torque6\engine\source\sim\simset.h" line="125">
@name STL Interface
@{

</member>
<member name="M:SimSet.onRemove" decl="true" source="e:\github\torque6\engine\source\sim\simset.h" line="160">
@}
</member>
<member name="M:SimSet.addObject(SimObject*)" decl="true" source="e:\github\torque6\engine\source\sim\simset.h" line="165">
@name Set Management
@{
</member>
<member name="M:SimSet.popObject" decl="true" source="e:\github\torque6\engine\source\sim\simset.h" line="172">

It will force the object to the end of the list if it already exists
in the list.
</member>
<member name="M:SimSet.getTamlChildCount" decl="false" source="e:\github\torque6\engine\source\sim\simset.h" line="181">
@}
</member>
<member name="T:SimSetIterator" decl="false" source="e:\github\torque6\engine\source\sim\simset.h" line="247">
Iterator for use with SimSets

@see SimSet
</member>
<!-- Discarding badly formed XML document comment for member 'T:SimGroup'. -->
<member name="M:SimGroup.addObject(SimObject*)" decl="true" source="e:\github\torque6\engine\source\sim\simset.h" line="303">
Add an object to the group.
</member>
<member name="M:SimGroup.removeObject(SimObject*)" decl="true" source="e:\github\torque6\engine\source\sim\simset.h" line="308">
Remove an object from the group.
</member>
<member name="M:SimGroup.findObject(System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\sim\simset.h" line="313">
Find an object in the group.
</member>
<member name="T:SimDataBlock" decl="false" source="e:\github\torque6\engine\source\sim\simdatablock.h" line="44">
Root DataBlock class.

@section SimDataBlock_intro Introduction

Another powerful aspect of Torque's networking is the datablock. Datablocks
are used to provide relatively static information about entities; for instance,
what model a weapon should use to display itself, or how heavy a player class is.

This gives significant gains in network efficiency, because it means that all
the datablocks on a server can be transferred over the network at client
connect time, instead of being intertwined with the update code for NetObjects.

This makes the network code much simpler overall, as one-time initialization
code is segregated from the standard object update code, as well as providing
several powerful features, which we will discuss momentarily.

@section SimDataBlock_preload preload() and File Downloading

Because datablocks are sent over the wire, using SimDataBlockEvent, before
gameplay starts in earnest, we gain in several areas. First, we don't have to
try to keep up with the game state while working with incomplete information.
Second, we can provide the user with a nice loading screen, instead of the more
traditional "Connecting..." message. Finally, and most usefully, we can request
missing files from the server as we become aware of them, since we are under
no obligation to render anything for the user.

The mechanism for this is fairly basic. After a datablock is unpacked, the
preload() method is called. If it returns false and sets an error, then the
network code checks to see if a file (or files) failed to be located by the
ResManager; if so, then it requests those files from the server. If preload
returns true, then the datablock is considered loaded. If preload returns
false and sets no error, then the connection is aborted.

Once the file(s) is downloaded, the datablock's preload() method is called again.
If it fails with the same error, the connection is aborted. If a new error is
returned, then the download-retry process is repeated until the preload works.

@section SimDataBlock_guide Guide To Datablock Code

To make a datablock subclass, you need to extend three functions:
     - preload()
     - packData()
     - unpackData()

packData() and unpackData() simply read or write data to a network stream. If you
add any fields, you need to add appropriate calls to read or write. Make sure that
the order of reads and writes is the same in both functions. Make sure to call
the Parent's version of these methods in every subclass.

preload() is a bit more complex; it is responsible for taking the raw data read by
unpackData() and processing it into a form useful by the datablock's owning object. For
instance, the Player class' datablock, PlayerData, gets handles to commonly used
nodes in the player model, as well as resolving handles to textures and other
resources. <b>Any</b> code which loads files or performs other actions beyond simply
reading the data from the packet, such as validation, must reside in preload().

To write your own preload() methods, see any of the existing methods in the codebase; for instance,
PlayerData::preload() is an excellent example of error-reporting, data validation, and so forth.

@note A useful trick, which is used in several places in the engine, is that of temporarily
      storing SimObjectIds in the variable which will eventually hold the "real" handle. ShapeImage
      uses this trick in several pllaces; so do the vehicle classes. See GameBaseData for more on
      using this trick.

@see GameBaseData for some more information on the datablocks used throughout
     most of the engine.
@see http://hosted.tribalwar.com/t2faq/datablocks.shtml for an excellent
     explanation of the basics of datablocks from script. Note that these comments
     mostly apply to GameBaseData and its children.
@nosubgrouping
</member>
<member name="F:SimDataBlock.modifiedKey" decl="false" source="e:\github\torque6\engine\source\sim\simdatablock.h" line="122">
@name Datablock Internals
@{
</member>
<member name="M:SimDataBlock.getNextModifiedKey" decl="false" source="e:\github\torque6\engine\source\sim\simdatablock.h" line="132">
Assign a new modified key.

Datablocks are assigned a modified key which is updated every time
a static field of the datablock is changed. These are gotten from
a global store.
</member>
<member name="M:SimDataBlock.getModifiedKey" decl="false" source="e:\github\torque6\engine\source\sim\simdatablock.h" line="139">
Get the modified key for this particular datablock.
</member>
<member name="M:SimDataBlock.packData(BitStream*)" decl="true" source="e:\github\torque6\engine\source\sim\simdatablock.h" line="148">
@}
@name Datablock Interface
@{

</member>
<member name="M:SimDataBlock.preload(System.Boolean,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte*)" decl="true" source="e:\github\torque6\engine\source\sim\simdatablock.h" line="157">
Called to prepare the datablock for use, after it has been unpacked.

@param  server      Set if we're running on the server (and therefore don't need to load
                    things like textures or sounds).
@param  errorBuffer If an error occurs in loading, this is set to a short string describing
                    the error.
@returns True if all went well; false if something failed.

@see @ref SimDataBlock_preload
</member>
<member name="T:SimObjectsConstants" decl="false" source="e:\github\torque6\engine\source\sim\simbase.h" line="92">
Definition of some basic Sim system constants.

These constants define the range of ids assigned to datablocks
(DataBlockObjectIdFirst - DataBlockObjectIdLast), and the number
of bits used to store datablock IDs.

Normal Sim objects are given the range of IDs starting at
DynamicObjectIdFirst and going to infinity. Sim objects use
a SimObjectId to represent their ID; this is currently a U32.

The RootGroupId is assigned to gRootGroup, in which most SimObjects
are addded as child members. See simManager.cc for details, particularly
Sim::initRoot() and following.
</member>
<member name="M:Sim.postEvent(SimObject*,SimEvent*,System.UInt32)" decl="true" source="e:\github\torque6\engine\source\sim\simbase.h" line="189">
a target time of 0 on an event means current event
</member>
<member name="F:ConsoleBaseType.smConsoleTypeCount" decl="false" source="e:\github\torque6\engine\source\console\consolebasetype.h" line="33">
This is used to generate unique IDs for each type.
</member>
<member name="F:ConsoleBaseType.smListHead" decl="false" source="e:\github\torque6\engine\source\console\consolebasetype.h" line="36">
We maintain a linked list of all console types; this is its head.
</member>
<member name="F:ConsoleBaseType.mListNext" decl="false" source="e:\github\torque6\engine\source\console\consolebasetype.h" line="39">
Next item in the list of all console types.
</member>
<member name="M:ConsoleBaseType.Dispose" decl="true" source="e:\github\torque6\engine\source\console\consolebasetype.h" line="42">
Destructor is private to avoid people mucking up the list.
</member>
<member name="M:ConsoleBaseType.getListHead" decl="true" source="e:\github\torque6\engine\source\console\consolebasetype.h" line="52">
@name cbt_list List Interface

Interface for accessing/traversing the list of types.
Get the head of the list.
</member>
<member name="M:ConsoleBaseType.getListNext" decl="false" source="e:\github\torque6\engine\source\console\consolebasetype.h" line="59">
Get the item that follows this item in the list.
</member>
<member name="M:ConsoleBaseType.initialize" decl="true" source="e:\github\torque6\engine\source\console\consolebasetype.h" line="65">
Called once to initialize the console type system.
</member>
<member name="M:ConsoleBaseType.getType(System.Int32!System.Runtime.CompilerServices.IsConst)" decl="true" source="e:\github\torque6\engine\source\console\consolebasetype.h" line="68">
Call me to get a pointer to a type's info.
</member>
<member name="M:ConsoleBaseType.#ctor(System.Int32!System.Runtime.CompilerServices.IsConst,System.Int32*,System.SByte!System.Runtime.CompilerServices.IsSignUnspecifiedByte!System.Runtime.CompilerServices.IsConst*)" decl="true" source="e:\github\torque6\engine\source\console\consolebasetype.h" line="71">
@}
The constructor is responsible for linking an element into the
master list, registering the type ID, etc.
</member>
<member name="M:IJWLayer.SimObjectWrapper.IsAlive" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="26">
-------------------------------------------------------------------------------------------------
<summary>  Query if this object is alive. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<example>
<code>
         SimObjectWrapper wrapper = new SimObjectWrapper(42);
         if(wrapper.IsAlive())
             wrapper.call("foo");
         </code>
         </example>

<returns>  true if alive, false if not. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.GetID(System.String)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="47">
-------------------------------------------------------------------------------------------------
<summary>  Get the unique numeric ID -- or "handle" -- of this object. </summary>

<remarks>
  The id is provided for you by the simulator upon object creation.  You can not change it
  and it likely will not be reused by any other object after this object is deleted.
</remarks>

<param name="mName">   Name of the new. </param>

<returns>  The identifier. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.SetName(System.String)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="70">
-------------------------------------------------------------------------------------------------
<summary>  Sets the name of the SimObject. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="mNewName">   The new name. </param>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.GetName" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="88">
-------------------------------------------------------------------------------------------------
<summary>  Gets the name. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<returns>  nullptr if it fails, else the name. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getClassNamespace" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="106">
-------------------------------------------------------------------------------------------------
<summary>  Gets class namespace. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<returns>  nullptr if it fails, else the class namespace. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getSuperClassNamespace" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="121">
-------------------------------------------------------------------------------------------------
<summary>  Gets super class namespace. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<returns>  nullptr if it fails, else the super class namespace. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.setClassNamespace(System.String)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="136">
-------------------------------------------------------------------------------------------------
<summary>  Sets class namespace. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="namespc"> The namespc. </param>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.setSuperClassNamespace(System.String)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="153">
-------------------------------------------------------------------------------------------------
<summary>  Sets super class namespace. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="namespc"> The namespace. </param>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.isMethod(System.String)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="170">
-------------------------------------------------------------------------------------------------
<summary>  Query if 'methodName' is defined. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="methodName"> Name of the method. </param>

<returns>  true if defined, false if not. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.call(System.String,System.String[])" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="190">
-------------------------------------------------------------------------------------------------
<summary>  Calls a consolemethod. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="name"> The name of the method. </param>
<param name="args"> The arguments. </param>

<returns>  nullptr if it fails, else a String^. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.dumpClassHierarchy" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="221">
-------------------------------------------------------------------------------------------------
<summary>  Dumps the class hierarchy. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.dump" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="233">
-------------------------------------------------------------------------------------------------
<summary>  Dumps this object. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.isMemberOfClass(System.String)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="245">
-------------------------------------------------------------------------------------------------
<summary>  Query if 'className' is member of class. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="className">  Name of the class. </param>

<returns>  true if member of class, false if not. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getClassName" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="276">
-------------------------------------------------------------------------------------------------
<summary>  Gets class name. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<returns>  nullptr if it fails, else the class name. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getFieldValue(System.String)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="292">
-------------------------------------------------------------------------------------------------
<summary>  Gets field value. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="fieldName">  Name of the field. </param>

<returns>  nullptr if it fails, else the field value. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.setFieldValue(System.String,System.String)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="311">
-------------------------------------------------------------------------------------------------
<summary>  Sets field value. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="fieldName">  Name of the field. </param>
<param name="value">      The value. </param>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getDynamicFieldCount" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="329">
-------------------------------------------------------------------------------------------------
<summary>  Gets dynamic field count. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<returns>  The dynamic field count. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getDynamicField(System.Int32)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="348">
-------------------------------------------------------------------------------------------------
<summary>  Gets dynamic field. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="index">   Zero-based index of the. </param>

<returns>  nullptr if it fails, else the dynamic field. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getFieldCount" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="386">
-------------------------------------------------------------------------------------------------
<summary>  Gets field count. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<returns>  The field count. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getField(System.Int32)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="416">
-------------------------------------------------------------------------------------------------
<summary>  Gets a field. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="index">   Zero-based index of the field. </param>

<returns>  nullptr if it fails, else the field. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.setProgenitorFile(System.String)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="458">
-------------------------------------------------------------------------------------------------
<summary>  Sets progenitor file. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="file"> The file. </param>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getProgenitorFile" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="474">
-------------------------------------------------------------------------------------------------
<summary>  Gets progenitor file. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<returns>  nullptr if it fails, else the progenitor file. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getType" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="489">
-------------------------------------------------------------------------------------------------
<summary>  Gets the typemask. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<returns>  The typemask. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getFieldType(System.String)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="504">
-------------------------------------------------------------------------------------------------
<summary>  Gets type of field. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="fieldName">  Name of the field. </param>

<returns>  nullptr if it fails, else the field type. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.setInternalName(System.String)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="529">
-------------------------------------------------------------------------------------------------
<summary>  Sets internal name. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="internalName">  Name of the internal. </param>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getInternalName" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="545">
-------------------------------------------------------------------------------------------------
<summary>  Gets internal name. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<returns>  nullptr if it fails, else the internal name. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.isChildOfGroup(System.Int32)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="560">
-------------------------------------------------------------------------------------------------
<summary>  Query if this object is child of group 'groupID'. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="groupID"> Identifier for the group. </param>

<returns>  true if child of group, false if not. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.getGroup" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="584">
-------------------------------------------------------------------------------------------------
<summary>  Gets the group. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<returns>  The group. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.deleteObject" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="602">
-------------------------------------------------------------------------------------------------
<summary>  Deletes the object. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.clone(System.Boolean)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="616">
-------------------------------------------------------------------------------------------------
<summary>  Makes a deep copy of this object. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="copyDynamicFields">   true to copy dynamic fields. </param>

<returns>  A copy of this object. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.startTimer(System.String,System.Single,System.Int32)" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="641">
-------------------------------------------------------------------------------------------------
<summary>  Starts a timer. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="callbackFunction"> The callback function. </param>
<param name="timePeriod">       The time period. </param>
<param name="repeat">           How many times to repeat (0 for infinite). </param>

<returns>  true if it succeeds, false if it fails. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.stopTimer" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="697">
-------------------------------------------------------------------------------------------------
<summary>  Stops a timer. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.isTimerActive" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="718">
-------------------------------------------------------------------------------------------------
<summary>  Queries if a timer is active. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<returns>  true if a timer is active, false if not. </returns>
-------------------------------------------------------------------------------------------------
</member>
<member name="M:IJWLayer.SimObjectWrapper.schedule(System.Int32,System.String,System.String[])" decl="false" source="e:\github\torque6\engine\compilers\ijwlayer\ijwlayer.cpp" line="733">
-------------------------------------------------------------------------------------------------
<summary>  Schedules a call to a consolemethod. </summary>

<remarks>  Lukas, 24-03-2015. </remarks>

<param name="time">    The time before the method is called. </param>
<param name="command"> The method to call. </param>
<param name="args">    The arguments. </param>

<returns>  The ID of the schedule. </returns>
-------------------------------------------------------------------------------------------------
</member>
</members>
</doc>