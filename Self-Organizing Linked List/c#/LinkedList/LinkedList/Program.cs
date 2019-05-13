using System;

namespace LinkedList
{
    internal class Program
    {
        private static readonly List list = new List();

        private static void DisplayValues()
        {
            Node cur = list.start;
            while (cur != null)
            {
                Console.WriteLine(cur.value);
                cur = cur.next;
            }
            Console.ReadKey();
        }

        private static void Main(string[] args)
        {
            list.Insert(10);
            list.Insert(2);
            list.Insert(34);
            list.Insert(76);
            list.Insert(23);
            list.Insert(34);



            /*
            list.Insert(3);
            list.Insert(2);
            list.Insert(2);
            list.Insert(4);
            list.Insert(1);
            list.Insert(6);
            */

            /*
            list.Insert(9);
            list.Insert(3);
            list.Insert(8);
            list.Insert(2);
            list.Insert(5);
            list.Insert(2);
            list.Insert(4);
            list.Insert(7);
            list.Insert(1);
            list.Insert(6);
            */

            DisplayValues();
        }
    }
}
