namespace LinkedList
{
    internal class Node
    {
        public Node next = null;
        public Node previous = null;
        public int value;
    }

    internal class List
    {
        public Node start = null;

        public void Insert(int value)
        {
            Node node = new Node
            {
                value = value
            };

            if (start == null) start = node;
            else Insert( node, start);

        }

        public void Insert(Node node, Node cur)
        {
            if (cur == start && node.value < cur.value)
            {
                Node temp = node; // New node to be added to start
                start.previous = null; // Remove node linking backwords
                temp.next = start; //Link current start to be its next link

                temp.next.previous = temp;

                start = temp;
            }
            else
            {
                if (cur.next == null) cur.next = node;
                else
                {
                    while (true)
                    {
                        if (node.value > cur.next.value)
                            cur = cur.next;
                        else break;


                        if (cur.next == null) break;
                    }

                    //Insert value between current and it's next value

                    node.next = cur.next;
                    cur.next = node;
                    node.previous = cur;
                }
            }
        }

    }
}
