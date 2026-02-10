using System;
   namespace UsageLibrary
   {
       public class ABaseTypeUnsealed
       {
           public void BasePublicMethod(int argument1) {}
       }
       public sealed class ABaseTypeSealed
       {
           public void BasePublicMethod(int argument1) {}
       }
       public class ADerivedType:ABaseTypeUnsealed
       {
           // Violates rule: DoNotDecreaseInheritedMemberVisibility.
           // The compiler returns an error if this is overridden instead of new.
           private new void BasePublicMethod(int argument1){}// @violation
       }
       public class ADerivedType:ABaseTypeSealed
       {
           // Violates rule: DoNotDecreaseInheritedMemberVisibility.
           // The compiler returns an error if this is overridden instead of new.
           private new void BasePublicMethod(int argument1){}// @violation
       }
   }