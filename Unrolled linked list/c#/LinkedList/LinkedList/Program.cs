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
                for (int i = 0; i < 3; i++)
                {
                    Console.WriteLine(cur.value[i]);
                }
                cur = cur.next;
            }
            Console.ReadKey();
        }

        private static void Main(string[] args)
        {
            list.Insert(3);
            list.Insert(2);
            list.Insert(2);
            list.Insert(4);
            list.Insert(1);
            list.Insert(6);

            DisplayValues();
        }
    }
}
