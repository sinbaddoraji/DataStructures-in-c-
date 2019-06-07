using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTree
{
    class Program
    {
        static void Main(string[] args)
        {
            BST tree = new BST();
            tree.AddNode(5);
            tree.AddNode(4);
            tree.AddNode(6);
            tree.AddNode(3);
            tree.AddNode(7);
            tree.AddNode(2);

            //Check if the tree contains value from 0 to 10
            for (int i = 0; i <= 10; i++)
            {
                if (tree.Contains(i))
                    Console.WriteLine("Tree contains {0}", i);
            }

            Console.ReadKey();
        }
    }
}
