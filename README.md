ExposeSdk
=========

Sample for exporting a .NET SDK from a C++ Rhino plug-in (http:www.rhino3d.com)

There are a few different ways to create a .NET SDK for a Rhino plug-in that other plug-ins/python scripts/grasshopper components can then use.  This project attempts to illustrate these approaches.

* Sample 1
The first sample (and only for now) involves a single C++ rhp and a .NET SDK dll.  The C++ rhp include several exported C functions that are decorated with RH_C_FUNCTION.  We then run the methodgen application (https://github.com/mcneel/rhinocommon/tree/master/methodgen) on the C functions to generate a C# class with pInvokes into the C++ plug-in.

By having both the rhp and dll in the same directory, RhinoCommon will be able to find the DLL since it uses registered plug-in directories as part of the assembly search path.


Authors
-------
Steve Baer - https://github.com/sbaer steve@mcneel.com

Legal Stuff
-----------
Copyright (c) 2012 Robert McNeel & Associates. All Rights Reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
Software.

THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY. ALL IMPLIED
WARRANTIES OF FITNESS FOR ANY PARTICULAR PURPOSE AND OF MERCHANTABILITY ARE HEREBY
DISCLAIMED.

Rhinoceros is a registered trademark of Robert McNeel & Associates.
