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
            else
            {
                node.previous = End();
                End().next = node;
            }
        }

        public Node End()
        {
            Node output = start;

            while (output.next != null)
                output = output.next;

            return output;
        }

    }
}
