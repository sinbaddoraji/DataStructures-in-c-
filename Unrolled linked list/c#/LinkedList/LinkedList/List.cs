namespace LinkedList
{
    internal class Node
    {
        public Node next = null;
        public int[] value = new int[3];
        private int availableIndex = 0;

        public bool IsFull() => availableIndex == 3;
        public void SetValue(int val)
        {
            if (!IsFull())
            {
                value[availableIndex] = val;
                availableIndex++;
            }
        }
    }

    internal class List
    {
        public Node start = new Node();
        public Node end = null;

        public void Insert(int value)
        {
            if (!start.IsFull())
                start.SetValue(value);
            else if (end == null)
            {
                Node next = new Node();
                next.SetValue(value);

                start.next = next;
                end = next;
            }
            else if (end.IsFull())
            {
                Node next = new Node();
                next.SetValue(value);

                end.next = next;
                end = next;
            }
            else end.SetValue(value);
        }

    }
}
