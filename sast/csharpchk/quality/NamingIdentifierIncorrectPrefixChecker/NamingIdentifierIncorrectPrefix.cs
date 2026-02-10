using System;

namespace Samples
{
    public interface Book   // @violation
    {
        string Title
        {
            get;
        }

        void Read();
    }

    public interface IBook      // Fixes the violation by prefixing the interface with 'I'
    {
        string Title
        {
            get;
        }

        void Read();
    }

    public class Collection<Item>   // @violation
    {
        public void DoSomeThingBad1<Item>() { } // @violation
        public void DoSomeThingBad2<Item>() { } // @violation
        void DoSomeThingValid1<Item>() { } // valid
    }

    public class CollectionValid<TItem>  // Fixes the violation by prefixing the generic type parameter with 'T'
    {
        void DoSomeThingValid1<TItem>() { } // valid
    }

    public interface IDictionary<K,T> // @violation
    {
    }

    public interface ICollection<TItem>
    {
        void DoSomeThingBad1<Item>(); // @violation
        void DoSomeThingBad2<Item>(); // @violation
        void DoSomeThingValid1<TItem>(); // valid
    }

    public struct PointWithBadTypeParam<K> // @violation
    {
        public K X;
        public K Y;
    }

    public struct PointWithGoodTypeParam<T>
    {
         public K X;
         public K Y;
    }


}