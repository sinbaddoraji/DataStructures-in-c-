using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryTree
{
    class Node
    {
        public Node left = null;
        public Node right = null;
        public int value;

        public Node() { }

        public Node(int value) => this.value = value;
    }

    class BST
    {
        Node root = null;

        public void AddNode(int value)
        {
            Node node = new Node(value)
            {
                left = null,
                right = null
            };
            AddNode(node, ref root);
        }

        void AddNode(Node node,ref Node chk)
        {
            //chk current node being checked

            if(chk == null)
            {
                chk = node;
                return;
            }
            if (node.value < chk.value)
            {
                if (chk.left != null) AddNode(node,ref chk.left);
                else chk.left = node;
            }
            else
            {
                if (chk.right != null) AddNode(node,ref chk.right);
                else chk.right = node;
            }
        }

        public bool Contains(int value)
        {
            Node cur = root;

            while (value > cur.value)
            {
                if (cur.right != null)
                    cur = cur.right;
                else break;
            }
            while (value < cur.value)
            {
                if (cur.left != null)
                    cur = cur.left;
                else break;
            }
            return cur.value == value;
        }

    }
}
