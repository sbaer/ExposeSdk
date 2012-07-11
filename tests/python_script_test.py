import scriptcontext
import clr
clr.AddReference("ExposeSdkDotNet")
import ExposeSdkDotNet as sdk

sdk.Sample.SayHello("Steve")
s = sdk.Sample(1,2,3)
s.AddAsPointToDoc(scriptcontext.doc, True)
