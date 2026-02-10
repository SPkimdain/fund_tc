/* WITH_CHECKERS : SAQT.M.CS.7194 */
/* WITH_CHECKERS : SAQT.M.CS.7196 */

using System.IO;

//NOTE: To run test code with additional engine options, write options like the below.
/* OPT : -show_followers */
public class Person // NOT BUG
{
    // Empty class
}

public class MetricTest
{
    static void CreatePerson1() { new Person(); ExcessiveIncoming(); }
    static void CreatePerson2() { new Person(); ExcessiveIncoming(); }
    static void CreatePerson3() { new Person(); ExcessiveIncoming(); }
    static void CreatePerson4() { new Person(); ExcessiveIncoming(); }
    static void CreatePerson5() { new Person(); ExcessiveIncoming(); }
    static void CreatePerson6() { new Person(); ExcessiveIncoming(); }
    static void CreatePerson7() { new Person(); ExcessiveIncoming(); }
    static void CreatePerson8() { new Person(); ExcessiveIncoming(); }
    static void CreatePerson9() { new Person(); ExcessiveIncoming(); }
    static void CreatePerson10() { new Person(); ExcessiveIncoming(); }
    static void CreatePerson11() { new Person(); ExcessiveIncoming(); }

    static void ExcessiveIncoming() { int x; return x; } /* BUG: SAQT.M.CS.7194 */

    static void Main() /* BUG: SAQT.M.CS.7196 */
    {
        CreatePerson1();
        CreatePerson2();
        CreatePerson3();
        CreatePerson4();
        CreatePerson5();
        CreatePerson6();
        CreatePerson7();
        CreatePerson8();
        CreatePerson9();
        CreatePerson10();
        CreatePerson11();

        Console.WriteLine("Test.");

    }
}