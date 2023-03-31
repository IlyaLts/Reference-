/*
An indexer is a special type of property that allows a class or a structure to be accessed like
an array for its internal collection. C# allows us to define custom indexers, generic indexers,
and also overload indexers.
*/
class StringDataStore
{
    private string[] strArr = new string[10]; // internal data storage

    public string this[int index]
    {
        get
        {
            if (index < 0 || index >= strArr.Length)
                throw new IndexOutOfRangeException("Index out of range");

                return strArr[index];
        }

        set
        {
            if (index < 0 ||  index >= strArr.Length)
                throw new IndexOutOfRangeException("Index out of range");

            strArr[index] = value;
        }
    }
}

/*
You can use expression-bodied syntax for get and set from C# 7 onwards.

Example: Indexer
class StringDataStore
{
    private string[] strArr = new string[10]; // internal data storage

    public string this[int index]
    {
        get => strArr[index];

        set => strArr[index] = value;
    }
}
*/

StringDataStore strStore = new StringDataStore();

strStore[0] = "One";
strStore[1] = "Two";
strStore[2] = "Three";
strStore[3] = "Four";
        
for(int i = 0; i < 10 ; i++)
    Console.WriteLine(strStore[i]);

/*
Output:
One
Two
Three
Four
*/