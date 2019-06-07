namespace LinkedList
{
    internal class Node
    {
        public Node next = null;
        public int value;
    }

    internal class List
    {
        public Node start = null;
        public Node end = null;

        public void Insert(int value)
        {
            Node node = new Node
            {
                value = value
            };

            if (start == null)
            {
                start = node;
                end = node;
            }
            else
            {
                end.next = node;
                end = node;
            }
        }

    }
}
