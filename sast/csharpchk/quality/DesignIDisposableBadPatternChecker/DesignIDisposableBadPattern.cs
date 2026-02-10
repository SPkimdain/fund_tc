using System;
using System.Runtime.InteropServices;

public class Resource : IDisposable
{
    private IntPtr nativeResource = Marshal.AllocHGlobal(100);
    private AnotherResource managedResource = new AnotherResource();

    private void Dispose() // @violation 1 1) Dispose() is not 'private' and 'sealed' 2) doesn't call Dispose(true);
    {
        GC.SuppressFinalize(this);
    }
    // NOTE: Leave out the finalizer altogether if this class doesn't
    // own unmanaged resources itself, but leave the other methods
    // exactly as they are.
    ~Resource() // @violation Finalizer calls Dispose(false)
    {
    }
    // The bulk of the clean-up code is implemented in Dispose(bool)
    public virtual void Dispose(bool disposing)  // @violation Dispose(boolean) is not protected, virtual, or unsealed
    {
        if (disposing)
        {
            // free managed resources
            if (managedResource != null)
            {
                managedResource.Dispose();
                managedResource = null;
            }
        }
        // free native resources if there are any.
        if (nativeResource != IntPtr.Zero)
        {
            Marshal.FreeHGlobal(nativeResource);
            nativeResource = IntPtr.Zero;
        }
    }
}
