using System;
using System.Runtime.InteropServices;

namespace UsageLibrary
{
    public class  DisposeMissingFinalize :IDisposable // @violation
    {
        private bool disposed = false;
        private IntPtr unmanagedResource;

        [DllImport("native.dll")]
        private static extern IntPtr AllocateUnmanagedResource();

        [DllImport("native.dll")]
        private static extern void FreeUnmanagedResource(IntPtr p);

        DisposeMissingFinalize()
        {
            unmanagedResource = AllocateUnmanagedResource();
        }

        protected virtual void Dispose(bool disposing)
        {
            if (!disposed)
            {
                // Dispose of resources held by this instance.
                FreeUnmanagedResource(unmanagedResource);
                disposed = true;

                // Suppress finalization of this disposed instance.
                if (disposing)
                {
                    GC.SuppressFinalize(this);
                }
            }
        }

        public void Dispose()
        {
            Dispose(true);
        }
//         ~TypeA()
//         {
//             Dispose(false);
//         }
    }
     public class  DisposeWithFinalizer:IDisposable
    {
        private bool disposed = false;
        private IntPtr unmanagedResource;

        [DllImport("native.dll")]
        private static extern IntPtr AllocateUnmanagedResource();

        [DllImport("native.dll")]
        private static extern void FreeUnmanagedResource(IntPtr p);

        DisposeMissingFinalize()
        {
            unmanagedResource = AllocateUnmanagedResource();
        }

        protected virtual void Dispose(bool disposing)
        {
            if (!disposed)
            {
                // Dispose of resources held by this instance.
                FreeUnmanagedResource(unmanagedResource);
                disposed = true;

                // Suppress finalization of this disposed instance.
                if (disposing)
                {
                    GC.SuppressFinalize(this);
                }
            }
        }

        public void Dispose()
        {
            Dispose(true);
        }

        ~TypeA()
        {
            Dispose(false);
        }
    }
}