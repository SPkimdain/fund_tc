using System;

namespace DesignLibrary
{
   public class HistoryBad
   {
      public void AddToHistory(string uriString)    // @violation
      {
          Uri newUri = new Uri(uriString);
      }

      public void AddToHistory(Uri uriType) { }
   }
   public class HistoryGood
   {
      public void AddToHistory(string uriString)
      {
          Uri newUri = new Uri(uriString);
          AddToHistory(newUri);
      }

      public void AddToHistory(Uri uriType) { }
   }
}